
#include<iostream>
using namespace std;

// CHECK LL2 also;
class Node {

    public:
    int data;
    Node* next;

    // Creating Constructor

    // Node(int data){
    //     this -> data = data;
    //     this -> next = NULL;
    //     // This is a current instance Referencer of the class
    //     // -> arrow operator 
    //     // we have to use arrow operator for assigning a value to a variable through pointer
    // }

    // Constructor
    Node(int data){
        this ->data = data;
        this ->next = NULL;
    }

    // destructor
    ~Node(){
        int value = this->data;
        //memory free
        // if(this->next != nullptr){
        //     this->next=nullptr;
        //     delete next;
        // }       

        // Here NO need for the above if statement because this statement is not needed as we are deallocating the the next pointer 
        // manually in the below code : like curr->next = nullptr

        cout<<"memory is free for the node with data: "<<value<<endl;
    }


};

void insertAtHead(Node* &head, int d){
    // We have taken the reference cause we don't want to create a copy of the 
    // original Linked list we want these changes to happend to the original linked list 
    // when we take objects without refernce C++ creates a copy of those objects and then performs the respective operations on these objects   

    // new Node creation
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

};

void insertAtTail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp; 

}; 

void insertAtPosition(Node* &head,Node* &tail,int position,int d){

    // Insert at start
    if(position == 1){
        insertAtHead(head, d);
        return;
    }

    // Insert At END
    Node* temp = head;
    int cnt = 1;

    while(cnt < position -1 ){
        temp = temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertAtTail(tail, d);
        return;

    }

    // Insertion at somewhere in the middle of head and tail 
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp->next;
    temp->next = nodeToInsert;
};

void deleteNode(Node* &head, int position){

    // deleting first or start node
    if(position == 1){

        Node* temp = head;
        
        head = head -> next;

        // memory free start node

        temp->next=nullptr;
        
        delete temp;
    }

    // /deleting any middle or last node
    else{

        Node* prev = nullptr;
        Node* curr = head;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr->next;

            count++;
        }

        prev->next=curr->next;
        
        curr->next = nullptr;
        delete curr;
    }

};

void print(Node* &head){
    Node* temp = head;

    while (temp != NULL){
        
        cout<< temp->data << "--->";
        temp = temp->next;
    }
    cout <<"NULL"<< endl;
};


int main(){

    Node* node = new  Node(10);
    Node* head =  node;
    Node* tail = node;
    insertAtTail(tail , 12);
    insertAtTail(tail, 15);
    
    print(head);

    insertAtPosition(head,tail,1,22);
    insertAtPosition(head,tail,5,25);


    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deleteNode(head,1);

    print(head);

    deleteNode(head,3);

    print(head);

    deleteNode(head,2);

    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;


    return 0;
}