// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

*/


Cpp code :


vector<int> Solution::plusOne(vector<int> &A) {
    
    int n=A.size();
    int crr=0;
    
    vector<int> ans;
    ans.push_back((1+A[n-1])%10);
    crr=(1+A[n-1])/10;
    
    for(int i=n-2;i>=0;i--)
    {
        ans.push_back((crr+A[i])%10);
        crr=(crr+A[i])/10;
    }
    
    if(crr)
     ans.push_back(crr);
     
    int x = ans.size();
    
    for(int i=0;i<x/2;i++)
     swap(ans[i],ans[x-i-1]);
     
    while(ans[0]==0)
    {
       ans.erase(ans.begin());
    }
    
    return ans;
}
