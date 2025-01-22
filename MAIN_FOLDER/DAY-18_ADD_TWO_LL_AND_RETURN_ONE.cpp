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


        // REVERSE THE LINKED-LIST
        Node* REV_LIST(Node* head){
            
            Node* prev = NULL;  
            Node* current = head;  
            
            while(current){  
                Node* nextNode = current->next;  
                current->next = prev;  
                prev = current;  
                current = nextNode;  
            }  
            return prev;  
        }
        
        // FNCTION TO REMOVE THE LEADING 0'S
        Node* TRIM_LEAD_ZEROS(Node* head){
            
            while(head != nullptr && head->data==0){
                head = head->next;
            }
            return head;
        }
        

        // ADDING TWO LISTS.
        Node* ADD_TWO_LIST(Node* num1, Node* num2){
            
            num1 = TRIM_LEAD_ZEROS(num1);
            num2 = TRIM_LEAD_ZEROS(num2);
            
            num1 = REV_LIST(num1);
            num2 = REV_LIST(num2);
            
            Node* result = NULL; 
            Node* tail = NULL;
        
            int carry = 0;
        
            while(num1!=NULL || num2!=NULL || carry>0){
                
                int data1 = (num1!=NULL) ? num1->data : 0;  
                int data2 = (num2!=NULL) ? num2->data : 0;  
        
                int sum = data1+data2+carry;
                carry = sum/10;
                
                Node* new_node = new Node(sum%10);
                
                if(result==NULL){
                    result = new_node;
                    tail = new_node;
                }
                else{
                    tail->next = new_node;
                    tail = new_node;
                }
        
                if(num1!=NULL){
                    num1 = num1->next;
                }
                if(num2!=NULL){
                    num2 = num2->next;
                }
            }

        // Reverse the result back before returning
        return REV_LIST(result);  
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

    // CREATE A LINKED LIST.
    LINKED_LIST* list = new LINKED_LIST();
    
    // INSERTING ELEMENTS AT HEAD.
    list->INSERT_HEAD(1);
    list->INSERT_HEAD(2);
    list->INSERT_HEAD(3);
    list->INSERT_HEAD(4);
    list->INSERT_HEAD(5);

    // DISPLAYING THE LINKED LIST.
    cout<<"LIST-1 BEFORE ADDITION   ::   ";
    list->DISPLAY(list->head);

    // CREATE ANOTHER LINKED LIST.
    LINKED_LIST* list2 = new LINKED_LIST();
    list2->INSERT_HEAD(6);
    list2->INSERT_HEAD(7);
    list2->INSERT_HEAD(8);
    list2->INSERT_HEAD(9);
    list2->INSERT_HEAD(10);

    // DISPLAYING THE LINKED LIST.
    cout<<"\n LIST-2 BEFORE ADDITION   ::   ";
    list2->DISPLAY(list2->head);

    // ADDING THE TWO LINKED LIST.
    Node* result = list->ADD_TWO_LIST(list->head, list2->head);
    
    // DISPLAYING THE RESULTING LINKED LIST.
    cout<<"\n RESULTING LIST AFTER ADDITION ::   ";
    list->DISPLAY(result);
    
    // DELETE THE LINKED LIST.
    delete list;
    delete list2;
    delete result;
       

return 0;
}