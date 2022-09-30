#include<bits/stdc++.h>
using namespace std;

template<typename N> class Node{
public:
    N value;
    Node *next;
    Node *prev;
    Node(N val){
        value = val;
        next = NULL;
        prev = NULL;
    }
};

template<typename S> class Stack{
    Node <S> *head;
    Node <S> *top;
    int count = 0;

public:

    Stack(){
        head = NULL;
        top = NULL;
    }
    //push
    void push(S val){
        Node <S>*newNode = new Node<S>(val);
        if(head==NULL){
            head = top = newNode;
            count++;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;
    }    
    //pop
    S pop(){
        Node <S>*delNode;
        delNode = top;
        S chk;
        if(head==NULL){
            cout << "Stack Underflow" << endl;
            return chk;
        }
        if(top==head){
            head = top = NULL;
        }else{
            top = delNode->prev;
            top->next = NULL;
        }
        chk = delNode->value;
        delete delNode;
        count--;
        return chk;
    }
    //empty
    bool empty(){
        if(head==NULL)
            return true;
            else
                return false;
    }
    //size
    int size(){
        return count;
    }
    //top
    S Top(){
        S chk;
        if (top == NULL)
        {
            cout << "Stack Underflow there is no element in Top" << endl;
        
    }
    else
        chk = top->value;
        return chk;
    }
};

