//
//  main.c
//  a5p5
//
//  Created by Jasmine Juwono on 27.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a5-p5.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person{
    char name[50];
    int age;
};

int value(const void *x, const void *y){
    return (int)(*(double*)y - *(double*)x);
}

int names(const void *x, const void *y){
    const struct person *one = x;
    const struct person *two = y;
    
    return(strcmp(one->name,two->name));
}

int ages(const void *x, const void *y){
    const struct person *one = x;
    const struct person *two = y;
    
    return(one->age - two->age);
}

void print(struct person *p, int i){
    int x;
    for(x = 0; x < i; x++){
        printf("%s:%d",p[x].name,p[x].age);
        if(x < i - 1){
            printf(" ");
        }
    }
    printf("\n");
}

int main(){
    int i,j;
    double *a;
    struct person *p;
    
    scanf("%d",&i);
    getchar();
    
    a = malloc(sizeof(double)*i);
    p = malloc(sizeof(struct person)*i);
    
    if(a == NULL){
        exit(1);
    }
   
    for(j = 0; j < i; j++){
        scanf("%lf",&a[j]);
        getchar();
    }
    
    for(j = 0; j < i; j++){
        fgets(p[j].name,sizeof(p[j].name), stdin);
        
        p[j].name[strlen(p[j].name) - 1] = '\0';
        scanf("%d",&p[j].age);
        getchar();
    }
    
    qsort(a, i, sizeof(double), value);
    
    printf("Decreasingly sorted floats:\n");
    for(j = 0; j < i; j++){
        printf("%.3lf",a[j]);
        if(j < i - 1){
            printf(" ");
        }
    }
    
    printf("\nAlphabetically sorted structs (name):\n");
    qsort(p, i, sizeof(struct person),names);
    print(p,i);
    
    printf("Increasingly sorted structs (age):\n");
    qsort(p, i,sizeof(struct person),ages);
    print(p,i);
    
    free(a);
    free(p);
          
    return 0;
}
