#include<bits/stdc++.h>


using namespace std;

// MAKING A NODE CLASS FOR BST.
class Node{
    public:

        int data;
        Node* left;
        Node* right;

    public:

        // CONSTRUCTOR (UDDC).
        Node(int data=0){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

         // DESTRUCTOR (UDDD).
         ~Node(){
            delete left;
            delete right;
        }

};

// MAKING A BST CLASS.
class BST{

    public:

        Node* root;

    public:

        // CONSTRUCTOR.
        BST(){
            this->root=nullptr;
        }

        // INSERTION FUNCTION FOR BST.
        void INSERT(Node* h){
            if(root==nullptr){
                root = h;
            }

            // CASE JAHA PRR ANY WALI NODE KA DATA LESS THEN HY HMARI NODE K DATA SE, SO LEFT PRR DAL DENN GY.
            if(root->data >= h->data){
                if(root->left==nullptr){
                    root->left = h;
                }
                else{
                    INSERT(root->left);
                }
            }
            // CASE JAHA PRR ANY WALI NODE KA DATA GREATER THEN HY HMARI NODE K DATA SE, SO RIGHT PRR DAL DENN GY.
            else{
                if(root->right==nullptr){
                    root->right = h;
                }
                else{
                    INSERT(root->right);
                }
            }
        }

        // FUNCTION TO CONVERT A TREE TO A MIRROR TREE.
        void MIRROR(Node* r){

            if(r==nullptr){
                return;
            }

            queue<Node*> q;
            q.push(r);

            while(!q.empty()){

                Node* temp = q.front();
                q.pop();

                swap(temp->left, temp->right);
                if(temp->left!= nullptr){
                    q.push(temp->left);
                }
                if(temp->right!= nullptr){
                    q.push(temp->right);
                }
            }
        }


        // PRINT BST LEVEL ORDER.
        void LEVEL_ORDER(Node* root){
            if(root==nullptr){
                return;
            }
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* temp = q.front();
                cout<<temp->data<<" ";
                q.pop();
                if(temp->left!= nullptr){
                    q.push(temp->left);
                }
                if(temp->right!= nullptr){
                    q.push(temp->right);
                }
            }
        }


        // DESTRUCTOR.
        ~BST(){
            delete this->root;
        }
};


int main(){

    BST bst;
    int arr[] = {50, 30, 20, 40, 70, 60, 80 , 100 , 200 , 300};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        bst.INSERT(new Node(arr[i]));
    }
    cout<<"\n ORIGNAL TREE  :: ";
    bst.LEVEL_ORDER(bst.root);
    cout<<endl;
    bst.MIRROR(bst.root);
    cout<<"\n MIRROR TREE   :: ";
    bst.LEVEL_ORDER(bst.root);
    cout<<endl;

return 0;
}