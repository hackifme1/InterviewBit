// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]

Return  : 2 which occurs 2 times which is greater than 3/2. 

*/


Cpp code :
// O(n) time complexity and  O(1) space complexity

int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    int cnt = 1, candte = A[0];

    for(int i=0;i<n;i++)
    {
        if(A[i] == candte)
        cnt++;
        else
        cnt--;

        if(cnt == 0)
        {
            candte = A[i];
            cnt = 1;
        }

    }

    return candte;
}

// O(nlogn) time complexity and  O(n) space complexity

int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    int k = n/2;
    vector<int> temp;
    
    for(int i=0;i<n;i++)
    temp.push_back(A[i]);

    sort(temp.begin(),temp.end());

    return temp[k];
}
