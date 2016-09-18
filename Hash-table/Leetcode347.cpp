class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {    
        unordered_map<int,int> map;
        priority_queue<pair<int,int>,vector<pair<int,int>>> heap;/*第一个参数指定元素类型，第二个参数决定使用哪一种容器，
																						第三个用于建立小顶堆*/
        vector<int> res;
        for(auto num:nums)
            map[num]++;
        for(auto pos:map)
            heap.push({pos.second,pos.first});
        for(int i=0;i<k;i++){
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
