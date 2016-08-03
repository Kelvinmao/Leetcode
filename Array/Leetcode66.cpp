/*solution1*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=0,size=digits.size(),carry=1;
        for(i=size-1;i>=0;i--){
            int digit=(digits[i]+carry)%10;
            carry=(digits[i]+carry)/10;
            digits[i]=digit;
            if(carry==0)
                return digits;
        }
        vector<int> res(size+1,0);
        res[0]=1;
        return res;
    }
};

/*solution2*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=0,size=digits.size();
        for(i=size-1;i>=0;i--){
            if(digits[i]==9)
                digits[i]=0;
            else{
                digits[i]++;
                return digits;
            }
        }
        digits[0]=1;
        digits.push_back(0);
        return digits;
    }
};
