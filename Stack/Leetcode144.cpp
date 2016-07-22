/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>list;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return list;
        stack<struct TreeNode *> S;
        struct TreeNode * pCur=root;
        while(pCur||!S.empty()){
            list.push_back(pCur->val);
            S.push(pCur);
            pCur=pCur->left;
            while(!pCur&&!S.empty()){
                pCur=S.top();
                S.pop();
                pCur=pCur->right;
            }
        }
        return list;
    }
};
