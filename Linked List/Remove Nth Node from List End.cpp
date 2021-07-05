// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.

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
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(A == NULL || B == 0)
    return A;

    ListNode* temp = A;
    ListNode* temp1 = A;
    ListNode* prev = NULL;

    int cnt = 0;

    while(temp)
    {
        temp = temp->next;
        cnt++;
    }

    if(cnt <= B)
    {
        A = A->next;
        return A;
    }

    int cnt1 = cnt - B;

    while(cnt1--)
    {
        prev = temp1;
        temp1 = temp1->next;
    }

    prev->next = temp1->next;
    
    return A;
}
