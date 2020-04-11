#include <stdio.h>


int last_index;

char ID[100];
char Name[100];
char Item_name[100];
char Quantity[100];
char Price[100];
char Discount[100];
char Delivery_fee[100];
char address[100];
char Phone_number[100];
char Delivery_man[100];
char Deliveryman_phone_number[100];

FILE *file;
int choice;
struct Customer {
    char name[50];
    char item_name[100];
    char ordered_date[100],recieved_date[100];
    char address[100];
    char phone_number[20];
    char payment_type[100];
    char deliveryman_name[100],deliveryman_phone_number[20];
    char status[100];
    int id,price,delivery_fee,discount,quality;
};


struct Customer c[100];


int i=0;
char str_id[10];
char str_quan[10];
char str_price[10];
char str_discount[10];
char str_delFee[10];
char recieve_date[20];
char order_date[20];
char title[100];

void display_Menu(){
         do{
        printf("\n\n");
        printf("\t\t\t\t\t\t\t ****************Welcome To Golden Media****************\n");
        printf("\t\t\t\t\t\t\t * 1. Add A New Customer                               *\n");
        printf("\t\t\t\t\t\t\t * 2. Display All Customer Information                 *\n");
        printf("\t\t\t\t\t\t\t * 3. Update Customer Information                      *\n");
        printf("\t\t\t\t\t\t\t * 4. Delete A Customer Information                    *\n");
        printf("\t\t\t\t\t\t\t * 5. Display A Specific Customer Information          *\n");
        printf("\t\t\t\t\t\t\t * 6. Exit                                             *\n");
        printf("\t\t\t\t\t\t\t *******************************************************\n\n");
        printf("Enter One Number Above For Your Work: ");
        scanf("%d",&choice);
        option(choice);
        }while(choice != 6);
}

void option(int choice){
    switch(choice){
        case 1:
                clrscr();
                printf("\n\n\t\t\t\t\t\t\tYou Chose:1. Add A New Customer\n\n");
                readFile();
                addCustomer();
                reset();

                    break;
        case 2:
                clrscr();
                printf("\n\n\t\t\t\t\t\t\tYou Chose:2. Display All Customer Information\n\n");
                readFile();
                displayAllcustomer();
                reset();
                    break;
        case 3:
                clrscr();
                printf("\n\n\t\t\t\t\t\t\tYou Chose:3. Update Customer Information\n\n");
                readFile();
                updateCustomer();
                reset();

                    break;
        case 4:
                clrscr();
                printf("\n\n\t\t\t\t\t\t\tYou Chose:4. Delete A Customer Information\n\n");
                readFile();
                delete();
                reset();

                    break;
        case 5:
                clrscr();
                printf("\n\n\t\t\t\t\t\t\tYou Chose:5. Display A Specific Customer Information ");
                readFile();
                specific();
                reset();
                break;
                    break;
        case 6:
                printf("\n\n\t\t\t\t\t\t\tYou Chose:6. Exit");
                readFile();
                writeFile();
                exit(0);
                break;
        default: printf("Please choose the correct number\n");
                break;
    }
}

void readFile(){

    file = fopen("costumer.txt","r");
    if(file == NULL){
        printf("Cannot read file\n");
        return;
    }
    fscanf(file, "%s %s %s %s %s %s %s %s %s %s %s %s %s",ID,Name,Item_name,Quantity,Price,Discount,order_date,recieve_date,Delivery_fee,address,Phone_number,Delivery_man,Deliveryman_phone_number);
    while(fscanf(file,"%s %s %s %s %s %s %s %s %s %s %s %s %s",str_id,c[i].name,c[i].item_name,str_quan,str_price,str_discount,c[i].ordered_date,c[i].recieved_date,str_delFee,c[i].address,c[i].phone_number,c[i].deliveryman_name,c[i].deliveryman_phone_number) != EOF) {
        c[i].id = atoi(str_id);
        c[i].quality = atoi(str_quan);
        c[i].price = atoi(str_price);
        c[i].discount = atoi(str_discount);
        c[i].delivery_fee = atoi(str_delFee);
        i++;
        last_index = i;
    }
    fclose(file);
}

void writeFile(){
    file = fopen("costumer.txt","w");
    fprintf(file, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",ID,Name,Item_name,Quantity,Price,Discount,order_date,recieve_date,Delivery_fee,address,Phone_number,Delivery_man,Deliveryman_phone_number);
    for(int i = 0;i<last_index;i++){
        fprintf(file,"%d\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%s\t%d\t\t%s\t%s\t%s\t\t%s\n",c[i].id,c[i].name,c[i].item_name,c[i].quality,c[i].price,c[i].discount,c[i].ordered_date,c[i].recieved_date,c[i].delivery_fee,c[i].address,c[i].phone_number,c[i].deliveryman_name,c[i].deliveryman_phone_number);
    }
      fclose(file);
}

void addCustomer(){

    c[last_index].id = last_index+1;
    printf("Input Customer name: ");
    scanf("%s",&c[last_index].name);
    printf("Input item: ");
    scanf("%s",&c[last_index].item_name);
    printf("Input quality: ");
    scanf("%d",&c[last_index].quality);
    printf("Input price: ");
    scanf("%d",&c[last_index].price);
    printf("Input discount: ");
    scanf("%d",&c[last_index].discount);
    printf("Input ordered_date: ");
    scanf("%s",c[last_index].ordered_date);
    printf("Input recieved_date: ");
    scanf("%s",c[last_index].recieved_date);
    printf("Input delivery_fee: ");
    scanf("%d",&c[last_index].delivery_fee);
    printf("Input address: ");
    scanf("%s",c[last_index].address);
    printf("Input phone_number: ");
    scanf("%s",c[last_index].phone_number);
    printf("Input deliveryman_name: ");
    scanf("%s",c[last_index].deliveryman_name);
    printf("Input deliveryman_phone_number: ");
    scanf("%s",c[last_index].deliveryman_phone_number);
    last_index = last_index +1;
    writeFile();
    printf("New Customer has been added\n");
}

void displayAllcustomer() {
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",ID,Name,Item_name,Quantity,Price,Discount,order_date,recieve_date,Delivery_fee,address,Phone_number,Delivery_man,Deliveryman_phone_number);
    for ( int i=0; i<last_index; i++){
        printf("%d\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%s\t%d\t\t%s\t%s\t%s\t\t%s\n",c[i].id,c[i].name,c[i].item_name,c[i].quality,c[i].price,c[i].discount,c[i].ordered_date,c[i].recieved_date,c[i].delivery_fee,c[i].address,c[i].phone_number,c[i].deliveryman_name,c[i].deliveryman_phone_number);
    }
}

void updateCustomer(){
    int id;
    printf("Input customer id that you want to update: ");
    scanf("%d" ,&id);
    for(int i =0;i<last_index;i++){
        if(id == c[i].id){
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",ID,Name,Item_name,Quantity,Price,Discount,order_date,recieve_date,Delivery_fee,address,Phone_number,Delivery_man,Deliveryman_phone_number);
            printf("%d\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%s\t%d\t\t%s\t%s\t%s\t\t%s\n",c[id-1].id,c[id-1].name,c[id-1].item_name,c[id-1].quality,c[id-1].price,c[id-1].discount,c[id-1].ordered_date,c[id-1].recieved_date,c[id-1].delivery_fee,c[id-1].address,c[id-1].phone_number,c[id-1].deliveryman_name,c[id-1].deliveryman_phone_number);
            printf("Input Customer name: ");
            scanf("%s",&c[id-1].name);
            printf("Input item: ");
            scanf("%s",&c[id-1].item_name);
            printf("Input quality: ");
            scanf("%d",&c[id-1].quality);
            printf("Input price: ");
            scanf("%d",&c[id-1].price);
            printf("Input discount: ");
            scanf("%d",&c[id-1].discount);
            printf("Input ordered_date: ");
            scanf("%s",c[id-1].ordered_date);
            printf("Input recieved_date: ");
            scanf("%s",c[id-1].recieved_date);
            printf("Input delivery_fee: ");
            scanf("%d",&c[id-1].delivery_fee);
            printf("Input address: ");
            scanf("%s",c[id-1].address);
            printf("Input phone_number: ");
            scanf("%s",c[id-1].phone_number);
            printf("Input deliveryman_name: ");
            scanf("%s",c[id-1].deliveryman_name);
            printf("Input deliveryman_phone_number: ");
            scanf("%s",c[id-1].deliveryman_phone_number);
            writeFile();
            printf("Customer ID %d has been updated\n",id);
            break;
        }
        if(i == last_index-1){
            printf("Don't have that id.Please Try again\n");
        }
    }
}

void delete(){

    printf("Delete Costumer Information Function\n");
    int id;
    printf("Input costumer ID: ");
    scanf("%d",&id);
//   use write to delete information
    file = fopen("costumer.txt", "w");
    fprintf(file, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",ID,Name,Item_name,Quantity,Price,Discount,order_date,recieve_date,Delivery_fee,address,Phone_number,Delivery_man,Deliveryman_phone_number);
    if(id < 0 || id > last_index){
        printf("You entered invalid id\n");
    }else{
        for(int i = id-1;i<last_index-1;i++){
            c[i].id = c[i].id;
            strcpy(c[i].name,c[i+1].name);
            strcpy(c[i].item_name,c[i+1].item_name);
            c[i].quality = c[i+1].quality;
            c[i].price = c[i+1].price;
            c[i].discount = c[i+1].discount;
            strcpy(c[i].ordered_date,c[i+1].ordered_date);
            strcpy(c[i].recieved_date,c[i+1].recieved_date);
            c[i].delivery_fee = c[i+1].delivery_fee;
            strcpy(c[i].address,c[i+1].address);
            strcpy(c[i].phone_number,c[i+1].phone_number);
            strcpy(c[i].deliveryman_name,c[i+1].deliveryman_name);
            strcpy(c[i].deliveryman_phone_number,c[i+1].deliveryman_phone_number);
        }
        last_index--;
        printf("Customer ID %d has been deleted\n",id);
    }

    for(int i = 0;i<last_index;i++){
        fprintf(file,"%d\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%s\t%d\t\t%s\t%s\t%s\t\t%s\n",c[i].id,c[i].name,c[i].item_name,c[i].quality,c[i].price,c[i].discount,c[i].ordered_date,c[i].recieved_date,c[i].delivery_fee,c[i].address,c[i].phone_number,c[i].deliveryman_name,c[i].deliveryman_phone_number);
    }
    fclose(file);
}

void specific(){
    printf("Show the specific information:\n");
    int id_user;
    printf("Please input the id:");
    scanf("%d" ,&id_user);
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",ID,Name,Item_name,Quantity,Price,Discount,order_date,recieve_date,Delivery_fee,address,Phone_number,Delivery_man,Deliveryman_phone_number);
    for(int k=0 ;k<=i;k++){
        if(id_user==c[k].id){
            printf("%d\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%s\t%d\t\t%s\t%s\t%s\t\t%s\n",c[k].id,c[k].name,c[k].item_name,c[k].quality,c[k].price,c[k].discount,c[k].ordered_date,c[k].recieved_date,c[k].delivery_fee,c[k].address,c[k].phone_number,c[k].deliveryman_name,c[k].deliveryman_phone_number);
            break;
        }
        if(k==i){
                printf("Id not found.\n");
        }
    }

}

void clrscr(){
    system("@cls||clear");
}

void reset(){
    i =0;
    last_index = 0;
}
