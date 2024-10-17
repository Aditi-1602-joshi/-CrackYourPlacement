class Solution {
public:

    void solve(vector<int>& nums, int ind, int n, vector<vector<int>>& ans, vector<int>& curr){
        if(ind >= n){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[ind]);
        solve(nums, ind+1, n, ans, curr);

        curr.pop_back();
        solve(nums, ind+1, n, ans, curr);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums, 0, nums.size(), ans, curr);
        return ans;
    }
};