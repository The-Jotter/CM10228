#include <stdio.h>
#include <stdlib.h>

typedef short ListValue;

typedef struct {
    ListValue        value;
    struct ListNode* next ;
} ListNode;

ListNode* new(ListValue value) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->next = (struct ListNode*)NULL;
    head->value = value;

    return head;
}

int length(ListNode* head) {
    int len = 1;

    ListNode* current = head;
    while(current != NULL && current->next != NULL) {
        current = (ListNode*)current->next;
        len++;
    }

    return len;
}

void append(ListNode* head, ListValue next) {
    ListNode* current = head;
    while(current->next != NULL) {
        current = (ListNode*)current->next;
    }

    ListNode* last = (ListNode*)malloc(sizeof(ListNode));
    last->next  = (struct ListNode*)NULL;
    last->value = next;

    current->next = (struct ListNode*)last;
}

void foreach(ListNode* list, void(callback)(ListValue) ) {
    ListNode* current = list;
    while(current->next != NULL) {
        callback(current->value);
        current = (ListNode*)current->next;
    }

    callback(current->value);
}

void printAsChar(ListValue value) {
    printf("%c", value);
}

int main(void) {
    ListNode* list = new('A');
    append(list, 'p');
    append(list, 'p');
    append(list, 'l');
    append(list, 'e');

    printf("This list is %d elements long!\n", length(list));

    foreach(list, printAsChar);
    printf("\n");

    return 0;
}