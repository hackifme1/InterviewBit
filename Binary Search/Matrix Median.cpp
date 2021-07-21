// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.


Input Format

The first and only argument given is the integer matrix A.

Output Format

Return the overall median of the matrix A.

Constraints

1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9
N*M is odd

For Example

Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
    
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

Input 2:
    A = [   [5, 17, 100]    ]
    
Output 2:
    17 

*/


Cpp code :

int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();

    int mdn_posn = (n*m + 1)/2;
    int l = 0, r = 0;

    for(int i=0;i<n;i++)
    {
        l = min(l, A[i][0]);
        r = max(r, A[i][m-1]);
    }

    while(l < r)
    {
        int mid = l + (r - l) / 2;
        int cnt = 0;
 
        for (int i = 0; i < n; i++)
            cnt += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
       
        if (cnt < mdn_posn)
            l = mid + 1;
        else
            r = mid;
    }

    return l;
}
