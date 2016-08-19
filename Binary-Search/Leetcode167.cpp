/*solution 1 ,use hash-table 8ms*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.empty())
            return {};
        unordered_map<int,int> hash;
        vector<int> res(2,0);
        for(int i=0;i<numbers.size();i++){
            int tmp=target-numbers[i];
            if(hash.find(tmp)!=hash.end()){
                res[0]=hash[tmp]+1;
                res[1]=i+1;
            }
            else
                hash[numbers[i]]=i;
        }
        return res;
    }
};
/*solution2 two pointers 8ms*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	int left = 0, right = numbers.size() - 1;
    	vector<int> res;
    	while(left < right){
        	long long val = numbers[left] + numbers[right];
        	if(val == target){
            	res.push_back(left + 1);
            	res.push_back(right + 1);
            	return res; 
        	}
			else if(val < target)
            	left++;
        	else
            	right--;
    	}
    	return res;
	}
};




