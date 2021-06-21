// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an integer A, return the number of trailing zeroes in A!.

Note: Your solution should be in logarithmic time complexity.

**Problem Constraints**
1 <= A <= 10000

**Input Format**
First and only argumment is integer A.

**Output Format**
Return an integer, the answer to the problem.


**Example Input**
Input 1:

 A = 4

Input 2:

 A = 5


**Example Output**
Output 1:

 0

Output 2:

 1


**Example Explanation**
Explanation 1:

 4! = 24
 
Explanation 2:

 5! = 120

*/


Cpp code :

int Solution::trailingZeroes(int A) {
    int cnt = 0;
    
    for(int i=5; A/i>=1; i=i*5)
    {
        cnt = cnt + A/i;
    }
    
    return cnt;
}
