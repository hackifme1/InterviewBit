// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result. 

If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]

*/


Cpp code :

void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size();
    int n = B.size();
    A.resize(m+n);
    int s = m + n;
    
        for(int i=0;i<m;i++)
        {
            A[s-i-1] = A[m-i-1];
        }
       
        int l = n, r = 0, k = 0;
        
        while(l<s && r<n && k<l)
        {
            if(A[l]<=B[r])
            {
                A[k++] = A[l++];                 
            }
            else
            {
                A[k++] = B[r++];
            }
        }
        
        while(l<s)
        {
           A[k++] = A[l++];
        }
        
        while(r<n)
        {
           A[k++] = B[r++];
        }
}
