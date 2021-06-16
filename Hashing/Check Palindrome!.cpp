// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string A consisting of lowercase characters.

Check if characters of the given string can be rearranged to form a palindrome.

Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.



Problem Constraints
1 <= |A| <= 105

A consists only of lower-case characters.

Input Format
First argument is an string A.


Output Format
Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.


Example Input
Input 1:

 A = "abcde"
 
Input 2:

 A = "abbaee"


Example Output
Output 1:

 0
 
Output 2:

 1


Example Explanation
Explanation 1:

 No possible rearrangement to make the string palindrome.
 
Explanation 2:

 Given string "abbaee" can be rearranged to "aebbea" to form a palindrome.

*/


Cpp code :

int Solution::solve(string A) {
    int n = A.size();
    int f[26]={0};

    for(int i=0;i<n;i++)
    {
        f[A[i]-'a']++;
    }
    
    int flag=0;
    
    for(int i=0;i<26;i++)
    {
        if(f[i]%2!=0 && flag==0) 
        flag=1;
        else if(f[i]%2!=0 && flag==1) 
        return 0;
    }
    return 1;
}
