//version 1.0.0
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.empty()&&magazine.empty()||ransomNote.empty()&&!magazine.empty())
            return true;
        int ransom_arr[26]={0};
        int mag_arr[26]={0};
        bool flag=false;
        for(int i=0;i<ransomNote.size();++i)
            ransom_arr[ransomNote[i]-'a']++;
        for(int i=0;i<magazine.size();++i)
            mag_arr[magazine[i]-'a']++;
        for(int i=0;i<ransomNote.size();++i){
            if(ransom_arr[ransomNote[i]-'a']<=mag_arr[ransomNote[i]-'a'])//注意此处的条件 
                flag=true;
            else
                return false;
        }
        return flag;
    }
};

//version 2.0.0,more graceful
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransom_arr[26]={0};
        int mag_arr[26]={0};
        for(int i=0;i<magazine.size();++i)
            ++mag_arr[magazine[i]-'a'];
        for(int i=0;i<ransomNote.size();++i)
            if((--mag_arr[ransomNote[i]-'a'])<0)
                return false;
        return true;
    }
};
