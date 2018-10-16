//
//  stack.c
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

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack push(struct stack s, char *word){
    if(s.count == 30){
        printf("Pushing Stack Overflow\n");
        return s;
    }
    
    strcpy(s.w[s.count].word, word);
    s.count++;
    return s;
};

struct stack pop(struct stack s){
    if(s.count == 0){
        printf("Popping Stack Underflow\n");
        return s;
    }
    
    strcpy(s.w[s.count - 1].word, "");
    s.count--;
    return s;
}

char* top(struct stack s){
    char *ch = (char*)malloc(strlen(s.w[s.count - 1].word) * sizeof(char));
    strcpy(ch, s.w[s.count - 1].word);
    return ch;
}

//struct stack empty(struct stack s){
//    printf("Emptying Stack ");
//    while(s.count > 0){
//        printf("%d ",s.array[s.count - 1]);
//        s.count--;
//    }
//    printf("\n");
//    return s;
//}

int isEmpty(struct stack s){
    if(s.count == 0){
        return 1;
    }else{
        return 0;
    }
}
