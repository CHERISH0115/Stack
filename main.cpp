#include"cherish.h"
#include"stdlib.h"
int main() {
    Stack stack;
    initStack(&stack);

    int choice;
    int value;

    while (1) {
        printf("Stack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Print Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to push: ");
            scanf_s("%d", &value);
            push(&stack, value);
            break;
        case 2:
            value = pop(&stack);
            if (value != -1) {
                printf("Popped element: %d\n", value);
            }
            break;
        case 3:
            value = top(&stack);
            if (value != -1) {
                printf("Top element: %d\n", value);
            }
            break;
        case 4:
            printStack(&stack);
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}