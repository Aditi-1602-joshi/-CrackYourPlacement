class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxleft=height[0],maxright=height[n-1];
        int left=0,right=n-1;//left at the 0th index and right at last index
        int sumwater=0;
        while(left<right){
            if(maxleft<=maxright){
                left++;
                maxleft=max(maxleft,height[left]);
                sumwater+=maxleft - height[left];
                
            }
            else{
                right--;
                maxright=max(maxright,height[right]);
                sumwater+=maxright-height[right];
            }
        }
        return sumwater;
    }
};