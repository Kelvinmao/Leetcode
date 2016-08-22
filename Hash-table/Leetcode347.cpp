class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;/*第一个参数指定元素类型，第二个参数决定使用哪一种容器，
																						第三个用于建立小顶堆*/
        for(auto num:nums)
            hash[num]++;
        for(auto pos : hash){
            heap.push({pos.second,pos.first});
            if(heap.size()>k)
                heap.pop();
        }
        while(!heap.empty()){
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
