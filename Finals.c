#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  ARRAY_SIZE   0XC

/******************************************************************************
 * Data Structure Definition:                                                 *
 ******************************************************************************/
typedef struct {  
	char name[24];          // Chocolate name  
 	int  weight;            // Chocolate weight in grams  
}chocoDesc;
 
typedef struct {
   char prodID[8];          //  product ID uniquely identifies the products; 
    chocoDesc prodDesc;      //  product description 
 	float prodPrice;         //  product price 
  	int prodQty;             //  product count or quantity   
}product;                   //  product record  

//Array implementation of List
typedef struct {
	product prod[ARRAY_SIZE];
	int count;  //Actual # of elements in the list
}ProdArrList;             

 
/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
ProdArrList populateProdList();      //Complete Code Given. Populate the list implemented using the array.
void displayHeader();               // Display the fields of the records such as  not the data 

void displayProdArrList(ProdArrList L);  
void deleteElem(ProdArrList *L, char ID[]);  // The function will delete the first occurrence of the record bearing the given ID. 
                                             // Succeeding elements should be moved 1 index lower. 
/************************************************************************************
 * READ ME FIRST before ANSWERING                                                   *
 *   1)  To facilitate the checking of the machine problem, follow the instructions *
 *       in each PROBLEM #.                                                         *
 *   2)  To accomplish the task for each PROBLEM, a series of function calls may be *
 *       necessary.                                                                 *  
 *   3)  Write you answer BELOW THE COMMENTS. DO NOT DELETE COMMENTS                *
 *   4)  Uncomment or copy the print statement in each PROBLEM#  if the task is     *
 *       completed.                                                                 *
 ***********************************************************************************/
 int main( ) 
 {	
 /*----------------------------------------------------------------------------------
 * 	Problem #1 :: a) Populates the list by calling populateProdList()              *
 *                b) Displays the product list by calling displayProdArrList().    *   
 *                c) Input from the keyboard an ID number, then call               * 
 *                   deleteElem() and displayProdArrList()                         *
 *---------------------------------------------------------------------------------*/	
   printf("\n\n\nProblem #1:: ");
   printf("\n------------");
   
   
   
   //Write your code below
   // Problem #1 a)
   ProdArrList productList = populateProdList();
   
   // Problem #1 b)
   displayProdArrList(productList);
   
   // Problem #1 c)
   char inputID[8];
   printf("\nEnter ID : ");
   scanf("%s", inputID);
   deleteElem(&productList, inputID);
   displayProdArrList(productList);
   
 	return 0;
}

/***********************************************************
 *  Problem1   :: Function Definitions                          *
 ************************************************************/
ProdArrList populateProdList()
{ 
   int count;    //No. of chocolate records in data
	product data[] = { 	{"1701", {"Toblerone", 135}, 150.75, 20}, 
						{"1356", {"Ferrero", 200}, 250.75, 85},
						{"1109", {"Patchi", 50}, 99.75, 35}, 
						{"1550", {"Cadbury", 120}, 200.00, 30},
						{"1807", {"Mars", 100}, 150.75, 20}, 
						{"1201", {"Kitkat", 50}, 97.75, 40},
						{"1201", {"Ferrero", 100},150.50, 50}, 
						{"1701", {"Toblerone", 50}, 90.75, 80},
						{"1701", {"Meiji", 75}, 75.50, 60},
						{"1310", {"Nestle", 100}, 124.50, 70},
						{"1807", {"Valor", 120}, 149.50, 90},
						{"1455", {"Tango", 75}, 49.50, 100},
						{"1703", {"Toblerone", 100}, 125.75, 60},
						{"1688", {"Lindt", 100}, 250.75, 15},
						{"1688", {"Guylian", 50}, 99.75, 35},
					 };
	count = sizeof(data)/sizeof(data[0]);		
	
	ProdArrList L = { .count = ARRAY_SIZE } ;
	memcpy(L.prod, data, sizeof(product) * ARRAY_SIZE );		 
			           
   return  L;
}

void displayHeader()
{
	printf("\n\n%-7s", "ID");
	printf("%-12s","Choco Name");
	printf("%-15s","Choco Weight");
	printf("\n%-7s%-12s%-15s", "--", "----------", "------------");
}
void displayProdArrList(ProdArrList L)
{
	int i;
	printf("\n\nDetails of the List :: ");
	printf("\n---------------------");
	displayHeader(); 
	
	//Write your code here. Hint: Traverse the list 
	//and for each record display the ID, choco name, and weight
	for (i = 0; i < L.count; ++i) {
		printf("\n%-7s", L.prod[i].prodID);
		printf("%-12s", L.prod[i].prodDesc.name);
		printf("%-15d", L.prod[i].prodDesc.weight);
	}
	
	printf("\n\n"); system("Pause");                //Leave this line	
	printf("\n\nNo. of elements :: %d", L.count);   //Complete this line and uncomment
}

void deleteElem(ProdArrList *L, char ID[])
{
    //Write your code here
    int j,i, found = 0;

    // Find the index of the record with the given ID
    for (i = 0; i < L->count; ++i) {
        if (strcmp(L->prod[i].prodID, ID) == 0) {
            found = 1;
            break;
        }
    }

    // If found, delete the record and move the succeeding elements 1 index lower
    if (found) {
        for (j = i; j < L->count - 1; ++j) {
            L->prod[j] = L->prod[j + 1];
        }
        L->count--;
        printf("\nRecord with ID %s deleted successfully.", ID);
    } else {
        printf("\nRecord with ID %s not found.", ID);
    }
}
