// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string A representing a roman numeral.

Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more 

details about roman numerals at Roman Numeric System


Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.

For Example

Input 1:
    A = "XIV"
    
Output 1:
    14

Input 2:
    A = "XX"
    
Output 2:
    20

*/


Cpp code :

int Solution::romanToInt(string A) {
    int n = A.size();

    unordered_map<char,int> ump;
    ump['I'] = 1;
    ump['V'] = 5;
    ump['X'] = 10;
    ump['L'] = 50;
    ump['C'] = 100;
    ump['D'] = 500;
    ump['M'] = 1000;
    
    int res = 0, i = 0;

    while(i < (n-1))
    {
        if(ump[A[i]]< ump[A[i+1]]) 
        res-=ump[A[i]];
        else 
        res+=ump[A[i]];

        i++;
    }

    res+=ump[A[i]];
    
    return res;
}
