// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=0,high=n-1,mid=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(isBadVersion(mid))
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};
