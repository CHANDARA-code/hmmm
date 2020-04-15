#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void display_Menu(){

    do
    {
        printf("*******************Welcome To Golden Media*******************");
        printf("*1. Add a new Customer");
        printf("*2. Display all Customer all Information");
        printf("*3. Update Customer Information");
        printf("*4. Delete a Customer Information");
        printf("*5. Display a Specific Customer Information");
        printf("*6. Exit");
        printf("*************************************************************");
        printf("Enter The Number Above To For Your Work: ");
        scanf("%d",&choice);
        option(choice);
    }
    while (choice);
}
