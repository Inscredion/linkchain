#include"linklist.h"
#include<stdlib.h>
#include<stdio.h>

void NullErr() {
    printf("ERROR! The linklist is null!");
}

void OutOfRange() {
    printf("ERROR! The index is out of range!");
}

Node* CreateNode(int newVal) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = newVal;
    newNode->next = NULL;
    return newNode;
}

void AddTailNode(Node* newNode, Node* node) {
    if (node == NULL)
    {
        node = newNode;
        exit(0);
    }
    Node* p = node;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
}

void DeleteTailNode(Node* node) {
    if (node == NULL)
        exit(0);
    Node* p = node;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}

Node* CreateList(int len) {
    int newVal;
    scanf_s("%d", &newVal);
    Node* head = CreateNode(newVal);
    Node* newNode;
    for (int i = 1; i < len; i++)
    {
        scanf_s("%d", &newVal);
        newNode = CreateNode(newVal);
        AddTailNode(newNode, head);
    }
    return head;
}

void Visit(Node* node) {
    if (node == NULL) {
        NullErr();
        exit(1);
    }
    Node* p = node;
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

bool SearchNode(Node* node, int newVal) {
    if (node == NULL) {
        NullErr();
        return false;
    }
    Node* p = node;
    while (p != NULL)
    {
        if (newVal == p->val)
            return true;
        p = p->next;
    }
    return false;
}

void DeleteNode(Node* node, int index) {
    if (node == NULL) {
        NullErr();
        exit(1);
    }
    if (index > ListLength(node)) {
        OutOfRange();
        exit(1);
    }
    Node* p = node;
    for (int i = 1;i < index - 1;i++) {
        p = p->next;
    }
    Node* temp = p->next;
    p->next = p->next->next;
    free(temp);
}

void AddNode(Node* node, int index, int newVal) {
    if (node == NULL) {
        NullErr();
        exit(1);
    }
    if (index > ListLength(node) || index < 0) {
        OutOfRange();
        exit(1);
    }
    Node* p = node;
    Node* newNode = CreateNode(newVal);
    //if (index == 0) {
    //    newNode->next = node;
    //    node = newNode;
    //    return ;
    //}
    for (int i = 1;i < index ;i++) {
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
}

void AlterNode(Node* node, int index, int newVal) {
    if (node == NULL) {
        NullErr();
        exit(1);
    }
    if (index > ListLength(node)) {
        OutOfRange();
        exit(1);
    }
    Node* p = node;
    for (int i = 1;i < index;i++) {
        p = p->next;
    }
    p->val = newVal;
}

void DestroyList(Node* node) {
    if (node == NULL) {
        NullErr();
        exit(0);
    }
    Node* p = node;
    while (p->next != NULL)
    {
        node = node->next;
    }
}

int ListLength(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int len = 0;
    Node* p = node;
    while (true)
    {
        if (p == NULL)
            break;
        len++;
        p = p->next;
    }
    return len;
}
