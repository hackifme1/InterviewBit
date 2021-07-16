// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
  
The root-to-leaf path 1->2 represents the number 12.

The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

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
void sumNumbers_help(TreeNode* A, int crnt, int &res)
{ 
    if(A == NULL)
    return;
    
    crnt = crnt*10 + A->val;
    crnt %= 1003;

    if(A->left == NULL && A->right == NULL)
    {
        res += crnt;
        res %= 1003;
        crnt = 0;
        return;
    }
    
    sumNumbers_help(A->left, crnt, res);
    sumNumbers_help(A->right, crnt, res);
}
 
int Solution::sumNumbers(TreeNode* A)
{ 
    if(A==NULL)    
    return 0;
    
    int crnt=0, res=0;    

    sumNumbers_help(A, 0, res);
    
    return res; 
}
