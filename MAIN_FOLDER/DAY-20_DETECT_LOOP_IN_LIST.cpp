#include<bits/stdc++.h>


// YOU CAN JUST COPY THE FUNCTION IF YOU NEED IT. THANKS

using namespace std;

// MAKING A NODE CLASS.
class Node{

    public:

        int data;
        Node* next;

        // USER DEFINED DEFAULT CONSTRUCTOR.
        Node(int d=0){
            this->data = d;
            this->next = NULL;
        }

        // DESTRUCTOR.
        ~Node(){
            // I AM DOING NOTHING HERE...
        }
};

// MAKING A LINKED LIST CLASS.
class LINKED_LIST{

    public:

        Node* head;
        Node* tail;

    public:

        // USER DEFINED DEFAULT CONSTRUCTOR.
        LINKED_LIST(){
            this->head = NULL;
            this->tail = NULL;
        }

        // INSERTION FUNCTION TO INSERT DATA AT HEAD.
        void INSERT_HEAD(int data){

            if(head == NULL){
                head = new Node(data);
                tail = head;
                return;
            }
            
            Node* new_node = new Node(data);
            new_node->next = head;
            head = new_node;
        }

        // FUNCTION TO DETECT LOOP IN LINKED LIST.
        bool DETECT_LOOP(Node* head) {
        
            Node* slow=head;
            Node* fast=head;
            
            while(fast && fast->next){
                
                slow = slow->next;
                fast = fast->next->next;
                
                if(slow==fast){
                    return true;
                }
            }
            
            return 0;
        }


        // FUNCTION TO DISPLAY THE LINKED LIST.
        void DISPLAY(Node* hd){
            
            Node* temp = hd;

            cout<<"\n LINKED LIST  ::  {  ";
            while(temp!=NULL){
                cout<<temp->data<<"  ";
                temp = temp->next;
            }
            cout<<"  }\n";
        }

        // DESTRUCTOR.
        ~LINKED_LIST(){
            Node* temp = this->head;
            while(temp!=NULL){
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
        }
};


//* MAIN FUNCTION *//
int main(){

    // CREATING A LINKED LIST.
    LINKED_LIST ll;
    
    // INSERTING ELEMENTS AT HEAD.
    ll.INSERT_HEAD(20);
    ll.INSERT_HEAD(4);
    ll.INSERT_HEAD(15);
    ll.INSERT_HEAD(85);
    ll.INSERT_HEAD(25);
    
    // DISPLAYING THE LINKED LIST.
    cout<<"\nOriginal Linked List ::  {  ";
    ll.DISPLAY(ll.head);
    
    // CHECKING FOR LOOP.
    if(ll.DETECT_LOOP(ll.head)){
        cout<<"\n LOOP DETECTED.\n";
    }
    else{
        cout<<"\n NO LOOP DETECTED.\n";
    }
    
// EXITING THE PROGRAM.
return 0;
}
