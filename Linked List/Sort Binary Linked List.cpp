// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a Linked List A consisting of N nodes.

The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's.

You need to sort the linked list and return the new linked list.

NOTE: Try to do it in constant space.


Problem Constraints
1 <= N <= 105

A.val = 0 or A.val = 1


Input Format
First and only argument is the head pointer of the linkedlist A.

Output Format
Return the head pointer of the new sorted linked list.


Example Input

Input 1:

 1 -> 0 -> 0 -> 1

Input 2:

 0 -> 0 -> 1 -> 1 -> 0


Example Output

Output 1:

 0 -> 0 -> 1 -> 1

Output 2:

 0 -> 0 -> 0 -> 1 -> 1


Example Explanation

Explanation 1:

 The sorted linked list looks like:
  0 -> 0 -> 1 -> 1

Explanation 2:

 The sorted linked list looks like:
  0 -> 0 -> 0 -> 1 -> 1

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
    ListNode* t = A;
    ListNode* t1 = A;
    int cnt0=0,cnt1=0;
    
    while(t)
    {
        if(t->val == 0)
        cnt0++;
        else
        cnt1++;
        
        t = t->next;
    }
    
    for(int i=0;i<cnt0;i++)
    {
        t1->val = 0;
        t1 = t1->next;
    }
    
    for(int i=cnt0;i<(cnt0+cnt1);i++)
    {
        t1->val = 1;
        t1 = t1->next;
    }
    return A;
}
