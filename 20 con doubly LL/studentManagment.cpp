#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
        int rollno;
        string name;
        string phone;
        string section;
        float attend;
        Student *Next;

        Student(int roll,string name1, string phone,string sec, float att)
        {
            rollno = roll;
            name = name1;
            phone = phone;
            section = sec;
            attend = att;
            Next = NULL;
    }
};
void insert(Student* &head, int roll, string name, string phone, string section, float attend){
    Student *newNode = new Student(roll, name, phone, section, attend);
    if(head==NULL){
        head = newNode;
        return;
    }
    Student *temp = head;
    while(temp->Next != NULL){
        temp = temp->Next;
    }
    temp->Next = newNode;
}
void display(Student *node){
    while(node!=NULL){
        cout << node->rollno << endl;
        cout << node->name << endl;
        cout << node->phone << endl;
        cout << node->section << endl;
        cout << node->attend << endl;
        node = node->Next;

        cout << endl;
        cout << endl;
    }
}

int main(){

    Student *head;
    int option;
    int rollno;
    string name;
    string phone;
    string section;
    float attend;
    do
    {
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter roll no" << endl;
            cin >> rollno;
            cout << "Enter your name" << endl;
            cin >> name;
            cout << "Enter your phone" << endl;
            cin >> phone;
            cout << "Enter your section" << endl;
            cin >> section;
            cout << "Enter your attend" << endl;
            cin >> attend;
            insert(head, rollno, name, phone, section, attend);
            break;

        case 2:
            display(head);
            break;
            // case 3:
            // case 4:
            // case 5:
        }
    }

    return 0;
}