/*solution1 60ms*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i=0,res=1,count=0,zero_pos=0;
        vector<int> output(nums.size(),0);
        for(i=0;i<nums.size();i++)
            res=res*nums[i];
        if(!res){
            if(nums.size()==2){
                swap(nums[0],nums[1]);
                return nums;
            }
            else if(nums.size()>2){
                res=1;
                /*计算除0以外所有元素的乘积，并记录0的个数和位置*/
				for(i=0;i<nums.size();i++){
                    if(nums[i]==0){
                        count++;
                        zero_pos=i;
                        continue;
                    }
                    res=res*nums[i];
                }
                if(count==1){
                    output[zero_pos]=res;
                    return output;
                }
                if(count>1)
                    return output;
            }
        }
        for(i=0;i<nums.size();i++)
            output[i]=res/nums[i];
        return output;
    }
};

/*solution3 60ms*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> arr1(nums.size(),1);
        int tmp=1;
        for(int i=1;i<arr1.size();i++)
            arr1[i]=arr1[i-1]*nums[i-1];
        for(int i=nums.size()-1;i>=0;i--){
            arr1[i]=arr1[i]*tmp;
            tmp=tmp*nums[i];
        }
        return arr1;
    }
};
