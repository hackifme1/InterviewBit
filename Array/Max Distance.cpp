// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Input Format
First and only argument is an integer array A.

Output Format
Return an integer denoting the maximum value of j - i;


Example Input
Input 1:

 A = [3, 5, 4, 2]


Example Output
Output 1:

 2


Example Explanation
Explanation 1:

 Maximum value occurs for pair (3, 4).

*/


Cpp code :

int Solution::maximumGap(const vector<int> &A) {
        int n = A.size();
        vector<int> v(n);
        
        v[n-1] = A[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            v[i] = max(v[i+1],A[i]);
        }
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
           int l = i + 1, r = n - 1; 
           int maxm = i;
           
           while(l<=r)
           {
               int m = l + (r - l)/2;
               
               if(v[m]>=A[i])
               {
                   maxm = max(maxm,m);
                   l = m + 1;
               }
               else
               r = m - 1;
           }
           
           res = max(res,maxm - i);
        }
        
        return res;
}
