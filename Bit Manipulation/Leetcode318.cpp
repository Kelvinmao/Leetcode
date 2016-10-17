/*Brute force*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int max=0;
        for(int i=0;i<words.size();i++){
            int k=0;
            int map[26]={0};
            int size_a=words[i].size();
            while(k<words[i].size())
                map[words[i][k++]-'a']=1;
            for(int j=i+1;j<words.size();j++){
                int m=0;
                int size_b=words[j].size();
                if(size_a*size_b>max){
                    while(m<words[j].size()){
                        if(map[words[j][m]-'a']==0)
                            m++;
                        else
                            break;
                    }
                    if(m==words[j].size())
                        max=size_a*size_b;
                    else
                        continue;
                }
            }
        }
        return max;
    }
};

/*Bit Manipulation*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size=words.size();
        int max=0;
        vector<int> word(size,0);
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++)
                word[i]|=1<<(words[i][j]-'a');
        }
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if((word[i]&word[j])==0&&words[i].size()*words[j].size()>max)
                    max=words[i].size()*words[j].size();
            }
        }
        return max;
    }
};
