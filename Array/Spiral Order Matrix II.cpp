// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.

Input Format:

The first and the only argument contains an integer, A.
Output Format:

Return a 2-d matrix of size A x A satisfying the spiral order.

Constraints:

1 <= A <= 1000

Examples:

Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]

*/


Cpp code :

vector<vector<int> > Solution::generateMatrix(int A) {
        int n = A;
        vector<vector<int>> res(n, vector<int>(n, 0));

        int i1 = 0, j = n-1, l = 0, r = n-1;
        int cnt = 1;
        int N = n*n;

        while(cnt <= N)
        {

            for(int i=l; i<=r; i++)
            {
                res[i1][i] = cnt++;
            }

            i1++;

            for(int i=i1; i<=j; i++)
            {
                 res[i][r] = cnt++;
            }

            r--;

            for(int i=r; i>=l; i--)
            {
                res[j][i] = cnt++;
            }

            j--;
                
            for(int i=j; i>=i1; i--)
            {
                res[i][l] = cnt++;
            }

            l++;
        }

        return res;
}
