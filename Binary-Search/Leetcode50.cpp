/*solution1 20ms*/
class Solution {
public:
    double myPow(double x, int n) {
        if(x&&!n)
            return 1;
        double res=1,flag=0;
        if(x==-1.0)
            return n&1==0||n==INT_MIN? 1:-1;
        if(n<0){
            if(n==INT_MIN&&x!=1)/*When n==INT_MIN,if you use abs() ,
									will cause overflow,for the abstract of INT_MIN is larger than INT_MAX for 1*/
                return 0;
            for(int i=0;i<abs(n);i++){
                flag=res;
                res=res*(1/x);  
                if(res==flag)/*flag is used to prevent from time limit exceed£¬
								for n may be very large, when res is going to be zero,
									the iteration will be useless*/
                    return res;
            }
        }
        else{
            for(int i=0;i<n;i++){
                flag=res;
                res=res*x;
                if(res==flag)
                    return res;
            }
        }
        return res;
    }
};

class Solution {
private:
    double power(double x,int n){
        if(x&&!n)
            return 1;
        double res=power(x,n/2);
        if(n%2==0)
            return res*res;
        else
            return res*res*x;
    }

public:
    double myPow(double x, int n) {
        if(n<0)
            return 1/power(x,-n);
        else
            return power(x,n);
    }
};	
