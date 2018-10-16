//
//  main.c
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

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    int i;
    struct stack s;
    s.count = 0;
    
    scanf("%d", &i);
    getchar();

    s = push(s, i);
    
    return 0;
}
