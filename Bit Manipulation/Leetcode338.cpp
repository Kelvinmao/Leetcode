/*compute every bit then judge if it equals 1*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        for(int i=0;i<=num;i++){
            for(int j=0;j<32;j++){
                if(i!=0&&(i>>j)&1==1)
                    res[i]++;
            }
        }
        return res;
    }
};

/*make use of what you have produced*/
class Solution {
public:
    vector<int> countBits(int num) {
        if(num==0)
            return {0};
        vector<int> res{0,1};
        int k=1,i=1;
        while(i<=num){
            for(i=pow(2,k);i<pow(2,k+1);i++){
                if(i>num)
                    break;
                int tmp=(pow(2,k+1)-pow(2,k))/2;
                if(i<pow(2,k)+tmp)
                    res.push_back(res[i-tmp]);
                else
                    res.push_back(res[i-tmp]+1);
            }
            k++;
        }
        return res;
    }
};

/*divide the section by odd or even*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res{0};
        for(int i=1;i<=num;i++){
            if(i%2==0)
                res.push_back(res[i/2]);
            else
                res.push_back(res[i/2]+1);
        }
        return res;
    }
}; 
