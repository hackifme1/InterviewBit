// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example :

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]

Output : [3 3 5]

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 5]

Output : [3 5]

NOTE : For the purpose of this problem ( as also conveyed by the sample case ), assume that elements that appear more than once in both arrays should be included multiple 
times in the final output. 

*/


Cpp code :

// O(N) time complexity and O(1) Space complexity

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> res;
    
    int m = A.size();
    int n = B.size();
    int l = 0, r = 0;
    
    while(l<m && r<n)
    {
        if(A[l]<B[r])
        l++;
        else if(A[l]>B[r])
        r++;
        else
        {
            res.push_back(A[l]);
            l++;
            r++;
        }
    }
    
    return res;
}

// or O(N) time complexity and O(N) Space complexity

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> res;
    
    unordered_map<int,int> ump2;
    int m = A.size();
    int n = B.size();
    
      for(int i=0;i<n;i++)
    {
        ump2[B[i]]++;
    }
    
    for(int i=0;i<m;i++)
    {
        if(ump2[A[i]]>0)
        {
            res.push_back(A[i]);
            ump2[A[i]]--;
        }
    }
    return res;
}
