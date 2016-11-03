class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1||numRows>s.size()||numRows==s.size())
            return s;
        vector<string> str(numRows);
        int step=1,row=0;
        for(int i=0;i<s.size();++i){
            str[row].push_back(s[i]);
            if(row==0)
                step=1;
            else if(row==numRows-1)
                step=-1;
            row+=step;
        }
        s.clear();
        for(int j=0;j<str.size();++j)
            s.append(str[j]);
        return s;
    }
};
