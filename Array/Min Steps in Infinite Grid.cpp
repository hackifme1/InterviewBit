// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

You are in an infinite 2D grid where you can move in any of the 8 directions

 (x,y) to 
    (x-1, y-1), 
    (x-1, y)  , 
    (x-1, y+1), 
    (x  , y-1),
    (x  , y+1), 
    (x+1, y-1), 
    (x+1, y)  , 
    (x+1, y+1) 
    
You are given a sequence of points and the order in which you need to cover the points.. Give the minimum number of steps in which you can achieve it. You start from the first point.

NOTE: This question is intentionally left slightly vague. Clarify the question by trying out a few cases in the “See Expected Output” section.


Input Format
Given two integer arrays A and B, where A[i] is x coordinate and B[i] is y coordinate of ith point respectively.

Output Format
Return an Integer, i.e minimum number of steps.


Example Input
Input 1:

 A = [0, 1, 1]
 B = [0, 1, 2]


Example Output
Output 1:

 2


Example Explanation
Explanation 1:

 Given three points are: (0, 0), (1, 1) and (1, 2).
 It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).


*/


Cpp code :

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    
    if(m!=n)
    return 0;
    
    int res = 0;
    
    for(int i=0;i<n-1;i++)
    {
        res+=max(abs(A[i+1]-A[i]),abs(B[i+1]-B[i]));
    }
    
    return res;
}
