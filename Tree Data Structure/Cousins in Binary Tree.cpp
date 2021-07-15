// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a Binary Tree A consisting of N nodes.

You need to find all the cousins of node B.

NOTE:

Siblings should not be considered as cousins.
Try to do it in single traversal.
You can assume that Node B is there in the tree A.
Order doesn't matter in the output.


Problem Constraints
 1 <= N <= 105 

 1 <= B <= N


Input Format
First Argument represents the root of binary tree A.

Second Argument is an integer B denoting the node number.

Output Format
Return an integer array denoting the cousins of node B.

NOTE: Order doesn't matter.


Example Input
Input 1:

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7 


B = 5

Input 2:

 A = 
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


B = 1



Example Output
Output 1:

 [6, 7]
 
Output 2:

 []


Example Explanation
Explanation 1:

 Cousins of Node 5 are Node 6 and 7 so we will return [6, 7]
 Remember Node 4 is sibling of Node 5 and do not need to return this.
 
Explanation 2:

 Since Node 1 is the root so it doesn't have any cousin so we will return an empty array.

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
void solve_help(TreeNode* root, int prnt, int lvl, map<int,pair<int,int>> &mp)
{
    if(root == NULL)
        return;
       
    mp[root->val] = make_pair(lvl, prnt);
        
    solve_help(root->left, root->val, lvl + 1, mp);
    solve_help(root->right, root->val, lvl + 1, mp);
}

vector<int> Solution::solve(TreeNode* A, int b) {
    vector<int> res;
    map<int,pair<int,int>> mp;
    if(A == NULL)
    return res;

    solve_help(A,-1,0,mp);

    int req_lvl = mp[b].first;
    int prnt = mp[b].second;

    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second.first == req_lvl)
        {
            if(it->second.second == prnt)
            continue;
            res.push_back(it->first);
        }       
    }
    
    return res;
}
