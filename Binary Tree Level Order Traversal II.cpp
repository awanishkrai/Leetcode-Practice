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
vector<vector<int>>BFS(TreeNode* root,vector<vector<int>>result){
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
    result.push_back(qs);
    }
}
// vector<vector<int>>ans;
// for(int i=result.size()-1;i>=0;i--){
//     ans.push_back(result[i]);
// }
// return ans;
reverse(result.begin(),result.end());
return result;
}
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>result;
        return BFS(root,result);
    }
};