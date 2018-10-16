//
//  main.c
//  a1p7
//
//  Created by Jasmine Juwono on 14.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a1-p7.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

//void function that set three bits to 1 by using
//a for loop and if statement. For loop to iterate
//it 7 times (since it is only 8 bits assigned) and
//then if statement to check if it is equal to the
//parameters set
void set3bits(char c, int x, int y, int z){
    int i;
    for(i = 7; i >= 0; i--){
        if(i == x || i == y || i ==z){
            printf("1");
        }
        else{
            printf("%d",((c >> i) & 1));
        }
    }
}

int main()
{
    int i, j, k, l;
    unsigned char c;
    c = getchar();
    
    scanf("%d %d %d",&i,&j,&k);
    int dec = c;
    
    printf("The decimal representation is: %d\n",dec);
    printf("The binary representation is: ");
    
    for(l = 7; l >= 0; l--){
        printf("%d",((c >> l) & 1));
    }
    printf("\nAfter setting the bits: ");
    
    //calling the void function and uses the parameters
    //set by the user when they inputted the values
    set3bits(c,i,j,k);
    printf("\n");
    
    return 0;
}

