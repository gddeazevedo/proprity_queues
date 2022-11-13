#include <stdio.h>
#include <string.h>
#include "src/heap/heap.h"


void main() {
    char vetor[] = "mixtring";
    build_heap_with_heap_down(vetor, strlen(vetor));
    printf("%s\n", vetor);
    change_priority(vetor, strlen(vetor) - 1, 'z', strlen(vetor) - 1);
    printf("%s\n", vetor);
}