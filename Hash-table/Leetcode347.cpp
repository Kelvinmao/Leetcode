class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;/*��һ������ָ��Ԫ�����ͣ��ڶ�����������ʹ����һ��������
																						���������ڽ���С����*/
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
