// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a stream of numbers A. On arrival of each number, you need to increase its first occurence by 1 and include this in the stream.

Return the final stream of numbers.

Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 10000



Input Format
First and only argument is the array A.

Output Format
Return an array, the final stream of numbers.



Example Input
Input 1:

A = [1, 1]

Input 2:

A = [1, 2]


Example Output
Output 1:

[2, 1]

Output 2:

[1, 2]


Example Explanation
Explanation 1:

 On arrival of the second element, the other element is increased by 1.
 
Explanation 2:

No increases are to be done.

*/


Cpp code :

vector<int> Solution::solve(vector<int> &A) {
      unordered_map<int,int> mp;
    for(int i=0; i<A.size(); i++)
    {
        if(mp.count(A[i]))
        {
            A[mp[A[i]]]++;
            mp[A[i]+1] = mp[A[i]];
        }
        mp[A[i]] = i;
    }
    return A;
}
