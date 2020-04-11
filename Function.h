#include<stdio.h>
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

struct CustomerBlacklist {
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
struct CustomerBlacklist bc[100];

int i=0;
char str_id[10];
char str_quan[10];
char str_price[10];
char str_discount[10];
char str_delFee[10];
char recieve_date[20];
char order_date[20];
char title[100];

void	display_Menu(){
	
}
void	Option()  {
	
}
void	readfile(){
	
}
void	writeFile() {
	
}
void	reset(){
	
}
void	displayallcustomer(){
	
}
void	deleting() {
	
}
void	updateCustomer(){
	
}
void	specific_information_custormer(){
	
}
void	addCustomer(){
	
}

