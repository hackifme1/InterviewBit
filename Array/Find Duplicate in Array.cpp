// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:
[3 4 1 4 1]

Sample Output:
1

If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1

*/


Cpp code :
//O(n) time complexity and O(n) space complexity (And one traversal only)

int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int f[n]={0};
    for(int i=0;i<n;i++)
    {
        f[A[i]]++;
        if(f[A[i]]>1)
        return A[i];
    }
    
    return -1;
    
}
