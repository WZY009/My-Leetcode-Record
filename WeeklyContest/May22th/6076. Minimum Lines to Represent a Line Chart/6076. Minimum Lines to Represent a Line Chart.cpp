// 6076. Minimum Lines to Represent a Line Chart.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    else return a[1] < b[1];
}
bool isCollinear(vector<int>& coordinate1, vector<int>& coordinate2, vector<int>& coordinate3) {
    pair<unsigned long long, unsigned long long> vector1 = { coordinate2[0] - coordinate1[0], coordinate2[1] - coordinate1[1] };
    pair<unsigned long long, unsigned long long> vector2 = { coordinate3[0] - coordinate2[0], coordinate3[1] - coordinate2[1] };
    /*
    * // this will cause accuracy loss!!! So you have to use dot multiple
    double k1 = vector1.second / vector1.first;
    double k2 = vector2.second / vector2.first;
    */
    unsigned long long x = vector1.first * vector2.second;
    unsigned long long y = vector1.second * vector2.first;
    if (x - y == 0) return true;
    return false;
}

int minimumLines(vector<vector<int>>& stockPrices) {
    // cout << stockPrices.size() << endl;
    if (stockPrices.size() == 1) return 0;
    else if (stockPrices.size() == 2) return 1;
    sort(stockPrices.begin(), stockPrices.end(), cmp);
    int i = 2;
    int num = 1;
    while (i < stockPrices.size()) {
        if (!isCollinear(stockPrices[i - 2], stockPrices[i - 1], stockPrices[i])) {
            //cout << stockPrices[i - 2][0] << ' ' << stockPrices[i - 2][1] << endl;
            //cout << stockPrices[i - 1][0] << ' ' << stockPrices[i - 1][1] << endl;
            //cout << stockPrices[i - 0][0] << ' ' << stockPrices[i - 0][1] << endl;
            //cout << "num++" << endl;
            //cout << "---------------------------------------------------" << endl;          
            num++;
        }
        else {
            //cout << stockPrices[i - 2][0] << ' ' << stockPrices[i - 2][1] << endl;
            //cout << stockPrices[i - 1][0] << ' ' << stockPrices[i - 1][1] << endl;
            //cout << stockPrices[i - 0][0] << ' ' << stockPrices[i - 0][1] << endl;
            //cout << "---------------------------------------------------" << endl;
        }
        i++;
    }
    return num;
}

int main()
{
    vector<vector<int>> vec = { 
        {83, 35}, {79,51}, {61,48}, {54, 87}, {44, 93}, {22, 5}, {87,28}, {64, 8}, {89, 78}, {62, 83}, {58, 72},
        {48, 7}, {97, 16}, {27, 100}, {65, 48}, {11, 31}, {29, 76}, {93, 29}, {72, 59}, {73, 74}, {9, 90}, {66, 81},
        {12, 8}, {86, 80}, {84, 43}, {36, 63}, {80, 45}, {81, 88}, {95, 5}, {40, 59}
    };

    std::cout << minimumLines(vec) <<endl;
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
