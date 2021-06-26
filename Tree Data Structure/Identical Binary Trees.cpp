// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 or True

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
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    stack<TreeNode*> stckA, stckB;
    if(A!=NULL)
    stckA.push(A);

    if(B!=NULL)
    stckB.push(B);

    while(!stckA.empty() && !stckB.empty())
    {
        TreeNode* topA = stckA.top();
        TreeNode* topB = stckB.top();
        stckA.pop();
        stckB.pop();
         
        if(topA->val != topB->val)
        return false;

        if(topA->right!=NULL)
        stckA.push(topA->right);

        if(topB->right!=NULL)
        stckB.push(topB->right);

        if(stckA.size()!=stckB.size())
        return false;

        if(topA->left!=NULL)
        stckA.push(topA->left);

        if(topB->left!=NULL)
        stckB.push(topB->left);

        if(stckA.size()!=stckB.size())
        return false;
    }

    return stckA.size()==stckB.size();
}
