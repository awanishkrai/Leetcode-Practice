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
vector<int>BFS(TreeNode* root,vector<int>result){
queue<TreeNode*>q;
q.push(root);
while(!q.empty()){
    int size=q.size();
    vector<int>qs;
    while(size--){
        TreeNode* temp=q.front();
        q.pop();
        if(temp!=nullptr){
        qs.push_back(temp->val);
        
        q.push(temp->left);
        q.push(temp->right);
        }
        
    }if(qs.size()!=0){
        result.push_back(qs[qs.size()-1]);
    }

}
return result;
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        return BFS(root,result);
    }
};