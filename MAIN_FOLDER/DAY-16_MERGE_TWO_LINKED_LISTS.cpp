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


        // FUNCTION TO MERGE TWO SORTED LINKED LIST.
        Node* sortedMerge(Node* head1, Node* head2) {
        
            vector<int> res;
            
            while(head1){
                res.push_back(head1->data);
                head1 = head1->next;
            }
            
            while(head2){
                res.push_back(head2->data);
                head2 = head2->next;
            }
            
            // JUGAR 2.0 (lol):
            sort( res.begin() , res.end() );
            
            // CREATING A NEW LINKED LIST. 
            Node* new_head = nullptr;  
            Node* current = nullptr;  
        
            // NOW CREATING A NEW LINKED LIST 
            for(int value : res){
                
                Node* new_node = new Node(value);  
                
                if(!new_head){
                    new_head = new_node; 
                    current = new_node;  
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
    list->INSERT_HEAD(6);
    list->INSERT_HEAD(4);

    // DISPLAYING THE LINKED LIST.
    cout<<"LIST-1 BEFORE MERGE   ::   ";
    list->DISPLAY();

    // CREATE SECOND LINKED LIST.
    LINKED_LIST* list2 = new LINKED_LIST();
    list2->INSERT_HEAD(9);
    list2->INSERT_HEAD(8);
    list2->INSERT_HEAD(2);
    list2->INSERT_HEAD(0);
    
    // DISPLAYING THE SECOND LINKED LIST.
    cout<<"\LIST-2 BEFORE MERGE   ::   ";
    list2->DISPLAY();
    
    // MERGING THE TWO LINKED LIST.

    Node* merged_list = list->sortedMerge(list->head, list2->head);
    
    // DISPLAYING THE MERGED LINKED LIST.
    cout<<"\nLIST-[1&2] AFTER GETTING MERGED  ::   ";
    list->DISPLAY();
    
    // FREEING MEMORY.
    delete list;
    delete list2;
    delete merged_list;

return 0;
}