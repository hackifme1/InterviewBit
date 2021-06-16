// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an 1D integer array A containing N distinct integers.

Find the number of unique pairs of integers in the array whose XOR is equal to B.

NOTE:

Pair (a, b) and (b, a) is considered to be same and should be counted once.


Problem Constraints
1 <= N <= 105

1 <= A[i], B <= 107



Input Format
First argument is an 1D integer array A.

Second argument is an integer B.


Output Format
Return a single integer denoting the number of unique pairs of integers in the array A whose XOR is equal to B.



Example Input
Input 1:

 A = [5, 4, 10, 15, 7, 6]
 B = 5
 
Input 2:

 A = [3, 6, 8, 10, 15, 50]
 B = 5


Example Output
Output 1:

 1
 
Output 2:

 2


Example Explanation
Explanation 1:

 (10 ^ 15) = 5
 
Explanation 2:

 (3 ^ 6) = 5 and (10 ^ 15) = 5

*/


Cpp code :

int Solution::solve(vector<int> &A, int B) {
         map<int,int> mp;
        int cnt = 0;
        int n = A.size();
        for(int i=0;i<n;i++)
        {
           int temp = A[i]^B;
           if(mp.find(temp)!=mp.end())
           {
               cnt++;
           }
           mp.insert({A[i],1});
        }
        
        return cnt;
}
