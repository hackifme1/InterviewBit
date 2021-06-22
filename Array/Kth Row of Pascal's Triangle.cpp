// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]
 
NOTE : k is 0 based. k = 0, corresponds to the row [1]. 

Note: Could you optimize your algorithm to use only O(k) extra space?

*/


Cpp code :

vector<int> Solution::getRow(int A) {
    vector <int> ans;
          
    int i = A + 1, c = 1;
    
    for(int j=1; j<=i; j++)
    {
        ans.push_back(c);
        c = c*(i - j)/j;
    }
    
    return ans;
}
