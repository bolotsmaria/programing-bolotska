#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List* create_list() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void destroy_list(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        destroy_entity(current->entity);
        free(current);
        current = next;
    }
    free(list);
}

void add_entity(List* list, Entity* entity) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->entity = entity;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void remove_entity(List* list, int index) {
    if (list->head == NULL  index < 0) {
        return;
    }

    if (index == 0) {
        Node* next = list->head->next;
        destroy_entity(list->head->entity);
        free(list->head);
        list->head = next;
        return;
    }

    Node* current = list->head;
    Node* previous = NULL;
    int current_index = 0;

    while (current != NULL && current_index < index) {
        previous = current;
        current = current->next;
        current_index++;
    }

    if (current != NULL) {
        previous->next = current->next;
        destroy_entity(current->entity);
        free(current);
    }
}

void sort_by_bow_weight(List* list) {
    if (list->head == NULL  list->head->next == NULL) {
        return;
    }

    int swapped;
    Node* current;
    Node* last = NULL;

    do {
        swapped = 0;
        current = list->head;

        while (current->next != last) {
            if (current->entity->bow.weight < current->next->entity->bow.weight) {
                Entity* temp = current->entity;
                current->entity = current->next->entity;
                current->next->entity = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

void print_list(const List* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

Node* current = list->head;
    while (current != NULL) {
        printf("Maker: %s\n", current->entity->maker);
        printf("Year: %d\n", current->entity->year);
        printf("Bow Weight: %.2f\n", current->entity->bow.weight);
        printf("Bow Material: %s\n", current->entity->bow.material);
        printf("Size: %d\n", current->entity->size);
        printf("\n");
        current = current->next;
    }
}
