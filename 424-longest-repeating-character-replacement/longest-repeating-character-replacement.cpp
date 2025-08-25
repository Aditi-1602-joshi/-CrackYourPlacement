class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;//<charcter,count>
        int res=0;
        int left=0, right=0;
        int maxfreq=0;
        int n=s.size();
        for(right=0;right<n;right++){
            mpp[s[right]]++;
            maxfreq=max(maxfreq,mpp[s[right]]);
            int len= right-left+1;
            //if valid
            if(len- maxfreq <= k){
                res= max(res,len);
            }
            //if not vallid
            else{
                mpp[s[left]]--;
                left++;
            }
        }
        return res;
    }
};