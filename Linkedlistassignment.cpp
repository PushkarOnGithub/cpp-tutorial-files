#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T element){
        data = element;
        next = NULL;
    }
};

template<typename T>
Node<T> *take_input(){
    T data;
    cin>>data;
    Node<T>*head = NULL;
    while(data!=-1){
        T *newNode = new Node<T>(data);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node<T> *temp = head;
            while(temp->next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
        cin>>data;
    }
    return head;
}

template<typename T>
Node<T> *take_input_better(){
    T data;
    cin>>data;
    Node<T>*head=NULL;
    Node<T>*tail=NULL;
    while(data != -1){
        Node<T> *newNode = new Node<T>(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

template<typename T>
void print(Node<T> *head){
    Node <T> *temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

template<typename T>
int leng(Node<T> *head){
    int count = 0;
    Node<T> *temp = head;
    while(temp != NULL){
        count = count + 1;
        temp = temp -> next;
    }
    return count;
}

template<typename T>
void print_index(Node <T> *head, int index){
    int length = leng<T>(head);
    if(index >= length){
        cout<<"List Index out of range"<<endl;
    }
    else{
        Node<T>*temp = head;
        while(index--){
            temp = temp -> next;
        }
        cout<<temp->data<<endl;
    }
}

template<typename T>
T indexData(Node <T> *head, int index){
    int length = leng<T>(head);
    if(index >= length){
        return -1;
    }
    else{
        Node<T>*temp = head;
        while(index--){
            temp = temp -> next;
        }
        return temp->data;
    }
}

template<typename T>
int findNode(Node<T> *head, int k){
    if(head == NULL) return -1;
    Node<T> *temp = head;
    int i = 0;
    while(temp != NULL){
        if(temp->data == k){
            return i;
        }
        temp = temp -> next;
        i++;
    }
    return -1;
}

template<typename T>
Node<T> *copy(Node<T> *head){
    if(head == NULL) return NULL;
    int length = leng(head);
    int i = 0;
    Node<T> *newHead = new Node<T>(indexData(head, i));
    Node<T> *tail = newHead;
    i = i + 1;
    while(i < length){
        Node<T>* newesthead = new Node<T>(indexData(head, i));
        tail->next = newesthead;
        tail = newesthead;
        i = i + 1;
    }
    return newHead;
}

template<typename T>
Node<T> *AppendLastNToFirst(Node<T> *head, int N){
    Node<T> *copyhead = copy(head);
    int length = leng<int>(copyhead);
    if(length <= N or copyhead == NULL){
        cout<<"Task Unsuccessful"<<endl;
        return NULL;
    }
    Node<T> *temp = copyhead;
    Node<T> *tail = NULL;
    Node<T> *newTail = NULL;
    int i = 0;
    while(temp != NULL){
        tail = temp;
        if(i == (length - N - 1)){
            newTail = temp;
        }
        temp = temp->next;
        i++;
    }
    tail->next = copyhead;
    Node<T> *newHead = newTail -> next;
    newTail -> next = NULL;

    return newHead;
}

template<typename T> 
void deleteNode(Node<T> *head, int k){
    if(head == NULL) return ;

    int index = findNode(head, k);
    if(index == -1) return ;

    Node<T> *tail = head;
    index = index - 1;  // to get the node before the deleting node
    if(index == -1){
        head -> data = head->next->data;
        head -> next = head->next->next;
        return;
    }
    while(index>0){
        tail = tail->next;
    }
    tail->next = tail->next->next;
}

template<typename T>
void remove_duplicates(Node<T> *head){
    if(head == NULL) return;

    Node<T> *temp = head;
    vector<T> uniques;
    while(temp != NULL){
        int NOTcontains = 1;
        for(int i = 0;i<uniques.size();i++){
            if(uniques[i] == temp->data){
                deleteNode(head, temp->data);
                NOTcontains = 0;
            }
        }
        if(NOTcontains){
            uniques.push_back(temp->data);
        }
        temp = temp->next;
    }
}

template<typename T>
void print_reverseLL(Node<T> *head){
    vector<T> pendingNodes;
    Node<T> *temp = head;
    while(temp != NULL){
        pendingNodes.push_back(temp->data);
        temp = temp->next;
    }
    for(int i = pendingNodes.size() - 1; i >= 0 ;i--){
        cout<<pendingNodes[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Node<int>*head;
    head = take_input_better<int>();
    print<int>(head);
    // cout<<leng<int>(head)<<endl;
    // print_index<int>(head, 0);
    // cout<<findNode<int>(head, 2)<<endl;
    // Node<int> *newHead = AppendLastNToFirst(head, 3);
    // print<int>(newHead);
    // deleteNode(head, 26);
    // remove_duplicates(head);
    print_reverseLL<int>(head);
    return 0;
}
