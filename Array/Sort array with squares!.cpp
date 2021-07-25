// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a sorted array A containing N integers both positive and negative.

You need to create another array containing the squares of all the elements in A and return it in non-decreasing order.

Try to this in O(N) time.


Problem Constraints
1 <= N <= 105.

-10^3 <= A[i] <= 10^3


Input Format
First and only argument is an integer array A.

Output Format
Return a integer array as described in the problem above.


Example Input
Input 1:

 A = [-6, -3, -1, 2, 4, 5]
 
Input 2:

 A = [-5, -4, -2, 0, 1]


Example Output
Output 1:

 [1, 4, 9, 16, 25, 36]
 
Output 2:

 [0, 1, 4, 16, 25]

*/


Cpp code :

vector<int> Solution::solve(vector<int> &A) {
        int n = A.size();
        vector<int> v;
        int l = 0, r = n-1;
        
        while(l <= r)
        {
            if(abs(A[l]) > abs(A[r]))
            {
                v.push_back(A[l]*A[l]);
                l++;
            }
            else
            {
                v.push_back(A[r]*A[r]);
                r--;
            }
        }
        
        reverse(v.begin(),v.end());
        
        return v;
}
