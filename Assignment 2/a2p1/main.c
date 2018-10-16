//
//  main.c
//  a2p1
//
//  Created by Jasmine Juwono on 09.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a2-p1.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int z, i;
    float *arr;
    
    //asking user for size of array
    scanf("%d", &z);
    getchar();
    
    //allocating memory for the array
    arr = (float*)malloc(sizeof(float)*z);

    if (arr == NULL){
        exit(1);
    }
    
    //putting the inputted values in the array
    for (i = 0; i < z; i++){
        scanf("%f", &arr[i]);
    }
    
    /*using pointer arithmetic to count the number of elements before
    the negative value. you do this by iterating until the end of the
     array (arr + z) and then subtracting the arr from the pointer to get
     the "distance" which is then the value before the negative value*/
    for(float* ptr = arr; ptr < arr + z; ptr++){
        if(*ptr < 0){
            int c = (ptr - arr);
            printf("Before the first negative value: %d elements\n", c);
        }
    }
    
    free(arr);
    
    return 0;
}
