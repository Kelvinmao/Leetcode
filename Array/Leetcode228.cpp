/*solution1 0ms*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i=0,size=nums.size();
        vector<string> res;
        if(nums.empty())
            return res;
        while(i<size){
            int j=1;
            while(i+j<size&&nums[i+j]-nums[i]==j)
                j++;
            res.push_back(j<=1?to_string(nums[i]):to_string(nums[i])+"->"+to_string(nums[i+j-1]));
            i+=j;
        }
        return res;
    }
};
