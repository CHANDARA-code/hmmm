
#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void updateCustomer(){
    int id;

    printf("Please Input the ID of Customer that you want to update: ");
    scanf("%d",&id);

    for (int i=0;i<last_index;i++)
    {
        if (id == c[i].cus_ID)
        {
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",No,ID,Name,Item_name,Quantity,Price,Discount,order_date,recieve_date,Delivery_fee,address,Phone_number,Delivery_man,Delivery_phone_number,Total);
            printf("%d\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%d\t%s\t%d\t%d\n",c[id-1].No,c[id-1].cus_ID,c[id-1].name,c[id-1].item_name,c[id-1].quantity,c[id-1].price,c[id-1].discount,c[id-1].ordered_date,c[id-1].recieved_date,c[id-1].delivery_fee,c[id-1].address,c[id-1].phone_number,c[id-1].delivery_name,c[id-1].delivery_phone_number);
            printf("Input Customer name: ");
            scanf("%s",c[id-1].name);
            printf("Input Item name: ");
            scanf("%s",c[id-1].item_name);
            printf("Input quantity: ");
            scanf("%d",c[id-1].quantity);
            printf("Input price: ");
            scanf("%d",c[id-1].price);
            printf("Input Discount: ");
            scanf("%d",c[id-1].discount);
            printf("Input oder date: ");
            scanf("%s",c[id-1].ordered_date);
            printf("Input receive date: ");
            scanf("%s",c[id-1].recieved_date);
            printf("Input delivery fee: ");
            scanf("%d",c[id-1].delivery_fee);
            printf("Input address: ");
            scanf("%s",c[id-1].address);
            printf("Input phone number: ");
            scanf("%d",c[id-1].phone_number);
            printf("Input delivery man's name: ");
            scanf("%s",c[id-1].delivery_name);
            printf("Input delivery phone number: ");
            scanf("%d",c[id-1].delivery_phone_number);
            writeFile();
            printf("Customer that have ID %d has been updated",id);
            break;
        }
        if (i == last_index-1)
        {
            printf("Don't have that id.Please Try again\n");
        }
    }
}
