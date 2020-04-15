#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int last_index;
char No[100];
char Name[100];
char ID[100];
char Item_name[100];
char Quantity[100];
char Price[100];
char Discount[100];
char Delivery_fee[100];
char address[100];
char Phone_number[100];
char Delivery_man[100];
char Delivery_phone_number[100];
char Total[100];

FILE *file;
int choice;
struct Customer {
    char name[50];
    char item_name[100];
    char ordered_date[100],recieved_date[100];
    char address[100];
    char phone_number[20];
    char payment_type[100];
    char delivery_name[100],delivery_phone_number[20];
    char status[100];
    int No,delivery_fee,discount,quantity,cus_ID,price;
    float total;
};

struct Customer c[100];


int i;
char str_No[10];
char str_ID[10];
char str_quan[10];
char str_price[10];
char str_discount[10];
char str_delFee[10];
char recieve_date[20];
char order_date[20];
char str_total[10];

void display_Menu();
void option();
void readFile();
void writeFile();
void addCustomer();
void displayAllcustomer();
void updateCustomer();
void deleting();
void specific();
void clrscr();
void reset();


#endif
