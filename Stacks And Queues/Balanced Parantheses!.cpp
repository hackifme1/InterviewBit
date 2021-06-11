// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string A consisting only of '(' and ')'.

You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.


Problem Constraints
1 <= |A| <= 105


Input Format
First argument is an string A.

Output Format
Return 1 if parantheses in string are balanced else return 0.

Example Input
Input 1:

 A = "(()())"
 
Input 2:

 A = "(()"

Example Output

Output 1:
 1
 
Output 2:

 0


Example Explanation
Explanation 1:

 Given string is balanced so we return 1
 
Explanation 2:

 Given string is not balanced so we return 0

*/

Cpp code :

int Solution::solve(string A) {
        stack<char> stck;
    int n =A.size();
    for(int i=0;i<n;i++)
    {
        if(A[i]=='(')
        stck.push('(');
        else
        {
            if(!stck.empty())
            stck.pop();
            else
            return 0;
        }
    }
    if(stck.empty()==1)
    return 1;
    else
    return 0;
}
