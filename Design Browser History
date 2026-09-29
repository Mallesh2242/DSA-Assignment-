#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char page[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

void insertPage() {
    struct Node *newNode, *temp;
    char name[50];

    printf("Enter page name: ");
    scanf("%49s", name);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->page, name);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        current = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Page inserted successfully.\n");
}

void moveForward() {
    if (current == NULL) {
        printf("No pages available.\n");
    } else if (current->next == NULL) {
        printf("Already at the last page.\n");
    } else {
        current = current->next;
        printf("Current page: %s\n", current->page);
    }
}

void moveBackward() {
    if (current == NULL) {
        printf("No pages available.\n");
    } else if (current->prev == NULL) {
        printf("Already at the first page.\n");
    } else {
        current = current->prev;
        printf("Current page: %s\n", current->page);
    }
}

void deletePage() {
    char name[50];
    struct Node *temp = head;

    printf("Enter page name to delete: ");
    scanf("%49s", name);

    while (temp != NULL && strcmp(temp->page, name) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Page not found.\n");
        return;
    }

    if (temp == head) {
        head = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (current == temp) {
        if (temp->next != NULL) {
            current = temp->next;
        } else {
            current = temp->prev;
        }
    }

    free(temp);

    printf("Page deleted successfully.\n");
}

void displayForward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("No pages available.\n");
        return;
    }

    printf("Pages from first to last:\n");

    while (temp != NULL) {
        printf("%s <-> ", temp->page);
        temp = temp->next;
    }

    printf("NULL\n");
}

void displayBackward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("No pages available.\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Pages from last to first:\n");

    while (temp != NULL) {
        printf("%s <-> ", temp->page);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Browser History ---\n");
        printf("1. Insert New Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Display Current Page\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertPage();
                break;

            case 2:
                moveForward();
                break;

            case 3:
                moveBackward();
                break;

            case 4:
                deletePage();
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                if (current == NULL)
                    printf("No current page.\n");
                else
                    printf("Current page: %s\n", current->page);
                break;

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}
