class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int left=0,right=numbers.size()-1;
        while(left<right){
            int sum=numbers[left]+numbers[right];
            if(sum>target){
                right--;
            }
            else if(sum<target){
                left++;
            }
            else{
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }
        }
        return ans;
    }
};