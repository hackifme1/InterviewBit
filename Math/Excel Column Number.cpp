// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

Given a column title A as appears in an Excel sheet, return its corresponding column number.



Problem Constraints
1 <= |A| <= 100

Input Format
First and only argument is string A.

Output Format
Return an integer


Example Input
Input 1:

 1
 
Input 2:

 28


Example Output
Output 1:

 "A"
 
Output 2:

 "AB"


Example Explanation
Explanation 1:

 1 -> "A"
 
Explanation 2:

A  -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 


*/


Cpp code :

int Solution::titleToNumber(string A) {
    int n = A.size();
    int res = 0;
    
    for(int i=n-1;i>=0;i--)
    {
        int tmp = (A[i]-'A'+1);
        res = res + pow(26,n-i-1)*tmp;
    }
    
    return res;
}
