// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Find the lowest common ancestor in an unordered binary tree given two values in the tree.

Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants.

Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

LCA = Lowest common ancestor

Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

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

 bool lca_help(TreeNode* root,int p, vector<TreeNode*> &v)
    {
        if(root==NULL)
            return false;
        
        v.push_back(root);
        
        if (root->val == p)
            return true;
        
        if((root->left&&lca_help(root->left,p,v)) || (root->right&&lca_help(root->right,p,v)))
            return true;
        
        v.pop_back();
        return false;
    }
    
int Solution::lca(TreeNode* A, int B, int C) {
        if(A==NULL)
            return NULL;
  
        int i;
        vector<TreeNode*> B_path, C_path;

        if((!lca_help(A,B,B_path))||(!lca_help(A,C,C_path)))
        return -1;
        
        for(i=0;i<B_path.size()&&i<C_path.size();i++)
        {
            if(B_path[i]->val!=C_path[i]->val)
                break;
        }
        
        return B_path[i-1]->val;
}
