// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string A and integer B, what is maximal lexicographical stringthat can be made from A if you do atmost B swaps.

Problem Constraints
1 <= |A| <= 9

A contains only digits from 0 to 9.

1 <= B <= 5

Input Format
First argument is string A.
Second argument is integer B.

Output Format
Return a string, the naswer to the problem.

Example Input
Input 1:

A = "254"
B = 1

Input 2:

A = "254'
B = 2


Example Output
Output 1:

 524
 
Output 2:

 542


Example Explanation
Explanation 1:

 Swap 2 and 5.
 
Explanation 2:

Swap 2 and 5 then swap 4 and 2.

*/


Cpp code :

void solved(string A, string &res, int B)
{
        if(B == 0)
        return;
        
        int n = A.size();
        
        for(int i=0;i<n-1;i++)
        {
            for(int j = i+1; j<n;j++)
            {
                if (A[i] < A[j]) 
                {
                    swap(A[i], A[j]);
     
                    if (A.compare(res) > 0)
                        res = A;
     
                    solved(A, res, B - 1);
     
                    swap(A[i], A[j]);
                }
            }
        }
}

string Solution::solve(string A, int B) {
       string res = A;
       
       solved(A,res,B);
       
       return res;
}
