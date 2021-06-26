// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3

The above binary tree is symmetric. 

But the following is not:

    1
   / \
  2   2
   \   \
   3    3
   
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

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
 bool tru(TreeNode* root1,TreeNode* root2)
{
        if(root1 == NULL && root2 == NULL)
            return true;
        
        if(root1 == NULL || root2 == NULL)
            return false;
        
        if(root1->val != root2->val)
            return false;
        
        return (tru(root1->left,root2->right) && tru(root1->right,root2->left));
        
}

int Solution::isSymmetric(TreeNode* A) {
     if(tru(A,A))
            return 1;
        else
            return 0;
}
