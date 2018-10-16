//
//  main.c
//  a1p6
//
//  Created by Jasmine Juwono on 14.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a1-p6.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, bit;
    unsigned char c;
    //getting the decimal representation of the char
    //by setting it an int
    c = getchar();
    int y = c;
    
    printf("The decimal representation is: %d\n", y);
    
    for(bit = 0; (1 << bit) <= c; bit++);
    
    printf("The binary representation is: ");
    //since it is represented in 8 bit, we set i to 7
    //and it decrements until it hits 0
    for(x = 7; x >= 0; x--){
        printf("%d", ((c >> x) & 1));
    }
    
    printf("\n");
    return 0;
}

