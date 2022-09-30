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
void insertionAtSpecificPosition(Node *&head, int pos, int val);
int searchByValueUnique(Node *&head, int key);
void searchByValueDuplicate(Node *&head, int key);
Test searchByValueDuplicateReturn(Node *&head, int key);
void searchByValueUnique(Node *&head, int searchValue, int value);

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}
void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
            cout << " -> ";
        n = n->Next;
    }
    cout << endl
         << endl;
}
int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }
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
int searchByValueUnique(Node *&head, int key){
    Node *temp = head;
    int count = 1;
    if(temp== NULL){
            return -1;
        }
    while(temp->value != key){
        if(temp->Next== NULL){
            return -1;
        }
        temp = temp->Next;
        count++;
    }
    return count;
}
void searchByValueDuplicate(Node *&head, int key){
    Node *temp = head;
    int size;
    size = countLength(head);
    int position[size+1],k = 1;
    int count = 1;
    int flag = 0;
    while(temp!= NULL){
        if(temp->value==key){
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
            count++;
    }
    cout << endl;
    if(flag==0){
        cout << "The search is not fount in this List" << endl;
    }
    else{
        position[0] = k;
        cout << "The value is found at position: ";
        for (int i = 1; i < position[0]; i++){
            cout << position[i];
            if(i<position[0]-1)
                cout << ",";
        }
    }
}
Test searchByValueDuplicateReturn(Node *&head, int key){
    Node *temp = head;
    Test T;
    int k = 1;
    int count = 1;
    while(temp!= NULL){
        if(temp->value==key){
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
            count++;
    }
    T.position[0] = k;
    return T;
}
void searchByValueUnique(Node* &head,int searchValue, int value){
    int position;
    position = searchByValueUnique(head, searchValue);
    insertionAtSpecificPosition(head, position + 1, value);

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
         << "Choice 4: Search a value(UNIQUE LIST)"
         << endl
         << "Choice 5: Search a duplicate value"
         << endl
         << "Choice 6: Insertion after a speific value(UNIQUE LIST)"
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
            cout << "Enter the value to search: ";
            cin >> value;
            position = searchByValueUnique(head, value);
            if(position!= -1){
                cout << "The number is at position " << position << endl;
            }
            else{
                cout << "The number fot found in this List" << endl;
            }
            break;
            case 5:
            cout << "Enter the value to search: ";
            cin >> value;
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if(T.position[0]==1){
                cout << "The number fot found in this List" << endl;
            }
            else{
                int size = T.position[0];
                cout << "The number is at position " << endl;
                for (int i = 0; i < size; i++){
                    cout << T.position[i];
                    if(i<size-1)
                        cout << ",";
                }
                cout << endl;
            }
            cout<< endl;
            
            break;
            case 6:
                cout << "Enter the value to search: ";
                int searchValue;
                cin >> searchValue;
                cout << "Enter the value to insert: ";
                cin >> value;
                searchByValueUnique(head, searchValue, value);
                break;

        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    cout << endl
         << "Linkd List: ";
    display(head);
    cout << "Length of the List: " << countLength(head) << endl;
    return 0;
}