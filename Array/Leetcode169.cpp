/*solution1 O(n^2) 20ms*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()<2)
            return nums[0];
        int i=0,j=0,size=nums.size(),count=0;
        int half=size/2;;
        for(i=0;i<size;i++){
            count=0;/*外循环每进行一次count计数变量应该重新置0*/
            /*遇到有重复元素的，我们仅以最后一个元素做参照，来对该元素出现次数进行统计*/
            while(nums[i]==nums[i+1])
                i++;
            for(j=0;j<size;j++){
                if(nums[j]==nums[i]){
                    count++;
                    if(count>half)
                        return nums[i];
                }
            }
        }
        return -1;
    }
};

/*solution2 sort 40ms*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

/*solution3 use majority voting algorithm*/
/*solution1 O(n^2) 20ms*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curIndex=0,count=0,i=0;
        for(i=0;i<nums.size();i++){
            nums[curIndex]==nums[i]?count++:count--;
            if(!count){
                curIndex=i;
                count=1;
            }
        }
        return nums[curIndex];
    }
};


/*solution4 use hash-table time-complexity O(n) memory-complexity O(n)*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()<2)
            return nums[0];
        unordered_map<int,int> num_count;
        int i=0,size=nums.size();
        for(i=0;i<size;i++){
            if(num_count.find(nums[i])==num_count.end())
                num_count[nums[i]]=0;
            else
                num_count[nums[i]]++;
            if(num_count[nums[i]]>=size/2)
                return nums[i];
        }
        return -1;
    }
};

