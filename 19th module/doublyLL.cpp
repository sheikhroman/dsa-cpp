#include <bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int val;
    doublyNode* prev;
    doublyNode* next;

    doublyNode(int val){
        this->val = val;
        prev = NULL;
        next = NULL;
    }

};
void insertAtTail(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev=temp;
}
void insertAtHead(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void display(doublyNode *n)
{
    while (n != NULL)
    {
        cout << n->val;
        if (n->next != NULL)
            cout << " - - -> ";
        n = n->next;
    }
    cout << endl
         << endl;
}
void displayreverse(doublyNode* &head){
    doublyNode* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while (temp->prev != NULL)
    {
        cout << temp->val;
        if (temp->next != NULL)
            cout << " - - -> ";
        temp = temp->prev;
    }
    cout << endl
         << endl;
}
int countLength(doublyNode *&head)
{
    int count = 0;
    doublyNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    doublyNode *head = NULL;
    int value, position;
    cout << "Choice 1: Insertion Head "
         << endl
         << "Choice 2: Insertion Tail"
         << endl
         << "Choice 3: Reverse Print"
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
            displayreverse(head);
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    cout << endl
         << "Doubly Linkd List: ";
    display(head);
    cout << "Length of the List: " << countLength(head) << endl;
    return 0;
}