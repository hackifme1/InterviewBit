// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

NOTE : The path has to end on a leaf node.

Example :

         1
        /
       2
min depth = 2.

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
int Solution::minDepth(TreeNode* A) {
        if(A == NULL)
            return 0;
        
        int l = 1 + minDepth(A->left);
        int r = 1 + minDepth(A->right);
        
        if(A->left==NULL)
            l =  r;

        if(A->right==NULL)
            r = l;
        
        return(min(l,r));
}
