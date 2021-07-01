// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary tree, return the inorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

Using recursion is not allowed.

*/


Cpp code :

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
        vector<int> res;
        TreeNode* temp = A;
        
        if(A == NULL)
            return res;
        
        stack<TreeNode*> stck;
        
        while(1)
        {
            while(temp)
            {
                stck.push(temp);
                temp = temp->left;
            }
            
            if(stck.empty())
                break;
            
            temp = stck.top();
            res.push_back(temp->val);
            stck.pop();
            temp = temp->right;
        }
        
        return res;
}
