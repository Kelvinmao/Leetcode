/*solution1*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.empty())
            return -1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[i+1])
                return nums[i];
        }
        return -1;
    }
};

/*solution2 binary-search TLE*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.empty())
            return res;
        sort(nums.begin(),nums.end());
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
    
    int findDuplicate(vector<int>& nums) {
        vector<int> res(2,-1);
        for(int i=0;i<nums.size();i++){
            res=searchRange(nums,nums[i]);
            if(res[0]!=res[1])
                return nums[res[0]];
        }
        return 65535;
    }
};

/*solution3*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low=0,size=nums.size(),high=size-1,mid=0,count=0,i=0;
        while(low<=high){
            count=0;
            mid=low+(high-low)/2;
            for(i=0;i<size;i++){
                if(nums[i]<=mid)
                    count++;
            }
            if(count>mid)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};

