// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.

The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]

A partially filled sudoku which is valid.

Note:

A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/


Cpp code :

int Solution::isValidSudoku(const vector<string> &A) {

    for(int  x=0;x<9;x++)
    {
        for(int y=0;y<9;y++)
        {
            int m = x, n = y;

            if(A[x][y] == '.')
            continue;
            
            for(int i=0;i<9;i++)
            {
                if(A[i][n] == A[x][y] && i != x)
                {
                    return 0;
                }
            }
            for(int i=0;i<9;i++)
            {
                if(A[m][i] == A[x][y] && i != y)
                {
                    return 0;
                }
            }
            
            for(int i=3*(m/3);i<=3*(m/3)+2;i++)
            {
                for(int j=3*(n/3);j<=3*(n/3)+2;j++)
                {
                    if(A[i][j] == A[x][y] && (i != x && j != y))
                    {
                        return 0;
                    }
                }
            }
        }
    }
   
    return 1;
}
