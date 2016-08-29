class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> hash;
        istringstream in(str);/*构造字符串流时，空格会成为其内部分界，这也是拆分含有空格的字符串的方法之一*/
        int i=0;
        for(string word;in>>word;i++){
            if(hash.find(pattern[i])!=hash.end()){
                if(hash[pattern[i]]!=word)
                    return false;
            }
            else{
                for(unordered_map<char,string>::iterator it=hash.begin();it!=hash.end();it++){
                    if(it->second==word)
                        return false;
                }
                hash[pattern[i]]=word;
            }
        }
        return i==pattern.size();
    }
};
