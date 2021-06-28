// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary tree, determine if it is height-balanced.

Height-balanced binary tree  : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
         Difference = 2 > 1.

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

int height(TreeNode* node) 
{ 
    if (node == NULL) 
        return 0; 

    return 1 + max(height(node->left),height(node->right)); 
}

int Solution::isBalanced(TreeNode* A) {
    int lh; 
    int rh; 
  
    if (A == NULL) 
        return 1; 
  
    lh = height(A->left); 
    rh = height(A->right); 
  
    if (abs(lh - rh) <= 1 && isBalanced(A->left) && isBalanced(A->right)) 
        return 1; 
  
    return 0; 
}
