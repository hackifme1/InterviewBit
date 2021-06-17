// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]

 NOTE:
 
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.

 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
 
Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 

*/


Cpp code :

void prmute_hlp(vector<int> &A, vector<vector<int> > &res, int indx)    
{
    int n = A.size();
    
        if (indx >= n) 
        {
            res.push_back(A);
            return;
        }
        
        for (int i = indx; i < n; i++)
        {
            swap(A[indx], A[i]);
            prmute_hlp(A, res, indx + 1);
            swap(A[indx], A[i]);
        }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > res;
    
    prmute_hlp(A, res, 0);
        
    return res;
}
