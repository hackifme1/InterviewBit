// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

You are given the following :

A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
You need to return  list of actual order of persons’s height

Consider that heights will be unique

Example

Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2

Output : 
actual order is: 5 3 2 1 6 4 
So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.

For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

You can do similar inference for other people in the list.

*/


Cpp code :

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n = A.size();

    vector<pair<int,int> > temp(n);
    vector<int> res(n,-1);
    
    for(int i=0;i<n;i++)
    {
        temp[i]={A[i],B[i]};
    }
 
    sort(temp.begin(),temp.end());
    
    for(int i=0;i<n;i++)
    {
        int indx = temp[i].second;
        int height = temp[i].first;
        int i1 = 0, j1 = 0;
        
        while(j1 < indx || res[i1]!=-1)
        {
            if(res[i1] == -1) 
            j1++;

            i1++;
        }
 
        res[i1] = height; 
    }

    return res;
}
