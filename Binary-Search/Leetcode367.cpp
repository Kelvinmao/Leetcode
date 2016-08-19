/*use Binary-Search£¬0ms*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0)
            return false;
        long long int low=0,high=num,mid=0;
        while(low<=high){
            mid=low+((high-low)>>1);
            if(mid*mid<num)
                low=mid+1;
            else if(mid*mid>num)
                high=mid-1;
            else if(mid*mid==num)
                return true;
        }
        return false;
    }
};
