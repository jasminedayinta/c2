//
//  linked_list.h
//  a3p4
//
//  Created by Jasmine Juwono on 16.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//defining the struct list
struct list {
    int info;
    struct list* next;
};

struct list* push_front(struct list *my_list, int value);
struct list* push_back(struct list* my_list, int value);
void print_elements(struct list* my_list);
void dispose_list(struct list* my_list);
struct list* pop(struct list* my_list);
void print_list(struct list * my_list);

#endif /* linked_list_h */
