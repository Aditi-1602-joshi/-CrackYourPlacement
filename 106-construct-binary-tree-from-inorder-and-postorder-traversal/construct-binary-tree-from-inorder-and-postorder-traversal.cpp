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

    TreeNode* treeConstruct(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, map<int,int>& mpp){
        if(instart>inend || poststart>postend){
            return nullptr;
        }
        int inroot = mpp[postorder[postend]];
        TreeNode* root = new TreeNode(postorder[postend]);
        int numsleft = inroot - instart;

        root->left = treeConstruct(inorder, instart, inroot-1, postorder, poststart, poststart+numsleft-1, mpp);
        root->right = treeConstruct(inorder, inroot+1, inend, postorder, poststart+numsleft, postend-1, mpp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())return nullptr;

        map<int,int> mpp;
        for(int i =0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        return treeConstruct( inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mpp);
    }
};