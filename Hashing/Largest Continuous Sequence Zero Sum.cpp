// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Find the largest continuous sequence in a array which sums to zero.

Example:

Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 

*/


Cpp code :

vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size();
    vector<int> v;
    map<int,int> mp;
    int sum = 0;
    int maxm = INT_MIN;
    int x=-1,y=-1;
    mp.insert({0,-1});
    
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        
        if(mp.find(sum)!= mp.end())
        {
            if((i-mp[sum])>maxm)
            {
                maxm = i-mp[sum];
                x = i;
                y = mp[sum] + 1;
            }
            continue;
        }
        
        mp[sum] = i;
    }
    if(sum == 0)
    return A;
    if(maxm == INT_MIN)
    return v;
    
    for(int i=y;i<=x;i++)
    v.push_back(A[i]);
    
    return v;
}
