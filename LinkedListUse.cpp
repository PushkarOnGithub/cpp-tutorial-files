#include <iostream>
#include <bits/stdc++.h>

#include "LinkedListClass.h"

using namespace std;

int main(){

    // Node *node1 = new Node(10);
    // Node *node2 = new Node(20);
    // Node *node3 = new Node(20);
    // Node *node4 = new Node(20);
    // node1 -> next = node2;
    // node2 -> next = node3;
    // node3 -> next = node4;
    // print(node2);

    /*
    Node *head = takeInput_Better();
    int index = 0;
    Node *temp = insert_node_recursively(head, index, 99);
    Node *temp2 = head;
    for(int i = 0; i< index-1; i++){
        temp2 = temp2 -> next;
    }
    if (index != 0)temp2 -> next = temp;
    else head = temp;
    print(head)
    */

    /*
    Node *head = takeInput_Better();
    int index = 0;
    Node *temp = delete_node_recursively(head, index);
    Node *temp2 = head;
    for(int i = 0;i<index-1;i++){
        temp2 = temp2 ->next;
    }
    if (index!=0) temp2->next = temp;
    else head = temp;
    print(head);
    */
    
    // Node *head = takeInput_Better();
    // cout<<find_node(head, 1)<<endl;

    Node *head1 = takeInput_Better();
    Node *head2 = takeInput_Better();
    Node *head3 = merge_two_sorted_LL(head1, head2);
    print(head3);
}   


