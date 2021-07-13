// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an integer A, how many structurally unique BST’s (binary search trees) exist that can store values 1…A?

Input Format:

The first and the only argument of input contains the integer, A.

Output Format:

Return an integer, representing the answer asked in problem statement.


Constraints:

1 <= A <= 18


Example:

Input 1:
    A = 3

Output 1:
    5

Explanation 1:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/


Cpp code :

double fac(int n) 
{
	if(n <= 1)
	return 1;
		
    return n*fac(n-1);
}

int Solution::numTrees(int A) {
    double n1 = fac(A); 
    double n2 = fac(2*A);
		
    return (int) ceil( (n2)/(n1*n1*(A+1)) );
}
