/*solution1,use a vector to compute the frequency,4ms*/ 
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> word(26,0);
        for(int i=0;i<s.size();i++)
            word[s[i]-'a']++;
        for(int i=0;i<t.size();i++){
            int tmp=word[t[i]-'a']--;
            if(tmp==0)
                return t[i];
        }
        return 'a';
    }
};

/*solution2,use bit manipulation£¬4ms*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        char tmp=0;
        for(char a:s)
            tmp^=a;
        for(char b:t)
            tmp^=b;
        return tmp;
    }
};

/*solution 3,one-line version of solution2*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        return accumulate(begin(s), end(s += t), 0, bit_xor<int>());
    }
};
