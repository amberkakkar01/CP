#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> res;
        if (!root)
            return res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 1; i <= size; i++)
            {
                Node* curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                if (i == size)
                    res.push_back(curr->data);
            }
        }
        return res;
    }
    void preorder(Node* root, int level, int &maxlevel, vector<int>&res)
    {
        if (!root)
            return;

        if (maxlevel < level)
        {
            res.push_back(root->data);
            maxlevel = level;
        }
        preorder(root->right, level + 1, maxlevel, res);
        preorder(root->left, level + 1, maxlevel, res);
    }
    vector<int> rightViewRecur(Node *root)
    {
        // Your Code
        vector<int> res;
        int maxlevel = 0;
        preorder(root, 1, maxlevel, res);
        return res;
    }
};



// { Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
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


int main() {
    int t;
    string  tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Solution ob;
        vector<int> vec = ob.rightView(root);
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

class Solution
{
public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> rightView;
        if (root == NULL) {
            return rightView;
        }

        queue<Node*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int queue_size = bfs.size();
            for (int size = 0; size < queue_size; size++) {
                Node* curr_element = bfs.front();
                bfs.pop();

                if (size == queue_size - 1) {
                    rightView.push_back(curr_element->data);
                }

                if (curr_element->left)
                    bfs.push(curr_element->left);
                if (curr_element->right)
                    bfs.push(curr_element->right);
            }
        }
        return rightView;
    }
};

class Solution
{
public:
    //Function to return list containing elements of right view of binary tree.
    void rightViewHelper(Node *root, vector<int> &rightView, int level, int &maxLevel) {
        if (root == NULL)
            return;

        if (level > maxLevel) {
            rightView.push_back(root->data);
            maxLevel = max(level, maxLevel);
        }

        rightViewHelper(root->right, rightView, level + 1, maxLevel);
        rightViewHelper(root->left, rightView, level + 1, maxLevel);
    }
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> right_view;
        int level = 0, maxLevel = -1;
        rightViewHelper(root, right_view, level, maxLevel);
        return right_view;
    }
};
