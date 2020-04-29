#include "rbtree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    RBT_t *new_tree = RBT_new();
    RBT_insert(new_tree, 3);
    RBT_insert(new_tree, 4);
    RBT_insert(new_tree, 5);
    RBT_insert(new_tree, 1);
    RBT_insert(new_tree, 2);
    RBT_clear_tree(new_tree);
    return 0;
}