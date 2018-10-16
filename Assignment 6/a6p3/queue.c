//
//  queue.c
//  a6p3
//
//  Created by Jasmine Juwono on 27.02.18.
//  Copyright © 2018 Jasmine Juwono. All rights reserved.
//

/*
 JTSK-320112
 a6-p3.c
 Jasmine Dayinta
 j.dayinta@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//static void copy_to_node(Item item, Node *pn);
//static void copy_to_item(Node *pn, Item *pi);

void initialize_queue(Queue *pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
    return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
    return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
    return pq->items;
}

int enqueue(Item item, Queue *pq)
{
    if(queue_is_full(pq)){
        return -1;
    }
    
    Node *n;
    n = malloc(sizeof(struct node));
    
    if(n == NULL){
        return -1;
    }
    
    if(pq->items < MAXQUEUE){
        n->item = item;
        n->next = NULL;
        
        if(pq->items == 0){
            pq->front = n;
            pq->rear = n;
        }else if(pq->items == 1){
            pq->front->next = n;
            pq->rear = n;
        }else{
            pq->rear->next = n;
            pq->rear = n;
        }
        pq->items++;
        return 0;
    }else{
        return -1;
    }
}

int dequeue(Item *pitem, Queue *pq){
    if(queue_is_empty(pq)){
        return -1;
    }
    
    Node *n;
    n = pq->front;
    *pitem=n->item;
    pq->front = pq->front->next;
    free(n);
    pq->items--;
    
    if(pq->items == 0){
        pq->front = pq->rear = NULL;
    }
    
    
    return 0;
}

void empty_queue(Queue *pq){
    Item dummy;
    while (!queue_is_empty(pq)) {
        dequeue(&dummy, pq);
    }
}

void print(const Queue *pq){
    if(pq->items == 0){
        printf("content of the queue: ");
    }else{
    printf("content of the queue: ");
    Node *n;
    n = pq->front;
   
    if(n==pq->rear){
        printf("%d ",n->item);
    }else{
        while(n!=pq->rear){
            printf("%d ",n->item);
            n = n->next;
            
            if(n==pq->rear){
                printf("%d ",n->item);
                }
            }
        }
    }   
    printf("\n");
}

/*static void copy_to_node(Item item, Node *pn)
{
    pn->item = item;
}

static void copy_to_item(Node *pn, Item *pi)
{
    *pi = pn->item;
}
*/
