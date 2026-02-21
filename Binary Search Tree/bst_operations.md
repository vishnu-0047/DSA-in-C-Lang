# Advanced Binary Search Tree (BST) in C

A comprehensive C implementation of a **Binary Search Tree** data structure. This version includes full support for node insertion, searching, and the complex logic required for node deletion.

## 📌 Overview

This repository demonstrates the fundamental operations of a BST. A Binary Search Tree is a node-based binary tree data structure which has the following properties:
*   The left subtree of a node contains only nodes with keys lesser than the node’s key.
*   The right subtree of a node contains only nodes with keys greater than the node’s key.
*   The left and right subtree each must also be a binary search tree.

## 🚀 Features

The program provides a menu-driven interface for:
1.  **Insert Node**: Adds a value while maintaining the BST property.
2.  **Delete Node**: Removes a value and reorganizes the tree (handles leaf, single-child, and dual-child scenarios using the *Inorder Successor*).
3.  **Search Node**: Efficiently checks if a value exists in $O(\log n)$ average time.
4.  **Display (Inorder)**: Prints the tree elements in sorted (ascending) order.

## 🛠️ Functionality Breakdown

*   `insertNode()`: Standard recursive insertion.
*   `searchNode()`: Recursive search that returns the node pointer if found.
*   `findMin()`: A helper function used during deletion to find the smallest node in the right subtree (Inorder Successor).
*   `deleteNode()`: 
    *   **Case 1**: Node is a leaf (removed directly).
    *   **Case 2**: Node has one child (child replaces the node).
    *   **Case 3**: Node has two children (replaced by the Inorder Successor).

## 💻 How to Build and Run

1.  **Requirement**: Ensure you have a C compiler (GCC).
2.  **Compile**:
    ```bash
    gcc bst_ops.c -o bst_ops
    ```
3.  **Run**:
    ```bash
    ./bst_ops
    ```

## 📊 Example Interaction

```text
------BINARY SEARCH TREE------
        1. Insert node
        2. Delete node
        3. Search node
        4. Display
        5. Exit
Enter choice: 1
Enter data: 50
50 is inserted in BST.

Enter choice: 1
Enter data: 30
30 is inserted in BST.

Enter choice: 3
Enter data to search: 30
Value 30 is found.

Enter choice: 2
Enter value to delete: 50
50 is deleted from BST.
```

## 📂 File Structure
*   `bst_operations.c`: The complete source code containing the logic and the user interface.
*   `bst_operations.md`: Documentation for the project.

