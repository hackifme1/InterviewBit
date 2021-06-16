// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2

Output :

1
as 3 - 1 = 2

Return 0 / 1 for this problem.

*/


Cpp code :

int Solution::diffPossible(const vector<int> &A, int B) {
    map<int,int> mp;
    int n = A.size();
    
    if(n==0||n==1)
    return 0;
    
    for(int i=0;i<n;i++)
    {
        int diff1=B+A[i],diff2=A[i]-B;
        
        if(mp.find(diff1)!=mp.end() || mp.find(diff2)!=mp.end())
        {
            return 1;
        }
        mp.insert({A[i],1});
    }
    
    return 0;
}
