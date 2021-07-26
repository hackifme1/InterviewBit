// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a 2D integer matrix A of size N x N find a B x B submatrix where B<= N and B>= 1, such that sum of all the elements in submatrix is maximum.


Problem Constraints
1 <= N <= 103.

1 <= B <= N 

-10^2 <= A[i][j] <= 10^2.


Input Format
First arguement is an 2D integer matrix A.
Second argument is an integer B.

Output Format
Return a single integer denoting the maximum sum of submatrix of size B x B.


Example Input

Input 1:

 A = [
        [1, 1, 1, 1, 1]
        [2, 2, 2, 2, 2]
        [3, 8, 6, 7, 3]
        [4, 4, 4, 4, 4]
        [5, 5, 5, 5, 5]
     ]
 B = 3
 
 
Input 2:

 A = [
        [2, 2]
        [2, 2]
    ]
 B = 2


Example Output

Output 1:

 48
 
Output 2:

 8


Example Explanation
Explanation 1:

    Maximum sum 3 x 3 matrix is
    8 6 7
    4 4 4
    5 5 5
    Sum = 48
    
Explanation 2:

 Maximum sum 2 x 2 matrix is
  2 2
  2 2
  Sum = 8

*/


Cpp code :

int cal_sum(vector<vector<int> > &prfx, int st_r, int st_c, int ed_r, int ed_c)
{
    int sum = prfx[ed_r][ed_c] ;

    if(st_r > 0)
    sum -= ( prfx[st_r - 1][ed_c]);

    if(st_c > 0)
    sum -= (prfx[ed_r][st_c - 1]);

    if(st_r > 0 && st_c > 0)
    sum += (prfx[st_r - 1][st_c - 1]);

    return sum;
}

int Solution::solve(vector<vector<int> > &A, int B) {
        int n = A.size();
    
    vector<vector<int>> prfx(n,vector<int> (n,0));
    
    for(int i = 0;i<n;i++)
    prfx[0][i] = A[0][i];

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        prfx[i][j] = prfx[i-1][j] + A[i][j];
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        prfx[i][j] = prfx[i][j-1] + prfx[i][j];
    }

    int maxm = INT_MIN;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i+B-1 < n && j+B-1 < n)
            maxm = max(maxm, cal_sum(prfx, i, j, i+B-1, j+B-1));
        }
    }

    return maxm;
}
