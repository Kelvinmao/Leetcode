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
        /*统计引用次数为i的文章数目*/
        for(int i=0;i<size;i++)
            count[citations[i]>size?size:citations[i]]++;
        for(int i=size;i>=0;i--){
            /*从最后一个开始，引用次数大于等于i的文章数目是引用次数大于等于i+1的文章数加上引用次数等于i的文章数目*/
			sum+=count[i];
            if(sum>=i)
                return i;
        }
        return -1;
    }
};
