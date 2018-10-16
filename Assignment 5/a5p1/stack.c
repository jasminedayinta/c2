//
//  stack.c
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

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack push(struct stack s, int i){
    if(s.count < 12){
        s.array[s.count] = i;
        s.count+=1;
        printf("Pushing %d\n", i);
    }else{
        printf("Pushing Stack Overflow\n");
    }
    return s;
};

struct stack pop(struct stack s){
    if(s.count == 0){
        printf("Popping Stack Underflow\n");
    }else{
        printf("Popping %d\n", s.array[s.count - 1]);
        s.count--;
    }
    return s;
}

struct stack empty(struct stack s){
    printf("Emptying Stack ");
    while(s.count > 0){
        printf("%d ",s.array[s.count - 1]);
        s.count--;
    }
    printf("\n");
    return s;
}

struct stack isEmpty(struct stack s){
    if(s.count == 0){
        printf("Stack is empty\n");
    }else{
        printf("Stack is not empty\n");
    }
    return s;
}

