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

        // FUNCTION TO ROTATE THE LINKED LIST.
        Node* ROTATE_LINKED_LIST(Node* head, int k) {
        
            Node* temp = head;
            
            vector<int> res;
            
            while(temp){
                res.push_back(temp->data);
                temp = temp->next;
            }
            
            int n = res.size();  
            k = k%n;        //  CASE WHERE ROTATION_ELEMENT IS GREATER THAN THE LIST_SIZE
        
            if(k==0){
                return head;
            }
        
            // BUILTIN FUNCTIONALITY OF VECTOR FOR ROTATION 
            std::rotate(res.begin(), res.begin() + k, res.end());  
        
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
    
    // DISPLAY THE LINKED LIST.
    cout<<"\n ORIGNAL LINKED LIST :: ";
    list->DISPLAY();

    // ROTATE THE LINKED LIST.
    Node* new_head = list->ROTATE_LINKED_LIST(list->head, 3);
    
    // DISPLAY THE ROTATED LINKED LIST.
    cout<<"\n ROTATED LINKED LIST :: ";
    Node* temp = new_head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
    cout<<"\n";
    
    // DELETE THE LINKED LIST.
    delete list;
    
    // DELETE THE ROTATED LINKED LIST.
    delete new_head;

return 0;
}