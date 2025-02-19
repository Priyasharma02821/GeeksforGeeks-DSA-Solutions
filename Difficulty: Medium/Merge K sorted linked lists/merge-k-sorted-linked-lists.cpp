//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    
// Comparator for the priority queue
struct Compare {
    bool operator()(const Node* a, const Node* b) {
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*>& lists) {
    // Min-heap (priority queue) to store the smallest elements
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Push the head of each list into the min-heap
    for (Node* list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    // Dummy node to simplify the code
    Node dummy(0);
    Node* tail = &dummy;

    // While there are elements in the min-heap
    while (!minHeap.empty()) {
        // Get the smallest element from the min-heap
        Node* smallest = minHeap.top();
        minHeap.pop();

        // Add it to the merged list
        tail->next = smallest;
        tail = tail->next;

        // If there are more elements in the list, push the next element into the min-heap
        if (smallest->next) {
            minHeap.push(smallest->next);
        }
    }

    // The merged list starts from the next of the dummy node
    return dummy.next;
}
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends