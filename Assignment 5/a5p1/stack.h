//
//  stack.h
//  a5p1
//
//  Created by Jasmine Juwono on 22.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a5-p1.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

struct stack{
    unsigned int count;
    int array[12];
};

struct stack push(struct stack s, int i);
struct stack pop(struct stack s);
struct stack empty(struct stack s);
struct stack isEmpty(struct stack s);

#endif /* stack_h */
