// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

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
ListNode* Solution::swapPairs(ListNode* A) {
    if(A == NULL|| A->next == NULL)
            return A;
        
        ListNode* prev = A;
        ListNode* curr = A->next;
        A = curr;
        
        while(1)
        {
            ListNode* nxt = curr->next;
            curr->next = prev;
            
             if (nxt == NULL || nxt->next == NULL)
             {
                prev->next = nxt;
                break;
             }
             
            prev->next = nxt->next;
  
            prev = nxt;
            curr = prev->next;
        }
        
        return A;
}
