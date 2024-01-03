#include <stdio.h>

// Function declaration
void table(int n);

int main() {
    int n = 9;  // Declare and initialize the variable
    table(n);   //table(9)

}

// Function definition
void table(int n) { // table(9)
    for (int i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", n, i, n * i);
    }
}

// i=1 ; i<=10 
//%d * %d = %d , n , i , n*i ....................... 9 * 1 = 9
// i=2 ; i<=10
//%d * %d = %d , n , i , n*i ....................... 9 * 2 = 18
// i=3; i<=10
//%d * %d = %d , n , i , n*i ....................... 9 * 3= 27
