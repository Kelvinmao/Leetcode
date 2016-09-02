/*version 1.0*/
class Solution {
private:
    string strSort(string& str){
        int count[26]={0},p=0,size=str.size();
        string res(size,'a');
        for(int i=0;i<str.size();i++)
            count[str[i]-'a']++;
        for(int i=0;i<26;i++)
            for(int j=0;j<count[i];j++)
                res[p++]+=i;   
        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty())
            return {};
        unordered_map<string,vector<string>> hash;
        vector<vector<string>> anagrams;
        for(string s:strs){
            string t=strSort(s);
            // sort(t.begin(),t.end());
            hash[t].push_back(s);
        }
        for(unordered_map<string,vector<string>>::iterator pos=hash.begin();pos!=hash.end();pos++){
            vector<string> anagram(pos->second.begin(),pos->second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};
	
/*version 2.0*/
class Solution {
private:
    string strSort(string& str){
        int count[26]={0},p=0,size=str.size();
        string res(size,'a');
        for(int i=0;i<str.size();i++)
            count[str[i]-'a']++;
        for(int i=0;i<26;i++)
            for(int j=0;j<count[i];j++)
                res[p++]+=i;   
        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty())
            return {};
        unordered_map<string,multiset<string>> hash;
        vector<vector<string>> anagrams;
        for(string s:strs){
            string t=strSort(s);
            // sort(t.begin(),t.end());
            hash[t].insert(s);
        }
        for(unordered_map<string,multiset<string>>::iterator pos=hash.begin();pos!=hash.end();pos++){
            vector<string> anagram(pos->second.begin(),pos->second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};
