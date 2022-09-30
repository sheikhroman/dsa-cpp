#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};
struct Test{
    int position[1000];
};
void insertAtHead(Node *&head, int val);
void insertAtTail(Node *&head, int val);
void display(Node *n);
int countLength(Node *&head);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtSpecificPosition(Node *&head, int position);
void deletironByValueUnique(Node *&head, int value);

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        newNode->Next = head;
        return;
    }
    Node *temp = head;
    while (temp->Next != head)
    {
        temp = temp->Next;
    }
    newNode->Next = head;
    temp->Next = newNode;
}
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->Next = head;
    if(head==NULL){
        head = newNode;
        newNode->Next = head;
        return;
    }
    Node *temp = head;
    while(temp->Next!=head){
        temp = temp->Next;
    }
    temp->Next = newNode;
    head = newNode;
}
void display(Node* head)
{
    Node *temp = head;
    if(head==NULL){
        cout << "The LL is Empty" << endl;
        return;
    }
    do{
        cout << temp->value;
        temp = temp->Next;
        if(temp!=head)
            cout << " -> ";
    } while (temp != head);
}
int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp = temp->Next;
    }
    while (temp != head);
    return count;
}
void insertionAtSpecificPosition(Node *&head, int pos, int val)
{
    int i = 0;
    Node *temp = head;
    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }
    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}
void deletionAtHead(Node* &head){
    Node *temp = head;
    if(temp!=NULL){
        Node *delNode = temp;
        while(temp->Next!=head){
            temp = temp->Next;
        }
        temp->Next = delNode->Next;
        head = delNode->Next;
        delete delNode;
    }
    else{
        cout << "There is no value in Linked List"<<endl;
    }
    
}
void deletionAtTail(Node *&head){
    Node *temp = head;
    if(temp!=NULL && temp->Next!=head){
        while(temp->Next->Next!=head){
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = delNode->Next;
        delete delNode;
    }
    else{
        if(temp==NULL)
            cout << "There is no value in Linked List"<<endl;

        else{
            deletionAtHead(head);
            }
    }
    
}
void deletionAtSpecificPosition(Node *&head, int position)
{
    Node *temp = head;
    if (position<=countLength(head))
    {
        if(position==1){
            deletionAtHead(head);
        }
        else if(position==countLength(head)){
            deletionAtTail(head);
        }
        else{
            int i = 1;
            while (i < position - 1)
            {
                temp = temp->Next;
                i++;
            }
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
        
    }
    else{
        //if(position>countLength(head)){
            cout << "Position out of bound";
       // }
        // else{
        // cout << "There is no value in Linked List"<<endl;
        // }
    }
}

int main()
{
    Node *head = NULL;
    int value, position;
    cout << "Choice 1: Insertion Head "
         << endl
         << "Choice 2: Insertion Tail"
         << endl
         << "Choice 3: Insertion at position"
         << endl
         << "Choice 4: Deletion at head"
         << endl
         << "Choice 5: Deletion at tail"
         << endl
         << "Choice 6: Deletion at speific position"
         << endl
         << "Choice 0: Exit"
         << endl;

    cout << "Next Choice: ";
    int choice;
    cin >> choice;
    while (choice != 0)
    {

        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter the position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insertionAtSpecificPosition(head, position, value);
        break;
        case 4:
            deletionAtHead(head);
            break;
        case 5:
            deletionAtTail(head);
            break;
        case 6:
        if(head==NULL){
            cout << "There is no value in Linked List"<<endl;
            break;
            }
        cout << "Enter the position: ";
            cin >> position;
            deletionAtSpecificPosition(head, position);
            //cout << "Enter the desied Position: ";
            cout << endl;
            display(head);
            
        break;        
        default : break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    cout << endl
         << "Linkd List: ";
    display(head);
    cout << endl;
    cout << "Length of the List: " << countLength(head) << endl;
    return 0;
}