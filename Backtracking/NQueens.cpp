// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.


Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,

There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/


Cpp code :

unordered_map<int,int> d,rd;

void solve(vector<vector<int>> &ans,int n,int row,vector<bool> c,vector<int> vec)
{
      if(row==n)
      {
          ans.push_back(vec);
          return;
      }
      
      for(int i=0;i<n;i++)
      {
          if(c[i]==false&&d[row+i]==0&&rd[row-i+n-1]==0)
          {
              vec.push_back(i+1);
              c[i]=true;
              d[row+i]=1;
              rd[row-i+n-1]=1;
              solve(ans,n,row+1,c,vec);
              vec.pop_back();
              c[i]=false;
              d[row+i]=0;
              rd[row-i+n-1]=0;
          }
      }
}


vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        int n = A;
        vector<vector<int>> res;
        vector<vector<string>> res1;       
        
        vector<bool> col(n,false);
      
        solve(res,n,0,col,{});
        
        string s="";
        
        for(int i=0;i<n;i++)
            s=s+'.';
        
        for(int i=0;i<res.size();i++)
        {
            vector<string> str;
            for(int j=0;j<n;j++)
            {
                str.push_back(s);
            }
            res1.push_back(str);
        }
        
         for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[i].size();j++)
            {
                res1[i][j][res[i][j]-1]='Q';
            }       
        }
        
        return res1;
    
}
