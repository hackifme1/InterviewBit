// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎

/* Problem Statement

Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE: A solution will always exist. read Goldbach’s conjecture

Example:

Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d.

*/

Cpp code :

vector<int> Solution::primesum(int A) {
    bool chk_prime[A+1];
    vector<int> v;
    for(int i=0;i<=A;i++)
    {
        chk_prime[i]=true;
    }
    
    chk_prime[0]=false;
    chk_prime[1]=false;
    int N = sqrt(A);
    
    for(int i=2;i<=N;i++)
    {
        for(int j=2;i*j<=A;j++)
        {
            chk_prime[i*j]=false;
        }
    }
    
    for(int i=2;i<=A;i++)
    {
        if(chk_prime[i]&&chk_prime[A-i])
        {
            v.push_back(i);
            v.push_back(A-i);
            break;
        }
    }
    return v;
}
