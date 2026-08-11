/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Initial ideation: hash map: store the mapping between each node in the og list and it's corresponding node in copied list

        // how to solve: insert our copies between initial and next node in pass 1
        // in pass 2: initialize random to next of random of initial, break back from the array and join with the new list

        if(!head) return nullptr;
        Node* curr= head;
        while(curr){
            Node* new_node= new Node(curr->val);
            new_node->next= curr->next;
            curr->next= new_node;
            curr= new_node->next;
        }
        curr= head;
        while(curr){
            if(curr->random){
                curr->next->random= curr->random->next;
            }curr= curr->next->next;
        }

        Node* new_head= head->next;
        Node* curr_old= head;
        Node* curr_new= new_head;

        while(curr_old){
            curr_old->next= curr_old->next->next;
            curr_new->next= curr_new->next? curr_new->next->next : nullptr;
            curr_old= curr_old->next;
            curr_new= curr_new->next;
        }

        return new_head;
    }
};