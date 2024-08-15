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
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        stack<TreeNode*> st;
        // Push the root node
        // onto the stack.
        st.push(root);  
        
        // Continue the loop until
        // the stack is empty.
        while (!st.empty()) {  
            // Get the top node from the stack.
            TreeNode* cur = st.top(); 
            // Pop the top node.
            st.pop();  

            if (cur->right != NULL) {
                 // Push the right child
                 // onto the stack.
                st.push(cur->right); 
            }
            
            if (cur->left != NULL) {
                 // Push the left child
                 // onto the stack.
                st.push(cur->left); 
            }

            if (!st.empty()) {
                // Connect the right child to
                // the next node in the stack.
                cur->right = st.top();  
            }
            
            // Set the left child to NULL to
            // form a right-oriented linked list.
            cur->left = NULL;  
        }
    }
};