/*solution1*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int size=nums.size();
        int i=0,min=0;
        for(i=0;i<size;i++){
            if(nums[i]<nums[min])
                min=i;
        }
        return nums[min];
    }
};

/*solution2*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int size=nums.size(),low=0,high=size-1,mid=0;
        while(low<high){
            if(nums[low]<nums[high])
                return nums[low];
            mid=(low+high)/2;
            if(nums[mid]>nums[high])
                low=mid+1;
            else
                high=mid;
        }
        return nums[low];
    }
};
