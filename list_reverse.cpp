#include <iostream>
#include <stdio.h>
typedef struct node{
    int           data;
    struct node*  next;
    node(int d):data(d), next(nullptr){}
}node;

void reverse(node* head)
{
    if (!head)
        return;
    reverse(head->next);
    printf("%d\n",head->data);
}

int main(int argc, char const *argv[])
{
    node n1(1);
    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = nullptr;

    reverse(&n1);
    return 0;
}
