/*solution1,use two unordered_map,24ms*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,char> hash;
        int i=0;
        for(i=0;i<s.size();i++){
            if(hash.find(s[i])!=hash.end()){
                if(hash[s[i]]!=t[i])
                    return false;
            }
            else{
                for(unordered_map<char,char>::iterator it=hash.begin();it!=hash.end();it++){
                    if(it->second==t[i])
                        return false;
                }
                hash[s[i]]=t[i];
            }
        }
        return i==s.size();
    }
};

/*solution2,use two arrays,8ms*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map1[256]={0},map2[256]={0},i=0;/*����Ҫ��ʼ��Ϊ0*/
        for(i=0;i<s.size();i++){
            if(map1[s[i]]!=map2[t[i]])/*���s�е��ַ�ӳ��֮���t���ַ�ӳ��֮����ȣ��򷵻�false;
			                           �״ν���ѭ��ʱ�������ַ�ӳ��֮���ֵ��Ϊ0�����Բ��᷵��false*/
                return false;
            map1[s[i]]=map2[t[i]]=i+1;/*���������Ϊͬһ��ֵ*/
        }
        return i==s.size();
    }
};
