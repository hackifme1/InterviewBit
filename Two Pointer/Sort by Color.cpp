// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array with n objects colored red, white or blue,
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]

*/


Cpp code :


// Two-pointer Approach

void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int l = 0, k = n-1, r = 0;
    
    while(r<=k)
    {
        if(A[r]==0)
        swap(A[l++],A[r++]);
        else if(A[r]==2)
        swap(A[k--],A[r]);
        else
        r++;
    }
}


// Using just three variables to store count of occurence of 0,1 and 2

void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    
    for(int i=0;i<n;i++)
    {
        if(A[i]==0)
        cnt0++;
        else if(A[i]==1)
        cnt1++;
        else
        cnt2++;
    }
    
    for(int i=0;i<cnt0;i++)
    A[i] = 0;
    
    for(int i=cnt0;i<(cnt0+cnt1);i++)
    A[i] = 1;
    
    for(int i=(cnt0+cnt1);i<n;i++)
    A[i] = 2;
}
