// In essence, the hashmap stores nums[j], which can reduce time complexity!
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1; // If we don't add this row, we can not find the target in the first time
        int result = 0;
        int sum = 0;
        for(int it : nums) {
            sum += it;
            int target = sum - k;
            if(map.find(target) != map.end()) {
                result += map[target];
            }
            map[sum]++;
        }
        return result;
    }
};
