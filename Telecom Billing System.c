#include <stdio.h>

struct customer
{
    int phn_no;
    char name[10];
    int bill;
};

void createlist(struct customer[], int);
void display(struct customer[], int);
int search(struct customer[], int, int);
void payment(struct customer[], int, int, int);

int main()
{
    struct customer data[80];
    int n, choice, phn_no, amount, index;

    printf("!!!!!!!!!!!!Telecom Billing System!!!!!!!!!\n\n");
    do
    {

        printf("\nTelecom Billing System Menu :\n");
        printf("press 1 to create list.\n");
        printf("Press 2 to display all records.\n");
        printf("Press 3 to search a record.\n");
        printf("Press 4 to payment.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Number of customer records you want to enter : ");
                scanf("%d", &n);
                createlist(data, n);
                break;

            case 2:
                display(data, n);
                break;
            case 3:
                printf("Enter account number to search : ");
                scanf("%d", &phn_no);
                index = search(data, n, phn_no);
                if (index ==  - 1)
                {
                    printf("Record not found : ");
                }
                else
                {
                    printf("Phn Number: %d\nName: %s\nBill: %d\n",
                        data[index].phn_no, data[index].name,
                        data[index].bill);
                }
                break;
            case 4:
                printf("Enter account number : ");
                scanf("%d", &phn_no);
                printf("Enter amount to withdraw : ");
                scanf("%d", &amount);
                payment(data, n, phn_no, amount);
        }
    }
    while (choice != 0);

    return 0;
}

void createlist(struct customer list[80], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter data for Record %d", i + 1);

        printf("\nEnter phn no : ");
        scanf("%d", &list[i].phn_no);
        fflush(stdin);
        printf("Enter name : ");
        gets(list[i].name);
        printf("Bill:");
        scanf("%d", &list[i].bill);

    }
}

void display(struct customer list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("phn no: %d\nName: %s\nBill: %d\n\n", list[i].phn_no,
               list[i].name, list[i].bill);
    }
}

int search(struct customer list[80], int s, int number)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (list[i].phn_no == number)
        {
            return i;
        }
    }
    return  - 1;
}
void payment(struct customer list[], int s, int number, int amt)
{
    int i = search(list, s, number);
    if (i ==  - 1)
    {
        printf("Record not found\n");
    }
    else if (list[i].bill < amt)
    {
        printf("Insufficient balance\n");
    }
    else
    {
        list[i].bill -= amt;
    }
}

