class Solution {
public:
    string toHex(int num) {
        string res;
        int low=0,high=0;
        char map[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        while(num&&res.size()<8){
            res=map[(num&0xf)]+res;
            num=num>>4;
        }
        return res;
    }
};
