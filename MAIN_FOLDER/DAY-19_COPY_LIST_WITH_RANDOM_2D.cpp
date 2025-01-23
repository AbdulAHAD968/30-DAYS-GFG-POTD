#include<bits/stdc++.h>

using namespace std;



// Definition for a Node.
class Node{
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


class Solution {
public:

    // Function to clone a linked list with random pointers.
    Node* copyRandomList(Node* head) {
        
        // If the list is empty, return NULL.
        if(!head){
            return NULL;
        }

        unordered_map<Node* , Node*> m;

        Node* crr = head;

        while(crr){
            // STORE THE NODES CORRESPONDING 
            // TO ORIGNAL NODES.
            m[crr] = new Node(crr->val);

            // GO AHEAD
            crr = crr->next;
        }
        crr = head;

        while(crr){

            //FIX THE NEXT POINTER OF NEW NODE.
            m[crr]->next = m[crr->next];

            // FIX THE RANDOM POINTER OF NEW NODE.
            m[crr]->random = m[crr->random];

            // GO AHEAD
            crr = crr->next;
        }

        return m[head];
    }
};


// OUR MAIN FUNCTION WITH ONLY ONE TEST CASE...
int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next->next->next->next;
    head->next->next->next->next->random = head->next->next->next->next->next;
    
    Solution s;
    Node* clone = s.copyRandomList(head);
    
    // PRINT THE CLONED LIST
    Node* crr = clone;
    while(crr){
        cout<<crr->val<<" -> ";
        if(crr->random){
            cout<<crr->random->val<<" ";
        }
        else{
            cout<<"NULL ";
        }
        crr = crr->next;
    }
    cout<<"NULL"<<endl;

return 0;
}