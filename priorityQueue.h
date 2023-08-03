#include<iostream>
#include<vector>

using namespace std;

class BinaryTreeNode{
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* prev;

    BinaryTreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->prev = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

class PriorityQueue{
    vector<int> pq;

    public:

    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }

    void rearrange(){

    }

    void insert(int data){

    }
};