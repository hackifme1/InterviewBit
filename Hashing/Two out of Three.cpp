// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given are Three arrays A, B and C.

Return the sorted list of numbers that are present in atleast 2 out of the 3 arrays.

Problem Constraints
1 <= |A|, |B|, |C| <= 100000

1 <= A[i], B[i], C[i] <= 100000

A, B, C may or may not have pairwise distinct elements.


Input Format
First argument is the array A.

First argument is the array B.

First argument is the array C.

Output Format
Return a sorted array of numbers.


Example Input
Input 1:

A = [1, 1, 2]
B = [2, 3]
C = [3]

Input 2:

A = [1, 2]
B = [1, 3]
C = [2, 3]


Example Output
Output 1:

[2, 3]

Output 2:

[1, 2, 3]


Example Explanation
Explanation 1:

1 is only present in A. 2 is present in A and B. 3 is present in B and C.

Explanation 2:

All numbers are present in atleast 2 out of 3 lists.


*/


Cpp code :

vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    map<int,int> mp1;
    map<int,int> mp2;
    map<int,int> mp3;
    
     vector<int> v;
    
    for(int i=0;i<A.size();i++)
    {
        mp1[A[i]]++;
    }
    
    for(int i=0;i<B.size();i++)
    {
       mp2[B[i]]++;
    }
    
    for(int i=0;i<C.size();i++)
    {
        mp3[C[i]]++;
    }
    
    for(int i=0;i<100003;i++)
    {
        if((mp1[i]>0 && mp2[i]>0 ) || (mp1[i]>0 && mp3[i]>0) || mp2[i]>0 && mp3[i]>0)
        {
            v.push_back(i);
        }
    }
    
    sort(v.begin(),v.end());
    
    return v;
}
