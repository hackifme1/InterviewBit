// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that 
A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.


Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0

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
    void findTarget_help(TreeNode* A, vector<int> &v)
    {
        if(A == NULL)
            return;
        
        v.push_back(A->val);
        findTarget_help(A->left,v);
        findTarget_help(A->right,v);
    }

int Solution::t2Sum(TreeNode* A, int B) {
        if(A == NULL)
        return 0;
        vector<int> v;
        map<int,int> mp;
        findTarget_help(A,v);
        
         for(int i=0;i<v.size();i++)
        {
            mp[v[i]]=i;
        }
        
        for(int i=0;i<v.size();i++)
        {
              int tgt = B - v[i];
              if(mp[tgt] && mp[tgt]!=i)
              {
                  return 1;
              }
        }
        
        return 0;
}
