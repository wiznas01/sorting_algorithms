#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/**
 * struct deck_node_s - Doubly linked list node for a card deck
 *
 * @card: Integer value of the card (0-100)
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct deck_node_s
{
    int card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void recursive_quick_sort(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void sort_deck(deck_node_t **deck);
void swap_nodes(listint_t *node1, listint_t *node2);
void merge_sort_recursive(int *array, size_t start, size_t end);
void merge(int *array, size_t start, size_t middle, size_t end);
void heapify(int *array, size_t size, size_t index, size_t total_size);
void swap(int *a, int *b);
int get_max(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);
void bitonic_merge(int *array, size_t start, size_t size, int dir);
void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir);
void quick_sort_hoare(int *array, size_t size);
void quick_sort_hoare_recurse(int *array, size_t low, size_t high, size_t size);
size_t hoare_partition(int *array, size_t low, size_t high, size_t size);

#endif
