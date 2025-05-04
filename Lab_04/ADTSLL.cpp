//to perform general operations on ADT singly linked list

#include <cstdio>
#include <iostream>

//creating class
class ADTSLL
{
    private:
        struct node
        {
            int data;
            struct node* next;
        };
        struct node* head;
    public:
        ADTSLL();
        int count();
        void reverseUtil(struct node* curr);
        int Insert_Beginning(int num);
        int Insert_End(int num);
        int Insert_Position(int num, int pos);
        int Delete_Beginning();
        int Delete_End();
        int Delete_Position(int pos);
        int Search(int num);
        void Display();
        void Reverse_Display();
        void Reverse_Link();
};

ADTSLL list;

int main()
{
    int choice, num, pos;
    while(1)
    {
        printf("\n\nMenu:\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Reverse Display\n10. Reverse Link\n11. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case(1):
                printf("Enter number to be inserted in beginning: ");
                scanf("%d",&num);
                if(list.Insert_Beginning(num)){printf("The element is added.");}
                else{printf("element not added.");}
                break;
            case(2):
                printf("Enter number to be inserted in end: ");
                scanf("%d",&num);
                if(list.Insert_End(num)){printf("The element is added.");}
                else{printf("element not added.");}
                break;
            case(3):
                printf("Enter number to be inserted in position: ");
                scanf("%d",&num);
                printf("Enter number the position: ");
                scanf("%d",&pos);
                if(list.Insert_Position(num, pos)){printf("The element is added.");}
                else{printf("\nelement not added.");}
                break;
            case(4):
                if(list.Delete_Beginning()){printf("Element is deleted.");}
                else{printf("\nElement was NOT deleted");}
                break;
            case(5):
                if(list.Delete_End()){printf("Element is deleted.");}
                else{printf("\nElement was NOT deleted");}
                break;
            case(6):
                printf("Enter Position to be deleted: ");
                scanf("%d",&pos);
                if(list.Delete_Position(pos)){printf("Element is deleted.");}
                else{printf("\nElement was NOT deleted");}
                break;
            case(7):
                printf("Enter the element to be searched: ");
                scanf("%d",&num);
                if(list.Search(num)){printf("Element is found.");}
                else{printf("Element was NOT found");}
                break;
            case(8):
                list.Display();
                break;
            case(9):
                list.Reverse_Display();
                break;
            case(10):
                list.Reverse_Link();
                break;
            case(11):
                return 0;
            default:
                printf("Invalid choice.");
        }
    }
}

ADTSLL::ADTSLL()
{
    head=NULL;
}

//function to insert an element in the beginning
int ADTSLL::Insert_Beginning(int num)
{
    struct node* newnode=(struct node*)malloc(sizeof(node));
    newnode->data=num;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        return 1;
    }
    else
    {
        newnode->next=head;
        head=newnode;
        return 1;
    }
    return 0;
}

//function to insert an element in the
int ADTSLL::Insert_End(int num)
{
    struct node* newnode=(struct node*)malloc(sizeof(node));
    newnode->data=num;
    newnode->next=NULL;
    struct node* temp=head;
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            temp->next=newnode;
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

//function to insert an element in a given position
int ADTSLL::Insert_Position(int num, int pos)
{
    int count=list.count();
    struct node* newnode=(struct node*)malloc(sizeof(node));
    newnode->data=num;
    struct node* temp=head;

    if(pos==1)
    {
        list.Insert_Beginning(num);
        return 1;
    }
    else if(pos==count+1)
    {
        list.Insert_End(num);
        return 1; 
    }
    else
    {
        int count=1;
        while(temp!=NULL)
        {
            if(count==pos-1)
            {
                newnode->next=temp->next;
                temp->next=newnode;
                return 1;
            }
            count++;
            temp=temp->next;
        }
    }

    printf("Index out of range.");
    return 0;
}

//function to delete beginning
int ADTSLL::Delete_Beginning()
{
    if(head==NULL){printf("The list is empty");}
    else
    {
        head=head->next;
        return 1;
    }
    return 0;
}

//function to delete end
int ADTSLL::Delete_End()
{
    struct node* temp=head;
    if(temp==NULL){printf("The list is empty");}
    else
    {
        while(temp!=NULL)
        {
            if(temp->next->next==NULL)
            {
                temp->next=NULL;
                return 1;
            }
            temp=temp->next;
        }
    }
    return 0;
}

//function to delete an element by position
int ADTSLL::Delete_Position(int pos)
{
    int count=list.count();
    struct node* temp=head;
    if(temp==NULL){printf("The list is empty");}
    else if(pos==1)
    {
        list.Delete_Beginning();
        return 1;
    }
    else if(pos==count)
    {
        list.Delete_End();
        return 1;
    }
    else
    {
        int count=1;
        while(temp!=NULL)
        {
            if (count=pos-1)
            {
                temp->next=temp->next->next;
                return 1;
            }
            count++;
            temp=temp->next;
        }
    }
    return 0;
}

//function to search an element
int ADTSLL::Search(int num)
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        if (temp->data==num)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

//function to display the list
void ADTSLL::Display()
{
    struct node* temp=head;
    if(temp==NULL){printf("The list is empty");}
    else
    {
        while(temp!=NULL)
        {
            printf("->%d",temp->data);
            temp=temp->next;
        }
    }
}

//function to display reverse of list
void ADTSLL::Reverse_Display()
{
    struct node* temp=head;
    int count=list.count();
    int arr[count];
    int i=0;
    if(head==NULL){printf("The list is empty");}
    while(temp!=NULL)
    {
        arr[i]=temp->data;
        temp=temp->next;
        i++;
    }
    for(int i=count-1; i>=0; i--)
    {
        printf("%d->",arr[i]);
    }
}

//function to reverse a link
void ADTSLL::Reverse_Link()
{
    if (head == NULL || head->next == NULL)
        return; // If empty or single node, no need to reverse

    reverseUtil(head);
}

//function to identify the length of list
int ADTSLL::count()
{
    int count=0;
    struct node* temp=head;
    while (temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void ADTSLL::reverseUtil(struct node* curr)
{
    if (curr->next == NULL) // Base case: last node becomes new head
    {
        head = curr;
        return;
    }

    reverseUtil(curr->next); // Recursively reach the last node

    curr->next->next = curr; // Reverse the link
    curr->next = NULL;  // Set the current node’s next to NULL
}