/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void smallest(TreeNode* root, int k, int& ksmallest, int& counter){
        if(root == nullptr || counter>k)return;

        smallest(root->left, k, ksmallest, counter);

        counter++;
        if(counter == k){
            ksmallest = root->val;
            return;
        }

        smallest(root->right, k, ksmallest, counter);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ksmallest;
        int counter = 0;
        smallest(root, k, ksmallest, counter);
        return ksmallest;
    }
};