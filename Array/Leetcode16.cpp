class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size=nums.size(),left=0,min=nums[0]+nums[1]+nums[2],mid=0,right=0;
        if(size<3)
            return 0;
        sort(nums.begin(),nums.end());
        for(left=0;left<size-2;left++){
            int tmp=target-nums[left];
            mid=left+1;
            right=size-1;
            while(mid<right){
                if(abs(tmp-nums[mid]-nums[right])<abs(target-min))
                    min=nums[left]+nums[mid]+nums[right];
                if(tmp==nums[mid]+nums[right])
                    return min;
                else if(nums[mid]+nums[right]<tmp)
                    mid++;
                else
                    right--;
            }
        }
        return min;
    }
};
