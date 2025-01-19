//{ Driver Code Starts
// Initial Template for C++
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

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


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

class Solution {
  public:
   Node* rotate(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    // Step 1: Find the length of the list
    Node* temp = head;
    int length = 1;
    while (temp->next != NULL) {
        length++;
        temp = temp->next;
    }

    // Step 2: Adjust k if it's greater than the length
    k = k % length;
    if (k == 0) {
        return head;
    }

    // Step 3: Find the new tail (node at position length - k - 1) and new head (node at position k)
    temp->next = head;  // Make the list circular
    int stepsToNewHead = k;
    Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = NULL;  // Break the circular list

    return newHead;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends