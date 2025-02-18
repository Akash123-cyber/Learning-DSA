// #include<iostream>

// using namespace std;

// class Node{
//     public:

//         int data;
//         Node* next;

//         Node(int data){
//             this->data = data;
//             this->next=nullptr;

//         }

//         ~Node(){
//             int value = this->data;
//             if(this->next!=nullptr){
//                 this->next = nullptr;
//                 delete next;

//             }

//             cout<<"Node is deleted with the data = "<<value<<endl;
//         }

        
// };

// void insertAtHead(Node* &head,int data){
//     Node* temp = new Node(data);
//     temp->next=head;
//     head = temp; 
// };

// void insertAtTail(Node* &tail,int data){
//     Node* temp = new Node(data);
//     tail->next=temp;
//     tail=temp;
// };

// void insertAtPosition(Node* &head, Node* &tail,int position,int data){
//     //insert at beginning
    
//     if(position == 1){
//         insertAtHead(head,data);
//         return;
//     }

//     //insertion at somewhere in the middle and the last node

//     Node* temp = head;
//     int count = 1;

//     // Traversing through LL 
//     while(count < position-1){ //this condition is important remember it as we are already at node1 post = 1 and 
//     // we need to insert as postion =3 we need to traverse to position =2 only so now the condition is (1<(post = 3)-1)
//     // so basically (1<2) so it will run once and we will reach Node2 as we needed to thats why count< position statement is not required;
//         temp = temp->next;
//         count++;
//     }

//     //last Node
//     if(temp->next==nullptr){
//         insertAtTail(tail,data);
//         return;
//     }

//     //middle
//     Node* newNode = new Node(data);
//     newNode->next = temp->next;
//     temp->next = newNode;

// };

// void DeleteNode(Node* &head,Node* &tail,int position){

//     if (position == 1)
//     {   
//         //this condition means that the head is the last node of our linked list if so then 
//         // tail would also be pointing to the same node as head then we have to delete tail also
//         if (head->next==nullptr)
//         {   
//             delete head;

//             delete tail;

//             return;
//         }
        
        
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//         return;
//     }
//     else{
//         //we require two pointer to track the node which is to be deleted (current) and the Node previous to the current Node (prev) so that
//         // we can re link the linked list 
//         Node* prev = nullptr;
//         Node* curr = head;
//         int count = 1;
//         while (count < position)
//         {
//             prev = curr;
//             curr = curr->next;
//             count++;
//         }

//         //middle or last node deleted; 

//         prev->next = curr->next;
        
//         if(curr->next==nullptr){
//             tail = prev;

//         }
        
//         delete curr;
//     }
        
// };

// void printLinkeList(Node* &head){
//     Node* temp = head;

//     while (temp != nullptr)
//     {   
//         cout<<temp->data<<"--->";
//         temp=temp->next;
//     }
//     cout<<"Nullptr"<<endl;
    
// }
    
// int main(){

//     Node* node1 = new  Node(10);
//     Node* head = node1;
//     Node* tail = node1;

//     insertAtPosition(head,tail,2,20);
//     insertAtPosition(head,tail,3,30);
//     insertAtPosition(head,tail,4,40);
//     insertAtPosition(head,tail,5,50);

//     insertAtPosition(head,tail,3,25);//total node = 6
//     DeleteNode(head,tail,1); //total node = 5

//     printLinkeList(head);

//     DeleteNode(head,tail,3);//total node = 4

//     printLinkeList(head);

//     // DeleteNode(head,tail,5);//thats why segmentation fault cause fifth position doesnt exists.
//     DeleteNode(head,tail,2);

//     printLinkeList(head);
//     DeleteNode(head,tail,1);
//     printLinkeList(head);
//     DeleteNode(head,tail,2);
//     printLinkeList(head);
//     DeleteNode(head,tail,1);
//     //Linked List is compleletly deleted at this point
//     return 0;
// }

#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }

    ~Node(){
        int value = this->data;
        if (this->next!=nullptr)
        {
            this->next = nullptr;
            delete next;
        }
        
        cout<<"Node deleted with the value : "<<value<<endl;
    }

};

void insertAtHead(Node* &head,int data){
    Node* temp = new Node(data);

    temp->next=head;
    
    head=temp;
};

void insertAtTail(Node* &tail,int data){
    Node* temp = new Node(data);

    tail->next = temp;

    tail = temp;
};

void insertAtPosition(Node* &head, Node* &tail, int position, int data){

    //insert at start 
    if (position == 1)
    {
        insertAtHead(head,data);
        return;
    }

    //insert at middle and end
    Node* temp = head;
    int count=1;

    while(count < position -1)
    {
        temp = temp->next;
        count++;
    }
    //end
    if (temp->next==nullptr)
    {
        insertAtTail(tail,data);
    }

    //middle
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
    
};

//delete

void DeleteNode(Node* &head, Node* &tail,int position){

    //delete at start
    if (position==1)
    {   

        if (head->next==nullptr) //basically the last node of the Linked List is going to be deleted
        {
            delete head;

            delete tail;
        }
        
        Node* temp = head;

        head = head->next;
        delete temp;
    
    }

    //Now for Middle and the end
    else{
    Node* curr = head;
    Node* prev = nullptr;
    int count=1;
    while (count < position)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    prev->next=curr->next;
    if (curr->next == nullptr)
    {
        tail = prev;
    }

    
    delete curr;
 }   
    
    
};

void printLinkedList(Node* &head){
    Node* temp = head;

    while (temp->next!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}
int main(){

Node* node1 = new  Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtPosition(head,tail,2,20);
    insertAtPosition(head,tail,3,30);
    insertAtPosition(head,tail,4,40);
    insertAtPosition(head,tail,5,50);

    insertAtPosition(head,tail,3,25);//total node = 6
    DeleteNode(head,tail,1); //total node = 5

    printLinkedList(head);

    DeleteNode(head,tail,3);//total node = 4

    printLinkedList(head);

    // DeleteNode(head,tail,5);//thats why segmentation fault cause fifth position doesnt exists.
    DeleteNode(head,tail,2);

    printLinkedList(head);
    DeleteNode(head,tail,1);
    printLinkedList(head);
    DeleteNode(head,tail,2);
    printLinkedList(head);
    DeleteNode(head,tail,1);

    return 0;
}
