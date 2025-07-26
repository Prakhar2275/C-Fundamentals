#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    int id;
    char title[100];
    char author[100];
};

void addBook()
{
    FILE *fp = fopen("library.dat", "ab");
    struct Book book;

    printf("Enter Book ID: ");
    scanf("%d", &book.id);
    getchar(); // consume newline

    printf("Enter Book Title: ");
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = 0;

    printf("Enter Book Author: ");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = 0;

    fwrite(&book, sizeof(book), 1, fp);
    fclose(fp);
    printf("Book added successfully.\n\n");
}

void displayBooks()
{
    FILE *fp = fopen("library.dat", "rb");
    struct Book book;

    printf("\n--- List of Books ---\n");
    while (fread(&book, sizeof(book), 1, fp))
    {
        printf("ID: %d\nTitle: %s\nAuthor: %s\n\n", book.id, book.title, book.author);
    }
    fclose(fp);
}

void searchBook()
{
    FILE *fp = fopen("library.dat", "rb");
    struct Book book;
    int id, found = 0;

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    while (fread(&book, sizeof(book), 1, fp))
    {
        if (book.id == id)
        {
            printf("Book Found:\nID: %d\nTitle: %s\nAuthor: %s\n\n", book.id, book.title, book.author);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Book with ID %d not found.\n\n", id);
    }

    fclose(fp);
}

void deleteBook()
{
    FILE *fp = fopen("library.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Book book;
    int id, found = 0;

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    while (fread(&book, sizeof(book), 1, fp))
    {
        if (book.id != id)
        {
            fwrite(&book, sizeof(book), 1, temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("library.dat");
    rename("temp.dat", "library.dat");

    if (found)
    {
        printf("Book deleted successfully.\n\n");
    }
    else
    {
        printf("Book with ID %d not found.\n\n", id);
    }
}

int main()
{
    int choice;

    do
    {
        printf("===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Delete Book by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline from buffer

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n\n");
        }
    } while (choice != 5);

    return 0;
}
