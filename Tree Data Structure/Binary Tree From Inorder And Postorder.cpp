// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given inorder and postorder traversal of a tree, construct the binary tree.

Note: You may assume that duplicates do not exist in the tree.

Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

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
unordered_map<int,int> ump;

TreeNode* buildTree_help(vector<int>& post, vector<int>& in, int st, int ed, int *strt)
{      
        if(st>ed)
            return NULL;

        TreeNode* node = new TreeNode(post[*strt]);
        (*strt)--;


        if(st == ed)
            return node;

        int indx = ump[node->val];
        
        node->right = buildTree_help(post,in,indx+1,ed,strt);
        node->left = buildTree_help(post,in,st,indx-1,strt);

        return node;      
    
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
        ump.clear();
        int strt;
        int n = A.size();
        
        strt = n - 1;
        
        for(int i=0;i<n;i++)
        {
            ump[A[i]] = i;
        }
        
        TreeNode* root = buildTree_help(B,A,0,n-1,&strt);
        
        return root;
}
