// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a set of digits (A) in sorted order, find how many numbers of length B are possible whose value is less than number C.

 NOTE: All numbers can only have digits from the given set. 
 
 ** Please note that a digit can be repeated multiple times while forming number by you. And there is no repetition of digits in the given array A.**
 
Examples:

	Input:
	  0 1 5  
	  1  
	  2  
	Output:  
	  2 (0 and 1 are possible)  

	Input:
	  0 1 2 5  
	  2  
	  21  
	Output:
	  5 (10, 11, 12, 15, 20 are possible)
    
Constraints:

    1 <= B <= 9, 0 <= C <= 1e9 & 0 <= A[i] <= 9

*/

Cpp code :

vector<int> tovector(int N)
{
    vector<int> digit;
 
    while (N != 0) {
        digit.push_back(N % 10);
        N = N / 10;
    }
 
    if (digit.size() == 0)
        digit.push_back(0);
        
    reverse(digit.begin(), digit.end());
 
    return digit;
}

int Solution::solve(vector<int> &A, int B, int C) {
    
    int n = C;
	int d = A.size();
	map<int,int> mp;
	vector<int> v;
	v = tovector(C);
    int sz = v.size();
	if(B>sz || d==0)
		return 0;
	int f[11] = {0};
	if(A[0]==0)
	f[0] = 1;
	
	
	
	for(int i=0;i<d;i++)
	{
		mp[A[i]] = 1;
	}
	
	for(int i=0;i<=9;i++)
	{
		if(mp[i])
		f[i] = f[i-1] + 1;
		else
		f[i] = f[i-1];
	}
    
		
		int s = 0;
		
	    if(B < sz)
		{
	        if (A[0] == 0 && B != 1)
	            return (d - 1) * pow(d, B - 1);
	        else
	            return pow(d, B);
    	}
		else
		{
			if(B == 1)
				{
					if(mp[C])
					return f[C]-1;
					else 
					return f[C];
				}
			else if(A[0]==0)
			{
				for(int i=0;i<sz;i++)
				{
						if(i==sz-1){
							if(mp[v[i]])
							s=s+(f[v[i]]-1);
							else
							s=s+(f[v[i]]);
						}
						else
						{
					    	if(mp[v[i]])
					    	{
					    		if(i==0)
					    			s=s+(f[v[i]]-2)*pow(d,sz-i-1);
					    		else
					    		    s=s+(f[v[i]]-1)*pow(d,sz-i-1);
					    	}
							else
							{
							    if(i==0)
								s=s+(f[v[i]]-1)*pow(d,sz-i-1);
								else
								s=s+(f[v[i]])*pow(d,sz-i-1);
								break;
							}
						}
				}
			}
			else
			{
					for(int i=0;i<sz;i++)
				{
						if(i==sz-1){
					    	if(mp[v[i]])
								s=s+(f[v[i]]-1);
							else{
							s=s+(f[v[i]]);
							break;
							}
						}
						else
						{
							if(mp[v[i]])
							s=s+(f[v[i]]-1)*pow(d,sz-i-1);
							else{
							s=s+(f[v[i]])*pow(d,sz-i-1);
							break;
							}
						}
						
				}
			}
		}
		
    return s;
}
