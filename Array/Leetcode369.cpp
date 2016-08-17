class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash(nums1.begin(),nums1.end());
        vector<int> res;
        int k=0;
        for(int i=0;i<nums2.size();i++){
            if(hash.count(nums2[i])){
                res.push_back(nums2[i]);
                hash.erase(nums2[i]);
            }
        }
        return res;
    }
};
