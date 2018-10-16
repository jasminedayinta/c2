//
//  main.c
//  a4p4
//
//  Created by Jasmine Juwono on 21.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a4-p4.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person{
    char name[30];
    int age;
};

//define pointer to function
int name(struct person p, struct person p2);
int age(struct person p, struct person p2);
void bubblesort(struct person *arr, int i, int (*compare)(struct person p, struct person p2));
void printarray(struct person *arr, int i);

//comparing names
int name(struct person p, struct person p2){
    if(strcmp(p.name, p2.name) > 0){
        return 1;
    }else if(strcmp(p.name, p2.name) < 0){
        return -1;
    }else if(p.age > p2.age){
        return 1;
    }else if(p.age < p2.age){
        return -1;
    }
    return 0;
}

//comparing age
int age(struct person p, struct person p2){
    if(p.age > p2.age){
        return 1;
    }else if(p.age < p2.age){
        return -1;
    }else if(strcmp(p.name, p2.name) > 0){
        return 1;
    }else if(strcmp(p.name, p2.name) < 0){
        return -1;
    }
    return 0;
    
}

void bubblesort(struct person *arr, int i, int (*compare)(struct person p, struct person p2)){
    int j, sort;
    struct person temp;
    do{
        sort = 0;
        for(j = 1; j < i; j++){
            if(compare(arr[j-1], arr[j]) > 0){
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                sort = 1;
            }
        }
    }
    while(sort == 1);
}

void printarray(struct person *arr, int i){
    int j;
    for(j = 0; j < i; j++){
        printf("{%s, %d}; ", arr[j].name, arr[j].age);
    }
    printf("\n");
}

int main() {
    int a, b;
    
    //input for number of people
    scanf("%d", &a);
    getchar();
    
    //dynamically allocating the inputs
    struct person *arr = (struct person *) malloc(sizeof(struct person)* a);
    for(b = 0; b < a; b++){
        fgets(arr[b].name, sizeof(arr[b].name), stdin);
        arr[b].name[strlen(arr[b].name) - 1] = '\0';
        scanf("%d", &arr[b].age);
        getchar();
    }
    
    int (*fptr[2])(struct person p, struct person p2) = {name, age};
    
    bubblesort(arr, a, fptr[0]);
    printarray(arr, a);
    bubblesort(arr, a, fptr[1]);
    printarray(arr, a);
    
    free(arr);
    
    return 0;
}
