// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given preorder and inorder traversal of a tree, construct the binary tree.

Note: You may assume that duplicates do not exist in the tree.

Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3

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
int strt = 0;
unordered_map<int,int> ump;

TreeNode* buildTree_help(vector<int>& pre, vector<int>& in, int st, int ed)
{
    if(st>ed)
        return NULL;
    
    
    TreeNode* node = new TreeNode(pre[strt]);
    strt++;
    
    
    if(st == ed)
        return node;
    
    int indx = ump[node->val];
   
    node->left = buildTree_help(pre,in,st,indx-1);
    node->right = buildTree_help(pre,in,indx+1,ed);
    
    return node;      
    
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    strt = 0;
    ump.clear();
       int n = B.size();
        for(int i=0;i<n;i++)
            ump[B[i]] = i;
        
      TreeNode* root = buildTree_help(A,B,0,n-1);      
        
        return root;
}
