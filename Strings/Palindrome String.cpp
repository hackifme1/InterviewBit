// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem.

*/


Cpp code :

int Solution::isPalindrome(string A) {
    string str = "";
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>=48&&A[i]<=57)
        str+=A[i];
        
        if(A[i]>=97&&A[i]<=122)
        str+=A[i];
        
        if(A[i]>=65&&A[i]<=90)
        {
            A[i]=A[i]+32;
            str+=A[i];
        }
    }

    string temp=str;
    
    reverse(temp.begin(),temp.end());
    
    if(str==temp)
        return 1;
    else
        return 0;
}
