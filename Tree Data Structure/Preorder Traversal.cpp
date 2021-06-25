// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary tree, return the preorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

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
vector<int> Solution::preorderTraversal(TreeNode* A) {
    
    vector<int> res;
    stack<TreeNode*> stck;
    
    if(A == NULL){
        return res;
    }
    
    stck.push(A);
    
    while(!stck.empty())
    {
        TreeNode* temp = stck.top();
        stck.pop();
        res.push_back(temp -> val);
        
        if(temp->right!=NULL)
        stck.push(temp->right);
      
        if(temp->left!=NULL)
        stck.push(temp->left);
    }

    return res;
}
