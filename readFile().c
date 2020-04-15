
#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void readFile(){
    file =fopen("costumer.txt","r");
    if (file == NULL)
    {
        printf("can not read file");
        printf("\n");
        return;
    }
    fscanf(file, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",NO,ID,Name,Item_name,Quantity,Price,Discount,order_date,recieve_date,Delivery_fee,address,Phone_number,Delivery_man,delivery_phone_number,Total);

    while (fscanf(file, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",str_No,str_ID,c[i].Name,c[i].Item_name,str_quan,str_price,str_discount,c[i].order_date,c[i].recieve_date,str_delFee,c[i].address,c[i].dhone_number,c[i].delivery_man,c[i].delivery_phone_number,str_total) != EOF);
    {
        c[i].No = atoi(str_No);
        c[i].cus_ID = atoi(str_ID);
        c[i].price = atoi(str_price);
        c[i].discount = atoi(str_discount);
        c[i].quantity = atoi(str_quan);
        c[i].delivery_fee = atoi(str_delFee);
        c[i].total = atoi(str_total);

        i++;
        last_index = i;
    }
    fclose(file);

}
