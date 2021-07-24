// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a linked list A , reverse the order of all nodes at even positions.



Problem Constraints
1 <= Size of linked list <= 100000



Input Format
First and only argument is the head of the Linked-List A.

Output Format
Return the head of the new linked list.


Example Input
Input 1:

A = 1 -> 2 -> 3 -> 4

Input 2:

A = 1 -> 2 -> 3


Example Output
Output 1:

 1 -> 4 -> 3 -> 2
 
Output 2:

 1 -> 2 -> 3


Example Explanation
Explanation 1:

Nodes are positions 2 and 4 have been swapped.

Explanation 2:

No swapping neccassary here.

*/


Cpp code :

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    if( A == NULL )
    return A;

    ListNode* temp = A;
    vector<int> v;
    int cnt = 0;

    while(temp)
    {
        cnt++;
        if(cnt%2 == 0)
        v.push_back(temp->val);

        temp = temp->next;
    }

    temp = A;

    reverse(v.begin(), v.end());

    int i = 0;

    cnt = 0;
    
    while(temp)
    {
        cnt++;

        if(cnt%2 == 0)
        temp->val = v[i++];
        temp = temp->next;
    }

    return A;
}
