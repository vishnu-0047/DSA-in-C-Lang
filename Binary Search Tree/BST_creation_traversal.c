#include <stdio.h>
#include <stdlib.h>
typedef struct BSTNode{
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
} Node;
Node* insertNode(Node* root,int val){
    if(root==NULL){
        Node* newNode=(Node*)malloc(sizeof(Node));
        newNode->key=val;
        newNode->left=newNode->right=NULL;
        return newNode;
    }
    if(val<root->key){
        root->left=insertNode(root->left,val);
    }
    else if(val>root->key){
        root->right=insertNode(root->right,val);
    }
    return root;
}
void inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->key);
        inOrder(root->right);
    }
}
void preOrder(Node* root){
    if(root!=NULL){
        printf("%d ",root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->key);
    }
}
int main(){
    Node* root=NULL;
    int val,choice,n;
    while(1){
        printf("------BINARY SEARCH TREE------\n");
        printf("\t1. Insert nodes\n\t2. Inorder traversal\n\t3. Preorder traversal\n\t4. Postorder traversal\n\t5. Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter no. of values to insert:");
            scanf("%d",&n);
            for(int i=0;i<n;i++){
                printf("Enter value:");
                scanf("%d",&val);
                root=insertNode(root,val);
            }
            printf("The values are inserted.\n",val);
            break;
        case 2:
            if(root!=NULL){
                inOrder(root);
                printf("\n");
            }
            else printf("Binary Search Tree is empty.\n");
            break;
        case 3:
            if(root!=NULL){
                preOrder(root);
                printf("\n");
            }
            else printf("Binary Search Tree is empty.\n");
            break;
        case 4:
            if(root!=NULL){
                postOrder(root);
                printf("\n");
            }
            else printf("Binary Search Tree is empty.\n");
            break;
        case 5:
            printf("Exited.\n");
            return 0;
        }
    }
}
