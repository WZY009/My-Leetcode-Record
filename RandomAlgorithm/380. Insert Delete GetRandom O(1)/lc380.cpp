// 2022 5.4 14:00
// 2022 5.4 18：05 - 看了答案
class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> umap;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(umap.find(val) != umap.end()) return false;
        umap[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(umap.find(val) == umap.end()) return false;
        int index = umap[val];
        umap[nums[nums.size() - 1]] = index;
        umap.erase(val);
        swap(nums[nums.size() - 1], nums[index]);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()]; // http://cplusplus.com/reference/cstdlib/rand/?kw=rand
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */