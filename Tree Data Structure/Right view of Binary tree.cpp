// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary tree A of integers. Return an array of integers representing the right view of the Binary tree.

Right view of a Binary Tree: is a set of nodes visible when the tree is visited from Right side.


Problem Constraints
1 <= Number of nodes in binary tree <= 105

0 <= node values <= 109 


Input Format
First and only argument is an pointer to the root of binary tree A.

Output Format
Return an integer array denoting the right view of the binary tree A.


Example Input
Input 1:

        1
      /   \
     2    3
    / \  / \
   4   5 6  7
  /
 8 
 
Input 2:

    1
   /  \
  2    3
   \
    4
     \
      5


Example Output
Output 1:

 [1, 3, 7, 8]
 
Output 2:

 [1, 3, 4, 5]

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
    void solve_help(TreeNode* A, int lvl, vector<pair<int,int> > &v)
    {
        if(A == NULL)
        return;

        v.push_back(make_pair(A->val, lvl));
        solve_help(A->left, lvl + 1, v);
        solve_help(A->right, lvl + 1, v);   
    }
    
vector<int> Solution::solve(TreeNode* A) {
        if(A == NULL)
        return {};

        vector<pair<int,int> > v;

        solve_help(A, 0, v);

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
        
        vector<int> ans;
        
        for(int i=0;i<res.size();i++)
        {
            ans.push_back(res[i][res[i].size()-1]);
        }
        
        return ans;
}
