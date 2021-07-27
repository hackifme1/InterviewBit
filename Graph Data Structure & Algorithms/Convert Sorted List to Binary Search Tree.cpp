// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example :


Given A : 1 -> 2 -> 3
A height balanced BST  :

      2
    /   \
   1     3

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    TreeNode* inorder(vector<int> &v, int st, int ed)
    {
        if(st > ed)
            return NULL;
        
        int mid = (st + ed) / 2;
        
        TreeNode* root = new TreeNode(v[mid]);
        
        root->left = inorder(v, st, mid - 1);
        root->right = inorder(v, mid + 1, ed);
        
        return root;
    }

TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        if(A == NULL)
        return NULL;
        
        vector<int> v;
        ListNode* temp = A;
        
        while(temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        int n = v.size();
        
        TreeNode* root = inorder(v,0, n-1);
        
        return root;
}
