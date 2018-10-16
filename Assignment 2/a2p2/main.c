//
//  main.c
//  a2p2
//
//  Created by Jasmine Juwono on 09.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a2-p2.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s1, *s2, *result;
    
    s1 = (char*)malloc(100*sizeof(char));
    s2 = (char*)malloc(100*sizeof(char));
    if(s1 == NULL || s2 == NULL){
        exit(1);
    }
    
    /*getting the input, then taking the
     length of the string and cutting the end
     by using \0*/
    fgets(s1, 100, stdin);
    fgets(s2, 100, stdin);
    s1[strlen(s1)-1]='\0';
    s2[strlen(s2)-1]='\0';
    
    //allocating the result of the two strings
    result = (char*) malloc(((strlen(s1) +strlen(s2)))*sizeof(char));
    if(result == NULL)
    {
        exit(1);
    }
    
    char *result_ptr = result;
    
    for(char *ptr = s1; ptr < s1+strlen(s1); ptr++){
        *result_ptr = *ptr;
        result_ptr++;
    }
    for(char *ptr = s2; ptr < s2+strlen(s2); ptr++){
        *result_ptr = *ptr;
        result_ptr++;
    }
    
    //print the result
    printf("Result of concatenation: %s\n", result);
    
    //deallocating
    free(s1);
    free(s2);
    free(result);
    
    return 0;
}
