// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

NOTE : The path has to end on a leaf node.

Example :

         1
        /
       2
       
max depth = 2.

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

int Solution::maxDepth(TreeNode* A) {
        int l,r,maxm;
        
        if(A == NULL)
            return 0;
        
        l = 1 + maxDepth(A->left);
        r = 1 + maxDepth(A->right);
        
        maxm = max(l,r);
        
        return maxm;
}
