// 6068. Maximum White Tiles Covered by a Carpet.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm> 
#include<vector>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end(), cmp);
        long long result = tiles[0][1] - tiles[0][0] + 1;
        long long lastLen = tiles[0][1] - tiles[0][0] + 1;
        for (int i = 1; i < tiles.size(); i++) {
            //cout << tiles[i][0] << ' ' << tiles[i][1] << endl;
            int curLen = tiles[i][1] - tiles[i][0] + 1;
            if (tiles[i][0] == tiles[i - 1][1] + 1) {
                curLen += lastLen;
                lastLen = curLen;
            }
            else lastLen = curLen;
            result = max(result, (long long)curLen);
        }
        return result > carpetLen ? carpetLen : result;
    }
};

int main()
{
    Solution* p = new Solution();
    vector<vector<int>> matrix{
    {1, 2},
    {5, 6},
    {9, 10},
    {13, 14}
    };
    std::cout << p->maximumWhiteTiles( ,10) <<endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
