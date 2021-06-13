// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Explanation :

342 + 465 = 807

Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

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
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
        ListNode* temp1 = A;
        ListNode* temp2 = B;
        ListNode* C = new ListNode((temp1->val + temp2->val)%10);
        int carr = (temp1->val + temp2->val)/10;
        
        temp1=temp1->next;
        temp2=temp2->next;
       
        ListNode* temp3 = C;
        
        while(temp1 != NULL && temp2 != NULL)
        {
            int s = (temp1->val + temp2->val + carr)%10;
            carr = (temp1->val + temp2->val + carr)/10;
            
            ListNode* t = new ListNode(s);
            temp3 ->next = t;
            temp3 = temp3->next;
             temp1=temp1->next;
             temp2=temp2->next;
        }
        
        while(temp1!=NULL)
        {
             int s = (temp1->val + carr)%10;
            carr = (temp1->val + carr)/10;
            
            ListNode* t = new ListNode(s);
            temp3 ->next = t;
            temp3 = temp3->next;
            
            temp1=temp1->next;
        }
        
        while(temp2!=NULL)
        {
            int s = (temp2->val + carr)%10;
            carr = (temp2->val + carr)/10;
            
            ListNode* t = new ListNode(s);
            temp3->next = t;
            temp3 = temp3->next;
            
            temp2 = temp2->next;
        }
        
        if(carr>0)
        {
            ListNode* t = new ListNode(carr);
            temp3->next = t;
            temp3 = temp3->next;
        }
        
        return C;

}
