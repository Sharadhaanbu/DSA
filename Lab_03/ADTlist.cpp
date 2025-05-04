#include <cstdio>
#include <iostream>

class ADTlist
{
    public:
        ADTlist();
        int Insert_beginning(int list[],int);
        int Insert_position(int list[],int,int);
        int Insert_end(int list[],int);
        int Delete_beginning(int list[]);
        int Delete_position(int list[],int);
        int Delete_end(int list[]);
        int Search(int list[],int);
        int Display(int list[]);
        int Rotate(int list[],int);
};

int main()
{
    ADTlist adt;
    int choice, num, pos;
    int arr[5] = {0};

    while(1)
    {
        printf("\n1. Insert begining \n2. Insert position \n3. Insert end \n4. Delete begining");
        printf("\n5. Delete position \n6. Delete end \n7. Search \n8. Display \n9. Rotate \n10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &num);
                adt.Insert_beginning(arr, num);
                break;
            case 2:
                printf("Enter element to be inserted: ");
                scanf("%d", &num);
                printf("Enter position (0-4): ");
                scanf("%d", &pos);
                adt.Insert_position(arr, num, pos);
                break;
            case 3:
                printf("Enter element to be inserted: ");
                scanf("%d", &num);
                adt.Insert_end(arr, num);
                break;
            case 4:
                adt.Delete_beginning(arr);
                printf("The element in the beginning is deleted.\n");
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                adt.Delete_position(arr, pos);
                break;
            case 6:
                adt.Delete_end(arr);
                break;
            case 7:
                printf("Enter Element to be searched: ");
                scanf("%d", &num);
                printf("The element is in position: %d\n", adt.Search(arr, num));
                break;
            case 8:
                adt.Display(arr);
                break;
            case 9:
                printf("Enter number of times to be rotated: ");
                scanf("%d", &num);
                adt.Rotate(arr, num);
                break;
            case 10:
                return 0;
            default:
                printf("Invalid choice, try again!\n");
        }
    }
}

ADTlist::ADTlist(){}

int ADTlist::Insert_beginning(int list[], int a)
{
    if(list[0] == 0)
    {
        list[0] = a;
    }
    else
    {
        for (int i = 4; i > 0; i--) 
        {
            list[i] = list[i-1];
        }
        list[0] = a;
    }
    return 0;
}

int ADTlist::Insert_position(int list[], int a, int pos)
{
    if (pos >= 0 && pos < 5) 
        list[pos] = a;
    else
        printf("Invalid position!\n");
    return 0;
}

int ADTlist::Insert_end(int list[], int a)
{
    for (int i = 0; i < 5; i++)
    {
        if (list[i] == 0)
        {
            list[i] = a;
            return 0;
        }
    }
    printf("List is full!\n");
    return -1;
}

int ADTlist::Delete_beginning(int list[])
{
    for(int i = 0; i < 4; i++)
    {
        list[i] = list[i+1];
    }
    list[4] = 0;
    return 0;
}

int ADTlist::Delete_position(int list[], int a)
{
    if (a >= 0 && a < 4) 
    {
        for(int i = a; i < 4; i++)
        {
            list[i] = list[i+1];
        }
        list[4] = 0;
    } else {
        printf("Invalid position!\n");
    }
    return 0;
}

int ADTlist::Delete_end(int list[])
{
    list[4] = 0;
    return 0;
}

int ADTlist::Search(int list[], int b)
{
    for(int i = 0; i < 5; i++)
    {
        if(list[i] == b)
            return i;
    }
    return -1; 
}

int ADTlist::Display(int list[])
{
    printf("List: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}

int ADTlist::Rotate(int list[], int n)
{
    for(int j = 0; j < n; j++)  
    {
        int temp = list[4];
        for(int i = 4; i > 0; i--)
        {
            list[i] = list[i-1];
        }
        list[0] = temp;
    }
    return 0;
}