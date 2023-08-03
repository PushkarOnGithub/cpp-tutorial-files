#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

#include "BinaryTreeClass.h"

BinaryTreeNode<int> * takeInput(){
    int rootData;
    cout<<"Enter Data : ";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;

    return root;
}

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

void printTree(BinaryTreeNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<" :";
    if(root->left != NULL){
        cout<<" L "<<root->left->data;
    }
    if(root->right != NULL){
        cout<<" R "<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
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

int countNodes(BinaryTreeNode<int> *root){
    if(root == NULL) return 0;
    int ans = 1;
    ans += countNodes(root->left);
    ans += countNodes(root->right);
    return ans;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isPresent(BinaryTreeNode<int> *root, int k){
    int ans = 0;
    if(root->data == k) ans += 1;
    if(root->left != NULL) ans += isPresent(root->left, k);
    if(root->right != NULL) ans += isPresent(root->right, k);

    return ans;
}

void mirrorTree(BinaryTreeNode<int> *root){
    if(root == NULL) return ;
    if(root->right != NULL){
        BinaryTreeNode<int> *temp = root->right;
        root->right = root->left;
        root->left = temp;
        if(root->left != NULL) mirrorTree(root->left);
        mirrorTree(root->right);
    }
    else if(root->left != NULL){
        BinaryTreeNode<int> *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        if(root->right != NULL) mirrorTree(root->right);
    }
}

void preOrder(BinaryTreeNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    if(root->left != NULL){
        preOrder(root->left);
    }
    if(root->right != NULL){
        preOrder(root->right);
    }
}

void postOrder(BinaryTreeNode<int> *root){
    if(root == NULL) return;
    if(root->left != NULL) postOrder(root->left);
    if(root->right != NULL) postOrder(root->right);
    cout<<root->data<<" ";
}

void inOrder(BinaryTreeNode<int> *root){
    // Firstly left printed then node and then right gets printed
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

BinaryTreeNode<int> * buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE){
    if(inS > inE) return NULL;

    int rootData = pre[preS];
    int rootIndex = -1;
    for(int i = inS;i <= inE;i++){
        if(in[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    int linS = inS;
    int linE = rootIndex - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;  // lpreE - lpreS = linE - linS

    int rpreS = lpreE + 1;
    int rpreE = preE; 
    int rinS = rootIndex + 1;
    int rinE = inE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, linS, linE, lpreS, lpreE);
    root->right = buildTreeHelper(in, pre, rinS, rinE, rpreS, rpreE);

    return root;
}

BinaryTreeNode<int> * buildTree(int *in, int *pre, int size){
    return buildTreeHelper(in, pre, 0, size-1, 0, size-1);
}

vector<int> * NodePath(BinaryTreeNode<int> *root, int k){
    if(root == NULL){
        return NULL;
    }
    if(root->data == k){
        vector<int> *v = new vector<int>();
        v->push_back(root->data);
        return v;
    }
    vector<int> *leftOutput = NodePath(root->left, k);
    if(leftOutput != NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = NodePath(root->right, k);
    if(rightOutput != NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    return NULL;
}

int main()
{
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;

    // BinaryTreeNode<int> *root = takeInputLevelWise();
    // printTreeLevelWise(root);
    // cout<<"The number of nodes is "<<countNodes(root);
    // cout<<"The Node "<<9<<" is present in the Tree : "<<isPresent(root, 3)<<endl;
    // // mirrorTree(root);
    // // printTreeLevelWise(root);
    // preOrder(root); cout<<endl;
    // postOrder(root); cout<<endl;
    // inOrder(root); cout<<endl;

    // int in[9] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    // int pre[9] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    // cout<<"The number of nodes is "<<countNodes(root)<<endl;;
    // vector<int> *v = NodePath(root, 9);
    // for(int i = 0;i < v->size();i++){
    //     cout<<v->at(i);
    //     if(i != v->size()-1) cout<<" <-- ";
    // }
    delete root;
    return 0;
}
