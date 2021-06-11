// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input : 
    A : [1 3 5] 
    k : 4
    
 Output : YES as 5 - 1 = 4 
 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.

*/

Cpp code :

int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size();
    
    int l = 0, r = 1;
    
    while(l<n && r<n)
    {
        int diff = (A[r]-A[l]);
        
        if(diff == B && l!=r)
        return 1;
        
        if(diff<B)
        r++;
        else
        l++;
    }
    
    return 0;
}
