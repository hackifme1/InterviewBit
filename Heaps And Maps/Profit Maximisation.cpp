// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.

Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.



Problem Constraints
1 <= |A| <= 100000

1 <= B <= 1000000


Input Format
First argument is the array A.

Second argument is integer B.

Output Format
Return one integer, the answer to the problem.

Example Input
Input 1:

A = [2, 3]
B = 3

Input 2:

A = [1, 4]
B = 2


Example Output
Output 1:

7

Output 2:

7


Example Explanation
Explanation 1:

 First you serve the seat with number = 3. Then with 2 and then with 2. hence answer = 3 + 2 + 2 = 7.

Explanation 2:

 You give bith tickets from the row with 4 seats. 4 + 3 = 7.

*/


Cpp code :

int Solution::solve(vector<int> &A, int B) {
    priority_queue<int> pq;
    int n = A.size();
    
    for (int i = 0; i < n; i++)
        pq.push(A[i]);
 
    int prft = 0;

    int cnt = 0;

    while (cnt < B) 
    {
        int top = pq.top();
        pq.pop();

        if (top == 0)
            break;

        prft = prft + top;
        pq.push(top - 1);
 
        cnt++;
    }

    return prft;
}
