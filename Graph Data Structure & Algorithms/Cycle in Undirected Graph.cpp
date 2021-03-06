// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an undirected graph having A nodes labelled from 1 to A with M edges given in a form of matrix B of size M x 2 where (B[i][0], B[i][1]) represents two nodes B[i][0] and
B[i][1] connected by an edge.

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

NOTE:

The cycle must contain atleast three nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


Problem Constraints
1 <= A, M <= 3105

1 <= B[i][0], B[i][1] <= A


Input Format
The first argument given is an integer A representing the number of nodes in the graph.
The second argument given is an matrix B of size M x 2 which represents the M edges such that there is a edge between node B[i][0] and node B[i][1].

Output Format
Return 1 if cycle is present else return 0.


Example Input
Input 1:

 A = 5
 B = [  [1. 2]
        [1, 3]
        [2, 3]
        [1, 4]
        [4, 5]
     ]
     
     
Input 2:

 A = 3
 B = [  [1. 2]
        [1, 3]
     ]


Example Output
Output 1:

 1
 
Output 2:

 0


Example Explanation*
Explanation 1:

 There is a cycle in the graph i.e 1 -> 2 -> 3 -> 1 so we will return 1
 
Explanation 2:

 No cycle present in the graph so we will return 0.

*/


Cpp code :

// using DFS traversal

	bool dfs(vector<int> adj[], vector<bool> &vis, int prnt, int node)
	{
	    vis[node] = true;
	    
	    for(auto ver : adj[node])
	    {
	        if(!vis[ver])
	      {
	          if(dfs(adj, vis, node, ver))
	          return true;
	      }
	        else if(ver != prnt)
	        return true;
	    }
	     
	    return false;
	}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A+1];
    
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    } 

    vector<bool> vis(A+1,false);

	   	for(int i=1;i<=A;i++)
	   	{
	   	    if(!vis[i])
	   	    {
    	   	    if(dfs(adj, vis, -1, i))
    	   	    return true;
	   	    }
	   	}
	   	
	return false;
}


// or using BFS traversal

	bool bfs(vector<int> adj[], vector<bool> &vis, int prnt, int node)
	{
	   queue<pair<int,int> > que;

	   que.push(make_pair(node, prnt));
	   
	   while(!que.empty())
	   {
		   pair<int,int> frnt = que.front();
		   vis[frnt.first] = true;
		   que.pop();

		   for(auto ver : adj[frnt.first])
		   {
			   if(!vis[ver])
			   {
				  que.push(make_pair(ver,frnt.first));
			   }
			   else if(frnt.second != ver)
			   return true;
		   }
	   }

	   return false;
	}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A+1];
    
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    } 

    vector<bool> vis(A+1,false);
    
	   	for(int i=1;i<=A;i++)
	   	{
	   	    if(!vis[i])
	   	    {
    	   	    if(bfs(adj, vis, -1, i))
    	   	    return true;
	   	    }
	   	}
	   	
	return false;
}
