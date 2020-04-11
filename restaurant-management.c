#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int counter = 0,choice;
FILE *file;
                                              ////////declare////////
char nameTitle[100],foodTitle[100],priceTitle[100],amountTitle[100],bookTableTitle[100],totalTitle[100];
char str_price[100],str_amount[100],str_bookTable[100],str_total[100];
char temp_name[100];
int temp_price,temp_amount,temp_total,temp_i;
                                                   ///////struct-customer////////
struct Customer {
	char name[100],food[100];
	int price,amount,book_table,total;
}customers[100];
                                                   ////////struct-food//////////
struct Food {
	char name[100];
	int price;
}food[6];
                                                    ///////////////////void///////////////
void clearScreen(),initialFood(),readFile(),writeFile(),orderFood(char name[100]),bookTable(char name[100]),displayInvoice(char name[100]),cancelBooking(char name[100]),promotion(),exit();
                                                    //////////////////main////////////////
int i;
int main(){
	system("color 70");
	initialFood();
	readFile();
	do{
		printf("\n\n----------------------------WELCOME TO RESTAURANT MANAGEMENT SYSTEM--------------------\n");
		printf("1.Order Food\n");
		printf("2.Book table\n");
		printf("3.Display invoice payment\n");
		printf("4.Cancel Booking\n");
		printf("5.Our Promotion\n");
		printf("6.Exit(Write Data into File)\n");
		printf("\n\n----Note you have to choose exit in order to write all the information into your file----\n");
		printf("\n\n>>Input your choice<< \n\n-->>\t");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					system("cls");
					printf("\n>>Input your Name Please<< \n\n-->>\t");
					scanf("%s",&temp_name);
					orderFood(temp_name);
					break;
			case 2:
					system("cls");
					printf("Input Customer Name: ");
					scanf("%s",&temp_name);
					bookTable(temp_name);
					break;
			case 3:
					system("cls");
					printf("Input Customer Name: ");
					scanf("%s",&temp_name);
					displayInvoice(temp_name);
					break;
			case 4:
					system("cls");
					printf("Input Customer Name: ");
					scanf("%s",&temp_name);
					cancelBooking(temp_name);
					break;
			case 5:
					system("cls");
					promotion();
			        break;
			case 6:
                    printf("\n>>Thanks For Welcome Good Luck<<");
                    exit(0);
			        break;
		}
	}while(choice >= 1 && choice <= 5);
	writeFile();
	return 0;
}
                                                ////////void-initialfood////////
void initialFood(){
	strcpy(food[0].name,"FriedRice");
	food[0].price = 2000;
	strcpy(food[1].name,"Burger");
	food[1].price = 20000;
	strcpy(food[2].name,"Pizza");
	food[2].price = 40000;
	strcpy(food[3].name,"Kimchi");
	food[3].price = 12000;
	strcpy(food[4].name,"Shushi");
	food[4].price = 8000;
	strcpy(food[5].name,"Spaghetti");
	food[5].price = 5000;
}

                                               ////////void-readfile/////////
void readFile(){
	file = fopen("Data.txt","r");
	fscanf(file,"%s %s %s %s %s %s",nameTitle,foodTitle,priceTitle,amountTitle,bookTableTitle,totalTitle);
	while(fscanf(file,"%s %s %s %s %s %s",customers[counter].name,customers[counter].food,str_price,str_amount,str_bookTable,str_total) != EOF){
		customers[counter].price = atoi(str_price);
		customers[counter].amount = atoi(str_amount);
		customers[counter].book_table = atoi(str_bookTable);
		customers[counter].total = atoi(str_total);
		counter++;
	}
	fclose(file);
}
                                            ///////void-writefile////////
void writeFile(){
	file = fopen("Data.txt","w");
	if(file == NULL){
		printf("Cant find a file\n");
	}
	fprintf(file,"%-30s%-20s%-10s%-10s%-20s%-10s\n","Name","Food","Price","Amount","Book_Table","Total_Price");
	for(i =0;i<counter;i++){
		fprintf(file,"%-30s%-20s%-10d%-10d%-20d%-10d\n",customers[i].name,customers[i].food,customers[i].price,customers[i].amount,customers[i].book_table,customers[i].total);
	}
	fclose(file);
}

int checkName(char name[100]){
	for(i = 0;i<counter;i++){
		if(strcmp(strlwr(name),strlwr(customers[i].name)) == 0){
			temp_i = i;
			return 1;
		}else if(i == counter-1){
			return 0;
		}
	}
}

int checkTable(int table){
	for(i=0;i<counter;i++){
		if(table == customers[i].book_table){
			return 0;
		}else if(i == counter-1){
			return 1;
		}
	}
}

int checkTableAndName(char name[100],int table){
	int j;
	for(i =0;i<counter;i++){
		if(strcmp(strlwr(name),strlwr(customers[i].name)) == 0){
			for(j =i;j<counter;j++){
				if(table == customers[i].book_table){
					return 1;
				}else if(j == counter-1){
					return 0;
				}
			}
		}else if(i == counter-1){
			return 0;
		}
	}
}
                                            ////////void-orderFood//////
void orderFood(char name[100]){
	int check_name;
	check_name = checkName(name);
	if(check_name == 0){
		int choice,amount,total;
		printf("\n>>>Here are the Food that we provide for our customer<<<\n\n");
		printf("1.%-30sprice\t%d\triel\n",food[0].name,food[0].price);
		printf("2.%-30sprice\t%d\triel\n",food[1].name,food[1].price);
		printf("3.%-30sprice\t%d\triel\n",food[2].name,food[2].price);
		printf("4.%-30sprice\t%d\triel\n",food[3].name,food[3].price);
		printf("5.%-30sprice\t%d\triel\n",food[4].name,food[4].price);
		printf("6.%-30sprice\t%d\triel\n",food[5].name,food[5].price);
		printf("\n\n>>>Which one do you want to order<<<\n\n-->>\t ");
		scanf("%d",&choice);
		if(choice >= 1 && choice <= 6){
			printf("\n\n>>>How many dish do you want<<<\n\n-->> ");
			scanf("%d",&amount);
			switch(choice){
				case 1:
						total = amount * food[0].price;
						strcpy(customers[counter].name,name);
						strcpy(customers[counter].food,food[0].name);
						customers[counter].amount = amount;
						customers[counter].price = food[0].price;
						customers[counter].total = total;
						counter++;
						printf("\n<<Note>> Your order is complete\n");
						break;
				case 2:
						total = amount * food[1].price;
						strcpy(customers[counter].name,name);
						strcpy(customers[counter].food,food[1].name);
						customers[counter].amount = amount;
						customers[counter].price = food[1].price;
						customers[counter].total = total;
						counter++;
						printf("\n<<Note>> Your order is complete\n");
						break;
				case 3:
						total = amount * food[2].price;
						strcpy(customers[counter].name,name);
						strcpy(customers[counter].food,food[2].name);
						customers[counter].amount = amount;
						customers[counter].price = food[2].price;
						customers[counter].total = total;
						counter++;
						printf("\n<<Note>> Your order is complete\n");
						break;
				case 4:
						total = amount * food[3].price;
						strcpy(customers[counter].name,name);
						strcpy(customers[counter].food,food[3].name);
						customers[counter].amount = amount;
						customers[counter].price = food[3].price;
						customers[counter].total = total;
						counter++;
						printf("\n<<Note>> Your order is complete\n");
						break;
				case 5:
						total = amount * food[4].price;
						strcpy(customers[counter].name,name);
						strcpy(customers[counter].food,food[4].name);
						customers[counter].amount = amount;
						customers[counter].price = food[4].price;
						customers[counter].total = total;
						counter++;
						printf("\n<<Note>> Your order is complete\n");
						break;
				case 6:
						total = amount * food[5].price;
						strcpy(customers[counter].name,name);
						strcpy(customers[counter].food,food[5].name);
						customers[counter].amount = amount;
						customers[counter].price = food[5].price;
						customers[counter].total = total;
						counter++;
						printf("\n<<Note>> Your order is complete\n");
						break;
			}
		}else {
			printf("You choose invalid number,Please choose again\n");
			orderFood(name);
		}
	}else {
		printf("This name is already exist,Please input another name\n");
	}
}


                                             /////////void-booktable////////
void bookTable(char name[100]){
	int check_name,check_table,table,bol = 1;
	check_name = checkName(name);
	if(check_name != 0){
		printf("---------------------We have 20 tables for our customer from 1 to 20 -------------------\n");
		do{
			printf("Which table do you want sit ");
			scanf("%d",&table);
			if(table != 0){
				check_table = checkTable(table);
				if(check_table != 0){
					customers[temp_i].book_table = table;
					bol = 0;
					printf("You have booked table (%d)\n",table);
					break;
				}else {
					printf("This table is not available,Please input again\n");
				}
			}else {
				printf("Table 0 is not valid\n");
			}
		}while(bol != 0);
	}else{
		printf("This name doesn't exist in our booking menu\n");
	}
}

                                              ///////void-promotion//////
void promotion(){
	printf("\n\nCouple-Set: Kimchi with Shushi\t\t\t\t\t15000\triel");
	printf("\n\nExtra-Set:  Sharksoup with fricerice and Shushi\t\t\t20000\triel");
	printf("\n\nTriple-Set: Fricenoodle with Kimchi and Spaghetti\t\t30000\triel");
}

                                              ////////void-exit////////
//void exit(0){
	//printf("\n>>Thanks For Welcome Good Luck<<");
//}


                                            ////////void-Invoice/////
void displayInvoice(char name[100]){
	int check_name;
	check_name = checkName(name);
	if(check_name != 0){
		if(customers[temp_i].book_table != 0){
			printf("\n\n-----------------------------------------------------Invoice-------------------------------------------------------\n");
			printf("%-30s%-20s%-10s%-10s%-20s%-10s\n","Name","Food","Price","Qauntity","Booking_Table","Total");
			printf("%-30s%-20s%-10d%-10d%-20d%-10d\n",customers[temp_i].name,customers[temp_i].food,customers[temp_i].price,customers[temp_i].amount,customers[temp_i].book_table,customers[temp_i].total);
		}else {
			printf("This customer hasn't booked the table yet\n");
		}
	}else{
		printf("This customer doesn't exist.\n");
	}


}
                                             ///////void-Cancel//////
void cancelBooking(char name[100]){
	int check_name,check_table,table,bol = 1;;
	check_name = checkName(name);
	if(check_name != 0){
		do{
			printf("Which table do you want to cancel: ");
			scanf("%d",&table);
			if(table != 0){
				check_table = checkTableAndName(name,table);
				if(check_table == 1){
					for(int i = temp_i;i<counter;i++){
	            		strcpy(customers[i].name,customers[i+1].name);
            			strcpy(customers[i].food,customers[i+1].food);
            			customers[i].price = customers[i+1].price;
            			customers[i].amount = customers[i+1].amount;
            			customers[i].book_table = customers[i+1].book_table;
            			customers[i].total = customers[i+1].total;
        			}
        			counter--;
        			bol = 0;
        			printf("Your cancel is complete\n");
				}else {
					printf("Sorry this table is not right one,Choose again\n");
				}
			}else{
				printf("Table 0 is not valid,Please choose again\n");
			}

		}while(bol != 0);
	}else {
		printf("This customer doesn't exist in our list\n");
	}
}
