class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int left=0,mid1=0,mid2=0,right=0,tmp_mid2=0,tmp_right=0,tmp_mid1=0,tmp_left=0;
        int size=nums.size();
        sort(nums.begin(),nums.end());
        if(size<4)
            return res;
        for(left=0;left<size-3;left++){
            int tmp_left=target-nums[left];
            if(left > 0 && nums[left] == nums[left-1])
                continue;
            if(nums[left]+nums[left+1]+nums[left+2]+nums[left+3]>target)
                break;
            if(nums[left]+nums[size-3]+nums[size-2]+nums[size-1]<target)
                continue;
            for(mid1=left+1;mid1<size-2;mid1++){
                int tmp=tmp_left-nums[mid1];
                mid2=mid1+1;
                right=size-1;
                if(mid1 > left+1 && nums[mid1] == nums[mid1-1])
                    continue;
                if(nums[left]+nums[mid1]+nums[mid1+1]+nums[mid1+2]>target)
                    break;
                if(nums[left]+nums[mid1]+nums[size-2]+nums[size-1]<target)
                    continue;
                while(mid2<right){
                    if(nums[mid2]+nums[right]==tmp){
                        tmp_mid2=nums[mid2];
                        tmp_right=nums[right];
                        res.push_back({nums[left],nums[mid1],nums[mid2],nums[right]});
                        while(mid2 < right && nums[++mid2] == tmp_mid2);
                        while(mid2 < right && nums[--right] == tmp_right);
                    }
                    else if(nums[mid2]+nums[right]<tmp)
                        mid2++;
                    else
                        right--;
                }
            }
        }
        return res;
    }
};
