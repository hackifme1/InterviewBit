// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Another question which belongs to the category of questions which are intentionally stated vaguely. 

Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Implement strStr().

strstr - locate a substring ( needle ) in a string ( haystack ).

Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

NOTE:

Good clarification questions:

What should be the return value if the needle is empty?

What if both haystack and needle are empty?

For the purpose of this problem, assume that the return value should be -1 in both cases.

*/


Cpp code :

int Solution::strStr(const string A, const string B) {
        int n = A.size();
        int m = B.size();
        
        if(m == 0)
            return 0;
        if(n == 0)
            return -1;
        
        for(int i=0, j=0; i<n; i++)
        { 
            if(A[i] == B[j])
            {
                if (j == m-1) 
                    return i-j;
                else 
                    j++;
            }
            else if(j)
            {
                i = i-j;    
                j = 0;              
            }
        }
        
        return -1;
}
