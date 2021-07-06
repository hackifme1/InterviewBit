// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.

Example : 

Given array S = {1 0 -1 0 -2 2}, and target = 0

A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
    
Also make sure that the solution set is lexicographically sorted.

Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])

*/


Cpp code :

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
        int n = A.size();
        sort(A.begin(),A.end());
        
        vector<vector<int>> res;   
        map<int,vector<pair<int,int>>> mp;
        set<vector<int>> st;
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                mp[A[i] + A[j]].push_back(make_pair(i,j));
            }
        }
        
         for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int s = A[i] + A[j];
                int srch = B - s;
                
                if(mp.find(srch) != mp.end())
                {
                    for(int k=0;k<mp[srch].size();k++)
                    {
                        if((mp[srch][k].first != i && mp[srch][k].second != j) && (mp[srch][k].first != j && mp[srch][k].second != i))
                        {
                            vector<int> t = {A[i],A[j],A[mp[srch][k].first],A[mp[srch][k].second]};
                            sort(t.begin(),t.end());
                            if(st.find(t) == st.end())
                            {
                                st.insert(t);
                                res.push_back(t);     
                            }                   
                        } 
                    }
                }
            }
        }
        
        sort(res.begin(),res.end());
        return res;
}
