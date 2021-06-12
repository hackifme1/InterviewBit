// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.

Chech whether A has redundant braces or not.

Return 1 if A has redundant braces, else return 0.

Note: A will be always a valid expression.


Input Format

The only argument given is string A.

Output Format

Return 1 if string has redundant braces, else return 0.

For Example

Input 1:
    A = "((a + b))"

Output 1:
    1

Explanation 1:
    ((a + b)) has redundant braces so answer will be 1.

Input 2:
    A = "(a + (a + b))"

Output 2:
    0

Explanation 2:
    (a + (a + b)) doesn't have have any redundant braces so answer will be 0.

*/


Cpp code :

int Solution::braces(string A) {
    stack<char> stck;
    int n = A.size();
    bool flag = false;
    for(int i = 0;i<n;i++)
    {
        if(A[i]=='+'||A[i]=='-'||A[i]=='*'||A[i]=='/'||A[i]=='(')
        {
            stck.push(A[i]);
        }
        
        if(A[i]==')')
        {
            if(stck.top()=='(')
            flag=true;
            while(stck.top()=='+'||stck.top()=='-'||stck.top()=='*'||stck.top()=='/')
            {
                stck.pop();
            }
            stck.pop();
        }
        
    }

    if(flag==true)
    return 1;
    else
    return 0;
    
}
