// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
  
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)

If no solution is possible, return an empty list.

*/


Cpp code :

vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();

    int i = -1, j = -1;

    vector<vector <int>> res;
    unordered_map<int,pair<int,int>> mp;
    
    for(int i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(mp.find(A[i] + A[j]) == mp.end())
            {
                mp[A[i] + A[j]] = {i,j};
            }
            else
            {
                int x = mp[A[i] + A[j]].first;
                int y = mp[A[i] + A[j]].second;

                if(x != i && x != j && y != i && y != j)
                {
                    vector<int> t;
                    t.push_back(x);
                    t.push_back(y);
                    t.push_back(i);
                    t.push_back(j);
                    res.push_back(t);
                }
            }
        }        
    }

    sort(res.begin(),res.end());
    
    return res[0];
}
