// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?

Note : repetition of number is allowed.

Example:

N = 4

Fibonacci numbers : 1 1 2 3 5 .... so on
here 2 + 2 = 4 
so minimum numbers will be 2 

*/


Cpp code :

int Solution::fibsum(int A) {
    vector<int> fib(100000,0);

    fib[0] = 1;
    fib[1] = 1;
    int i;

    for(i=2;i<100000;i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        if(fib[i] > A)
        break;
    }

    if(fib[i-1] == A)
    return 1;

    int cnt = 0;
    
    for(int j = i-1;j>=0 && A;j--)
    {
        if(A >= fib[j])
        {
            A = A - fib[j];
            cnt++;
        }
        else
        continue;
    }

    return cnt;
}
