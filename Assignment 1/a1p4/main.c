//
//  main.c
//  a1p4
//
//  Created by Jasmine Juwono on 13.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a1-p4.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#define INTERMEDIATE

int main(){
    int x, y;
    int z = 0;
    scanf("%d",&x);
    getchar();
    
    int i[x],j[x];
    
    for(y = 0; y < x; y++){
        scanf("%d",&i[y]);
        getchar();
    }
    for(y = 0; y < x;y++){
        scanf("%d",&j[y]);
        getchar();
        }
    #ifdef INTERMEDIATE
        printf("The intermediate product values are:\n");
        for(y = 0; y < x; y++){
            printf("%d\n",i[y]*j[y]);
        }
    #endif
        for(y = 0; y < x; y++){
            z += i[y]*j[y];
        }
    
        printf("The scalar product is: %d\n",z);
        return 0;
    }

