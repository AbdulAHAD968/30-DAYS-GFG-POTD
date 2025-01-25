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


        Node* FIRST_LOOP_NODE(Node* head) {
        
            Node* slow = head;
            Node* fast = head;
            
            while(slow && fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
                
                if(fast==slow){
                    // LOOP DETECTED, NOW WILL LOOK  FOR THE NODE.
                    slow = head;
                    while(slow!=fast){
                        slow = slow->next;
                        fast = fast->next;
                    }
                    return slow;
                }
            }
            
            return nullptr;
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
    
    // INSERTING ELEMENTS TO THE LINKED LIST.
    list.INSERT_END(1);
    list.INSERT_END(2);
    list.INSERT_END(3);
    list.INSERT_END(4);
    list.INSERT_END(5);
    
    cout << "Original Linked List: ";
    list.print();
    
    Node* loop_node = list.FIRST_LOOP_NODE(list.head);
    
    if(loop_node!= nullptr){
        cout << "Loop Detected at Node: " << loop_node->data << endl;
    } else {
        cout << "No Loop Detected" << endl;
    }
    
    return 0;
}