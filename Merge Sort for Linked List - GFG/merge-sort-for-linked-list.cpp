//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    Node* merge(Node* list1, Node* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
    
        Node* dummy = new Node(-1);
        Node* current = dummy;
    
        while(list1 && list2) {
            if(list1->data <= list2->data) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
    
        current->next = list1 ? list1 : list2;
        return dummy->next;
    }
    
    Node* getMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;
    
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
    
        if(prev) prev->next = nullptr;
        return slow;
    }
    
    Node* solve(Node* head) {
        if(!head || !head->next) return head;
    
        Node* mid = getMiddle(head);
        Node* left = solve(head);
        Node* right = solve(mid);
    
        return merge(left, right);
    }
  
    Node* mergeSort(Node* head) {
        return solve(head);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends