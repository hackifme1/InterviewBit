// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,

Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
 
ListNode* Solution::deleteDuplicates(ListNode* A) {
     ListNode* temp = A;
        if(A==NULL||A->next==NULL)
            return A;
        
        int p = A->val;
        temp = temp->next;
        ListNode* prv =A;
        while(temp)
        {
            if(temp->val==p)
            {
                prv->next = temp->next;
            }
            else
            {
                p = temp->val;
                prv = prv->next;
            }
            temp = temp->next;
        }
        return A;
}
