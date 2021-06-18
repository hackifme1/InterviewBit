// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string A and integer B, remove all consecutive same characters that have length exactly B.



Problem Constraints
1 <= |A| <= 100000

1 <= B <= |A|



Input Format
First Argument is string A.

Second argument is integer B.

Output Format
Return a string after doing the removals.

Example Input
Input 1:

A = "aabcd"
B = 2
Input 2:

A = "aabbccd"
B = 2


Example Output
Output 1:

 "bcd"
Output 2:

 "d"


Example Explanation
Explanation 1:

 "aa" had length 2.
 
Explanation 2:

 "aa", "bb" and "cc" had length of 2.

*/


Cpp code :

string Solution::solve(string A, int B) {
    int n = A.size();
    string res = "";
    
    int st[n];
    st[0] = 1;
    
    for(int i=1;i<n;i++)
    {
        if(A[i]==A[i-1])
        {
            st[i]=1+st[i-1];
        }
        else
        {
            st[i]=1;
        }
    }
    
    for(int i=n-1; i>=0;)
    {
        if(st[i]>=B)
        {
            i=i-st[i];
        }
        else
        {
            res+=A[i];
            i--;
        }
    }
    
    reverse(res.begin(),res.end());
    return res;
}
