// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,

Given 1->2->3->3->4->4->5, return 1->2->5.

Given 1->1->1->2->3, return 2->3.

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
        if(A == NULL || A->next == NULL)
            return A;

        ListNode* temp = A, *pre = NULL, *crr = temp->next;
        bool flag = false;

        while(crr)
        {
            while(crr && (temp->val == crr->val))
            {
                crr = crr->next;
                flag = true;
            }

            if(flag == true)
            {
                if(pre) 
                pre->next = crr;
                else
                A = crr;

                temp = crr;

                if(crr)
                crr = crr->next;

                flag = false;
            }
            else
            {
                pre = temp;
                temp = temp->next;
                crr = crr->next;
            }            
        }

        return A;
}
