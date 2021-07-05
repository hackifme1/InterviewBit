// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Merge two sorted linked lists and return it as a new list. 

The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
  
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

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
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* res = NULL;

    if(A == NULL)
    return B;
    if(B == NULL)
    return A;

    if(A->val <= B->val)
    {
        res = A;
        res->next = mergeTwoLists(A->next,B);
    }
    else
    {
        res = B;
        res->next = mergeTwoLists(A,B->next);
    }
    
    return res;
}
