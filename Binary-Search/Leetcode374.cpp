// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long int low=1,high=n,mid=0;
        while(low<=high){
            mid=low+((high-low)>>1);
            if(guess(mid)==0)
                return mid;
            else if(guess(mid)==1)
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};
