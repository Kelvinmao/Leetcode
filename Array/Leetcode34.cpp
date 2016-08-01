class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.empty())
            return res;
        int low=0,size=nums.size(),high=size-1,mid=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        if(nums[low]!=target)
            return res;
        res[0]=low;

        high=size-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        res[1]=high;
        return res;
    }
};
