/*TLE*/
class Solution {
public:
    void moveRight(vector<int> &nums){
        int temp=nums.back();
        int i=0;
        for(i=nums.size()-2;i>=0;i--)
            nums[i+1]=nums[i];
        nums[0]=temp;
    }
    
    void rotate(vector<int>& nums, int k) {
        if(k<=0)
            return;
        int i=0;
        for(i;i<k%nums.size();i++)
            moveRight(nums);
    }
};

/*create a same vector*/
class Solution {
public:
    
    void rotate(vector<int>& nums, int k) {
        if(k<=0)
            return;
        int size=nums.size(),i=0;
        vector<int>nums2(nums.begin(),nums.end());
        for(i=0;i<size;i++){
            nums[(i+k)%size]=nums2[i];
        }
    }
};


