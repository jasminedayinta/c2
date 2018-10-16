//
//  main.c
//  a3p4
//
//  Created by Jasmine Juwono on 16.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int main(){
    struct list *my_list = NULL;
    
    //using switch-case to do the different tasks
    //accroding to what is inputted
    while(1){
        char ch;
        ch = getchar();
        getchar();
        int x;
        switch(ch){
            case 'a':
                scanf("%d", &x);
                getchar();
                my_list=push_back(my_list, x);
                break;
            case 'b':
                scanf("%d", &x);
                getchar();
                my_list = push_front(my_list, x);
                break;
            case 'r':
                my_list = pop(my_list);
                break;
            case 'p':
                print_list(my_list);
                break;
            case 'q':
                dispose_list(my_list);
                exit(1);
                break;
        }
    }
    
    return 0;
}
