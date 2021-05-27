// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
*/

Cpp code :

Complexity : O(nlogn)

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    sort(A.begin(),A.end());
    int j=1;
    for(int i=0;i<n;i++)
    {
        if(A[i]<=0)
        continue;
        else if(A[i]==j)
        {
            j++;
        }
        else
        return j;
    }
    return(j);
}
