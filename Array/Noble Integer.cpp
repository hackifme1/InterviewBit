// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

Given an integer array A, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p.


Input Format
First and only argument is an integer array A.

Output Format
Return 1 if any such integer p is found else return -1.

Example Input
Input 1:

 A = [3, 2, 1, 3]
 
Input 2:

 A = [1, 1, 3, 3]

Example Output
Output 1:
 1
 
Output 2:
-1


Example Explanation
Explanation 1:

 For integer 2, there are 2 greater elements in the array. So, return 1.
 
Explanation 2:

 There is no such integer exists.

*/

Cpp code :


int Solution::solve(vector<int> &A) {
    int n = A.size();
    sort(A.begin(),A.end());
    
    for(int i=0;i<n;i++)
    {
        if(i<n-1)
        {
            if(A[i]==A[i+1])
            continue;
        }
        if(A[i]==(n-i-1))
        return 1;
    }
    return -1;
}
