//
// Created by aidankeefe on 10/27/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "Arena.h"


/*
 * create an arena according
 */
Arena* create_arena(const size_t size_in_bytes) {
    Arena* arena = malloc(sizeof(Arena)+ size_in_bytes * sizeof(char));
    if (!arena)
        return nullptr;


    arena->currentPointer = arena->buffer;
    arena->size = size_in_bytes;

    return arena;
}

static void* arena_ptr_align(void* ptr, const size_t alignment) {
    uintptr_t p = (uintptr_t)ptr;
    uintptr_t aligned = (p + alignment - 1) & ~(alignment - 1);
    return (void*)aligned;
}

void* arena_alloc(Arena arena[static 1], size_t size) {
    if (arena == NULL) {
        return nullptr;
    }
    if (arena->currentPointer - arena->buffer + size > arena->size) {
        return nullptr;
    }
    size_t alignment = alignof(max_align_t);
    void* ptr = arena_ptr_align(arena->currentPointer, alignment);
    arena->currentPointer = ptr + size ;
    return ptr;
}

ARENA_STATUS arena_free(Arena arena[static 1]) {
    free(arena);
    return ARENA_OK;
}

ARENA_STATUS arena_clear(Arena arena[static 1]) {
    memset(arena->buffer, 0, arena->size);
    arena->currentPointer = arena->buffer;
    return ARENA_OK;
}

/*
 * This clears the arena above the given point to_remove. this will overwrite everything if you are not careful.
 */
ARENA_STATUS arena_pop(Arena arena[static 1], void* to_remove){
    if (!arena || !to_remove) {
        return ARENA_POP_ERROR;
    }
    if ((BYTE*)to_remove < arena->currentPointer && (BYTE*)to_remove >= &arena->buffer[arena->size]) return ARENA_POP_ERROR;
    memset(to_remove, 0, arena->currentPointer - (BYTE*)to_remove);
    arena->currentPointer = to_remove;
    return ARENA_OK;
}
