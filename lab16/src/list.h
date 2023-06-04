#ifndef LIST_H
#define LIST_H

#include "entity.h"

typedef struct Node {
    Entity* entity;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

List* create_list();

void destroy_list(List* list);

void add_entity(List* list, Entity* entity);

void remove_entity(List* list, int index);

void sort_by_bow_weight(List* list);

void print_list(const List* list);

#endif  // LIST_H
