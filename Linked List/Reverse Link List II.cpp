// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:

Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note 1:

Given m, n satisfy the following condition:

1 ≤ m ≤ n ≤ length of list.

Note 2:

Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.

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
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
     if(A==NULL)
            return NULL;
        
        vector<int> v;
        
        ListNode *temp = A;
        
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        temp = A;
        
        for(int i=0;i<B-1;i++)
            temp = temp->next;
        
        for(int i=C;i>=B;i--)
        {
            temp->val = v[i-1];    
            temp = temp->next;
        }
        
        return A;
}
