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

    TreeNode* treeConstruct(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, map<int,int>& mpp){

        if(prestart>preend || instart>inend)return nullptr;

        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = mpp[root->val];
        int leftnums = inroot - instart;

        root->left = treeConstruct(preorder, prestart+1, prestart+leftnums, inorder, instart, inroot-1, mpp);
        root->right = treeConstruct(preorder, prestart+leftnums+1, preend, inorder, inroot+1, inend, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 1 && preorder[0] == -1){
            TreeNode* node = new TreeNode(preorder[0]);
            return node;
        }

        map<int,int> mpp;
        for(int i=0 ; i<preorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = treeConstruct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1, mpp);

        return root;
    }
};