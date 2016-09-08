class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()<2)
            return 1;
        int i=0,new_len=1;
        for(i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[new_len]=nums[i];
                new_len++;
            }
        }
        return new_len;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(),unique(nums.begin(),nums.end()));
    }
};
