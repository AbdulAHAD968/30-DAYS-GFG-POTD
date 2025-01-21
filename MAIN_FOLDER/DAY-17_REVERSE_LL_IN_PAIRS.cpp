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


        // FUNCTION TO REVERSE LINKED LIST IN PAIRS OF A NUMBER SAY->[K]
        Node* REVERSE_K_GROUP(Node* head, int k) {
            
            Node* curr = head;
            Node* prev = NULL;
            Node* tmp = NULL;

            int count = 0;

            // COUNT THE NUMBER OF NODES, KEEPING IN MIND WE HAVE TO REVERSE K OR FEWER NODES.
            tmp = head;
            int size=0;

            while(tmp){
                size++;
                tmp = tmp->next;
            }

            // Reverse k nodes (or fewer if the remaining size < k)
            tmp = head;
            while(curr && count<k){
                tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
                count++;
            }

            // RECURSIVELY PROCESS THE REMAINING LIST.
            if(tmp){
                head->next = REVERSE_K_GROUP(tmp, k);
            }

            return prev;    // RETURN NEW HEAD AFTER REVERSING.
        }


        // FUNCTION TO DISPLAY THE LINKED LIST.
        void DISPLAY(){
            
            Node* temp = this->head;

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

    // CREATE A LINKED LIST.
    LINKED_LIST* list = new LINKED_LIST();
    
    // INSERTING ELEMENTS AT HEAD.
    list->INSERT_HEAD(1);
    list->INSERT_HEAD(2);
    list->INSERT_HEAD(3);
    list->INSERT_HEAD(4);
    list->INSERT_HEAD(5);
    list->INSERT_HEAD(6);
    list->INSERT_HEAD(7);
    list->INSERT_HEAD(8);
    list->INSERT_HEAD(9);
    list->INSERT_HEAD(10);
    list->INSERT_HEAD(11);
    list->INSERT_HEAD(12);

    // DISPLAYING THE LINKED LIST.
    cout<<"LIST BEFORE REVERSING   ::   ";
    list->DISPLAY();


    // REVERSING THE LINKED LIST IN PAIRS OF 3.
    Node* new_head = list->REVERSE_K_GROUP(list->head, 3);
    
    // DISPLAYING THE LINKED LIST AFTER REVERSING.
    cout<<"\nLIST AFTER REVERSING   ::   ";
    list->DISPLAY();
    
    // FREEING MEMORY.
    delete list;
    delete new_head;    

return 0;
}