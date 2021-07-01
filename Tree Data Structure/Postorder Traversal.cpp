// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

Using recursion is not allowed.

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
vector<int> Solution::postorderTraversal(TreeNode* A) {
        vector<int> res;
        
        TreeNode* temp = A;
        TreeNode* prev = NULL;

        if(A == NULL)
            return res;
        
        stack<TreeNode*> stck;
        
        while(!stck.empty()|| temp)
        {
          if(temp)
          {
            stck.push(temp);
            temp = temp->left;
          }
          else
          {
            TreeNode* node = stck.top();
                
                if (node -> right && prev != node -> right) 
                {
                    temp = node -> right;
                } 
                else 
                {
                    res.push_back(node -> val);
                    prev = node;
                    stck.pop();
                }
          }
        }
        
        return res;
}
