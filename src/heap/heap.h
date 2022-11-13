#ifndef HEAP_H
#define HEAP_H

#include "../helpers/helpers.h"

#define ROOT 0

int get_parent(int child);
int get_left_child(int parent);
int get_right_child(int parent);
void build_heap_with_heap_up(char* array, int length);
void build_heap_with_heap_down(char* array, int length);
void heap_up(char* heap, int child);
void heap_down(char* heap, int parent, int heap_size);
void heap_sort(char* array, int length);
void change_priority(char* heap, int current_node, char new_priority, int heap_size);

#endif