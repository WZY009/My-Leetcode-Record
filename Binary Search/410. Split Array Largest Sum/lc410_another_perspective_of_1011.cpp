// 2022 5.6 10：30 ~ 10：33(I don't have any ideas so view the answer)
// Oh shit! Just need converting this problem to leetcode 1011. Capacity To Ship Packages Within D Days
// 2022 5.6 10:40 restart!
// 2022 5.6 11:03
// Generalized binary search is not so magical. It is essentially a search for the answer to a problem that has a solution and can be found in limited steps.
// 410. Split Array Largest Sum and 1011. Capacity To Ship Packages Within D Days are only one and two sides of the generalized dichotomy search, but it needs to be proved that this question is equivalent to the previous question
class Solution {
public:
    int getParts(vector<int>& nums, int tempMax) {
        int cost = 0;
        int temp = tempMax;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= temp) {
                temp -= nums[i];
            }
            else {
                temp = tempMax;
                cost++;
                i--;
            }
        }
        return cost + 1;
    }
    int leftBound(vector<int>& nums, int minCap, int maxCap, int m) {
        int left = minCap;
        int right = maxCap;
        int mid;
        while(left <= right) {
            mid = left + ((right - left) >> 1);
            int temp = getParts(nums, mid);
            if(temp == m) right = mid - 1;
            else if(temp < m) right = mid - 1;
            else if(temp > m) left = mid + 1;
        }
        return left;
    }
    int splitArray(vector<int>& nums, int m) {
        int minSum = 0; // due to nums[i] >= 0, you can't initialize minSum as 1 !
        int maxSum = 0;
        for(int num : nums) {
            minSum = minSum > num ? minSum : num;
            maxSum += num;
        }
        return leftBound(nums, minSum, maxSum, m);
    }
};