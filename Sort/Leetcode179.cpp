class Solution {
private:
    static bool compTwoString(string& s1,string& s2){
        return s1+s2>s2+s1;
    }
public:
    string largestNumber(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<string> tmp;
        string res;
        for(int num:nums)
            tmp.push_back(to_string(num));
        sort(tmp.begin(),tmp.end(),compTwoString);
        for(string s:tmp)
            res+=s;
        return res[0]=='0'?"0":res;
    }
};
