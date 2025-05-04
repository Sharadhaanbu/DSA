#include "round_robin.h"

int main() {
    int timeSlice, choice, time;
    
    printf("Enter time slice: ");
    scanf("%d", &timeSlice);
    
    RoundRobinScheduler scheduler(timeSlice);

    while (1) {
        printf("\nMenu:\n1. Insert Process\n2. Execute\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter process time: ");
                scanf("%d", &time);
                if (scheduler.Insert_end(time)) {
                    printf("Process added.\n");
                } else {
                    printf("Failed to add process.\n");
                }
                break;

            case 2:
                scheduler.Execute();
                break;

            case 3:
                scheduler.Display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}


// Insert Process at End
int RoundRobinScheduler::Insert_end(int time) {
    Process* newProcess = new Process(time);
    
    if (head == NULL) {
        head = newProcess;
        head->next = head;
        head->prev = head;
        return 1;
    }

    Process* tail = head->prev;
    tail->next = newProcess;
    newProcess->prev = tail;
    newProcess->next = head;
    head->prev = newProcess;

    return 1;
}

// Execute Round Robin Scheduling
int RoundRobinScheduler::Execute() {
    if (head == NULL) {
        printf("No processes to execute.\n");
        return 0;
    }

    Process* temp = head;
    
    while (head) {
        printf("Executing process with remaining time: %d\n", temp->time);
        temp->time -= timeSlice;

        if (temp->time <= 0) {
            printf("Process completed execution.\n");

            if (temp->next == temp) { 
                delete temp;
                head = NULL;
                return 1;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (temp == head) 
                head = temp->next;

            Process* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }

        if (head == NULL) return 1;
    }
    return 1;
}

// Display Process Queue
void RoundRobinScheduler::Display() {
    if (head == NULL) {
        printf("No processes in the queue.\n");
        return;
    }

    Process* temp = head;
    do {
        printf("-> %d ", temp->time);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
