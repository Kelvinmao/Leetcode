/*solution1，36ms*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size=height.size();
        int start=0,end=size-1;
        int container=0,max_value=0;
        while(start<end){
            container=min(height[start],height[end])*(end-start);
            max_value=max(container,max_value);
            if(height[start]<height[end])
                start++;
            else
                end--;
        }
        return max_value;
    }
};

/*solution2,24ms*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size=height.size();
        int start=0,end=size-1;
        int container=0,max_value=0,het=0;
        while(start<end){
            het=min(height[start],height[end]);
            container=het*(end-start);
            max_value=max(container,max_value);
            /*如果不大于当前height，则start继续向前移动*/
			while(height[start]<=het&&start<end)
                start++;
            while(height[end]<=het&&start<end)
                end--;
        }
        return max_value;
    }
};
