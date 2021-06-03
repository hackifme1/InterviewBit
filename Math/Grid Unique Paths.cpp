// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid.

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)

*/

// Can be done by using formula :(A+B-2)!/(A-1)!(B-1)!  or
// by Dynamic Programming (Me implementing this)

Cpp code :

int Solution::uniquePaths(int A, int B) {
    
     int dp[300][300];
        
        for(int i=0;i<A;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=0;i<B;i++)
        {
            dp[0][i]=1;
        }
        
        if(B>=2){
        for(int i=1;i<A;i++)
        {
            for(int j=1;j<B;j++)
            {
               if(((i-1)>=0)&&((j-1)>=0))
                   dp[i][j]=dp[i-1][j]+dp[i][j-1];
            } 
        }
        }
        return dp[A-1][B-1];

}
