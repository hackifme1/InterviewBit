// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists.


Problem Constraints
 1 <= N <= 105 

 1 <= Data Values of Each Node <= N

 1 <= B <= N


Input Format
First Argument represents pointer to the root of binary tree A.

Second Argument is an integer B denoting the node number.


Output Format
Return an one-dimensional array denoting the path from Root to the node B in order.


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

 [1, 2, 5]
 
Output 2:

 [1]


Example Explanation
Explanation 1:

 We need to find the path from root node to node with data value 5.
 So the path is 1 -> 2 -> 5 so we will return [1, 2, 5]

Explanation 2:

 We need to find the path from root node to node with data value 1.
 As node with data value 1 is the root so there is only one node in the path.
 So we will return [1]

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
 bool path(TreeNode* root, vector<int> &res, int B)
 {
     if(root == NULL)
     return false;

     res.push_back(root->val);

     if(root->val == B)
     return true;

     if(path(root->left,res,B)||path(root->right,res,B))
     return true;
     
     res.pop_back();
     return false;
 }

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;

    if(A == NULL)
    return res;

    bool ans = path(A,res,B);
    
    return res;
}
