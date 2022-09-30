#include<bits/stdc++.h>
#include<string>
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
void inOrder(treeNode *root, string &chk);

void inOrder(treeNode *root,string &chk){
    if(root==NULL)
    return;
    
    inOrder(root->leftChild, chk);
    chk += to_string(root->data);
    inOrder(root->rightChild, chk);
}
void preOrderTraversal(treeNode *root,string &chk){
    if(root==NULL)
    return;

    chk += to_string(root->data);
    inOrder(root->leftChild, chk);
    inOrder(root->rightChild, chk);
}
void postOrder(treeNode *root,string &chk){
    if(root==NULL)
    return;
    
    inOrder(root->leftChild, chk);
    inOrder(root->rightChild, chk);
    chk += to_string(root->data);
}

void printTree(treeNode * root,int lavel){
    if(root==NULL){
        return;
    }
    if(root->leftChild==NULL && root->rightChild==NULL){
        cout << root->data << endl;
        return;
    }
    else{
        cout << endl;
        spacePrint(lavel);
        cout << "Root: " << root->data << endl;
    }
    if(root->leftChild!=NULL){
        spacePrint(lavel);
        cout << "Left: ";
        printTree(root->leftChild, lavel + 1);
    }
    if(root->rightChild!=NULL){
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

int searchInOrder(int inOrder[], int current, int start, int end){
    for (int i = start; i <= end; i++){
        if(inOrder[i]==current){
            return -1;
        }
    }
    return -1;
}
treeNode * buildTreePreIn(int preOrder[],int inOrder[], int start, int end){
    static int id = 0;
    int current = preOrder[id];
    id++;
    treeNode *newNode = new treeNode(current);
    if(start==end){
        return newNode;
    }
    int pos = searchInOrder(inOrder, current, start, end);
    newNode-> leftChild= buildTreePreIn(preOrder, inOrder, start, pos - 1);
    newNode->rightChild= buildTreePreIn(preOrder, inOrder, pos + 1, end);
    return newNode;
}


int main(){
    

    int n;
    cin >> n;
    int preOrder[n], inOrder[n];
    for (int i = 0; i < n;i++){
        cin >> preOrder[i];
    }
    for (int i = 0; i < n;i++){
        cin >> inOrder[i];
    }
    treeNode *root = buildTreePreIn(preOrder, inOrder, 0, n - 1);
    string chkPre ="";
    preOrderTraversal(root, chkPre);
    cout << chkPre << endl
         << endl;
    return 0;
}


/*
9
0 3 1 4 2 5 7 8 6
0 3 1 4 7 5 8 2 6
3 1 4 0 7 5 8 2 6

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

InOrder Traversal: 314075826
PreOrder Traversal: 031475826
PostOrder Traversal: 314758260
*/