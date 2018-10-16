//
//  main.c
//  a1p1
//
//  Created by Jasmine Juwono on 08.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a1-p1.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
/*defining the macro that swaps two variables by creating a temp.
 A and B are the two define variables and C is a free variable,
 which will be used to define the type*/
#define SWAP(A, B, C) {C Temp;Temp=A;A=B;B=Temp;}

int main() {
    int a, b;
    double c, d;
    
    //asking user for input
    scanf("%d%d", &a, &b);
    scanf("%lf%lf", &c, &d);
   
    //calling the macro SWAP
    SWAP(a,b,int);
    SWAP(c,d,double);
    
    //printing the result
    printf("After swapping:\n%d\n%d\n%.6lf\n%.6lf\n",a,b,c,d);
    
    return 0;
}
