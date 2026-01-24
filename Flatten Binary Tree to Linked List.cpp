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

    void flatten(TreeNode* root) {
         if(!root)return;

         TreeNode* temp=root;
         flatten(root->left);
         flatten(root->right);
         if(root->left!=nullptr){
            TreeNode* temp=root->left;
            root->left=nullptr;
            TreeNode* temp1=root->right;
            root->right=temp;
            TreeNode* Curr=temp;
            while(Curr->right!=nullptr){
                Curr=Curr->right;
            }
    
            Curr->right=temp1;

         }
         
    }
};