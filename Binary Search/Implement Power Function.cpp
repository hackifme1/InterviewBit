// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎

/* Problem Statement :

Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.

*/

Cpp code :

long long int powr(long long int X,long long int N,long long int D)
{
     if(X==0)
    return 0;
       if(N == 0)
    return 1;
    else if(N%2==0)
    {
        long long int t = powr(X,N/2,D);
        long long int r = (t%D*t%D)%D;
        return r;
    }
    else
    {
        long long int t = (powr(X,(N-1)/2,D));
        long long int r = (t%D*t%D*X%D)%D;
        if(r<0)
        r = (r+D)%D;
        return r;
    }
}

int Solution::pow(int x, int n, int d) {
     // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     long long int X=x;
      long long int N=n;
       long long int D=d;
       int res = powr(X,N,D)%d;
   return res;
    
}
