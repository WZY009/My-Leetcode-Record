class Solution {
public:
    int jump(vector<int>& nums) {
        int curArrange = 0;
        int newArrange = 0;
        int result = 0;
        if(nums.size() == 1) return 0;
        for(int i = 0; i < nums.size(); i++) {
            newArrange = newArrange > (i + nums[i]) ? newArrange : (i + nums[i]);
            if(i == curArrange) {
                if(curArrange != nums.size() - 1) {
                    result++;
                    curArrange = newArrange;
                    if(newArrange >= nums.size() - 1) break; // this row is to prevent the surplus loop, it is also ok without this row but it will cost more time
                }
                else break;                  
            }          
        }
        return result;        
    }
};