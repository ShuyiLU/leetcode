/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        dfs(root);
        if (head) head->left=la;
        if (la) la->right=head;
        return head;
    }
private:
    void dfs(Node* root) {
        if (!root) return;
        dfs(root->left);
        if (!la) head=root;
        else {
            la->right=root;
            root->left=la;
        }
        la=root;
        dfs(root->right);
    }
    Node *head=NULL, *la=NULL;
};
