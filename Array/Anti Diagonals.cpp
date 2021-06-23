// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:
	
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]

*/


Cpp code :

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();

    int sz = 2*(n - 1) + 1;
    
    vector<vector<int>> res(sz);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            res[i+j].push_back(A[i][j]);
        }
    }
    
    return res;
}
