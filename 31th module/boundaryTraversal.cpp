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

int lavelOrderTraversal(treeNode *root, string &chk, int k){
    if(root==NULL){
        return -1;
    }
    int level = 0;
    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);
    int max = -9999;

    while(!q.empty()){
        treeNode *chkNode = q.front();
        q.pop();
        if(chkNode != NULL){
            if(level==k){
                if(max<chkNode->data){
                    max = chkNode->data;
                }
            }
            cout << chkNode->data<<" ";
            chk += to_string(chkNode->data);
            if(chkNode->leftChild!=NULL){
                q.push(chkNode->leftChild);
            }
            if(chkNode->rightChild!=NULL){
                q.push(chkNode->rightChild);
            }
        }
        else{
            if(q.empty()){
                q.push(NULL);
                level++;
            }
        }
    }
    return max;
}

void printLeaves(treeNode * root){
    if(root=NULL)
        return;
    if(root->leftChild==NULL&& root->rightChild==NULL){
        cout << root->data <<" ";
        return;
    }
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}
void printLeftNonLeaves(treeNode * root){
    if(root=NULL)
        return;
        if(root->leftChild!=NULL){
            cout << root->data;
            printLeftNonLeaves(root->leftChild);
        }
        else if(root->rightChild!=NULL){
            cout << root->data;
            printLeftNonLeaves(root->rightChild);
        }
}
void printRightNonLeaves(treeNode * root){
    if(root=NULL)
        return;
        if(root->rightChild!=NULL){
            cout << root->data;
            printLeftNonLeaves(root->rightChild);
        }
        else if(root->leftChild!=NULL){
            cout << root->data;
            printLeftNonLeaves(root->leftChild);
        }
}

void boundaryTravelsal(treeNode *root){
    if(root==NULL)
        return;
    cout << root->data << " ";

    //LB non-Leaves
    printLeftNonLeaves(root->leftChild);
    //LB Leaves
    printLeaves(root->leftChild);
    //RB Leaves
    printLeaves(root->rightChild);
    //RB non_Leaves
    printRightNonLeaves(root->rightChild);
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
    //printTree(allNodes[0], 0);

    string inOrderTraversal = "";
    string preOrderTraversal = "";
    string postOrderTraversal = "";
    string lavelorderTraversal = "";

    // inOrder(allNodes[0], inOrderTraversal);
    // preOrder(allNodes[0], preOrderTraversal);
    // postOrder(allNodes[0], postOrderTraversal);
    //int maxValueAtK =  lavelOrderTraversal(allNodes[0], lavelorderTraversal, 2);
    boundaryTravelsal(allNodes[0]);

    // cout << "InOrder Traversal: " << inOrderTraversal << endl;
    // cout << "PreOrder Traversal: " << preOrderTraversal << endl;
    // cout << "PostOrder Traversal: " << postOrderTraversal << endl;
    //cout   << endl  << maxValueAtK << endl << endl;
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