//
//  main.c
//  a6p6
//
//  Created by Jasmine Juwono on 27.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/* JTSK-320112
 a6-p6.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file1, *file2;
    char c[3], c1, c2;
    
    //opening the first file
    file1 = fopen("chars.txt", "r");
    if (file1 == NULL){
        exit(1);
    }else{
        fread(c, 1, 3, file1);
        c1 = c[0];
        c2 = c[2];
        }
    
    //opening the second file
    file2 = fopen("codesum.txt", "w+");
    if (file2 == NULL){
        printf("File not open\n");
        exit(1);
    }
    
    int result = (int)c1 + (int)c2;
    fwrite(&result, sizeof(int), 1, file1);

    //closing the files
    fclose(file1);
    fclose(file2);
    
    return 0;
}
