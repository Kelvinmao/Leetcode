/*solution1,use two unordered_map,24ms*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,char> hash;
        int i=0;
        for(i=0;i<s.size();i++){
            if(hash.find(s[i])!=hash.end()){
                if(hash[s[i]]!=t[i])
                    return false;
            }
            else{
                for(unordered_map<char,char>::iterator it=hash.begin();it!=hash.end();it++){
                    if(it->second==t[i])
                        return false;
                }
                hash[s[i]]=t[i];
            }
        }
        return i==s.size();
    }
};

/*solution2,use two arrays,8ms*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map1[256]={0},map2[256]={0},i=0;/*数组要初始化为0*/
        for(i=0;i<s.size();i++){
            if(map1[s[i]]!=map2[t[i]])/*如果s中的字符映射之后和t中字符映射之后不相等，则返回false;
			                           首次进入循环时，两个字符映射之后的值都为0，所以不会返回false*/
                return false;
            map1[s[i]]=map2[t[i]]=i+1;/*否则将其更新为同一个值*/
        }
        return i==s.size();
    }
};
