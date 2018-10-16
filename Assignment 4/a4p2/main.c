//
//  main.c
//  a4p2
//
//  Created by Jasmine Juwono on 20.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a4-p2.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//define pointer to function
void one(char *ch);
void two(char *ch);
void three(char *ch);
void four(char *ch);

//string becomes uppercase
void one(char *ch){
    char c;
    while((*ch) != '\0'){
        c = toupper(*ch);
        printf("%c", c);
        ch++;
    }
    printf("\n");
}

//string becomes lowercaase
void two(char *ch){
    char c;
    while(*ch != '\0'){
        c = tolower(*ch);
        printf("%c", c);
        ch++;
    }
    printf("\n");
}

//characters from uppercase become lowercase, vice versa
void three(char *ch){
    char c;
    while(*ch != '\0'){
        if(*ch >= 65 && *ch <=90){
            c = tolower(*ch); //switch to lowercase
            printf("%c", c);
            ch++;
        }else if(*ch >= 90 && *ch <= 122){
            c = toupper(*ch); //switch to uppercase
            printf("%c", c);
            ch++;
        }else{
            printf("%c", *ch);
            ch++;
        }
    }
    printf("\n");
    
}

void four(char *ch){
    exit (1);
}

int main(){
    char ch[100];
    int i;
    
    fgets(ch, 200, stdin);
    ch[strlen(ch) - 1] = '\0';
    
    void(*fptr[4])(char*) = {one, two, three, four};
    
    while(1){
        scanf("%d", &i);
        i = i - 1; //read the array from the very beginning
        fptr[i](ch);
    }
    return 0;
}
