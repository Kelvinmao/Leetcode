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
    vector<int> list;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return list;
        stack<struct TreeNode *> S;
        struct TreeNode * pCur=root;
        /*栈不空或pCur不空时循环*/
		while(pCur||!S.empty()){
            /*有左子树，压入栈*/
			if(pCur->left){
                S.push(pCur);
                pCur=pCur->left;
            }
            /*无左子树，将val追加进list*/
			else{
                list.push_back(pCur->val);
                pCur=pCur->right;/*进右子树继续判断*/
                /*右子树为空回退到上一节点*/
				while(!pCur&&!S.empty()){
                    pCur=S.top();
                    /*回退后将值追加入list*/
					list.push_back(pCur->val);
                    S.pop();/*出栈，向右子树移动*/
                    pCur=pCur->right;
                }
            }
        }
        return list;
    }
};
