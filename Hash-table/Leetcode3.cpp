/*solution1 hash-map+sliding window*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        unordered_map<char,int> hash;
        int longest,res=0,i=0,j=0,size=s.size();
        string tmp;
        while(i<size&&j<size){
            if(hash.find(s[j])==hash.end()){
                hash[s[j++]]=j;
                res=max(res,j-i);
            }
            else    
                hash.erase(s[i++]);
        }
        return res;
    }
};

/*solution2*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mymap(256,-1);
        int i,last=0,res=0;
        for(i=0;i<s.length();i++) {
            if(mymap[s[i]]==-1 || mymap[s[i]]<last)
                res = max(res,i-last+1);
            else
                last = mymap[s[i]]+1;
            mymap[s[i]]=i;
        }
        return res;
    }
};
