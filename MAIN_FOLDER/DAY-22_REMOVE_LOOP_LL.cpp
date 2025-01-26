#include<bits/stdc++.h>


using namespace std;



// MAKING A NODE CLASS.
class Node{
    public:

        int data;
        Node* next;

        // DEFAULT CONSTRUCTOR DEFINED BY ME
        Node(int val=0){
            data = val;
            next = NULL;
        }

        // DESTRUCTOR DEFINED BY ME
        ~Node(){
            // nothing to do here
        }

};


//  MAKING A LINKED LIST CLASS.
class LINKED_LIST{

    public:

        Node* head;
        Node* tail;

    public:

        // DEFAULT CONSTRUCTOR DEFINED BY ME
        LINKED_LIST(){
            head = NULL;
            tail = NULL;
        }

        // PRINT FUNCTION.
        void print(){
            Node* temp = head;
            while(temp!= NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }

        // INSERT AT TAIL.
        void INSERT_END(int val=0){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
        }


        // FUNTION TO REMOVE THE LOOP IN LINKED LIST..
        void REMOVE_LOOP(Node* head) {
            
            if(head==nullptr || head->next==nullptr){
                return;
            }
        
            Node *slow=head;
            Node* fast=head;
        
            slow = slow->next;
            fast = fast->next->next;
        
            // USING FLOYD'S CYCLE
            while(fast && fast->next){
                if(slow==fast){
                    break;
                }
                slow = slow->next;
                fast = fast->next->next;
            }
        
            // If loop exists
            if(slow==fast){
                
                slow = head;

                if(slow==fast){
                    while(fast->next != slow){
                        fast = fast->next;
                    }
                }
                else{
                    
                    while(slow->next!=fast->next){
                        slow = slow->next;
                        fast = fast->next;
                    }
                }
        
                fast->next = nullptr;
            }
        }

        // DESTRUCTOR DEFINED BY ME
        ~LINKED_LIST(){
            Node* temp = head;
            while(temp!= NULL){
                Node* next_node = temp->next;
                delete temp;
                temp = next_node;
            }
        }
};


// OUR MAIN FUNCTION WITH ONLY ONE TEST CASE...
int main(){

    // CREATING A LINKED LIST.
    LINKED_LIST list;

    // INSERTING ELEMENTS AT THE END OF THE LINKED LIST.
    for(int i=1; i<=5; i++){
        list.INSERT_END(i);
    }

    // PRINTING THE LINKED LIST.
    cout << "Original Linked List: ";
    list.print();

    // CREATING A LOOP IN THE LINKED LIST.
    list.tail->next = list.head->next->next;
    
    // PRINTING THE LINKED LIST AFTER LOOP CREATION.
    cout << "Linked List after loop creation: ";
    list.print();
    
    // REMOVING THE LOOP IN THE LINKED LIST.
    list.REMOVE_LOOP(list.head);
    
    // PRINTING THE LINKED LIST AFTER LOOP REMOVAL.
    cout << "Linked List after loop removal: ";
    list.print();
    
    
    
    // RETURN 0 TO INDICATE SUCCESS.
return 0;
}