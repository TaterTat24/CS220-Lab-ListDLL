/** 
 * ===========================================================
 * Name: Benjamin Tat
 * Section: T6
 * Project: 
 * Purpose: List ADT as linked list
 * ===========================================================
 */
#include <stdio.h>
#include <assert.h>

#include "listAsDoubleLinkedList.h"

int main() {

    // Insert an appropriate test harness for your linked list implementation.  
    // Your tests will test each function when the list is empty, has a single element, and will also
    // test modifications to the head, tail, or middle elements.

    // You are not being judged/graded on the quality of your lab
    // However, it is in your best interest to make a high quality ADT for future assignments . . . hint hint

    DoubleLinkedList *DoubleLinkedList = createLinkedList();
    printf("%p\n", DoubleLinkedList);
    printLinkedList(DoubleLinkedList);
    assert(lengthOfLinkedList(DoubleLinkedList) == 0);

    insertElementLinkedList(DoubleLinkedList, 0, 5);
    printLinkedList(DoubleLinkedList);
    assert(lengthOfLinkedList(DoubleLinkedList) == 1);

    appendElementLinkedList(DoubleLinkedList, 9);
    printLinkedList(DoubleLinkedList);
    assert(lengthOfLinkedList(DoubleLinkedList) == 2);

    deleteElementLinkedList(DoubleLinkedList, 1);
    printLinkedList(DoubleLinkedList);
    assert(lengthOfLinkedList(DoubleLinkedList) == 1);

    deleteElementLinkedList(DoubleLinkedList, 0);
    printLinkedList(DoubleLinkedList);
    assert(lengthOfLinkedList(DoubleLinkedList) == 0);

    insertElementLinkedList(DoubleLinkedList, 0, 5);
    printLinkedList(DoubleLinkedList);
    assert(lengthOfLinkedList(DoubleLinkedList) == 1);

    appendElementLinkedList(DoubleLinkedList, 9);
    printLinkedList(DoubleLinkedList);
    assert(lengthOfLinkedList(DoubleLinkedList) == 2);

    //int nodeValue = getElementLinkedList(DoubleLinkedList, 0);
    //assert(nodeValue == 5);

    return 0;
}