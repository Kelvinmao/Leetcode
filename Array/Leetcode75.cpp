/*solution1 4ms use counting sort*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=0;
        vector<int> zero;
        vector<int> one;
        vector<int> two;
        for(i=0;i<nums.size();i++){
            switch(nums[i]){
                case 0:
                    zero.push_back(nums[i]);
                    break;
                case 1:
                    one.push_back(nums[i]);
                    break;
                case 2:
                    two.push_back(nums[i]);
                    break;   
            }
        }
        for(i=0;i<zero.size();i++)
            nums[i]=zero[i];
        for(i,j=0;j<one.size();i++,j++)
            nums[i]=one[j];
        for(i,k=0;k<two.size();i++,k++)
            nums[i]=two[k];
    }
};
