#include <stdio.h>
#include <stdlib.h>

struct node {
    int roll;
    struct node *next;
};

struct node *head = NULL;

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Updated List: ");
    while (temp != NULL) {
        printf("%d ", temp->roll);
        temp = temp->next;
    }
    printf("\n");
}

void insertBeginning(int roll) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->roll = roll;
    newnode->next = head;
    head = newnode;

    printf("Inserted %d at beginning\n", roll);
    display();
}

void insertEnd(int roll) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->roll = roll;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Inserted %d at end\n", roll);
    display();
}

void search(int roll) {
    struct node *temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Roll number %d found\n", roll);
            return;
        }
        temp = temp->next;
    }

    printf("Roll number %d not found\n", roll);
}

void deleteRoll(int roll) {
    struct node *temp = head;
    struct node *prev = NULL;

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Roll number %d not found. Cannot delete.\n", roll);
        display();
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);

    printf("Deleted roll number %d\n", roll);
    display();
}

int main() {
    int n, roll, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter roll numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &roll);
        insertEnd(roll);
    }

    printf("\nEnter roll number to insert at beginning: ");
    scanf("%d", &roll);
    insertBeginning(roll);

    printf("\nEnter roll number to insert at end: ");
    scanf("%d", &roll);
    insertEnd(roll);

    printf("\nEnter roll number to search: ");
    scanf("%d", &roll);
    search(roll);

    printf("\nEnter roll number to delete: ");
    scanf("%d", &roll);
    deleteRoll(roll);

    return 0;
}
