// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a positive integer A, return its corresponding column title as appear in an Excel sheet.


Problem Constraints
1 <= A <= 1000000000

Input Format
First and only argument is integer A.

Output Format
Return a string, the answer to the problem.

Example Input
Input 1:

 A = 1
 
Input 2:

 A = 28

Example Output
Output 1:

 "A"
 
Output 2:

 "AB"


Example Explanation
Explanation 1:

 1 -> A
 
Explanation 2:

1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB 

*/


Cpp code :

string Solution::convertToTitle(int A) {
    char str[10001]; 
    int i = 0; 
   int n = A;
    while (n > 0) 
    {
        int rem = n % 26;
 
        if (rem == 0) 
        {
            str[i++] = 'Z';
            n = (n / 26) - 1;
        }
        else 
        {
            str[i++] = (rem - 1) + 'A';
            n = n / 26;
        }
    }
    str[i] = '\0';
 
    reverse(str, str + strlen(str));
    return str;
}
