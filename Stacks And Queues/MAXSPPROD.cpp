// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (i>j). If multiple A[j]'s are present in multiple positions, the LeftSpecialValue is
the maximum value of j.
RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (j>i). If multiple A[j]'s are present in multiple positions, the RightSpecialValue is 
the minimum value of j.
Write a program to find the maximum special product of any integer in the array.

NOTE:  As the answer can be large, output your answer modulo 109 + 7.


Problem Constraints
1 <= N <= 105
 
1 <= A[i] <= 109


Input Format
First and only argument is an integer array A.

Output Format
Return an integer denoting the maximum special product of any integer.



Example Input
Input 1:

 A = [1, 4, 3, 4]
 
Input 2:

 A = [10, 7, 100]


Example Output
Output 1:

 3
 
Output 2:

 0


Example Explanation
Explanation 1:

 For A[2] = 3, LeftSpecialValue is 1 and RightSpecialValue is 3.
 So, the ans is 1*3 = 3.
 
Explanation 2:

 There is not any integer having maximum special product > 0. So, the ans is 0.

*/


Cpp code :

void lft_grtr(vector<int> A, long long int n,vector<long long int> &lft)
{
    stack<long long int> stck;
 
    for (long long int i = n - 1; i >= 0; i--) 
    { 
        while (!stck.empty() && A[i] > A[stck.top()]) 
        {
            long long int r = stck.top();
            stck.pop();
 
            lft[r] = i ;
        }
 
        stck.push(i);
    }
}
 
void rit_grtr(vector<int> A, long long int n, vector<long long int> &rit)
{
    stack<long long int> stck;

    for (long long int i = 0; i < n; ++i) 
    { 
        while (!stck.empty() && A[i] > A[stck.top()]) 
        {
            long long int r = stck.top();
            stck.pop();
 
            rit[r] = i;
        }
 
        stck.push(i);
    }
}

int Solution::maxSpecialProduct(vector<int> &A) {
    long long int n = A.size();
    long long int mod = 1e9 + 7;
    
    vector<long long int> lft(n+1, 0);
    vector<long long int> rit(n+1, 0);

   
    lft_grtr(A,n,lft);
    rit_grtr(A,n,rit);

    long long int maxm = INT_MIN;
    
    for(long long int i=0;i<n;i++)
    {
        maxm = max(maxm,(lft[i]*rit[i]));
    }

    return maxm%mod;
}
