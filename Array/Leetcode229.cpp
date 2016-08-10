class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int curIndex1=0,curIndex2=0,count1=0,count2=0;
        int size=nums.size(),i=0,tri=size/3;
        vector<int>res;
        for(i=0;i<nums.size();i++){
            nums[i]==nums[curIndex1]?count1++:count1--;
            nums[i]==nums[curIndex2]?count2++:count2--;
            if(!count1){
                curIndex1=i;
                count1=1;
            }
            else if(!count2){
                curIndex2=i;
                count2=1;
            }
        }
        count1=0,count2=0;
        for(i=0;i<nums.size();i++){
            if(nums[i]==nums[curIndex1])
                count1++;
            if(nums[i]==nums[curIndex2])
                count2++;
        }
        if(count1>tri)
            res.push_back(nums[curIndex2]);
        if(count2>tri)
            res.push_back(nums[curIndex1]);
        return res;
    }
};
