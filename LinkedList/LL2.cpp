
#include<iostream>
using namespace std;

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
        //using recursive call in the destructor here as delete statement will run it will 
        // gonna call the destructor where the destructor will set the next pointer of the node to nullptr
        // and then it will delete the next pointer to basically deallocate the memory associated to the next pointer
        // and then it will run the cout statement
        if(this->next != nullptr){
            this->next=nullptr;
            delete next;
        }       
        cout<<"memory is free for the node with data: "<<value<<endl;
    }
    // we can only have one destructor per class in c++ 

// Question: How delete works in this code
//     In C++, the delete keyword has two effects:

// Calls the destructor (~Node): When delete is called on an object, its destructor is automatically invoked.
// Frees the memory: After the destructor finishes execution, the memory allocated for the object is returned to the system (deallocated).


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

void deleteNode(Node* &head, Node* &tail, int position){

    // deleting first or start node
    if(position == 1){


        //this condition means that the head is the last node of our linked list if so then 
        // tail would also be pointing to the same node as head then we have to delete tail also
        if(head->next == nullptr){
            // tail=nullptr; //if head is the last node of the Linked List then tail will also be pointing at the same address as head
            delete tail;

            // head = nullptr; //constructor will handle this statement so no need for head = nullptr but in case of tail = nullptr there is no need
            //for that statement because when the second last node was deleted the tail was = prev and prev->next was nullptr so already tail->next = nullptr
            delete head;

            // delete temp;//deleting temp also in the end this is end of end for the linked list as there was only one node was left now there is 
            // no need for the head , tail and temp pointers initiated for the traversal and then deletion.
            return;
        }

        Node* temp = head;

        head = head -> next;  //in last step what will happen here is that head will point to nullptr if head is the only node in the linked list


        // memory free start node

        // temp->next=nullptr; here we don't need this line as we have give the same functionality in the desctructor
        
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
        if(curr->next==nullptr){
            tail = prev; //managing tail pointer
           
        }
        // curr->next = nullptr; here we don't need this line as we have give the same functionality in the desctructor
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

    deleteNode(head,tail,1);

    print(head);

    deleteNode(head,tail,3);

    print(head);

    deleteNode(head,tail,3);

    print(head);

    deleteNode(head,tail,2);
    
    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deleteNode(head,tail,1);

    // cout<<"Head "<<head->data<<endl;
    // cout<<"tail "<<tail->data<<endl;


    return 0;
}