#include "heap.h"

int get_parent(int child) {
    return (child - 1) / 2;
}

int get_left_child(int parent) {
    return 2 * parent + 1;
}

int get_right_child(int parent) {
    return 2 * parent + 2;
}

void build_heap_with_heap_up(char* array, int length) {
    for (int current_node = 1; current_node < length; current_node++) {
        heap_up(array, current_node);
    }
}

void build_heap_with_heap_down(char* array, int length) {
    for (int i = length / 2; i >= ROOT; i--) {
        heap_down(array, i, length);
    }
}

void heap_up(char* heap, int child) {
    int parent = get_parent(child);

    while (parent >= ROOT && heap[parent] < heap[child]) {
        swap(heap, child, parent);
        child = parent;
        parent = get_parent(child);
    }
}

void heap_down(char* heap, int parent, int heap_size) {
    while (get_left_child(parent) <= heap_size) {
        int left = get_left_child(parent);
        int right = get_right_child(parent);
        int child = left;

        if (right <= heap_size && heap[right] > heap[left]) {
            child = right;
        }

        if (heap[parent] < heap[child]) {
            swap(heap, child, parent);
            parent = child;
        } else {
            break;
        }
    }
}

void heap_sort(char* array, int length) {
    build_heap_with_heap_down(array, length);
    int heap_size = length - 1;

    for (int i = length - 1; i > ROOT; i--) {
        swap(array, ROOT, i);
        heap_size--;
        heap_down(array, ROOT, heap_size);
    }
}

void change_priority(char* heap, int current_node, char new_priority, int heap_size) {
    char old_priority = heap[current_node];
    heap[current_node] = new_priority;

    if (old_priority < new_priority) {
        heap_up(heap, current_node);
    } else {
        heap_down(heap, current_node, heap_size);
    }
}