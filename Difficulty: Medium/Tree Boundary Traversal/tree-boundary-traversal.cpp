//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node *node) {
    return node->left == nullptr && node->right == nullptr;
}

// Function to collect the left boundary nodes
void collectBoundaryLeft(Node *root, vector<int> &res) {
    if (root == nullptr)
        return;

    Node *curr = root;
    while (!isLeaf(curr)) {
        res.push_back(curr->data);

        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

// Function to collect the leaf nodes using Morris Traversal
void collectLeaves(Node* root, vector<int>& res) {
    Node* current = root;

    while (current) {
        if (current->left == nullptr) {
          
            // If it's a leaf node
            if (current->right == nullptr) 
                res.push_back(current->data);
            
            current = current->right;
        } 
          else {
          
            // Find the inorder predecessor
            Node* predecessor = current->left;
            while (predecessor->right && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            } 
              else {
                  // If it's predecessor is a leaf node
                if (predecessor->left == nullptr) 
                    res.push_back(predecessor->data);
                
                predecessor->right = nullptr;
                current = current->right;
            }
        }
    }
}

// Function to collect the right boundary nodes
void collectBoundaryRight(Node *root, vector<int> &res) {
    if (root == nullptr)
        return;

    Node *curr = root;
    vector<int> temp;
    while (!isLeaf(curr)) {
      
        temp.push_back(curr->data);

        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; --i)
        res.push_back(temp[i]);
}

// Function to perform boundary traversal
vector<int> boundaryTraversal(Node *root) {
    vector<int> res;

    if (!root)
        return res;

    // Add root data if it's not a leaf
    if (!isLeaf(root))
        res.push_back(root->data);

    // Collect left boundary
    collectBoundaryLeft(root->left, res);

    // Collect leaf nodes
    collectLeaves(root, res);

    // Collect right boundary
    collectBoundaryRight(root->right, res);

    return res;
}

};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends