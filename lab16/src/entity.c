#include "entity.h"
#include <stdlib.h>
#include <string.h>

Entity* create_entity(int is_acoustic, const char* maker, int year, float bow_weight, const char* bow_material, int size) {
    Entity* entity = (Entity*)malloc(sizeof(Entity));
    entity->is_acoustic = is_acoustic;
    strncpy(entity->maker, maker, sizeof(entity->maker) - 1);
    entity->year = year;
    entity->bow.weight = bow_weight;
    strncpy(entity->bow.material, bow_material, sizeof(entity->bow.material) - 1);
    entity->size = size;
    return entity;
}

void destroy_entity(Entity* entity) {
    free(entity);
}
