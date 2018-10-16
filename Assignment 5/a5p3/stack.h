//
//  stack.h
//  a5p3
//
//  Created by Jasmine Juwono on 27.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a5-p3.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

struct problem{
    char word[30];
} Problem;

struct stack{
    unsigned int count;
    struct problem w[30];
};

struct stack push(struct stack s, char *word);
struct stack pop(struct stack s);
char* top(struct stack s);
//struct stack empty(struct stack s);
int isEmpty(struct stack s);

#endif /* stack_h */

