// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

*/


Cpp code :

void bck(vector<int> &A, vector<vector<int>> &ans,int indx, vector<int> &subtrk)
{
    ans.push_back(subtrk);
    
    for(int i=indx;i<A.size();i++)
    {
        subtrk.push_back(A[i]);
        bck(A,ans,i+1,subtrk);
        subtrk.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> subtrk;
    
    sort(A.begin(),A.end());
    
    bck(A,ans,0,subtrk);
    return ans;
}
