class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {    
        unordered_map<int,int> map;
        priority_queue<pair<int,int>,vector<pair<int,int>>> heap;/*��һ������ָ��Ԫ�����ͣ��ڶ�����������ʹ����һ��������
																						���������ڽ���С����*/
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
