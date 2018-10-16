//
//  main.c
//  a2p4
//
//  Created by Jasmine Juwono on 13.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a2-p4.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, x, y, z;
    scanf("%d %d %d", &a, &b, &c);
    int ***m;
    //dynamically allocating the number of rows
    m = (int ***)malloc(sizeof(int **)*a);
    if(!m)
    {
        printf("Error!");
        exit(1);
    }
    for(x = 0; x < a; x++){
        //dynamically allocating the number of columns
        m[x]= (int **)malloc(sizeof(int *)*b);
        for(y = 0; y < b; y++){
            //dynamically alloacting the depth (the third dimension)
            m[x][y]=(int *)malloc(sizeof(int)*c);
            if(!m)
            {
                printf("Error!");
                exit(1);
            }
            for(z = 0; z < c; z++){
                scanf("%d",&m[x][y][z]);
            }
        }
    }
    //printing the results
    for(z = 0; z < c; z++){
        printf("Section %d:\n",z+1);
        for(y = 0; y < b; y++){
            for(x = 0; x < a; x++){
                printf("%d ",m[x][y][z]);
        }
        printf("\n");
    }
}
    free(m);

    return 0;
}
