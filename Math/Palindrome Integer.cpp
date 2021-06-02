// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False

*/


Cpp code :

int Solution::isPalindrome(int A) {
    if( A < 0 )
    return 0;
    
    string str = to_string(A);
    int n = str.size();
    int l=0,r=n-1;
    
    while(l<r)
    {
        if(str[l] != str[r])
        return 0;
        
        l++;
        r--;
    }
    
    return 1;
    
}

// or

int Solution::isPalindrome(int A) {
 int sum =0,temp = A;
    
    if(A<0)
    return 0;
    
    while(temp)
    {
        int r = temp%10;
        sum = sum*10 + r;
        temp = temp/10;
    }
        
        if(sum == A)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    
}
