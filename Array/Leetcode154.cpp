class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,size=nums.size(),high=size-1,mid=0;
        while(low<high){
            mid=low+(high-low)/2;
            if(nums[low]<nums[high])
                return nums[low];
            if(nums[mid]>nums[high])
                low=mid+1;
            else if(nums[mid]<nums[high])
                high=mid;
            else
                high--;
        }
        return nums[low];
    }
};
