# Red-Black Tree

This is an implementation in C of the Data Structure Red-Black Tree for the 
Seminar "Exploring Data Structures in C" at the Technische Bergakademie Freiberg
(TUBAF).

The code is based on the pseudocode from the book "Introduction to Algorithms" 
by Thomas H. Cormen et al.

This structure is intended to be generic (the data and not the keys). 
There is a a generic form to create a new tree and wrappers around it.
For example:

```
// &print_data is a pointer to the function who knows how to cast your data
// in order to print it
RBT_new(&print_data); 
RBT_new_int();
```

It can export a DOT file in order to visualize the graph in Graphviz.

## Build
```
mkdir build
cd build
cmake ..
make
```

## Run the executable
```
./rbtree
```

## Export DOT file into a PNG Image (You need to install Grahpviz)

```
dot rbtree.dot -Tpng -o rbtree.png
```

## API

Define a function to print the type of your data
```
void print_data(void *data){
    printf("Data: %d\n", *(int *)data);
}
```

Create a custom tree. You need to pass the function pointer to print the data
that you are going to use.
```
RBT_t *newTree = RBT_new(&print_data);
```

Or use some of the predefined wrappers around the C types
```
RBT_t *intTree = RBT_new_int();
```

Insert a new node in the tree by key with a value
```
int new_value = 10;
RBT_insert(intTree, 1, &new_value, sizeof(new_value));
```

Delete a node by passing the node
```
RBT_delete(intTree, pNode);
```

Search a node by key
```
RBT_search(newTree, 3);
```

Print a node by key
```
RBT_print_node(newTree, 3);
```

Generate a DOT file (Graphviz) from the tree
```
RBT_export_dot(newTree);
```

Clear the whole tree
```
RBT_destroy(newTree);
```