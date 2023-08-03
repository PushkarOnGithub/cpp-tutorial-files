#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeInput(){                     // O(n^2) complexity due to second while loop
    int data;
    cin>>data;
    Node *head = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if (head==NULL){
            head = newNode;
        }
        else{
            Node *temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
        cin>>data;
    }
    return head;
}

Node * takeInput_Better(){         // O(n) complexity
    Node *head = NULL;
    Node *tail = NULL;
    int data;
    cin>>data;

    while (data != -1)
    {
        Node *newNode = new Node(data);
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
void print(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int len(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        count += 1;
        temp = temp -> next;
    }
    return count;
}

void print_index(Node *head, int const index){
    int lenth = len(head);
    if (index>=lenth){
        cout<<"List index Out of range"<<endl;
    }
    else{
        int ind = 0;
        while (ind != index)
        {
            head = head -> next;
            ind++;
        }
        cout<<(head->data)<<endl;
        
    }
}

Node* insert_node(Node *head, int const index, int const data){
    int lenth = len(head);
    if(index < 0 || index > lenth){
        cout<<"Opearation Failed"<<endl;
    }
    else if (index == 0){
        Node *newNode = new Node(data);
        newNode ->next = head;
        head = newNode;
        cout<<"Addition Successful"<<endl;
        return head;
    }
    else{
        Node *newNode = new Node(data);
        int ind = 0;
        Node *temp = head;
        for(;ind<index-1;ind++){
            temp = temp -> next;
        }
        newNode -> next = temp ->next;
        temp -> next = newNode;
        cout<<"Addition Successful"<<endl;
        return head;
    }
}

Node * insert_node_recursively(Node *head, int const index, int const data){  
    if(index == 0){
        Node *newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
        return head;
    }
    return insert_node_recursively((head -> next), (index - 1), data);
}


Node * delete_Node(Node *head, int const index){
    int lenth = len(head);
    if(index < 0 || index >= lenth){
        cout<<"Deletion Failed"<<endl;
    }
    else if (index == 0){
        Node *temp = head;
        head = head -> next;
        cout<<"Deletion Successful"<<endl;
        return head;
        delete temp;
    }
    else{
        int ind = 0;
        Node *temp = head;
        for(;ind<index-1;ind++){
            temp = temp -> next;
        }
        temp -> next = (temp -> next)-> next;
        cout<<"Deletion Successful"<<endl;
        delete (temp ->next);
        return head;
    }
}

Node * delete_node_recursively(Node *head, int const index){
    if(index == 0){
        head = (head->next);
        return head;
    }
    else if (index>0){
    return delete_node_recursively(head->next, index-1);
    }
}

int find_node(Node* head, int const element){
    int index = 0;
    Node *temp = head;
    while(temp -> next != NULL){
        if (temp -> data != element){
            temp = temp -> next;
            index++;
        }
        else if(temp -> data == element){
            break;
        }
    }
    if (temp -> data == element){
        return index;
    }
    return -1;
}

int midPoint(Node *head){
    // return (len(head)-1)/2;
    int midpoint = 0;
    Node *slow = head;
    Node *fast = head->next;
    while(fast -> next != NULL){
        fast = (fast -> next) -> next;
        slow = slow -> next;
        midpoint += 1;
        if(fast == NULL){
            break;
        }
    }
    cout<<slow->data<<endl;
    return midpoint;
}

Node *merge_two_sorted_LL(Node *head1, Node *head2){
    Node *h1 = head1;
    Node *h2 = head2;
    Node *head = NULL;
    Node *tail = NULL;
    while(h1!=NULL || h2!=NULL){
        if((h1->data) <= (h2->data)){
            if(head == NULL){
                head = h1;
                tail = h1;
            }
            else{
                tail->next = h1;
                tail = h1;
            }
            h1 = h1 -> next;
        }
        else if ((h1->data) > (h2->data)){
            if(head == NULL){
                head = h2;
                tail = h2;
            }
            else{
                tail -> next = h2;
                tail = h2;
            }
            h2 = h2 -> next;
        }
    }
    tail -> next = h2==NULL ? h1 : h2;
    return head;
}