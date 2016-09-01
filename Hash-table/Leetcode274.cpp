/*solution1 as the definition ,4ms*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
            return 0;
        sort(citations.begin(),citations.end(),greater<int>());
        for(int i=0;i<citations.size();i++){
            if(i>=citations[i])
                return i;
        }
        return citations.size();
    }
};

/*solution2 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
            return 0;
        sort(citations.begin(),citations.end());
        int size=citations.size(),sum=0;
        vector<int> count(size+1,0);
        /*ͳ�����ô���Ϊi��������Ŀ*/
        for(int i=0;i<size;i++)
            count[citations[i]>size?size:citations[i]]++;
        for(int i=size;i>=0;i--){
            /*�����һ����ʼ�����ô������ڵ���i��������Ŀ�����ô������ڵ���i+1���������������ô�������i��������Ŀ*/
			sum+=count[i];
            if(sum>=i)
                return i;
        }
        return -1;
    }
};
