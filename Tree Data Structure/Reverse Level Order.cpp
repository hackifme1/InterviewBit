// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary tree, return the reverse level order traversal of its nodes values. (i.e, from left to right and from last level to starting level).

Problem Constraints
1 <= number of nodes <= 5 * 105

1 <= node value <= 105


Input Format
First and only argument is a pointer to the root node of the Binary Tree, A.

Output Format
Return an integer array denoting the reverse level order traversal from left to right.


Example Input
Input 1:

    3
   / \
  9  20
    /  \
   15   7
   
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [15, 7, 9, 20, 3] 
 
Output 2:

 [3, 6, 2, 1]


Example Explanation
Explanation 1:

 Nodes as level 3 : [15, 7]
 Nodes at level 2: [9, 20]
 Nodes at level 1: [3]
 Reverse level order traversal will be: [15, 7, 9, 20, 3]
 
Explanation 2:

 Nodes as level 3 : [3]
 Nodes at level 2: [6, 2]
 Nodes at level 1: [1]
 Reverse level order traversal will be: [3, 6, 2, 1]

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
 
vector<int> Solution::solve(TreeNode* A) {
    vector<int> res;
  
    if(A==NULL)
    return res;
    
    queue<TreeNode* > q;
    
    q.push(A);
    
    while(!q.empty())
    {
    
        int count=q.size();
        
        for(int i=0;i<count;i++)
        {
        
            TreeNode* curr = q.front();
            
            q.pop();
            
            res.push_back(curr->val);
            
            if(curr->right!=NULL)
            q.push(curr->right);
            
            if(curr->left!=NULL)
            q.push(curr->left);
        }
    }
  
    reverse(res.begin(),res.end());
    
    return res;
    
}
