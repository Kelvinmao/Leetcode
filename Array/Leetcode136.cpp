/*use bit manipulation 20ms,no extra place*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i=0,single=0;
        for(i=0;i<nums.size();i++)
            single^=nums[i];
        return single;
    }
};

/*use hash-table*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash;
        int i=0,single;
        for(i=0;i<nums.size();i++){
            if(hash.find(nums[i])==hash.end())
                hash[nums[i]]=i;
            else
                hash.erase(nums[i]);
        }
        unordered_map<int,int>::iterator it=hash.begin();
        return (*it).first;
    }
};
