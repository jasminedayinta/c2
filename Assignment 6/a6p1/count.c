//
//  main.c
//  a6p1
//
//  Created by Jasmine Juwono on 23.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a6-p1.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char file[256];
    char text[256];
    int i = 0;
    
    fgets(file, sizeof(file), stdin);
    file[strlen(file)-1] = '\0';
    
    FILE *fp;
    
    fp = fopen(file, "r");
    if(fp == NULL){
        printf("Error!\n");
        exit(1);
    }
    
    while(fscanf(fp,"%s",text) != EOF){
        int j = 0, n = 0, word = 0, next = 0;
        while (j < strlen(text)){
            if(text[j] == ' ' || text[j] == ','
               || text[j] == '?' || text[j] == '!'
               || text[j] == '.' || text[j] == '\t'
               || text[j] == '\r' || text[j] == '\n'){
                if (word == 1){
                    word = 0;
                    n++;
                    next = 0;
                }else{
                    next = 1;
                }
            }else if(next == 1){
                next = 0;
                n++;
            }
            j++;
        }
        n++;
        i+=n;
    }
    
    printf("The file contains %d words.\n", i);
    fclose(fp);
    
    return 0;
}
