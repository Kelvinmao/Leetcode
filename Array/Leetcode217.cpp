class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)
            return false;
        sort(nums.begin(),nums.end());
        int i=0;
        for(i;i<nums.size();i++){
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }
};
