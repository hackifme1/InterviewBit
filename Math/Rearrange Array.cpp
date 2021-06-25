// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:

Input : [1, 0]
Return : [0, 1]

Lets say N = size of the array. Then, following holds true :
All elements in the array are in the range [0, N-1]
N * N does not overflow for a signed integer

*/


Cpp code :

void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size() ;

    for (int i = 0 ; i < n ;i ++ )
    {
        if(A[A[i]] >= n )
        {
        
            A[i] = A[A[i]]/ n + (A[i] + 1 ) * n - 1 ;
        
        }
        else
        {
        
            A[i] = A[A[i]] + (A[i]+1) * n;
        
        }
    }
    for (int i = 0 ; i < n ;i ++ )
    {
        if (A[i] >= n) 
            A[i] %=n ;
    }

}
