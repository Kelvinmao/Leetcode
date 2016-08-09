/*solution1 O(n^2) 20ms*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()<2)
            return nums[0];
        int i=0,j=0,size=nums.size(),count=0;
        int half=size/2;;
        for(i=0;i<size;i++){
            count=0;/*��ѭ��ÿ����һ��count��������Ӧ��������0*/
            /*�������ظ�Ԫ�صģ����ǽ������һ��Ԫ�������գ����Ը�Ԫ�س��ִ�������ͳ��*/
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
        if(nums.size()<2)
            return nums[0];
        int size=nums.size(),count=1,curIndex=0;
        for(int i=1;i<size;i++){
            nums[i]==nums[curIndex]?count++:count--;
            if(!count){
                curIndex=i;
                count=1;
            }
        }
        return nums[curIndex];
    }
};

