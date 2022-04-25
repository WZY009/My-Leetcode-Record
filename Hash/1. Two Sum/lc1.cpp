class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // the solution is quite strange because the map is constrctured before compare.
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int left = target - nums[i];
            auto it = map.find(left);
            if (it != map.end()) {
                return { i, it->second };
            }
            map.insert({ nums[i], i });
        }
        return {};
    }
};
