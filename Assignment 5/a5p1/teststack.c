//
//  main.c
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

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    int i = 0;
    struct stack s;
    s.count = 0;
    
    while(1){
        char ch;
        ch = getchar();
        getchar();
        switch(ch){
            case 's':
                scanf("%d",&i);
                getchar();
                s = push(s,i);
                break;
            case 'p':
                s = pop(s);
                break;
            case 'e':
                s = empty(s);
                break;
            case 'q':
                printf("Quit\n");
                return 0;
        }
    }
    return 0;
}
