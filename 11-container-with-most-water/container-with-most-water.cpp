class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int ans= INT_MIN;
        while(left<right){
            int ar=min(height[left],height[right]) * (right-left);
            ans= max(ans,ar);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};