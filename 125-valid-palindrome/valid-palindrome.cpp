class Solution {
public:

    bool isalphanumeric(char ch){
            if((int)ch >= (int)'A' && (int)ch<='Z' ||
                (int)ch >= (int)'a' && (int)ch<='z' ||
                (int)ch >= (int)'0' && (int)ch<='9'){
                    return true;
                }
                return false;
     }
                    


    bool isPalindrome(string s) {
        int left=0,right=s.size()-1;
        while(left<right){
            while(!(isalphanumeric(s[left])) && left<right){
                left++;
            }
            while(!(isalphanumeric(s[right])) && left<right){
                right--;
            }
            if(tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
       
    }
};