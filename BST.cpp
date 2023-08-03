#include <iostream>
#include <bits/stdc++.h>

#include "BinaryTreeClass.h"
#include "LinkedListClass.h"
#include "PairClass.h"

using namespace std;

BinaryTreeNode<int> * takeInputLevelWise(){
    int rootData;
    cout<<"Enter Root Data : ";
    cin>>rootData;
    if(rootData == -1) return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(not pendingNodes.empty()){
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<front->data<<" : ";
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout<<"Enter right child of "<<front->data<<" : ";
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void printTreeLevelWise(BinaryTreeNode<int> *root){
    if(root == NULL) return;
    queue <BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(not pendingNodes.empty()){
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" : ";
        if(front->left != NULL){
            cout<<"L "<<front->left->data;
            pendingNodes.push(front->left);
        }
        if(front->right != NULL){
            cout<<" R "<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

bool SearchBST(BinaryTreeNode<int> *root, int k){
    if(root == NULL) return 0;
    if(root->data == k) return 1;
    if(root->data > k) return SearchBST(root->left, k);
    if(root->data < k) return SearchBST(root->right, k);
}

void printNodesInRange(BinaryTreeNode<int> *root, int min, int max){
    if(root == NULL){return ;}
    if(root->data <= max and root->data >= min){
        cout<<root->data<<" ";
        printNodesInRange(root->left, min, max);
        printNodesInRange(root->right, min, max);
    }
    if(root->data > max){
        printNodesInRange(root->left, min, max);
    }else if(root->data < min){
        printNodesInRange(root->right, min, max);
    }
}

int maximum(BinaryTreeNode<int> *root){
    if(root == NULL) return INT_MIN;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int> *root){
    if(root == NULL) return INT_MAX;
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root){  // time complexity is bad = (number of nodes * height of the tree)
    if(root == NULL) return true;
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data > leftMax) && (root->data < rightMin) && (isBST(root->left)) && (isBST(root->right));

    return output;
}

class isBSTOutput{
    public:
    bool isBST;
    int min;
    int max;

    isBSTOutput(bool isBST, int min, int max){
        this->isBST = isBST;
        this->min = min;
        this->max = max;
    }
};

isBSTOutput isBST2(BinaryTreeNode<int> *root){
    if(root == NULL){
        isBSTOutput output(true, INT_MAX, INT_MIN);
        return output;
    }
    isBSTOutput leftOutput = isBST2(root->left);
    isBSTOutput rightOutput = isBST2(root->right);
    // making output for recursion
    int overall_minimum = min(root->data, min(leftOutput.min, rightOutput.min));
    int overall_maximum = max(root->data, max(leftOutput.max, rightOutput.max));
    bool overall_isBST = (root->data > leftOutput.max) && (root->data < rightOutput.min) && (leftOutput.isBST) && (rightOutput.isBST);

    isBSTOutput output(overall_isBST, overall_minimum, overall_maximum);

    return output;
}

bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL) return true;
    if(root->data <= min || root->data > max){
        return false;
    }
    bool isLeftOK = isBST3(root->left, min, root->data);
    bool isRightOK = isBST3(root->right, root->data, max);
    return isLeftOK && isRightOK;
}

BinaryTreeNode<int> * BSTfromSortedArray(int *arr, int n){
    if(n%2 != 0){
        int mid = n/2;
        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
        if(n==1) return root;
        root->left = BSTfromSortedArray(arr, n/2);
        root->right = BSTfromSortedArray(arr+mid+1, n/2);
        return root;
    }
    else if(n%2 == 0){
        int mid = n/2;
        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
        root->left = BSTfromSortedArray(arr, n/2);
        if(n!=2) root->right = BSTfromSortedArray(arr+mid+1, (n/2)-1);
        return root;
    }
}

Pair<Node *> LLfromBST(BinaryTreeNode<int> *root){
    if(root == NULL ){
        Pair<Node *> P(NULL, NULL);
        return P;
    }
    Node *rootNode = new Node(root->data);

    Pair<Node *> left = LLfromBST(root->left);
    Node *leftNodehead = left.first;
    Node *leftNodetail = left.second;

    Pair<Node *> right = LLfromBST(root->right);
    Node *rightNodehead = right.first;
    Node *rightNodetail = right.second;

    if(rightNodehead == NULL && leftNodehead == NULL){
        Pair<Node *> P(rootNode, rootNode);
        return P;
    }
    else if(rightNodehead == NULL){
        rightNodehead = rootNode;
        rightNodetail = rootNode;
    }
    else if(leftNodehead == NULL){
        leftNodehead = rootNode;
        leftNodetail = rootNode;
    }

    leftNodetail->next = rootNode;
    rootNode->next = rightNodehead;

    Pair<Node *> P(leftNodehead, rightNodetail);
    return P;
}

int main(){
    // BinaryTreeNode<int> *root = takeInputLevelWise();
    // cout<<(SearchBST(root, 2))<<endl;
    // printNodesInRange(root, 3, 6);
    // cout<<endl;
    // cout<<isBST(root)<<endl;
    // cout<<isBST2(root).isBST<<endl;
    // cout<<isBST3(root)<<endl;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    BinaryTreeNode<int> *root2 = BSTfromSortedArray(arr, 8);
    printTreeLevelWise(root2);
    cout<<isBST(root2)<<endl;
    print(LLfromBST(root2).first);
    return 0;
}