// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 

Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]

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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
        vector<vector<int>> res;
       
        if(A == NULL)
            return res;

        int i = 0;        
        
        queue<TreeNode*> q;
        q.push(A);

        while(!q.empty())
        {
            vector<int> v;
            int j;
            int k = q.size();

            for(j=0;j<k;j++)
            {
                TreeNode* cur=q.front();
                v.push_back(cur->val);

                if(cur->left)
                q.push(cur->left);

                if(cur->right)
                q.push(cur->right);

                q.pop();
            }
          
            if(i&1)
            reverse(v.begin(),v.end());

            res.push_back(v);
            i++;           
        }
        
        return res;
}
