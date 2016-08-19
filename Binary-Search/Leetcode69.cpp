/*solution1 use binary-search 8ms*/
class Solution {
public:
    int mySqrt(int x) {
        if(x<0)
            return -1;
        int low=0,high=x;
        double root=0;
        while(low<=high){
            root=low+(high-low)/2;
            if(x>=root*root&&x<(root+1)*(root+1))
                return (int)root;
            if(root*root<x)
                low=root+1;
            else
                high=root-1;
        }
        return -1;
    }
};

/*solution 2 use Newton's method*/
class Solution {
public:
    int mySqrt(int x) {
        if(x<0)
            return -1;
        if(x==0)
            return 0;
        double last=0,res=1;
        while(res!=last){
            last=res;
            res=(res+x/res)/2;
        }
        return (int)res;
    }
};
