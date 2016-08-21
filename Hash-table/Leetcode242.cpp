/*solution 1,52ms*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.empty()&&t.empty())
            return true;
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> hash;
        unordered_map<char,int> hash2;
        bool flag=false;
        for(int i=0;i<s.size();i++)
            hash[s[i]]++;
        for(int i=0;i<t.size();i++)
            hash2[t[i]]++;
        for(int i=0;i<s.size();i++){
            if(hash[s[i]]==hash2[s[i]])
                flag=true;
            else
                return false;
        }
        return flag;
    }
};

/*solution2 36ms*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> hash;
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
            hash[t[i]]--;
        }
        for(auto pos:hash)
            if(pos.second!=0)
                return false;
        return true;
    }
};

/*solution 3,use array instead of hash-table,12ms*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int count[26]={0};
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(int pos:count)
            if(pos!=0)
                return false;
        return true;
    }
};
