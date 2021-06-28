// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.

NOTE : You may assume 1 <= k <= Total number of nodes in BST

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
void inorder(TreeNode* root,vector<int> &res)
{
    if(root==NULL)
      return;
        
    inorder(root->left,res);
    res.push_back(root->val);
    inorder(root->right,res);
}
    
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> res;
    inorder(A,res);     
        
    return res[B-1];
}
