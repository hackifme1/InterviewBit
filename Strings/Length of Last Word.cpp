// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.

*/


Cpp code :

int Solution::lengthOfLastWord(const string A) {
    int n = A.size();
 
    int cnt = 0;
    int indx = n - 1;
     
    while(A[indx] == ' ' && indx >= 0)
    {
        indx--;
    } 
    
    while(indx >= 0 && A[indx] != ' ')
    {
        cnt++;
        indx--;
    }
    
    return cnt;
}
