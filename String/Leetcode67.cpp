class Solution {
public:
    string addBinary(string a, string b) {
        int str_size=max(a.size(),b.size());
        string res;
        int carry=0;
        for(int i=0;i<str_size;i++){
            int tmpA=i<a.size()?(a[a.size()-1-i]-'0'):0;
            int tmpB=i<b.size()?(b[b.size()-1-i]-'0'):0;
            res.insert(0,to_string((tmpA+tmpB+carry)%2));
            carry=(tmpA+tmpB+carry)>1?1:0;
        }
        if(carry==1)
            res.insert(0,"1");
        return res;
    }
};
