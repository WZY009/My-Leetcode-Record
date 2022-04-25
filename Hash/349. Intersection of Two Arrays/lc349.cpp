class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> num_set(nums1.begin(), nums1.end());
        for (int i : nums2) {
            if (num_set.find(i) != num_set.end())
                result_set.insert(i);
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
