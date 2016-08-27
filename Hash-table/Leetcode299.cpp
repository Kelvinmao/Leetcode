class Solution {
public:
    string getHint(string secret, string guess) {
        if(secret.empty()||guess.empty())
            return "0A0B";
        vector<int> countS(10,0);
        vector<int> countG(10,0);
        string res;
        int countA=0,countB=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])
                countA++;
            else{
                /*统计不成对元素个数*/
				countS[secret[i]-'0']++;
                countG[guess[i]-'0']++;
            }
        }
        for(int i=0;i<countS.size();i++)
            countB+=min(countS[i],countG[i]);
        res=to_string(countA)+'A'+to_string(countB)+'B';
        return res;
    }
};
