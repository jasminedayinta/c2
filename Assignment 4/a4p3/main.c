//
//  main.c
//  a4p3
//
//  Created by Jasmine Juwono on 20.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a4-p3.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//define pointer to function
void a(int *arr, int i);
void d(int *arr, int i);
void e(int *arr, int i);

int comp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

//ascending order
void a(int *arr, int i){
    qsort(arr,i,sizeof(int),comp);
    int n;
    for(n = 0; n < i; n++){
        printf("%d ",arr[n]);
    }
    printf("\n");
}

//descending order
void d(int *arr, int i){
    qsort(arr,i,sizeof(int),comp);
    int n;
    for(n = i - 1; n >= 0; n--){
        printf("%d ",arr[n]);
    }
    printf("\n");
}

//quits the program
void e(int *arr, int i){
    exit (0);
}

void (*fptr[3])(int*,int)={a,d,e};

int main(){
    int z, i;
    char ch;
    
    scanf("%d",&z);
    getchar();
    int arr[z];
    
    //putting the inputted values into an array
    for(i = 0; i < z; i++){
        scanf("%d",&arr[i]);
        getchar();
    }

    while(1){
        ch = getchar();
        getchar();
        if(ch == 'a'){
            fptr[0](arr,z);
        }else if(ch == 'd'){
            fptr[1](arr,z);
        }else if(ch == 'e'){
            fptr[2](arr,z);
        }else{
            getchar();
        }
    }
    return 0;
}
