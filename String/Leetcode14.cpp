class Solution {
    string FindMinString(vector<string> & strs){
        string min_string=strs[0];
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<min_string.size())
                min_string=strs[i];
        }
        return min_string;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        string min_string;
        int min_size=0;
        if(strs.empty())
            return "";
        min_string=FindMinString(strs);
        min_size=min_string.size();
        for(int i=0;i<strs.size();i++){
            int j=0;
            for(j=0;j<min_string.size();j++)
                if(min_string[j]!=strs[i].at(j))
                    break;
            if(j<min_size)
                min_size=j;
        }
        return min_string.substr(0,min_size);
        
    }
};
