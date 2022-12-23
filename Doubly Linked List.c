#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedList {
    int data;
    struct DoublyLinkedList* next;
    struct DoublyLinkedList* prev;
}DLL;


void PrintListToFile(DLL* headOfTheList);
DLL* additemtoend(DLL* headOfTheList, int data);
void printlist(DLL* headOfTheList);
DLL* removeitem(DLL* headOfTheList, int toremove);
DLL* removeitemrecursively(DLL* headOfTheList, int toremove);
DLL* additemtomiddle(DLL* headOfTheList, int data);
DLL* reverse_list(DLL* headOfTheList);

int main()
{
    DLL* headOfTheList1 = NULL;
    int input, input2;
    while(1){
        printf("\n\n1->Input new item to list.\n");
        printf("2->Input new item to middle.\n");
        printf("3->Delete item from list.\n");
        printf("4->Print list.\n");
        printf("5->Reverse the list.\n");
        printf("6->Print list to a file.\n");
        printf("7->End program.\n\n");
        printf("Enter your choice -> ");
        scanf("%d",&input);
        printf("\n");
        switch(input)
        {
            case 1:
                printf("Enter a number to add to list -> ");
                scanf("%d",&input2);
                headOfTheList1 = additemtoend(headOfTheList1, input2);
                break;

            case 2:
                printf("Enter a number to add to middle -> ");
                scanf("%d",&input2);
                headOfTheList1=additemtomiddle(headOfTheList1,input2);
                break;

            case 3:
                printf("Enter a number to delete -> ");
                scanf("%d",&input2);
                headOfTheList1 = removeitem(headOfTheList1, input2);
                break;

            case 4:
                if(NULL!=headOfTheList1)
                   printlist(headOfTheList1);
                else
                    printf("List doesn't contain any data");
                break;

            case 5:
                headOfTheList1=reverse_list(headOfTheList1);
                break;

            case 6:
                PrintListToFile(headOfTheList1);
                break;

            default:
                printf("Please select a number from the list!\n");
        }

        if(input == 7)
            break;
    }
    return 0;

}


DLL* additemtomiddle(DLL* headOfTheList, int data)
{
    DLL* newitem_middle = (DLL*) malloc(sizeof(DLL));

    if(NULL == newitem_middle)
        exit(EXIT_FAILURE);

    newitem_middle->data=data;
    newitem_middle->next=NULL;
    newitem_middle->prev=NULL;

    DLL* temp=headOfTheList;

    while(temp->next != NULL && temp->data<=data)
        temp=temp->next;
    if(temp->next == NULL && temp->data<=data){
            headOfTheList=additemtoend(headOfTheList,data);
            return headOfTheList;
        }

    if(temp==headOfTheList)
    {
        temp->prev=newitem_middle;
        newitem_middle->next=temp;
        newitem_middle->prev=NULL;
        return newitem_middle;
    }

    temp->prev->next = newitem_middle;
    newitem_middle->prev = temp->prev;
    temp->prev = newitem_middle;
    newitem_middle->next = temp;

    return headOfTheList;

}


DLL* additemtoend(DLL* headOfTheList, int data)
{
    DLL* newitem = (DLL*) malloc(sizeof(DLL));
    if(NULL == newitem)
    {
        printf("Cannot allocate memory!");
        exit(EXIT_FAILURE);
    }

    newitem->data=data;
    newitem->next=NULL;
    newitem->prev=NULL;

    if (NULL == headOfTheList)
    {
        return(newitem);
    }
    DLL* temp = headOfTheList;

    while(NULL != temp->next)
    {
        temp = temp->next;
    }

    temp->next = newitem;
    newitem->prev = temp;

    return headOfTheList;
}

void printlist(DLL* headOfTheList)
{
    if(NULL != headOfTheList)
    {
        printf("Data = %d\n", headOfTheList->data);
        if(NULL != headOfTheList->next);
            printlist(headOfTheList->next);
    }
}

DLL* removeitem(DLL* headOfTheList, int toremove)
{
    DLL* temp = headOfTheList;
    while(NULL != temp && toremove != temp->data)
        temp = temp->next;
    if(NULL == temp){
        printf("Item is not in the list!\n");
        return headOfTheList;}
    else
        if (NULL != temp->prev)
            temp->prev->next=temp->next;
        if (NULL != temp->next)
            temp->next->prev=temp->prev;
        if (temp == headOfTheList)
            headOfTheList = headOfTheList->next;
        free(temp);
    return headOfTheList;
}

DLL* reverse_list(DLL* headOfTheList)
{
    if(NULL!=headOfTheList)
    {
        if(headOfTheList->next==NULL)
            return headOfTheList;

        DLL* tempend = (DLL*) malloc(sizeof(DLL));
        DLL* temphead = (DLL*) malloc(sizeof(DLL));
        int temp;

        tempend=headOfTheList;
        while(NULL!=tempend->next)
            tempend=tempend->next;

        temphead=headOfTheList;

        while(temphead != tempend->next && temphead != tempend)
        {
            temp=temphead->data;
            temphead->data=tempend->data;
            tempend->data=temp;
            temphead=temphead->next;
            tempend=tempend->prev;
        }

    }
    return headOfTheList;
}

void PrintListToFile(DLL* headOfTheList)
{
    FILE* List;

    List = fopen("List.txt", "w+");

    while(headOfTheList!=NULL)
    {
        fprintf(List, "%s", "Data->" );
        fprintf(List,"%d\n",headOfTheList->data);

        headOfTheList=headOfTheList->next;

    }

    fclose(List);
}








