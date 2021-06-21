// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an integer A you need to find the Ath fibonacci number modulo 109 + 7.

The first fibonacci number F1 = 1

The first fibonacci number F2 = 1

The nth fibonacci number Fn = Fn-1 + Fn-2 (n > 2)


Problem Constraints
1 <= A <= 109.


Input Format
First argument is an integer A.

Output Format
Return a single integer denoting Ath fibonacci number modulo 109 + 7.

Example Input
Input 1:

 A = 4
 
Input 2:

 A = 3


Example Output
Output 1:

 3
 
Output 2:

 2


Example Explanation
Explanation 1:

 F3 = F2 + F1 = 1 + 1 = 2
 F4 = F3 + F2 = 2 + 1 = 3
 
Explanation 2:

 F3 = F2 + F1 = 1 + 1 = 2


*/

Cpp code :

#define mod 1000000007

vector<vector<long long>> multiply(vector<vector<long long>> &A,vector<vector<long long>> &B) {
   
    vector<vector<long long>> C(A);
    for ( int i=0 ; i<2 ; i++ )
    {
        for ( int j=0 ; j<2 ; j++ )
        {
            long long sum = 0;
            for ( int k=0 ; k<2 ; k++ )
            sum = (sum + (A[i][k]*B[k][j])%mod)%mod;
            C[i][j] = sum;
        }
    }

    return C;
}

void mat_power ( vector<vector<long long>> &mat,int n ) {
    if ( n == 1 ) 
    return;
    mat_power(mat,n/2);
    mat = multiply(mat,mat);
    
    if ( n & 1 ) 
    { 
        vector<vector<long long>> m = {{1,1},{1,0}};
        mat = multiply(mat,m);
    }
    
    return;
}

int Solution::solve(int n) {

    vector<vector<long long>> mat = {{1,1},{1,0}};
    
    if ( n==0 ) 
    return 0;
    mat_power(mat,n-1);
    
    return mat[0][0];
}
