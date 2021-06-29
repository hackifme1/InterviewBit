// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string A of parantheses  ‘(‘ or ‘)’.

The task is to find minimum number of parentheses ‘(‘ or ‘)’ (at any positions) we must add to make the resulting parentheses string valid.

An string is valid if:

Open brackets must be closed by the corresponding closing bracket.
Open brackets must be closed in the correct order.


Problem Constraints
1 <= |A| <= 105

A[i] = '(' or A[i] = ')'


Input Format
First and only argument is an string A.

Output Format
Return a single integer denoting the minimumnumber of parentheses ‘(‘ or ‘)’ (at any positions) we must add in A to make the resulting parentheses string valid.


Example Input
Input 1:

 A = "())"
 
Input 2:

 A = "((("


Example Output
Output 1:

 1
 
Output 2:

 3


Example Explanation
Explanation 1:

 One '(' is required at beginning.
 
Explanation 2:

 Three ')' is required at end.

*/


Cpp code :

int Solution::solve(string A) {
    int n = A.size();
    int cnt = 0, res = 0;

    for(int i=0;i<n;i++)
    {
        if(A[i]=='(')
        cnt++;
        else
        {
            cnt--;
            if(cnt < 0)
            {
                res++;
                cnt = 0;
            }
        }
    }
    
    res+=cnt;

    return res;
}
