class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res=0,last1bit=0,single1=0,single2=0;
        vector<int> result(2,0);
        for(int num:nums)
            res^=num;
        last1bit=res-(res&(res-1));
        for(int num:nums){
            if((last1bit&num)==0)
                single1^=num;
            else
                single2^=num;
        }
        result[0]=single1;
        result[1]=single2;
        return result;
    }
};
