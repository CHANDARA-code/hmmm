
#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void displayAllcustomer() {

    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",No,ID,Name,Item_name,Quantity,Price,Discount,order_date,recieve_date,Delivery_fee,address,Phone_number,Delivery_man,Delivery_phone_number,Total);

    for (int i=0;i<last_index;i++)
    {
        printf("%d\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%d\t%s\t%d\t%d\n",c[i].No,c[i].cus_ID,c[i].name,c[i].item_name,c[i].quantity,c[i].price,c[i].discount,c[i].ordered_date,c[i].recieved_date,c[i].delivery_fee,c[i].address,c[i].phone_number,c[i].delivery_name,c[i].delivery_phone_number);
    }
}
