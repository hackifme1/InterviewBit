// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.

Your algorithm’s runtime complexity must be in the order of O(log n).

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].


Input Format

The first argument given is the integer array A.
The second argument given is the integer B.

Output Format

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].

Constraints

1 <= N <= 10^6
1 <= A[i], B <= 10^9
For Example

Input 1:
    A = [5, 7, 7, 8, 8, 10]
    B = 8
Output 1:
    [3, 4]
    
Explanation 1:
    First occurence of 8 in A is at index 3
    Second occurence of 8 in A is at index 4
    ans = [3, 4]

Input 2:
    A = [5, 17, 100, 111]
    B = 3
Output 2:
    [-1, -1]

*/


Cpp code :

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = A.size();
    vector<int> v;
    
  // lower bound
    int l = 0, r = n;
    
    while(l<r)
    {
        int m = l + (r-l)/2;
        
        if(A[m]>=B)
        r = m;
        else
        l = m + 1;
    }
    
    if(l < n && A[l] < B) {
       l++;
    }

    if(l==n||A[l]!=B)
    {
        v.push_back(-1);
        v.push_back(-1);
        return v;
    }
    v.push_back(l);
    
  // upper bound
    l = 0; r = n;
    
    while(l<r)
    {
        int m = l + (r-l)/2;
        
        if(A[m]<=B)
        l = m + 1;
        else
        r = m;
    }
    
    if(l < n && A[l] <= B) {
       l++;
    }

    v.push_back(l-1);
    return v;
}
