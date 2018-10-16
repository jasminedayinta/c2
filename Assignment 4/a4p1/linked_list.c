//
//  linked_list.c
//  a3p4
//
//  Created by Jasmine Juwono on 16.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list* push_front(struct list *my_list, int value)
{
    struct list *newel;
    newel = (struct list*) malloc(sizeof(struct list));
    if (newel == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    newel->info = value;
    newel->next = my_list;
    return newel;
}

struct list* push_back(struct list* my_list, int value)
{
    struct list *cursor, *newel;
    
    cursor = my_list;
    newel = (struct list*) malloc(sizeof(struct list));
    if (newel == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    newel->info = value;
    newel->next = NULL;
    if (my_list == NULL)
        return newel;
    while (cursor->next != NULL)
        cursor = cursor->next;
    cursor->next = newel;
    return my_list;
}

void print_elements(struct list* my_list)
{
    while (my_list != NULL) {
        printf("%d ", my_list->info);
        my_list = my_list->next;
    }
    printf("\n");
}

void dispose_list(struct list* my_list)
{
    struct list *nextelem;
    while (my_list != NULL) {
        nextelem = my_list->next;
        free(my_list);
        my_list = nextelem;
    }
}

//pop function that removes the first element
struct list* pop(struct list* my_list){
    if(my_list != NULL){
        struct list *p = my_list->next;
        free(my_list);
        return p;
    }
    return my_list;
}

void print_list(struct list * my_list) {
    struct list * p ;
    for( p = my_list ; p ; p = p -> next ) {
        printf ("%d ", p-> info ) ;
    }
    printf("\n");
}
