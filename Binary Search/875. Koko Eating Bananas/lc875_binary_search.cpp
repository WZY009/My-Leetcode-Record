// 2022 5.5 14:33
// 2022 5.5 simulation TLE 15:03
// 2022 5.5 15:43 
class Solution {
public:
    int getHours(vector<int>& piles, int speed) {
        int res = 0;
        for(int i = 0; i < piles.size(); i++) {
            res += piles[i] / speed;
            if(piles[i] % speed != 0) res++;
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long sum = 0;
        int maximum = INT_MIN;
        for(long pile : piles) {
            maximum = pile > maximum ? pile : maximum;
            sum += pile;
        } 
        int left = sum / h > 0 ? sum / h : 1; // pay attention! you don't need to set up left as long type. because sum / h <= 10 ^ 9 * length / h
        int right = maximum;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            int temp = getHours(piles, mid);
            if(temp == h) right = mid - 1;
            // Pay attention to monotonicity of functions and corresponding parameters！
            // In this case, if mid is bigger, the return value of getHours() will smaller!
            // If temp is too large, you can larger its left border.
            // If temp is too small, you can smaller its right border.
            else if(temp > h) left = mid + 1; 
            else if(temp < h) right = mid - 1;            
        }
        return left;
    }
};