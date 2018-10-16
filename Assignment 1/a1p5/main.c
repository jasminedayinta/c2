//
//  main.c
//  a1p5
//
//  Created by Jasmine Juwono on 14.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a1-p5.c
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
    printf("The backwards binary representation is: ");
    
    for(x = 0; x < bit; x++){
        printf("%d", ((c >> x) & 1));
    }
    
    printf("\n");
    return 0;
}
