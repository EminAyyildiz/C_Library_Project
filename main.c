
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void addBook(void);
void listBooks(void);
void listBooksByAuthor(void);
void borrowBook(void);

struct Book {
    char title[50];
    char author[50];
    int published_year;
};

struct Book library[100];
int bookCount = 0;


void addBook()
{
    
    printf("Enter book title: ");
    scanf(" %[^\n]s", library[bookCount].title);
    printf("Enter book author: ");
    scanf(" %[^\n]ss", library[bookCount].author);
    printf("Enter publication year: ");
    scanf("%d", &library[bookCount].published_year);
    bookCount++;
    printf("The book is being added to the library... Please wait. \n");
    sleep(1.5);
    printf("The book has been successfully added. \n");
}

void listBooks() {
    if (bookCount == 0)
    {
        printf("Kütüphanede kitap bulunmuyor.\n");
    }
    else {
        printf("All books are listed... Please wait. \n");
        sleep(1.5);
        for (int i = 0; i < bookCount; i++) {
            
            
            printf("Book Title: %s\nAuthor: %s\nPublication Year: %d\n", library[i].title, library[i].author, library[i].published_year);
            printf("**********\n");
        }
    }
}
void listBooksByAuthor() {
    char author[50];
    int i, found = 0, check = 0;
    printf("Enter author name: ");
    scanf("%s", author);
    
    for (i = 0; i < bookCount; i++) {
        if (strcmp(library[i].author, author) == 0) {
            
            if (check == 0){
                printf("Listing all books by %s... Please wait.\n",author);
                sleep(2);
                check = 1 ;
            }
                printf("Book Title: %s\nAuthor: %s\nPublication Year: %d\n", library[i].title, library[i].author, library[i].published_year);
                found = 1;
            }
            
        
    }
    if (found == 0) {
        printf("No books found by the author %s\n", author);
    }
}

void borrowBook() {
    char title[50];
    int i= 0;
    int found = 0;
    printf("Enter book title: ");
    scanf("%s", title);
    for (i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            found = 1;
            break;
        }
    }
    if (found == 1) {
        for (i = 0; i < bookCount - 1; i++) {
            library[i] = library[i + 1];
        }
        bookCount--;
        printf("The book titled %s is being given... Please wait.\n",title);
        sleep(1.5);
        printf("Book borrowed successfully!\n");
    } else {
        printf("Book not found in the library.\n");
    }
}

int main(void) {
    int choice;
    while (1) {
        printf("**** MENU ****\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. List Books by Author\n");
        printf("4. Borrow Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                listBooksByAuthor();
                break;
            case 4:
                borrowBook();
                break;
            case 5:
                printf("Exiting...Please wait..\n");
                sleep(1.5);
                printf("BYE BYE :)) \n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
