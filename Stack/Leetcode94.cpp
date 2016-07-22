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
        /*ջ���ջ�pCur����ʱѭ��*/
		while(pCur||!S.empty()){
            /*����������ѹ��ջ*/
			if(pCur->left){
                S.push(pCur);
                pCur=pCur->left;
            }
            /*������������val׷�ӽ�list*/
			else{
                list.push_back(pCur->val);
                pCur=pCur->right;/*�������������ж�*/
                /*������Ϊ�ջ��˵���һ�ڵ�*/
				while(!pCur&&!S.empty()){
                    pCur=S.top();
                    /*���˺�ֵ׷����list*/
					list.push_back(pCur->val);
                    S.pop();/*��ջ�����������ƶ�*/
                    pCur=pCur->right;
                }
            }
        }
        return list;
    }
};
