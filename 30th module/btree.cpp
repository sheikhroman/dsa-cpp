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
void preOrder(treeNode *root,string &chk){
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
            cout << "Invalid Index" << endl;
            break;
        }
        if(left!=-1){
            allNodes[i]->leftChild = allNodes[left];
        }
        if(left!=-1){
            allNodes[i]->rightChild = allNodes[right];
        }
    }
    printTree(allNodes[0], 0);
    string inOrderTraversal = "";
    string preOrderTraversal = "";
    string postOrderTraversal = "";
    inOrder(allNodes[0], inOrderTraversal);
    preOrder(allNodes[0], preOrderTraversal);
    postOrder(allNodes[0], postOrderTraversal);
    cout << "InOrder Traversal: " << inOrderTraversal << endl;
    cout << "PreOrder Traversal: " << preOrderTraversal << endl;
    cout << "PostOrder Traversal: " << postOrderTraversal << endl;
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

InOrder Traversal: 314075826
PreOrder Traversal: 031475826
PostOrder Traversal: 314758260
*/