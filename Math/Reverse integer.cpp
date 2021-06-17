// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Reverse digits of an integer.

Example1:

x = 123,
return 321

Example2:

x = -123,
return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

*/


Cpp code :

int Solution::reverse(int A) {
    long long rev = 0;
        
        while(A) 
        {
            rev = rev*10 + A%10;
            A /= 10;
        }
        
        return (rev<INT_MIN || rev>INT_MAX) ? 0 : rev;
}
