/*solution1*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()||target<nums[0])
            return 0;
        int low=0,size=nums.size(),high=size-1,mid=0,i=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        // if not found,let varible i go back to find an exact position 
        for(i=size;i>=0&&nums[i-1]>target;i--);
        return i;
    }
};

/*solution2*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()||target<nums[0])
            return 0;
        int low=0,size=nums.size(),high=size-1,mid=0,i=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        // if not found
        return low;
    }
};

