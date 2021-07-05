// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given two arrays A & B of size N each.

Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and  B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4  , 1+4=5  ,   2+3=5   ,    2+4=6

and maximum 2 elements are 6, 5

Example:

N = 4

a[]={1,4,2,3}

b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)

*/


Cpp code :

#define peyr pair<int,pair<int,int>>
#define f first
#define s second

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> res;
    int n = A.size();

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    priority_queue<pair<int,pair<int,int>>> pq;
    map<pair<int,int>,int> st;

    st[make_pair(n-1,n-1)] = 1;

    pq.push(make_pair(A[n-1]+B[n-1],make_pair(n-1,n-1)));

    for(int i=0;i<n;i++)
    {
        peyr top = pq.top();
        pq.pop();
        res.push_back(top.f);

        int x = top.s.f;
        int y = top.s.s;

        if(st[make_pair(x-1,y)] != 1)
        {
            st[make_pair(x-1,y)] = 1;
            pq.push(make_pair(A[x-1]+B[y],make_pair(x-1,y)));
        }

        if(st[make_pair(x,y-1)] != 1)
        {
            st[make_pair(x,y-1)] = 1;
            pq.push(make_pair(A[x]+B[y-1],make_pair(x,y-1)));
        }

    }

    return res;
}
