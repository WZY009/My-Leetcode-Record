class Solution {
public:
    int jump(vector<int>& nums) {
        int curArrange = 0;
        int newArrange = 0;
        int result = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(curArrange >= nums.size() - 1) break; // this row is to prevent the surplus loop, it is also ok without this row but it will cost more time            
            newArrange = newArrange > (i + nums[i]) ? newArrange : (i + nums[i]);
            if(i == curArrange) {
                result++;
                curArrange = newArrange;                               
            }          
        }
        return result;        
    }
};