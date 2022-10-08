#include <bits/stdc++.h>

using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(int val) {
        data = val;
        leftChild = NULL;
        rightChild = NULL;
    }

};

void printSpace(int level) {
    for (int i = 0; i < level; i++) {
        cout << "   ";
    }
}

void printTree(TreeNode* root, int level) {
    if (root == NULL) return; //  we was sent first element because it's a main root 
    if (root->leftChild == NULL && root->rightChild == NULL) {
        cout << root->data << endl;
        return;
    }
    else {
        cout << endl;
        printSpace(level);
        cout << "Root  : " << root->data << endl;
    }
    if (root->leftChild != NULL) {
        printSpace(level);
        cout << "Left  : ";
        printTree(root->leftChild, level + 1);
    }
    if (root->rightChild != NULL) {
        printSpace(level);
        cout << "Right : ";
        printTree(root->rightChild, level + 1);
    }

}

void preOrderTraversal(TreeNode* root, string& str) { //   root left right
    if (root == NULL) return;
    str += to_string(root->data);
    preOrderTraversal(root->leftChild, str);
    preOrderTraversal(root->rightChild, str);
}



void printLeftNonLeaves(TreeNode* root) {
    if (root == NULL) return;

    if (root->leftChild != NULL) {
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }
    else if (root->rightChild != NULL) {
        cout << root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }

}

void printRightNonLeaves(TreeNode* root) {
    if (root == NULL) return;
    if (root->rightChild != NULL) {
        cout << root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }
    else if (root->leftChild != NULL) {
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }

}

void printLeaves(TreeNode* root) {
    if (root == NULL) return;
    if (root->leftChild == NULL && root->rightChild == NULL) {
        cout << root->data << " ";
        return;
    }
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);

}

void boundaryTraversal(TreeNode* root) {
    if (root == NULL) return;
    cout << root->data << " ";

    //LB non-leaves
    printLeftNonLeaves(root->leftChild);
    // LB Leaves
    printLeaves(root->leftChild);
    //RB Leaves
    printLeaves(root->rightChild);
    //RB non-leaves
    printRightNonLeaves(root->rightChild);
}





int main() {

    int n;
    cout << "How many nodes you want to add : ";
    cin >> n;
    TreeNode* allNodes[n];

    for (int i = 0; i < n; i++) {
        allNodes[i] = new TreeNode(-1);
    }
    for (int i = 0; i < n; i++) {
        int val, left, right;
        // cout << "value | " << "Left | " << "Right | ";
        cin >> val >> left >> right; // 0 1 2
        allNodes[i]->data = val;
        // cout << n << endl;
        if (left > n - 1 || right > n - 1) {
            cout << "Invalid Index" << endl;
            break;
        }
        if (left != -1) { // Linking node / root / leaf
            allNodes[i]->leftChild = allNodes[left];
        }
        if (left != -1) { // Linking node / root / leaf
            allNodes[i]->rightChild = allNodes[right];
        }
    }
    boundaryTraversal(allNodes[0]);

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

Root  : 0
Left  :
   Root  : 1
   Left  : 3
   Right : 4
Right :
   Root  : 2
   Left  :
      Left  : 7
      Right : 8
   Right : 6

In Order Traversal   : 314075826
Pre Order Traversal  : 013425786
Post Order Traversal : 314075826


9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6
*/