/** 
 * ================================================================
 * Name: Benjamin Tat
 * Section: T6
 * Project: Implementation of Double-Linked List Library
 * =================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#include "listAsDoubleLinkedList.h"

DoubleLinkedList* createLinkedList(){
    DoubleLinkedList *list = malloc(sizeof(DoubleLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->numberOfElements = 0;
    return list;
}

int lengthOfLinkedList(DoubleLinkedList* list){
    return list->numberOfElements;
}

void printLinkedList(DoubleLinkedList* list){
    for (Node *current = list->head; current != NULL; current = current->next){
        printf("%d ", current->data);
    }
    printf("\n");
}

void insertElementLinkedList(DoubleLinkedList* list, int position, int element){
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = element;

    if (lengthOfLinkedList(list) == 0){
        list->head = node;
        list->tail = node;
        list->numberOfElements++;
    } else if (position == 0){
        node->next = list->head;
        list->head->prev = node;
    } else if (position == lengthOfLinkedList(list)-1){
        list->tail->prev = list->tail;
        list->tail = node;
        list->numberOfElements++;
    } else {
        Node *currentNode = list->head;
        int currentPosition = 0;
        while (currentPosition != position-1){
            currentNode = currentNode->next;
            currentPosition++;
        }
        
        //somewhere in here is broken
        Node *temp = currentNode;
        node->next = temp->next;
        node->prev = temp;
        node->next->prev = node;
        temp->next = node;
        list->numberOfElements++;
    }
}

void appendElementLinkedList(DoubleLinkedList* list, int element){
    Node *node = malloc(sizeof(node));
    node->next = NULL;
    node->data = element;

    list->tail->next = node;
    list->tail = node;
    list->numberOfElements++;
}

void deleteElementLinkedList(DoubleLinkedList* list, int position){
    if (lengthOfLinkedList(list) == 1){
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->numberOfElements--;
    } else if (position == 0) {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->numberOfElements--;
    } else if (position == lengthOfLinkedList(list)-1) {
        Node *currentNode = list->head;
        int currentPosition = 0;
        while (currentPosition != position-1){
            currentNode = currentNode->next;
            currentPosition++;
        }

        Node *temp = currentNode;
        temp->next = NULL;
        free(list->tail);
        list->tail = currentNode;
        list->numberOfElements--;
    }
    else {
        Node *currentNode = list->head;
        int currentPosition = 0;
        while (currentPosition != position){
            currentNode = currentNode->next;
            currentPosition++;
        }

        Node *nodeToDelete = currentNode;

        Node *currentNode2 = list->head;
        currentPosition = 0;
        while (currentPosition != position-1){
            currentNode2 = currentNode2->next;
            currentPosition++;
        }

        Node *nodeBefore = currentNode2;
        nodeBefore->next = nodeToDelete->next;
        free(nodeToDelete);
        list->numberOfElements--;
    }
}

//Broken here too
int getElementLinkedList(DoubleLinkedList* list, int position){
    Node *currentNode = list->head;
    int currentPosition = 0;
    while (currentPosition != position-1){
        currentNode = currentNode->next;
        currentPosition++;
    }

    int nodeNumber = currentNode->data;
    return nodeNumber;
}