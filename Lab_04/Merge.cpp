#include "list.h"

int main() {
    List list1, list2, list3;
    int choice, value;

    while (1) {
        printf("\n1. Insert into List1\n2. Insert into List2\n3. Merge into List3\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                list1.insertAscending(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                list2.insertAscending(value);
                break;

            case 3:
                list3.mergeLists(list1, list2);
                printf("Lists merged into List3.\n");
                break;

            case 4:
                printf("List1: ");
                list1.display();
                printf("List2: ");
                list2.display();
                printf("List3: ");
                list3.display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
