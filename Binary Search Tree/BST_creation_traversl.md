# Binary Search Tree (BST) Implementation in C

This repository contains a simple, menu-driven implementation of a **Binary Search Tree (BST)** using C. The program allows users to dynamically insert nodes and perform various depth-first search (DFS) traversals.

## 🚀 Features

The program provides a command-line interface to perform the following operations:
1.  **Insert Nodes**: Add multiple integers into the BST.
2.  **Inorder Traversal**: Displays the elements in ascending order (Left, Root, Right).
3.  **Preorder Traversal**: Displays the elements in the order: Root, Left, Right.
4.  **Postorder Traversal**: Displays the elements in the order: Left, Right, Root.
5.  **Dynamic Memory Management**: Uses `malloc` to allocate memory for nodes at runtime.

## 🛠️ How to Run

### Prerequisites
*   A C compiler (like `gcc`, `clang`, or MinGW for Windows).

### Steps
1.  **Clone the repository**:
    ```bash
    git clone https://github.com/your-username/your-repo-name.git
    cd your-repo-name
    ```
2.  **Compile the code**:
    ```bash
    gcc bst_implementation.c -o bst
    ```
3.  **Run the executable**:
    ```bash
    ./bst
    ```

## 📂 Code Structure

*   `struct BSTNode`: Defines the structure of a tree node (key, left pointer, right pointer).
*   `insertNode()`: A recursive function that places a new value in its correct position based on BST properties (smaller values to the left, larger to the right).
*   `traversal functions`: Recursive implementations of Inorder, Preorder, and Postorder logic.
*   `main()`: Handles the user menu and program flow.

## 📊 Example Usage

```text
------BINARY SEARCH TREE------
        1. Insert nodes
        2. Inorder traversal
        3. Preorder traversal
        4. Postorder traversal
        5. Exit
Enter choice: 1
Enter no. of values to insert: 3
Enter value: 50
Enter value: 30
Enter value: 70
The values are inserted.

Enter choice: 2
30 50 70 
```

## 📝 License
This project is open-source and available under the [MIT License](LICENSE).

***

