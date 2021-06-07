// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an integar A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY


Input Format

The first and only argument given is the integer A.
Output Format

Return floor(sqrt(A))


Constraints
1 <= A <= 10^9

For Example

Input 1:
    A = 11
Output 1:
    3

Input 2:
    A = 9
Output 2:
    3

*/


Cpp code :

int Solution::sqrt(int A) {
     long long int l=0, r = 100001;
        
        while(l<=r)
        {
            long long int m = l + (r-l)/2;
            long long int t = m*m;
            if(t == A)
                return m;
            
            if(t<A)
                l = m + 1;
            else
                r = m - 1;
        }
        
        if((l*l)>A)
            return l-1;
            
        return l;
}
