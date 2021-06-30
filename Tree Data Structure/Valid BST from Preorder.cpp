// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

You are given a preorder traversal A, of a Binary Search Tree.

Find if it is a valid preorder traversal of a BST.


Problem Constraints
1 <= A[i] <= 10^6

1 <= |A| <= 10^5

Input Format
First and only argument is an integer array A denoting the pre-order traversal.

Output Format
Return an integer:

0 : Impossible preorder traversal of a BST
1 : Possible preorder traversal of a BST


Example Input
Input 1:

A = [7, 7, 10, 10, 9, 5, 2, 8]

Example Output
Output 1:

 1

*/


Cpp code :

int Solution::solve(vector<int> &A) {
    int n = A.size();
    stack<int> stck;

    int root = INT_MIN;
 
    for (int i=0; i<n; i++)
    {
        if (A[i] < root)
            return 0;
        
        while (!stck.empty() && (A[i] > stck.top()))
        {
            root = stck.top();
            stck.pop();
        }
 
        stck.push(A[i]);
    }

    return 1;
}
