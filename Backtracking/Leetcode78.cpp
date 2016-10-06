/*Solution1 ,Iteration*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> res(1);
        for(int i=0;i<S.size();++i){
            int size=res.size();
            for(int j=0;j<size;j++){
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        return res;
    }
};

/*Solution2 Recursion*/
class Solution {
private:
    void backtracking(vector<int> & nums,vector<int> & sub,vector<vector<int>> & subs,int start){
        subs.push_back(sub);
        for(int i=start;i<nums.size();++i){
            sub.push_back(nums[i]);
            backtracking(nums,sub,subs,i+1);
            sub.pop_back();
        }
    }
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> subs;
        vector<int> sub;
        backtracking(S,sub,subs,0);
        return subs;
    }
};
