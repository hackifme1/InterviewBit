// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

There is a row of seats. Assume that it contains N seats adjacent to each other. There is a group of people who are already seated in that row randomly. i.e. some are sitting
together & some are scattered.

An occupied seat is marked with a character 'x' and an unoccupied seat is marked with a dot ('.')

Now your target is to make the whole group sit together i.e. next to each other, without having any vacant seat between them in such a way that the total number of hops or jumps
to move them should be minimum.

Return minimum value % MOD where MOD = 10000003

Example

Here is the row having 15 seats represented by the String (0, 1, 2, 3, ......... , 14) -

              . . . . x . . x x . . . x . .

Now to make them sit together one of approaches is -
                  . . . . . . x x x x . . . . .

Following are the steps to achieve this -

1 - Move the person sitting at 4th index to 6th index -  
    Number of jumps by him =   (6 - 4) = 2

2 - Bring the person sitting at 12th index to 9th index - 
    Number of jumps by him = (12 - 9) = 3

So now the total number of jumps made = 
    ( 2 + 3 ) % MOD = 
    5 which is the minimum possible jumps to make them seat together.

There are also other ways to make them sit together but the number of jumps will exceed 5 and that will not be minimum.

For example bring them all towards the starting of the row i.e. start placing them from index 0. 

In that case the total number of jumps will be 
    ( 4 + 6 + 6 + 9 )%MOD 
    = 25 which is very costly and not an optimized way to do this movement

*/


Cpp code :

int Solution::seats(string A) {
    long long int mod = 10000003;
    long long int n = A.size();

    vector<long long int> posn;

    for(long long int i=0;i<n;i++)
    {
        if(A[i] == 'x')
        posn.push_back(i);
    }

    if(posn.size() == 0)
    return 0;

    long long int res = 0;
    long long int m = posn.size();
    long long int mid = m/2;
    long long int temp = 1;

    for(long long int i=0;i<mid;i++)
    {
        res = (res + posn[mid] - posn[i] - temp)%mod;
        temp++;
    }

    temp = 1;

    for(long long int i=mid+1;i<m;i++)
    {
        res = (res + posn[i]- (posn[mid] + temp))%mod;
        temp++;
    }

    return res;
}
