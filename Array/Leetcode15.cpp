class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int left=0,mid=0,right=0,tmp=0,size=nums.size();
        for(left=0;left<size&&nums[left]<=0;left++){
            tmp=0-nums[left];
            mid=left+1;
            right=size-1;
            while(mid<right){
                if(nums[mid]+nums[right]==tmp){
                    int tmp_left=nums[left],tmp_right=nums[right],tmp_mid=nums[mid];
                    vector<int>triplet(3,0);
                    triplet[0]=nums[left];
                    triplet[1]=nums[mid];
                    triplet[2]=nums[right];
                    res.push_back(triplet);
                    while(mid<right&&nums[++mid]==tmp_mid);
                    while(mid<right&&nums[--right]==tmp_right);
                }
                else if(nums[mid]+nums[right]<tmp)
                    mid++;
                else
                    right--;
            }
            while(left+1<size&&nums[left]==nums[left+1])
                left++;
        }
        return res;
    }
};
