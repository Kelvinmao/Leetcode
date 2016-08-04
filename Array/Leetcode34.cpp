class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.empty())
            return res;
        int low=0,size=nums.size(),high=nums.size()-1,mid=0;
        while(low<high){
            mid=low+(high-low)/2;
            if(nums[mid]>target)
                high=mid-1;
            else if(nums[mid]==target)
                high=mid;
            else
                low=mid+1;
        }
        if(nums[low]==target)
            res[0]=low;
        
        low=0,size=nums.size(),high=size-1,mid=0;
        while(low+1<high){
            mid=low+(high-low)/2;
            if(nums[mid]<target)
                low=mid+1;
            else if(nums[mid]==target)
                low=mid;
            else
                high=mid-1;
        }
        if(nums[low+1]==target&&size>1)
            res[1]=low+1;
        else if(nums[low]==target)
            res[1]=low;
        else
            res[1]=-1;
        return res;
    }
};
