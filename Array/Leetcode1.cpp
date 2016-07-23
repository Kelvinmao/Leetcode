/*first solution,very slow*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i=0,j=0,k=0;
    int *arr=(int *)malloc(2*sizeof(int));;
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                arr[0]=i;
                arr[1]=j;
            }
        }
    }
    return arr;
}

/*second solution,faster,using hash table*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> hash;
        int i=0,numToFind=0;
        for(i=0;i<nums.size();i++){
            numToFind=target-nums[i];
            if(hash.find(numToFind)!=hash.end()){
                result.push_back(hash[numToFind]);
                result.push_back(i);
            }
            hash[nums[i]]=i;
        }
        return result;
    }
};
