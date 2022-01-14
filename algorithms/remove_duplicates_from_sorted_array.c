class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write_i = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[i-1]) {
                nums[++write_i] = nums[i];
            }
        }
        
        int ret = nums.size() == 0 ? 0 : write_i+1;
        
        return ret;
    }
};
