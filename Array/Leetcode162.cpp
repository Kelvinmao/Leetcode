class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid=0;
        while(low<=high){
            if(low==high)
                return low;
            mid=low+(high-low)/2;
            if(nums[mid]<nums[mid+1])
                low=mid+1;
            else
                high=mid;
        }
        return -1;
    }
};
