#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>  // For using bool type in C

int main() {
    int i, c = 0, k = 0;
    char T[10][50];  // Array of strings with each string having max 50 characters
    bool res = true, kaws = true;
    char a;

    while (res) {
        printf("1. number\n2. (\n3. )\n4. +-*/ cos 7. sin ln ex sqrt\n");
        scanf("%d", &i);

        switch (i) {
            case 1:
                printf("Please enter a number: ");
                scanf("%s", T[c]);  // Read string directly into T[c]
                c++;
                break;
            case 2:
                strcpy(T[c], "(");  // Use strcpy to copy string values into T[c]
                c++;
                k++;
                break;
            case 3:
                if (k > 0) {
                    strcpy(T[c], ")");  // Use strcpy to copy string values into T[c]
                    c++;
                    k--;
                } else {
                    printf("marakch fatah 9aws ya hmar\n");
                }
                break;
            case 4:
                printf("Enter operation: ");

                getchar();  // Clear the newline character left by previous scanf
                scanf("%c", &a);  // Read the operator without storing any spaces

                switch (a) {
                    case '+':
                        strcpy(T[c], "+");
                        c++;
                        break;
                    case '-':
                        strcpy(T[c], "-");
                        c++;
                        break;
                    case '*':
                        strcpy(T[c], "*");
                        c++;
                        break;
                    case '/':
                        strcpy(T[c], "/");
                        c++;
                        break;
                    default:
                        printf("Invalid operator\n");
                }
                break;
            case 5:
                res = false;
                break;
            default:
                printf("nta hmar\n");
                res = false;  // Exit the loop if an invalid option is selected
                break;
        }
    }

    // Print the contents of the array
    printf("Contents of the array:\n");
    for (int g = 0; g < c; g++) {
        printf("%s ", T[g]);
    }
    printf("\n");

    return 0;
}
