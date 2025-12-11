//
// Created by aidankeefe on 10/27/25.
//

#ifndef ACO_ARENA_H
#define ACO_ARENA_H

#include <stdint.h>
#include <stddef.h>

typedef enum ARENA_STATUS {
    ARENA_OK,
    ARENA_ALLOCATION_ERROR,
    ARENA_CREATION_ERROR,
    ARENA_POP_ERROR,
} ARENA_STATUS;

#define BYTE uint8_t

typedef struct Arena {
    BYTE* currentPointer;
    size_t size;
    BYTE buffer[];
} Arena;


Arena* create_arena(size_t size_in_bytes);
void* arena_alloc(Arena* arena, size_t size);
ARENA_STATUS arena_free(Arena* arena);
ARENA_STATUS arena_clear(Arena* arena);
ARENA_STATUS arena_pop(Arena* arena, void* to_remove);

#endif //ACO_ARENA_H