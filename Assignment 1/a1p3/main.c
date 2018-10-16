//
//  main.c
//  a1p3
//
//  Created by Jasmine Juwono on 09.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a1-p3.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

//the three macros needed which calculates the max
//min and the mid range
#define MAX(A, B) (((A) > (B)) ? (A) : (B))
#define MIN(A, B) (((A) < (B)) ? (A) : (B))
#define MID_RANGE(A, B) ((A) + (B))/2

int main() {
    
    int x, y, z;
  
    //asking user for input
    scanf("%d %d %d", &x, &y, &z);
    double A = x, B = y, C = z;
    //calling the macro set earlier in the code
    double w = MID_RANGE((MAX(MAX(A,B), C)), (MIN(MIN(A,B), C)));
   
    printf("The mid-range is: %.6lf\n", w);
   
    return 0;
}
