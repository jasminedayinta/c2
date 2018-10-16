//
//  main.cpp
//  a3p3
//
//  Created by Jasmine Juwono on 20.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
JTSK-320112
a3-p3.c
Jasmine Dayinta
j.dayinta@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct list{
    char info;
    struct list *next;
    struct list *prev;
};

struct list* push_front(struct list *my_list, int value){
    struct list *newel;
    newel = (struct list *)malloc(sizeof(struct list));
    if(newel == NULL){
        printf("Error allocating memory \n");
        return my_list;
    }
    if(my_list == NULL){
        newel->next = NULL;
        newel->prev = NULL;
        newel->info = value;
        my_list = newel;
        return my_list;
    }else{
        newel->info = value;
        newel->next = my_list;
        my_list->prev = newel;
        newel->prev = NULL;
        return newel;
    }
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

struct list* delete_list(struct list *my_list, char ch){
    struct list *next, *prev, *curr, *start;
    curr = my_list;
    start = my_list;
    int count = 0;
    while(curr != NULL){
        if(curr->info == ch){
            next = curr->next;
            prev = curr->prev;
            if(curr->next != NULL){
                next->prev = prev;
            }
            if(curr->prev != NULL){
                prev->next = next;
            }
            if(curr->prev == NULL){
                free(curr);
                start = next;
                curr = next;
                curr->prev = NULL;
                count = 1;
                continue;
            }
            free(curr);
            curr = next;
            count = 1;
        }else{
            curr = curr->next;
        }
    }
    if(count == 0){
        printf("The element is not in the list!\n");
    }
    return start;
}

void dispose_list(struct list* my_list){
    struct list *nextelem;
    while (my_list != NULL) {
        nextelem = my_list->next;
        free(my_list);
        my_list = nextelem;
    }
}

void print_list(struct list * my_list){
    struct list * p ;
    for( p = my_list ; p ; p = p->next ) {
        printf ("%c ", p-> info ) ;
    }
    printf("\n");
}

int main (){
    struct list *my_list;
    my_list = NULL;
    while(1){
        char ch, a, b;
        ch = getchar();
        getchar();
        switch(ch){
            case '1':
                a = getchar();
                getchar();
                my_list = push_front(my_list,a);
                break;
            case '3':
                print_list(my_list);
                break;
            case '5':
                dispose_list(my_list);
                return 0;
            case '2':
                b = getchar();
                getchar();
                my_list=delete_list(my_list,b);
                break;
            case '4':
                my_list = reverse(my_list);
                print_list(my_list);
                my_list = reverse(my_list);
                break;
        }
    }
    return 0;
}

