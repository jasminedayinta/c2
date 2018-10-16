//
//  main.c
//  a2p3
//
//  Created by Jasmine Juwono on 13.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a2-p3.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

//matrix multiplication function
void matrix_mul(int**mA, int **mB, int n, int m, int p){
    int a, b, c, d;
    int **res;
    //dynamically allocating the number of rows from the
    //matrix A
    res = (int **)malloc(sizeof(int)*n);
    if(!res){
        printf("Error!");
        exit(1);
    }
    for(a = 0; a < n; a++){
        //dynamically allocating the number of columns
        //from matrix B
        res[a] = (int *)malloc(sizeof(int)*p);
        if(!res){
            printf("Error!");
            exit(1);
        }
        for(b = 0; b < p; b++){
            d = 0;
            for(c = 0; c < m; c++){
                //multiplying the two matrices to get the result
                d += mA[a][c] * mB[c][b];
            }
            res[a][b] = d;
            printf("%d ", res[a][b]);
        }
        printf("\n");
    }
    free(res);
}

int main(){
    int n, m, p, a, b;
    //asking user for the dimension of the matrix
    scanf("%d %d %d",&n,&m,&p);
    int **mA, **mB;
    mA = (int **)malloc(sizeof(int *)*n);
    if(!mA){
        printf("Error!");
        exit(1);
    }
    mB = (int **)malloc(sizeof(int *)*m);
    if(!mB){
        printf("Error!");
        exit(1);
    }
    
    //asking the user for the values to put
    //in the matrix and dynamically allocating them
    for(a = 0; a < n; a++){
        mA[a] = (int *)malloc(sizeof(int)*m);
        if(!mA){
            printf("Error!");
            exit(1);
        }
        for(b = 0; b < m; b++){
            scanf("%d",&mA[a][b]);
        }
    }
    for(a = 0; a < m; a++){
        mB[a]=(int *)malloc(sizeof(int)*p);
        if(!mB){
            printf("Error!");
            exit(1);
        }
        for(b = 0; b < p; b++){
            scanf("%d",&mB[a][b]);
        }
    }
    //printing the result
    printf("Matrix A:\n");
    for(a = 0; a < n; a++){
        for(b = 0; b < m; b++){
            printf("%d ",mA[a][b]);
        }
        printf("\n");
    }
    
    printf("Matrix B:\n");
    
    for(a = 0; a < m; a++){
        for(b = 0; b < p; b++){
            printf("%d ",mB[a][b]);
        }
        printf("\n");
    }
    printf("The multiplication result AxB:\n");
    matrix_mul(mA,mB,n,m,p);
    
    free(mA);
    free(mB);
    
    return 0;
}
