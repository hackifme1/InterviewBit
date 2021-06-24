// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

NOTE: if B > N, return an empty array.

Input Format
First argument is an integer array A
Second argument is an integer B.

Output Format
Return an integer array.

Example Input
Input 1:

 A = [1, 2, 1, 3, 4, 3]
 B = 3
 
Input 2:

 A = [1, 1, 2, 2]
 B = 1


Example Output
Output 1:

 [2, 3, 3, 2]
 
Output 2:

 [1, 1, 1, 1]


Example Explanation
Explanation 1:

 A=[1, 2, 1, 3, 4, 3] and B = 3
 All windows of size B are
 [1, 2, 1]
 [2, 1, 3]
 [1, 3, 4]
 [3, 4, 3]
 So, we return an array [2, 3, 3, 2].
 
Explanation 2:

 Window size is 1, so the output array is [1, 1, 1, 1].

*/


Cpp code :

vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    vector<int> res;
    int cnt = 0;

    if(B>n)
    return res;

    unordered_map<int,int> ump;

    for(int i=0;i<B;i++)
    {
        if(ump[A[i]]==0)
        cnt++;

        ump[A[i]]++;
    }

    res.push_back(cnt);

    for(int i=B;i<n;i++)
    {
         if (ump[A[i - B]] == 1) 
         {
            cnt--;
         }

        ump[A[i - B]] -= 1;
 
        if (ump[A[i]] == 0) 
        {
            cnt++;
        }

        ump[A[i]] += 1;
        res.push_back(cnt);
    }

    return res;
}
