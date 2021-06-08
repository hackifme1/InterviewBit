// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Input Format:

First and only argument of input contains an integer array A
Output Format:

return a single integer denoting single element
    
    
Constraints:

2 <= N <= 2 000 000  
0 <= A[i] <= INT_MAX


For Examples :

Example Input 1:
    A = [1, 2, 2, 3, 1]
    
Example Output 1:
    3
Explanation:
    3 occurs only once
    
Example Input 2:
    A = [1, 2, 2]
    
Example Output 2:
    1
    
*/

Cpp code :

int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    int res = A[0];
    for(int i=1;i<n;i++)
    {
        res^=A[i];
    }
    
    return res;
}
