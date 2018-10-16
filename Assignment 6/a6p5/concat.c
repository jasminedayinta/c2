//
//  main.c
//  a6p5
//
//  Created by Jasmine Juwono on 27.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/* JTSK-320112
 a6-p5.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE **file1, *file2;
    char c[256];
    char ch[64];
    int val = 0;
    int i = 0;
    int l = 0;
    int m;
    memset(ch, '\0', 64);
    
    scanf("%d", &val);
    getchar();
    
    file1 = (FILE**)malloc(sizeof(FILE)*val);
    
    for(m = 0; m <= val; m++){
        fgets(c, 256, stdin);
        c[strlen(c) - 1] = '\0';
        
        file1[m] = fopen(c, "r");
        if(file1[m] == NULL){
            exit(1);
        }
    }
    
    file2 = fopen("output.txt", "w");

    while(i != val){
        memset(ch, '\0', 64);
        while(fread(ch, 64, 1, file1[i]) == 0){
            fwrite(ch, 1, 64, file2);
            fprintf(file2, "\r\n");
            printf("%s\n", ch);
            i++;
            
            if(i == val){
                break;
                l = 1;
            }
        }
        
        while(l == 0){
            fwrite(ch, 1, 64, file2);
            printf("%s\n", ch);
        }
    }
   
    free(file1);
    fclose(file2);
    
    return 0;
}
