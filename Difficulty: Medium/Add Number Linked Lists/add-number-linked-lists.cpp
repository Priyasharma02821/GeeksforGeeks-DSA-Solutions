//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
   Node *reverse(Node *head) {
    Node *prev = nullptr, *curr = head, *next;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to trim leading zeros in linked list
Node *trimLeadingZeros(Node* head) {
    while(head->next != nullptr && head->data == 0)
        head = head->next;
    return head;
}

// function to find the length of linked list
int countNodes(Node* head) {
    int len = 0;
      Node* curr = head;
  
      while(curr != nullptr) {
        len += 1;
          curr = curr->next;
    }
      return len;
}

// Function to add two numbers represented by linked list
Node *addTwoLists(Node *num1, Node *num2) {
    num1 = trimLeadingZeros(num1);
    num2 = trimLeadingZeros(num2);
  
      // Find the length of both the linked lists
      int len1 = countNodes(num1);
      int len2 = countNodes(num2);
      
      // If num1 is smaller, swap the two linked lists by
      // calling the function with reversed parameters
    if(len1 < len2)
          return addTwoLists(num2, num1);

    int carry = 0;
    num1 = reverse(num1);
    num2 = reverse(num2);
  
    Node *res = num1;
  
    // Iterate till either num2 is not empty or
      // carry is greater than 0
    while (num2 != nullptr || carry != 0) {
      
          // Add carry to num1
        num1->data += carry;

        // If num2 linked list is not empty, add it to num1
        if (num2 != nullptr) {
            num1->data += num2->data;
            num2 = num2->next;
        }
      
        // Store the carry for the next nodes
        carry = num1->data / 10;
          
          // Store the remainder in num1
          num1->data = num1->data % 10;
          
          // If we are at the last node of num1 but carry is 
          // still left, then append a new node to num1
          if(num1->next == nullptr && carry != 0)
            num1->next = new Node(0);
      
          num1 = num1->next;
    }

    // Reverse the resultant linked list to get the
    // required linked list
    return reverse(res);
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends