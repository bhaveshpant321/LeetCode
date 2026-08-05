/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Alternatives: Create an array and compare with reverse or reverse a copy of the entire list: Takes O(n) extra space
        // find the middle and reverse the latter part, then just compare: O(1) extra space (inplace reversal and comparison)

        ListNode* fast= head, *slow= head, *prev, *temp;
        while(fast && fast->next){  // finding mid
            slow= slow->next;
            fast= fast->next->next;
        }
        prev= slow; slow= slow->next; prev->next= nullptr;

        while(slow){    // reversal
            temp= slow->next; slow->next= prev; prev= slow; slow= temp;
        }

        fast= head; slow= prev;
        while(slow){    // comparison
            if(fast->val!= slow->val)   return false;
            else{ fast= fast->next; slow= slow->next; }
        }
        return true;
    }
};