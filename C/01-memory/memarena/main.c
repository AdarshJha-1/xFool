#include <stdio.h>
#include <stdlib.h>
#include <stdalign.h>
#include <stddef.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct
{
    unsigned char *memory;
    size_t capacity;
    size_t offset;
} Arena;

int arena_create(size_t, Arena *ar);
void arena_destroy(Arena *);
void *arena_alloc(Arena *ar, size_t size);

int arena_create(size_t capacity, Arena *ar)
{
    unsigned char *mem = malloc(capacity);
    if (mem == NULL)
    {
        return FAILURE;
    }
    ar->memory = mem;
    ar->capacity = capacity;
    ar->offset = 0;
    return SUCCESS;
}

void arena_destroy(Arena *ar)
{
    if (ar->memory != NULL)
    {
        free(ar->memory);
        ar->memory = NULL;
    }
    ar->capacity = 0;
    ar->offset = 0;
}

void *arena_alloc(Arena *ar, size_t size)
{
    if (size > ar->capacity - ar->offset)
    {
        return NULL;
    }
    void *ptr = ar->memory + ar->offset;
    ar->offset += size;
    return ptr;
}

int main(void)
{
    Arena ar = {0};
    int ok = arena_create(1024, &ar);
    if (ok < 0)
    {
        printf("ERROR :: error creating arena\n");
        return 1;
    }
    arena_destroy(&ar);

    // Learning about alignment

    printf("Alignment of char = %zu\n", alignof(char));
    printf("Alignment of int = %zu\n", alignof(int));
    printf("Alignment of double = %zu\n", alignof(double));
    printf("Alignment of struct = %zu\n", alignof(struct { int a; int b; double c; }));
    printf("Alignment of max_align_t = %zu\n", alignof(max_align_t));
    return 0;
}