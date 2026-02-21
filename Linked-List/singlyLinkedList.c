//SINGLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct CNode {
    int data;
    struct CNode* next;
};
typedef struct CNode Node;
Node* head=NULL;
Node* temp;

void insertAtBeginning(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=head;
    head=newNode;
    printf("%d is inserted at beginning.\n",val);
}

void insertAtEnd(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    temp=head;
    if (temp==NULL){
        head=newNode;
        newNode->next=NULL;
    }
    else {
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=NULL;
    }
    printf("%d is inserted at the end.\n",val);
}

void insertAtPos(int pos,int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    temp=head;
    for (int i=0;i<pos-1;i++) {
        temp=temp->next;
        if (temp==NULL) {
            printf("Invalid position.\n");
            return;
        }
    }
    newNode->next=temp->next;
    temp->next=newNode;
    printf("%d is inserted at position %d.\n",val,pos);
}
void deleteAtBeginning() {
    temp=head;
    if (head==NULL) {
        printf("List is empty.\n");
        return;
    }
    head=head->next;
    printf("%d is deleted from the beginning.\n",temp->data);
    free(temp);
}

void deleteAtEnd() {
    Node* old=head;
    Node* p=head;
    if (head==NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next==NULL) {
        printf("\n%d is deleted from the end.\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    while (p->next!=NULL) {
        old=p;
        p=p->next;
    }
    printf("\n%d is deleted from the end.\n",p->data);
    free(p);
    old->next=NULL;
}

void deleteAtPos(int pos) {
    temp=head;
    Node* p=head;
    if (temp==NULL) {
        printf("List is empty.\n");
        return;
    }
    for (int i=0;i<pos;i++) {
        p=temp;
        temp=temp->next;
        if (temp==NULL) {
            printf("Invalid position.\n");
            return;
        }
    }
    p->next=temp->next;
    if (temp->next==NULL) p->next=NULL;
    printf("%d is deleted from position %d.\n",temp->data,pos);
    free(temp);

}

void search(int pos) {
    temp=head;
    if (head==NULL) {
        printf("List is empty.\n");
        return;
    }
    for (int i=0;i<pos;i++) {
        temp=temp->next;
        if (temp==NULL) {
            printf("Invalid position.\n");
            return;
        }
    }
    printf("Value at %d position is %d.\n",pos,temp->data);
}

void traverse() {
    temp=head;
    if (temp==NULL) {
        printf("List is empty.\n");
        return;

    }
    printf("List: [");
    while (temp!=NULL) {
        printf("%d",temp->data);
        if (temp->next!=NULL) printf("\t");
        temp=temp->next;
    }
    printf("]\nIndex: ");
    temp=head;
    for (int i=0;temp!=NULL;i++){
        printf("%d",i);
        if (temp->next!=NULL) printf("\t");
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    int val,choice,pos;
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
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert:");
                scanf("%d",&val);
                insertAtBeginning(val);
                break;

            case 2:
                printf("Enter value to insert:");
                scanf("%d",&val);
                insertAtEnd(val);
                break;

            case 3:
                printf("Enter position(starts at 0):");
                scanf("%d",&pos);
                printf("Enter value:");
                scanf("%d",&val);
                if (pos==0) insertAtBeginning(val);
                else insertAtPos(pos,val);
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                printf("Enter position(starts at 0):");
                scanf("%d",&pos);
                if (pos==0) deleteAtBeginning();
                else deleteAtPos(pos);
                break;
            case 7:
                printf("Enter position to search:");
                scanf("%d",&pos);
                search(pos);
                break;

            case 8:
                traverse();
                break;
            case 9:
                return 0;

            default: printf("\nWrong choice!\n");

        }
    }
}
