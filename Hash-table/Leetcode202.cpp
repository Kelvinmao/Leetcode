/*solution1 use unordered_set,7ms*/
class Solution {
private:
    int divideThenSum(int n){
        int tmp=n,sum=0;
        while(n){
            tmp=n%10;
            sum+=tmp*tmp;
            n=n/10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        unordered_set<int> hash;
        int res=n;
        while(true){
            res=divideThenSum(res);
            if(hash.count(res)==0)
                hash.insert(res);
            else
                return res==1;
        }
    }
};

/*solution 2,use Floyd cycle algorithm,4ms*/
class Solution {
private:
    int divideThenSum(int n){
        int tmp=n,sum=0;
        while(n){
            tmp=n%10;
            sum+=tmp*tmp;
            n=n/10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow=n,fast=n;
        do{
            slow=divideThenSum(slow);
            fast=divideThenSum(divideThenSum(fast));
        }while(slow!=fast);
        return slow==1;
    }
};
