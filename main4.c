#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index){

    item_list[index].price = price;
    item_list[index].sku = (char *)malloc(strlen(sku) + 1);
    item_list[index].category = (char *)malloc(strlen(category) + 1);
    item_list[index].name = (char *)malloc (strlen(name) + 1);

    strcpy(item_list[index].sku,sku);
    strcpy(item_list[index].category , category);
    strcpy(item_list[index].name , name);
}

void free_items(Item *item_list, int size){
    for (int i = 0; i < size; i++){

        free (item_list[i].sku);
        free (item_list[i].category);
        free (item_list[i].name);
        
    }

    free (item_list);
}

double average_price(Item *item_list, int size){
    double total = 0;
    double average = 0;

    for (int i = 0; i<size; i++){
        total += item_list[i].price;
        
    }
    
    average = total / size;
    return (average);

}

void print_items(Item *item_list, int size){
    int i;
    for (i=0; i<size; i++)
    {
        printf("############################\n");

        printf("Item Name: %s \n", item_list[i].name);
        printf("Item SKU: %s \n",item_list[i].sku );
        printf("Item Category: %s \n", item_list[i].category);
        printf("Item Price: $%.2f \n", item_list[i].price);
    }

}

int main(int argc ,char * argv[]) {
    int i = 0;
    int size = 5;
    int skumatch = 0;
    int found = 0;
    Item *item_list = (Item *)malloc (sizeof(Item)*5);

    add_item(item_list, 4.99, "12345", "fruit", "Apple", 0 );
    add_item(item_list, 7.99, "23456", "fruit", "Banana", 1 );
    add_item(item_list, 99.99, "76432", "Electronics", "Television", 2 );
    add_item(item_list, 699.99, "09876", "Appliance", "Fridge", 3 );
    add_item(item_list, 199.99, "98675", "Appliance", "Microwave", 4 );

    print_items(item_list, size);
    printf("############################\n");
    printf("Average price of items: %0.2f\n" ,average_price(item_list, size));
    printf("############################\n");

    while( i < size){
        if(strcmp(item_list[i].sku, argv[1]) == 0){
            printf("A match for the input SKU has been found: %s \n", item_list[i].name);
            found = 1;
            break;
        }

        i++;
    }

    if(found == 0){
        printf("No item matches the SKU: %s", item_list[i].sku);
    }


    free_items(item_list, size);

    return 0;
}