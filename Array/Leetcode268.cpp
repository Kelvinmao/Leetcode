/*solution1 32ms accumulate the sequence from 0 to n, 
not a good algorithm£¬when the test case is large£¬maybe overflow.
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return ((nums.size()*(nums.size()+1))>>1)-accumulate(nums.begin(),nums.end(),0);/*parameter 0 is initial value*/
    } 
};

/*solution2 use bit manipulation and the property of XOR 36ms*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0,y=0,i=0;
        for(i=0;i<=nums.size();i++)
            x^=i;
        for(i=0;i<nums.size();i++)
            y^=nums[i];
        return x^y;
    } 
};

/*solution3 one-pass,with bit manipulation 38ms*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=nums.size(),y=0,i=0;
        for(i=0;i<nums.size();i++)
            x=x^i^nums[i];
        return x;
    } 
};
