class Solution {
private:
    int str2int(string s){
        int res=0;
        for(int i=0;i<s.size();i++){
            res<<=3;
            res|=(s[i]&7);   
        }
        return res;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> map;
        vector<string> res;
        for(int i=0;i+10<=s.size();i++){
            if(map[str2int(s.substr(i,10))]++==1)
                res.push_back(s.substr(i,10));
        }
        return res;
    }
};
