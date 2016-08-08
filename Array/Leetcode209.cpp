class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
            return 0;
        int low=0,high=0,size=nums.size(),sum=0,min_size=INT_MAX;
        for(high=0;high<size;high++){
            sum+=nums[high];
            while(sum>=s){
                min_size=min(min_size,high-low+1);
                sum-=nums[low++];
            }
        }
        return min_size==INT_MAX ? 0:min_size;
    }
};
