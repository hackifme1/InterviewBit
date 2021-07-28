// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a tree with N nodes labelled from 1 to N.

Each node is either good or bad denoted by binary array A of size N where if A[i] is 1 then ithnode is good else if A[i] is 
0 then ith node is bad.

Also the given tree is rooted at node 1 and you need to tell the number of root to leaf paths in the tree that contain not more than C good nodes.

NOTE:

Each edge in the tree is bi-directional.


Problem Constraints
2 <= N <= 105

A[i] = 0 or A[i] = 1

0 <= C <= N


Input Format
First argument is an binary integer array A of size N.
Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.
Third argument is an integer C.

Output Format
Return an integer denoting the number of root to leaf paths in the tree that contain not more than C good nodes.


Example Input
Input 1:

 A = [0, 1, 0, 1, 1, 1]
 B = [  [1, 2]
        [1, 5]
        [1, 6]
        [2, 3]
        [2, 4]
     ]
 C = 1


Example Output
Output 1:

 3


Example Explanation
Explanation 1:

 Path (1 - 2 - 3) and (1 - 5) and (1 - 6) are the paths which contain atmost C nodes.

*/


Cpp code :

 int res ;
 int c;

 void dfs(vector<int> adj[], vector<bool> &vis, vector<int> &A, int node,int cnt)
 {
     vis[node] = true;

     if(A[node-1] == 1)
     {
         cnt++;
     }
     
     for(auto ver : adj[node])
     {
         if(!vis[ver])
         {
             dfs(adj, vis, A, ver,cnt);             
         }         
     }
    
    if(adj[node].size() ==1 && cnt <= c)
    res++;
 }

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n = A.size();
    res = 0;
    vector<int> adj[n+1];
    c = C;

    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
  
    vector<bool> vis(n+1, false);
    map<int,int> mp;
    
    dfs(adj, vis, A, 1, 0);

    return res;
}
