//
//  main.c
//  a3p2
//
//  Created by Jasmine Juwono on 16.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a3-p2.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

//defining the struct list
struct list {
    int info;
    struct list* next;
};

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

struct list* insert(struct list* my_list, int x, int value){
    int i = 0;
    struct list *j, *k;
    struct list *newel;
    
    newel = (struct list *) malloc(sizeof(struct list));
    if (newel == NULL){
        return my_list;
    }
    j = my_list;
    while(i < x - 1){
        j = j->next;
        i++;
    }
    k = j;
    k = k->next;
    newel->info = value;
    newel->next = k;
    j -> next = newel;
    return my_list;
}

struct list* reverse(struct list* my_list){
    struct list *prev = NULL;
    struct list *curr;
    struct list *next;
    curr = my_list;
    
    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void print_elements(struct list* my_list){
    while (my_list != NULL) {
        printf("%d ", my_list->info);
        my_list = my_list->next;
    }
    printf("\n");
}

void dispose_list(struct list* my_list){
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

int main(){
    struct list *my_list = NULL;
    int count = 0;
    //using switch-case to do the different tasks
    //accroding to what is inputted
    while(1){
        char ch;
        ch = getchar();
        getchar();
        int x, y, z;
        switch(ch){
            case 'a':
                scanf("%d", &x);
                getchar();
                my_list = push_back(my_list, x);
                count++;
                break;
            case 'b':
                scanf("%d", &x);
                getchar();
                my_list = push_front(my_list, x);
                count++;
                break;
            case 'r':
                my_list = pop(my_list);
                count--;
                break;
            case 'p':
                print_list(my_list);
                break;
            case 'q':
                dispose_list(my_list);
                exit(1);
                break;
            case 'i':
                scanf("%d %d", &y, &z);
                getchar();
                if(y < 0 || y > count){
                    printf("Invalid position!\n");
                }else{
                    my_list = insert(my_list, y, z);
                }
                break;
            case 'R':
                my_list = reverse(my_list);
                break;
        }
    }
    
    return 0;
}
