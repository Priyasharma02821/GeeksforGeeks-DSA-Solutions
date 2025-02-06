//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Recursive function to build the binary tree.
Node *buildTreeRecur(unordered_map<int,int> &mp, vector<int> &preorder, 
                         int &preIndex, int left, int right) {

    // For empty inorder array, return null
    if (left > right)
        return nullptr;

    int rootVal = preorder[preIndex];
    preIndex++;

    // create the root Node
    Node *root = new Node(rootVal);

    // find the index of Root element in the in-order array.
    int index = mp[rootVal];

    // Recursively create the left and right subtree.
    root->left = buildTreeRecur(mp, preorder, preIndex, left, index - 1);
    root->right = buildTreeRecur(mp, preorder, preIndex, index + 1, right);

    return root;
}

// Function to construct tree from its inorder and preorder traversals
Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
    
      // Hash map that stores index of a root element in inorder array
      unordered_map<int,int> mp;
      for (int i = 0; i < inorder.size(); i++) 
          mp[inorder[i]] = i;
  
      int preIndex = 0;
    Node *root = buildTreeRecur(mp, preorder, preIndex, 0, inorder.size() - 1);

    return root;
}
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends