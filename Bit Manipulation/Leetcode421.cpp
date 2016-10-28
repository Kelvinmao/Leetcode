class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxValue=0,mask=0;
        unordered_set<int> map;
        for(int i=31;i>=0;i--){
            mask|=(1<<i);
            map.clear();
            for(int num:nums)
                map.insert(num&mask);
            int candidate= maxValue|(1<<i);
            for(int prefix:map){
                if(map.find(prefix^candidate)!=map.end()){
                    maxValue=candidate;
                    break;
                }
            }
        }
        return maxValue;
    }
};
