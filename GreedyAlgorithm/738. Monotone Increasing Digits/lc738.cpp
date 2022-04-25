/*class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        int temp = n;
        int last1 = 0;
        int last2 = 0;
        while(temp != 0) {
            last1 = temp % 10;
            temp /= 10;
            last2 = temp % 10;
            temp /= 10;
            if(last1 < last2) {
                return monotoneIncreasingDigits(n - 1);
            }
        }
        return n;
    }
};
// this solution is wrong because if the length is odd, it will effect the Odd digit number. For example: 329
*/
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        int index = strNum.size();
        for(int i = strNum.size() - 1; i > 0; i--) { // 9 is the largest one in the single digits. Thus, it is the closest one 
            if(strNum[i - 1] > strNum[i]) {
                index = i;
                strNum[i - 1]--;
            }
        }
        for(int i = index; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};