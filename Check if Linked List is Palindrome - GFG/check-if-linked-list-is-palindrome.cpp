//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    Node* getMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* reverseList(Node* head) {
        if(!head) return nullptr;

        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = current->next;

        while(current) {
            current->next = prev;
            prev = current;
            current = nextNode;
            if(nextNode) {
                nextNode = nextNode->next;
            }
        }
        return prev;
    }
    
    bool isPalindrome(Node *head) {
        Node* mid = getMiddle(head);
        Node* secondHead = reverseList(mid);

        while(head && secondHead) {
            if(head->data != secondHead->data) return false;
            head = head->next;
            secondHead = secondHead->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends