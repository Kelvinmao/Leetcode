/*solution 1,use heap,144ms,O(n^2 *  logk),k is the size of heap*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> heap;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                heap.emplace(matrix[i][j]);
                if(heap.size()>k)
                    heap.pop();
            }
        }
        return heap.top();
    }
};

/*solution 2,use binary-search,O(nlogn),56ms*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low=matrix[0][0],n=matrix.size(),high=matrix[n-1][n-1],cnt=0,mid=low+((high-low)>>1);
        while(low<=high){
            mid=low+((high-low)>>1);
            cnt=0;
            for(int i=0;i<matrix.size();i++)
                cnt=cnt+upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            if(cnt<k)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};
