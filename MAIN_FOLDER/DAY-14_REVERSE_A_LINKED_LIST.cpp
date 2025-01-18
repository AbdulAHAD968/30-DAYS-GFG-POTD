#include<bits/stdc++.h>

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

        // FUNCTION TO REVERSE A LINKED LIST.
        Node* REVERSE_LINKED_LIST(Node* head){
        
            Node* temp = head;
            vector<int> res;
            
            while(temp){
                res.push_back(temp->data);
                temp = temp->next;
            }
            
            reverse( res.begin() , res.end() );
                
            Node* new_head = NULL;  
            Node* current = NULL;  

            for(int value : res){
                Node* new_node = new Node(value);
                new_node->next = NULL; 

                if(new_head == NULL){
                    new_head = new_node;
                    current = new_head;
                }
                else{
                    current->next = new_node;
                    current = current->next;
                }
            }
            return new_head;
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
    list->INSERT_HEAD(5);
    list->INSERT_HEAD(3);
    list->INSERT_HEAD(7);
    list->INSERT_HEAD(1);
    
    // DISPLAY THE LINKED LIST.
    cout<<"Original Linked List : ";
    list->DISPLAY();

    // REVERSE THE LINKED LIST.
    Node* new_head = list->REVERSE_LINKED_LIST(list->head);
    
    // DISPLAY THE REVERSED LINKED LIST.
    cout<<"Reversed Linked List : ";
    Node* temp = new_head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
    cout<<"\n";
    
    // DELETE THE LINKED LIST.
    delete list;

    // DELETE THE REVERSED LINKED LIST.
    delete new_head;

    
return 0;
}