// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 

*/


Cpp code :

int Solution::isPower(int A) {
    if(A == 1)
    return 1;

    for(int i=2;i*i<=A; i++)
    {
        int temp = A;

        while(temp%i == 0)
        {
            temp = temp/i;
        }

        if(temp == 1)
        return 1;
    }

    return 0;
}
