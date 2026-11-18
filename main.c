
#include <stdio.h>
#include <string.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    int available;
};

void addBook(struct Book *b, int *n)
{
    printf("\nEnter Book ID: ");
    scanf("%d", &b[*n].id);
    getchar();

    printf("Enter Book Title: ");
    fgets(b[*n].title, 50, stdin);
    b[*n].title[strcspn(b[*n].title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(b[*n].author, 50, stdin);
    b[*n].author[strcspn(b[*n].author, "\n")] = '\0';

    b[*n].available = 1;
    (*n)++;

    printf("\nBook added successfully!\n");
}

void displayBooks(struct Book *b, int n)
{
    int i;

    if (n == 0)
    {
        printf("\nNo books in the library.\n");
        return;
    }

    printf("\n--- Library Books ---\n");

    for (i = 0; i < n; i++)
    {
        printf("\nBook ID: %d", b[i].id);
        printf("\nTitle: %s", b[i].title);
        printf("\nAuthor: %s", b[i].author);

        if (b[i].available == 1)
            printf("\nStatus: Available\n");
        else
            printf("\nStatus: Issued\n");
    }
}

int searchBook(struct Book *b, int n, int id)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (b[i].id == id)
            return i;
    }

    return -1;
}

void issueBook(struct Book *b, int n)
{
    int id, pos;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    pos = searchBook(b, n, id);

    if (pos == -1)
        printf("\nBook not found!\n");
    else if (b[pos].available == 0)
        printf("\nBook is already issued!\n");
    else
    {
        b[pos].available = 0;
        printf("\nBook issued successfully!\n");
    }
}

void returnBook(struct Book *b, int n)
{
    int id, pos;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    pos = searchBook(b, n, id);

    if (pos == -1)
        printf("\nBook not found!\n");
    else if (b[pos].available == 1)
        printf("\nThis book is already available!\n");
    else
    {
        b[pos].available = 1;
        printf("\nBook returned successfully!\n");
    }
}

int main()
{
    struct Book books[100];
    int n = 0;
    int choice;

    do
    {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (n < 100)
                    addBook(books, &n);
                else
                    printf("\nLibrary is full!\n");
                break;

            case 2:
                displayBooks(books, n);
                break;

            case 3:
            {
                int id, pos;

                printf("\nEnter Book ID to search: ");
                scanf("%d", &id);

                pos = searchBook(books, n, id);

                if (pos == -1)
                    printf("\nBook not found!\n");
                else
                {
                    printf("\nBook Found!\n");
                    printf("Title: %s\n", books[pos].title);
                    printf("Author: %s\n", books[pos].author);

                    if (books[pos].available == 1)
                        printf("Status: Available\n");
                    else
                        printf("Status: Issued\n");
                }
                break;
            }

            case 4:
                issueBook(books, n);
                break;

            case 5:
                returnBook(books, n);
                break;

            case 6:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}