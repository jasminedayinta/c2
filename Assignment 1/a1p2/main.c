//
//  main.c
//  a1p2
//
//  Created by Jasmine Juwono on 08.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a1_p2.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
/*defining the macro by comparing the character
 with 1, which then gives the least significant
 bit*/
#define LEAST(C) {C & 1};

int main() {
  
    unsigned char c;
    scanf("%c", &c);
    getchar();
    int ch = LEAST(c);
        //created the variable ch that calls the macro LEAST
    
    printf("The decimal representation is: %d\n", c);
    printf("The least significant bit is: %d\n", ch);
    
    return 0;
}
