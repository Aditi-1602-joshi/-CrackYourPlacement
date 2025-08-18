class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //<value,freq>
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        for(auto& it: mpp){
            bucket[it.second].push_back(it.first);
        }
        vector<int> res;
        for(int i=bucket.size()-1; i>=0 && res.size()<k; i--){
            for(auto& it:bucket[i]){
                res.push_back(it);
                if(res.size()==k)return res;
            }
        }
        return res;
    }
};