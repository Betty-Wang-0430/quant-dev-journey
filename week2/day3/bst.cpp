/*

## Trees

A **tree** is a data structure made of nodes connected by edges.

### Binary Tree

Each node has at most **2 children**:

```text
      8
     / \
    3   10
```

### Binary Search Tree (BST)

A BST follows:

```text
left subtree < node < right subtree
```

This makes searching efficient when the tree is balanced.

### BST Search

* Compare the target with the current node.
* If target is smaller → go left.
* If target is larger → go right.
* If equal → found.

Average/balanced case: **O(log n)**
Worst case: **O(n)** if the tree becomes unbalanced.

### Tree Traversals

For:

```text
        8
       / \
      3   10
     / \
    1   6
```

**In-order:**

```text
Left → Node → Right
→ 1 3 6 8 10
```

For a BST, in-order traversal gives the values in **sorted order**.

**Pre-order:**

```text
Node → Left → Right
→ 8 3 1 6 10
```

**Post-order:**

```text
Left → Right → Node
→ 1 6 3 10 8
```

### Important

A BST can become unbalanced:

```text
1
 \
  2
   \
    3
     \
      4
```

Then searching becomes **O(n)**.

Balanced trees such as **AVL trees** and **red-black trees** help maintain O(log n) operations.

*/

#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* create_node(int value) {
    return new Node{value, nullptr, nullptr};
}

void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = create_node(value);
        return;
    }
    if (value < root->value) {
        if (root->left == nullptr) {
            root->left = create_node(value);
        } else {
            insert(root->left, value);
        }
    } else if (value > root->value) {
        if (root->right == nullptr) {
            root->right = create_node(value);
        } else {
            insert(root->right, value);
        }
    }  
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    std::cout << root->value << " ";
    inorder(root->right);
}

bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (value == root->value) {
        return true;
    }
    if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void delete_tree(Node* root) {
    if (root == nullptr) {
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

int main() {
    Node* root = create_node(8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);

    std::cout << search(root, 6) << "\n";
    std::cout << search(root, 14) << "\n";
    std::cout << search(root, 7) << "\n";

    delete_tree(root);

    return 0;
}

