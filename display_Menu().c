#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void display_Menu(){

    do
    {
        printf("\t\t\t\t\t\t\t\t*******************Welcome To Golden Media*******************");
        printf("\t\t\t\t\t\t\t\t*1. Add a new Customer");
        printf("\t\t\t\t\t\t\t\t*2. Display all Customer all Information");
        printf("\t\t\t\t\t\t\t\t*3. Update Customer Information");
        printf("\t\t\t\t\t\t\t\t*4. Delete a Customer Information");
        printf("\t\t\t\t\t\t\t\t*5. Display a Specific Customer Information");
        printf("\t\t\t\t\t\t\t\t*6. Exit");
        printf("\t\t\t\t\t\t\t\t*************************************************************");
        printf("\t\t\t\t\t\t\t\tEnter The Number Above To For Your Work: ");
        scanf("%d",&choice);
        option(choice);
    }
    while (choice);
}
