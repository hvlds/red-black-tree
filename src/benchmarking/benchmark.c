#include "benchmarking/benchmark.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "benchmarking/avl_tree.h"
#include "benchmarking/binary_search_tree.h"
#include "benchmarking/colors.h"
#include "benchmarking/comparators.h"
#include "benchmarking/debug.h"
#include "benchmarking/red_black_tree.h"
#include "rbtree.h"

void shuffle(int* array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void benchmark() {
    unordered_insertion();
}

void unordered_insertion() {
    printf("\nSTART BENCHMARKING\n");

    int iterations = 10;

    // Generate 10000 elements in order and
    int count = 100;
    int values[count];
    for (int i = 0; i < count; i++) {
        values[i] = i + 1;
    }
    shuffle(values, count);

    printf("\tInsertion of %d ordered/ascendent integers\n", count);

    clock_t start;

    // Insert RB Tree
    for (int it = 1; it <= iterations; it++) {
        start = clock();
        RBT_t* rbTree = RBT_new_int();
        for (int i = 0; i < count; i++) {
            RBT_insert(rbTree, values[i], &values[i], sizeof(values[i]));
        }

        printf("\tInsertion Time RBT[%d]: %.6fms\n", it, (double)(clock() - start) / (CLOCKS_PER_SEC / 1000));

        RBT_destroy(rbTree);
    }

    // Insert alternative RBT (cstuff)

    for (int it = 1; it <= iterations; it++) {
        start = clock();
        binary_tree* rbt = new_binary_tree(compare_integer, ORD_ASC);
        for (int i = 0; i < count; i++) {
            int* data = malloc(sizeof(int));
            *data = values[i];
            rb_insert(rbt, (void*)data, FALSE);
        }

        printf("\tInsertion Time RBT (cstuff library): %.6fms\n", (double)(clock() - start) / (CLOCKS_PER_SEC / 1000));
        delete_tree(rbt);
    }

    // Insert BST
    for (int it = 0; it <= iterations; it++) {
        start = clock();
        binary_tree* bst = new_binary_tree(compare_integer, ORD_ASC);
        for (int i = 0; i < count; i++) {
            int* data = malloc(sizeof(int));
            *data = values[i];
            node* n = tree_insert(bst, data, FALSE);
        }

        printf("\tInsertion Time BST (cstuff library): %.6fms\n", (double)(clock() - start) / (CLOCKS_PER_SEC / 1000));

        delete_tree(bst);
    }

    // Insert AVL
    for (int it = 0; it <= iterations; it++) {
        start = clock();
        binary_tree* avl = new_binary_tree(compare_integer, ORD_ASC);
        for (int i = 0; i < count; i++) {
            int* data = malloc(sizeof(int));
            *data = values[i];
            node* n = tree_insert(avl, data, FALSE);
        }

        printf("\tInsertion Time AVL (cstuff library): %.6fms\n", (double)(clock() - start) / (CLOCKS_PER_SEC / 1000));

        delete_tree(avl);
    }
}