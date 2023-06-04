#ifndef ENTITY_H
#define ENTITY_H

typedef struct {
    int is_acoustic;
    char maker[50];
    int year;
    struct {
        float weight;
        char material[50];
    } bow;
    int size;
} Entity;

Entity* create_entity(int is_acoustic, const char* maker, int year, float bow_weight, const char* bow_material, int size);

void destroy_entity(Entity* entity);

#endif  // ENTITY_H
