//
//  stack.c
//  a5p2
//
//  Created by Jasmine Juwono on 26.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a5-p2.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack push(struct stack s, int i){
    if(s.count != 0){
        printf("Pushing Stack Overflow\n");
        return s;
    }
    
    printf("The binary representation of %d is ", i);
    
    if(i == 0){
        s.array[s.count] = 0;
        s.count++;
    }else{
        while(i > 0){
            s.array[s.count] = i%2;
            s.count++;
            i /= 2;
        }
    }
    s = pop(s);
    return s;
}


struct stack pop(struct stack s){
    if(s.count == 0){
        printf("Popping Stack Underflow\n");
        return s;
    }
    
    while(s.count){
        printf("%d", s.array[s.count - 1]);
        s.array[s.count - 1] = 0;
        s.count--;
    }
    printf(".\n");
    return s;
}

struct stack empty(struct stack s){
    printf("Emptying Stack ");
    while(s.count > 0){
        printf("%d ",s.array[s.count - 1]);
        s.array[s.count - 1] = 0;
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
