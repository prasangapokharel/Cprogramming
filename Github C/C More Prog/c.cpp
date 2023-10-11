#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct book {
    int bid;
    char title[100];
    float price;
    int page;
};

void sort_books(struct book *books, int num_books);

int main() {
    struct book books[MAX_BOOKS];
    int num_books;

    printf("Enter the number of books to be added (max 100): ");
    scanf("%d", &num_books);

    // Read book details from user
    for (int i = 0; i < num_books; i++) {
        printf("Enter details for book %d\n", i + 1);
        printf("Bid: ");
        scanf("%d", &books[i].bid);
        printf("Title: ");
        scanf("%s", books[i].title);
        printf("Price: ");
        scanf("%f", &books[i].price);
        printf("Page: ");
        scanf("%d", &books[i].page);
    }

    // Sort books by title
    sort_books(books, num_books);

    // Print sorted books
    printf("\nBooks sorted by title:\n");
    for (int i = 0; i < num_books; i++) {
        printf("Book %d\n", i + 1);
        printf("Bid: %d\n", books[i].bid);
        printf("Title: %s\n", books[i].title);
        printf("Price: %.2f\n", books[i].price);
        printf("Page: %d\n", books[i].page);
    }

    return 0;
}

void sort_books(struct book *books, int num_books) {
    struct book temp;
    int i, j;

    for (i = 0; i < num_books - 1; i++) {
        for (j = i + 1; j < num_books; j++) {
            if (strcmp(books[i].title, books[j].title) > 0) {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

