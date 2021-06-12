// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.


Input Format

The only argument given is character array A.

Output Format

Return the value of arithmetic expression formed using reverse Polish Notation.

For Example

Input 1:
    A =   ["2", "1", "+", "3", "*"]

Output 1:
    9

Explaination 1:
    starting from backside:
    *: ( )*( )
    3: ()*(3)
    +: ( () + () )*(3)
    1: ( () + (1) )*(3)
    2: ( (2) + (1) )*(3)
    ((2)+(1))*(3) = 9
    
Input 2:
    A = ["4", "13", "5", "/", "+"]

Output 2:
    6

Explaination 2:
    +: ()+()
    /: ()+(() / ())
    5: ()+(() / (5))
    1: ()+((13) / (5))
    4: (4)+((13) / (5))
    (4)+((13) / (5)) = 6

*/


Cpp code :

int Solution::evalRPN(vector<string> &A) {
    int n = A.size();
    stack<int> stck;
    
    for(int i=0;i<n;i++)
        {
            if(A[i]!="+"&&A[i]!="-"&&A[i]!="*"&&A[i]!="/")
            {
                stringstream inbit(A[i]);
                int x = 0;
                inbit >> x;
                stck.push(x);
            }
            else
            {
                int opnd1 = stck.top();
                stck.pop();
                int opnd2 = stck.top();
                stck.pop();
                int res;
                if(A[i]=="+")
                 res = opnd2 + opnd1;
                else if(A[i]=="-")
                 res = opnd2 - opnd1;
                else if(A[i]=="*")
                 res = opnd2 * opnd1;
                else
                 res = opnd2 / opnd1;
                
                stck.push(res);
            }
        }
        return stck.top();
    
}
