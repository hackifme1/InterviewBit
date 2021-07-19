// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

NOTE : The length of the list is divisible by K

Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.

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
ListNode* Solution::reverseList(ListNode* A, int B) {
        ListNode* crr = A;
        int cnt = 0;
        
        while (crr != NULL && cnt != B) 
        { 
            crr = crr->next;
            cnt++;
        }
        
        if (cnt == B) 
        { 
            crr = reverseList(crr, B); 
            
            while (cnt--) 
            { 
                ListNode* tmp = A->next; 
                A->next = crr; 
                crr = A; 
                A = tmp; 
            }
            
            A = crr;
        }
        
        return A;
}
