// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.

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
ListNode* Solution::rotateRight(ListNode* A, int B) {
        if( A == NULL)
        return A;
        
        ListNode* temp = A;
        int posnh = 0, cnt = 0;
        
        while(temp->next)
        {
            cnt++;
            temp = temp->next;
        }
       
        cnt++;
        
        int r = B % cnt;
        
        if(r == 0)
            return A;
        
        temp->next = A;
        
        for(int i=0;i<(cnt-r);i++)
        {
            temp = temp->next;
        }
        
        A = temp->next;
        temp->next = NULL;

        return A;  
}
