// 6077. Sum of Total Strength of Wizards.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include<vector>
#include <stack>
using namespace std;

int totalStrength(vector<int>& strength) {
    const int mod = 1e9 + 7;

    int n = strength.size();
    vector<int> left(n, -1); // left[i] 为左侧严格小于 strength[i] 的最近元素位置（不存在时为 -1）
    vector<int> right(n, n); // right[i] 为右侧小于等于 strength[i] 的最近元素位置（不存在时为 n）
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && strength[st.top()] >= strength[i]) {
            right[st.top()] = i;
            st.pop();
        }
        if (!st.empty()) left[i] = st.top();
        st.push(i);
    }

    long s = 0L; // 前缀和
    vector<int> ss(n + 2); // 前缀和的前缀和
    for (int i = 1; i <= n; ++i) {
        s += strength[i - 1];
        ss[i + 1] = (ss[i] + s) % mod;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        long l = left[i] + 1, r = right[i] - 1; // [l,r] 左闭右闭
        long tot = ((i - l + 1) * (ss[r + 2] - ss[i + 1]) - (r - i + 1) * (ss[i + 1] - ss[l])) % mod;
        ans = (ans + strength[i] * tot) % mod; // 累加贡献
    }
    return (ans + mod) % mod; // 防止算出负数（因为上面算 tot 有个减法）
}

int main()
{
    vector<int> vec = { 1,3,1,2 };
    cout << totalStrength(vec) << endl;
}
