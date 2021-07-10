// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most 2 transactions.

Return the maximum possible profit.

Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).



Input Format:

The first and the only argument is an integer array, A.

Output Format:

Return an integer, representing the maximum possible profit.


Constraints:

1 <= length(A) <= 7e5
1 <= A[i] <= 1e7

Examples:

Input 1:
    A = [1, 2, 1, 2]

Output 1:
    2

Explanation 1: 
    Day 0 : Buy 
    Day 1 : Sell
    Day 2 : Buy
    Day 3 : Sell

Input 2:
    A = [7, 2, 4, 8, 7]

Output 2:
    6

Explanation 2:
    Day 1 : Buy
    Day 3 : Sell

*/


Cpp code :

int Solution::maxProfit(const vector<int> &A) {
        int n = A.size();
        
        vector<int> dp_mxprft_l(n),dp_mxprft_r(n);
        int minm = A[0];
        int mxprft_l = 0;
        
        for(int i=1;i<n;i++)
        {
           minm = min(minm,A[i]);
           mxprft_l = A[i] - minm;
            if(mxprft_l > dp_mxprft_l[i-1])
                dp_mxprft_l[i] = mxprft_l;
            else
                dp_mxprft_l[i] = dp_mxprft_l[i-1];
        } 
        
        int maxm = A[n-1];
        int mxprft_r = 0;
        
        for(int i=n-2;i>=0;i--)
        {
           maxm = max(maxm,A[i]);
           mxprft_r = maxm - A[i];
            
           if(mxprft_r > dp_mxprft_r[i+1])
             dp_mxprft_r[i] = mxprft_r;
           else
             dp_mxprft_r[i] = dp_mxprft_r[i+1];
        } 
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            res = max(res, dp_mxprft_l[i] + dp_mxprft_r[i]);
        }
        
        return res;
}
