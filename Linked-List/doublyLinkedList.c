#include<stdio.h>
#include<stdlib.h>

struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};
typedef struct DNode Node;
Node* head = NULL;
Node* temp;

void insertAtBeginning(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) head->prev = newNode;
    head = newNode;
    printf("%d is inserted at beginning.\n", val);
}

void insertAtEnd(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d is inserted at the end.\n", val);
}

void insertAtPos(int pos, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Invalid position.\n");
            return;
        }
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
    printf("%d is inserted at position %d.\n", val, pos);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    printf("%d is deleted from the beginning.\n", temp->data);
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    if (head->next == NULL) {
        printf("\n%d is deleted from the end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    printf("\n%d is deleted from the end.\n", temp->data);
    free(temp);
}

void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Invalid position.\n");
            return;
        }
    }
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next;
    printf("%d is deleted from position %d.\n", temp->data, pos);
    free(temp);
}

void search(int pos) {
    temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Invalid position.\n");
            return;
        }
    }
    printf("Value at %d position is %d.\n", pos, temp->data);
}

void traverse() {
    temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: [");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf("\t");
        temp = temp->next;
    }
    printf("]\nIndex: ");
    temp = head;
    for (int i = 0; temp != NULL; i++) {
        printf("%d", i);
        if (temp->next != NULL) printf("\t");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int val, choice, pos;
    while (1) {
        printf("------------LINKED LIST MENU------------\n");
        printf("\t1. Insert at beginning\n");
        printf("\t2. Insert at end\n");
        printf("\t3. Insert at position\n");
        printf("\t4. Delete from beginning\n");
        printf("\t5. Delete from end\n");
        printf("\t6. Delete from position\n");
        printf("\t7. Search\n");
        printf("\t8. Display\n");
        printf("\t9. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert:");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 2:
                printf("Enter value to insert:");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 3:
                printf("Enter position(starts at 0):");
                scanf("%d", &pos);
                printf("Enter value:");
                scanf("%d", &val);
                if (pos == 0) insertAtBeginning(val);
                else insertAtPos(pos, val);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position(starts at 0):");
                scanf("%d", &pos);
                if (pos == 0) deleteAtBeginning();
                else deleteAtPos(pos);
                break;
            case 7:
                printf("Enter position to search:");
                scanf("%d", &pos);
                search(pos);
                break;
            case 8:
                traverse();
                break;
            case 9:
                return 0;
            default:
                printf("\nWrong choice!\n");
        }
    }
}
