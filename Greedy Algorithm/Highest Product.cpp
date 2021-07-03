// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array A, of N integers A.

Return the highest product possible by multiplying 3 numbers from the array.

NOTE:  Solution will fit in a 32-bit signed integer.



Input Format:

The first and the only argument is an integer array A.

Output Format:

Return the highest possible product.

Constraints:

1 <= N <= 5e5

Example:

Input 1:
A = [1, 2, 3, 4]

Output 1:
24

Explanation 1:
2 * 3 * 4 = 24

Input 2:
A = [0, -1, 3, 100, 70, 50]

Output 2:
350000

Explanation 2:
70 * 50 * 100 = 350000

*/


Cpp code :
// O(n) time complexity and O(1) space complexity

int Solution::maxp3(vector<int> &A) {
    int n = A.size();

    int maxm1 = INT_MIN, maxm2 = INT_MIN, maxm3 = INT_MIN;
 
    int minm1 = INT_MAX, minm2 = INT_MAX;
 
    for (int i = 0; i < n; i++)
    {
        if (A[i] > maxm1)
        {
            maxm3 = maxm2;
            maxm2 = maxm1;
            maxm1 = A[i];
        }
        else if (A[i] > maxm2)
        {
            maxm3 = maxm2;
            maxm2 = A[i];
        }
        else if (A[i] > maxm3)
            maxm3 = A[i];
 
        if (A[i] < minm1)
        {
            minm2 = minm1;
            minm1 = A[i];
        }
        else if(A[i] < minm2)
            minm2 = A[i];
    }
 
    return max(minm1 * minm2 * maxm1, maxm1 * maxm2 * maxm3);
}

// O(nlogn) time complexity and O(1) space complexity

int Solution::maxp3(vector<int> &A) {
        int n = A.size();
        
        sort(A.begin(),A.end());
        
        int maxm, maxm1;
        maxm = max(A[n-2]*A[n-1]*A[n-3],A[0]*A[1]*A[2]);
        maxm1 = max(A[0]*A[1]*A[n-1],A[0]*A[n-2]*A[n-1]);
        
        int m1 = max(maxm,maxm1);
        return m1;
}
