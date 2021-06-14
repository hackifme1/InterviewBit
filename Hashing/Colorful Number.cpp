// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:
A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different

Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6

this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1

*/


Cpp code :

int Solution::colorful(int A) {
    string str = to_string(A);
    int n = str.size();
    map<int,int> mp;
    
    for(int i=0;i<n;i++)
    {
        int prdct = 1;
        for(int j=i;j<n;j++)
        {
            int num = str[j]-'0';
            prdct*=num;
            
            if(mp[prdct]==1)
            return 0;
            
            mp[prdct] = 1;
        }
    }
    
    return 1;
}
