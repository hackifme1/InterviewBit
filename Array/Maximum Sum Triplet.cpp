// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array A containing N integers.

You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

If no such triplet exist return 0.


Problem Constraints
3 <= N <= 105.
1 <= A[i] <= 108.


Input Format
First argument is an integer array A.

Output Format
Return a single integer denoting the maximum sum of triplet as described in the question.


Example Input
Input 1:

 A = [2, 5, 3, 1, 4, 9]
 
Input 2:

 A = [1, 2, 3]


Example Output
Output 1:

 16
 
Output 2:

 6


Example Explanation
Explanation 1:

 All possible triplets are:-
    2 3 4 => sum = 9
    2 5 9 => sum = 16
    2 3 9 => sum = 14
    3 4 9 => sum = 16
    1 4 9 => sum = 14
  Maximum sum = 16
  
Explanation 2:

 All possible triplets are:-
    1 2 3 => sum = 6
 Maximum sum = 6

*/


Cpp code :

int Solution::solve(vector<int> &A) {
    int n = A.size();

int grtr[n+1];
set<int> s;

grtr[n] = 0;

for(int i=n-1;i>=0;i--)
{
    grtr[i] = max(grtr[i+1],A[i]);
}

s.insert(INT_MIN);

int res = 0;

for(int i=0;i<n-1;i++)
{
    if(A[i]<grtr[i+1])
    {
        auto lb = s.lower_bound(A[i]);
        *lb--;

        res = max(res,((*lb)+grtr[i+1]+A[i]));

        s.insert(A[i]);
    }
}

return res;

}
