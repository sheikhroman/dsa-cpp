#include<bits/stdc++.h>
using namespace std;

class treeNode{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int value){
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void printTree(treeNode *root, int lavel);
void spacePrint(int lavel);

void printTree(treeNode*root, int lavel){
    if(root==NULL){
        return;
    }
    if(root->leftChild==NULL && root->rightChild==NULL){    //case-->1
        cout << root->data << endl;
        return;
    }
    else{                                                  //case--->2
        cout << endl;
        spacePrint(lavel);
        cout << "Root: " << root->data << endl;
    }

    if (root->leftChild != NULL)
    {
        spacePrint(lavel);
        cout << "Left: ";
        printTree(root->leftChild, lavel + 1);
    }

    if (root->rightChild != NULL)
    {
        spacePrint(lavel);
        cout << "Right: ";
        printTree(root->rightChild, lavel + 1);
    }
}

void spacePrint(int lavel){
    for (int i = 0; i < lavel; i++){
        cout << "    ";
    }
}

int main(){

    int n;
    cin >> n;
    treeNode *allNodes[n];
    for (int i = 0; i < n; i++){
        allNodes[i] = new treeNode(-1);
    }
    for (int i = 0; i < n; i++){
        int value, left, right;
        cin >> value >> left >> right;
        allNodes[i]->data = value;
        if(left>n-1 || right>n-1){
            cout << "Invalid Index"<<endl;
            break;
        }
        
        if(left!=-1){
            allNodes[i]->leftChild = allNodes[left];
        }
        if(right!=-1){
            allNodes[i]->rightChild = allNodes[right];
        }
    }
    printTree(allNodes[0], 0);
    return 0;
}
/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

Root: 0
Left:
    Root:1
    left:3
    Right:4
Right:
    Root:2
    Left:
        Root:5
        Left:7
        Right:8
    Right:6


*/