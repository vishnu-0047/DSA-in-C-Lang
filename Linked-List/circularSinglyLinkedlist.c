//CIRCULAR SINGLY LINKED LIST
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
    temp=head;
    newNode->data=val;
    if (head==NULL) {
        newNode->next=newNode;
    }
    else {
        while (temp->next!=head) temp=temp->next;
        newNode->next=head;
        temp->next=newNode; // also can use temp->next=head; because in insertion at beginning head=newNode
    }
    head=newNode;
    printf("%d is inserted at beginning.\n",val);
}

void insertAtEnd(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    temp=head;
    if (head==NULL){
        head=newNode;
        newNode->next=newNode; // newNode->next=head; is also valid because (see upper comment)
    }
    else {
        while (temp->next!=head) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }
    printf("%d is inserted at the end.\n",val);
}

void insertAtPos(int pos,int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    temp=head;
    for (int i=0;i<pos-1;i++) {
        temp=temp->next;
        if (temp==head) {
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
    Node* last=head;
    if (head==NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("%d is deleted from the beginning.\n",temp->data);
    while (last->next!=head) last=last->next;
    if (head==head->next) {
        free(temp);
        head=NULL;
    }
    else {
        head=head->next;
        free(temp);
        last->next=head;

    }

}

void deleteAtEnd() {
    Node* old=head;
    Node* p=head;
    if (head==NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next==head) {
        printf("\n%d is deleted from the end.\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    while (p->next!=head) {
        old=p;
        p=p->next;
    }
    printf("\n%d is deleted from the end.\n",p->data);
    free(p);
    old->next=head;
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
        if (temp==head) {
            printf("Invalid position.\n");
            return;
        }
    }
    p->next=temp->next;
    if (temp->next == head) p->next=head;
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
        if (temp==head) {
            printf("Invalid position.\n");
            return;
        }
    }
    printf("Value at %d position is %d.\n",pos,temp->data);
}

void traverse() {
    int i=0;
    temp=head;
    if (head==NULL) {
        printf("List is empty.\n");
        return;

    }
    printf("List: [");
    do{
        printf("%d",temp->data);
        if (temp->next!=head) printf("\t");
        temp=temp->next;
    }while (temp!=head);
    printf("]\nIndex: ");
    temp=head;
    do{
        printf("%d",i);
        if (temp->next!=NULL) printf("\t");
        temp=temp->next; i++;
    }while (temp!=head);
    printf("\n");
}

int main() {
    int val,choice,pos;
    while (1) {
        printf("-------CIRCULAR LINKED LIST MENU-------\n");
        printf("\t1. Insert at beginning\n");
        printf("\t2. Insert at end\n");
        printf("\t3. Insert at position\n");
        printf("\t4. Delete at beginning\n");
        printf("\t5. Delete at end\n");
        printf("\t6. Delete at position\n");
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
