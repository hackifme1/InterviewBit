// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

NOTE:

The cycle must contain atleast two nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


Problem Constraints
2 <= A <= 105

1 <= M <= min(200000,A(A-1))

1 <= B[i][0], B[i][1] <= A



Input Format
The first argument given is an integer A representing the number of nodes in the graph.
The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].

Output Format
Return 1 if cycle is present else return 0.



Example Input
Input 1:

 A = 5
 B = [  [1, 2] 
        [4, 1] 
        [2, 4] 
        [3, 4] 
        [5, 2] 
        [1, 3] ]
        
        
Input 2:

 A = 5
 B = [  [1, 2]
        [2, 3] 
        [3, 4] 
        [4, 5] ]


Example Output
Output 1:

 1
 
Output 2:

 0


Example Explanation*
Explanation 1:

 The given graph contain cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1
 
Explanation 2:

 The given graph doesn't contain any cycle.

*/


Cpp code :

	bool dfs(vector<int> adj[], vector<bool> &vis, vector<bool> &dfs_vis, int prnt, int node)
	{
	    vis[node] = true;
	    dfs_vis[node] = true;
	    
	    for(auto ver : adj[node])
	    {
	        if(!vis[ver])
	      {
	          if(dfs(adj, vis, dfs_vis, node, ver))
	          return true;
	      }
	        else if(dfs_vis[ver])
	        return true;
	    }
	     
	    dfs_vis[node] = false;
	    
	    return false;
	}

int Solution::solve(int A, vector<vector<int> > &B) {
    int n = B.size();
    vector<int> adj[A+1];
    for(int i=0;i<n;i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
    }
    
    vector<bool> vis(A+1, false);
	vector<bool> dfs_vis(A+1, false);
        
	   	for(int i=1;i<=A;i++)
	   	{
	   	    if(!vis[i])
	   	    {
    	   	    if(dfs(adj, vis, dfs_vis, -1, i))
    	   	    return 1;
	   	    }
	   	}
	   	
	   	return 0;
}
