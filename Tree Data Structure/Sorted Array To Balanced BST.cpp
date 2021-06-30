// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example :


Given A : [1, 2, 3]

A height balanced BST  : 

      2
    /   \
   1     3


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
TreeNode* tobst(const vector<int> &A, int l, int r)
{
        if(l>r)
            return NULL;
        
        int m = l + (r-l)/2;
        
        TreeNode* node = new TreeNode(A[m]);
        
        node->left = tobst(A,l,m-1);
        node->right = tobst(A,m+1,r);
        
        return node;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n = A.size();
        
    TreeNode* root = tobst(A,0,n-1);
        
    return root;
}
