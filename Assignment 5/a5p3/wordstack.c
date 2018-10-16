//
//  main.c
//  a5p3
//
//  Created by Jasmine Juwono on 27.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a5-p3.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(){
    int i = 0;
    int x = 1;
    struct stack s;
    s.count = 0;
    
    while(x){
        char word[256];
        fgets(word, 256, stdin);
        word[strlen(word) - 1] = '\0';
    
        if(strcmp(word, "exit") == 0){
            x = 0;
        }else{
            char c[30];
            strcpy(c, "");
            for(i = 0; i < strlen(word); i++){
                if(word[i] == ' '){
                    s = push(s, c);
                    strcpy(c, "");
                }else{
                    char *ch = (char*)malloc(sizeof(word[i]));
                    *ch = word[i];
                    strcat(c, ch);
                    free(ch);
                    
                    if(i == strlen(word) - 1){
                        s = push(s, c);
                        strcpy(c, "");
                    }
                }
            }
            
            char word2[256];
            strcpy(word2, "");
            while(!isEmpty(s)){
                strcat(word2, top(s));
                strcat(word2, " ");
                s = pop(s);
            }
            
            word2[strlen(word2) - 1] = '\0';
            if(strcmp(word, word2) == 0){
                printf("The sentence is palindromic by words!\n");
            } else {
                printf("The sentence is not palindromic by words!\n");
            }
        }
    }
    return 0;
}
