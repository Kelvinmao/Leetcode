/*my first solution*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0)
            return;
        int i=0,j=0,zero_num=0,size=nums.size();
        while(i<size){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
                i++;   
            }
            else{
                zero_num++;
                i++;
            }
        }
        for(i=size-zero_num;i<size;i++)
            nums[i]=0;
    }
};

/*second solution*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        fill(remove(nums.begin(),nums.end(),0),nums.end(),0);
    }
};
