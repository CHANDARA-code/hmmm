
#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void option(int choice){

    switch (choice)
    {
        case 1: printf("You chose 1\n\n");
                readFile();
                reset();
                    break;
        case 2: printf("You chose 2\n\n");
                readFile();
                displayAllcustomer();
                reset();
                    break;
        case 3: printf("You chose 3\n\n");
                readFile();
                reset();
                    break;
        case 4: printf("You chose 4\n\n");
                readFile();
                delete();
                reset();
                    break;
        case 5: printf("You chose 5\n\n");
                readFile();
                reset();
                    break;
        case 6: printf("You chose 6\n\n");
                readFile();
                writeFile();
                exit(0);
                    break;
        default : printf("Please choose a correct number\n\n");
                  break;
    }

}
