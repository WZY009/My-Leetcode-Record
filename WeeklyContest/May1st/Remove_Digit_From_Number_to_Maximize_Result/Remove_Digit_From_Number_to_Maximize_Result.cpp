// Remove_Digit_From_Number_to_Maximize_Result.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
// check every digit. If the digit behind the target digit is larger than target digit. remove this one. If smaller, go right to find the larger one. If there is no larger ones , deleting the last one.
void getRes(string& s, int pos) {
    if (pos == s.size() - 1) {
        s.resize(s.size() - 1);
        return;
    }
    for (int i = pos; i < s.size() - 1; i++) {
        s[i] = s[i + 1];
    }
    s.resize(s.size() - 1);
    return;
}

string removeDigit(string number, char digit) {
    int index = 0;
    while (index < number.size()) {
        if (number[index] == digit)  break;
        index++;
    }
    if (index == number.size() - 1) {
        getRes(number, index);
        return number;
    }
    int node[2]{ index, number[index] };
    if (number[index + 1] > digit) {
        getRes(number, index);
        return number;
    }
    while (index < number.size()) {
        if (number[index] == digit) {
            if (index == number.size() - 1) {
                getRes(number, index);
                return number;
            }
            else {
                if (number[index + 1] > digit) {
                    getRes(number, index);
                    return number;
                }
                else {
                    node[0] = index;
                    node[1] = number[index];
                }
            }
        }
        index++;
    }
    getRes(number, node[0]);
    return number;
}
int main()
{
    std::cout << removeDigit("1234531", 1);
}
