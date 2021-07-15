// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

Example :

Given binary tree

    3
   / \
  9  20
    /  \
   15   7
   
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is much greater than number of nodes on a level.

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
void levelOrder_help(TreeNode* A, int lvl, vector<pair<int,int> > &v)
{
    if(A == NULL)
    return;
    
    v.push_back(make_pair(A->val, lvl));
    levelOrder_help(A->left, lvl + 1, v);
    levelOrder_help(A->right, lvl + 1, v);   
}

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > res1;
    if(A == NULL)
    return res1;

    vector<pair<int,int> > v;

    levelOrder_help(A, 0, v);

    int n = v.size();
    int maxm = INT_MIN;

    for(int i=0;i<n;i++)
    {
        maxm = max(maxm, v[i].second);
    }

    vector<vector<int> > res(maxm+1);

    for(int i=0;i<n;i++)
    {
        res[v[i].second].push_back(v[i].first);
    }

    return res;
}
