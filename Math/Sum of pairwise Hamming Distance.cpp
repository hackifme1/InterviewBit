// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.

Given an array A of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array. Return the answer modulo 1000000007.

Problem Constraints
1 <= |A| <= 200000

1 <= A[i] <= 109

Input Format
First and only argument is array A.

Output Format
Return one integer, the answer to the problem.

Example Input
Input 1:

 A = [1]
 
Input 2:

 A = [2, 4, 6]


Example Output
Output 1:

 0
 
Output 2:

 8


Example Explanation
Explanation 1:

 No pairs are formed.
 
Explanation 2:

 We return, f(2, 2) + f(2, 4) + f(2, 6) + f(4, 2) + f(4, 4) + f(4, 6) + f(6, 2) + f(6, 4) + f(6, 6) = 8

*/


Cpp code :

int Solution::hammingDistance(const vector<int> &A) {
    long long int n = A.size();
    long long int mod = 1e9 + 7;
    long long int res = 0;
    
    for(long long int i=0;i<32;i++)
    {
        long long int cnt = 0;
        for(long long int j=0;j<n;j++)
        {
            if(A[j]&(1<<i))
            cnt=(cnt%mod+1)%mod;
        }
        res=(res%mod + ((cnt%mod) * ((n - cnt)%mod) * 2)%mod)%mod;
    }
    
    return res;
}
