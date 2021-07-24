// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 

*/


Cpp code :

/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function->
    // Do not read input, instead use the arguments to the function->
    // Do not print the output, instead return values as specified
    // Still have a doubt-> Checkout www->interviewbit->com/pages/sample_codes/ for more details

        if(A == NULL || A->next == NULL)
            return NULL;
        
        ListNode* temp = A;
        ListNode* temp1 = A;
        int flag = 0;

        while(temp && temp1)
        {
            if (temp1->next == NULL) 
            return NULL;

            temp = temp->next;
            temp1 = temp1->next->next;
            
            if(temp == temp1)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        return NULL;

        temp = A;

        while(temp != temp1)
        {
            temp = temp->next;
            temp1 = temp1->next;
        }

        return temp;
}
