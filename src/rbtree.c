#include "rbtree.h"

#include <stdlib.h>

RBT_t *RBT_new_tree() {
    RBT_t *pRBT = NULL;
    pRBT = malloc(sizeof(RBT_t));
    if (pRBT != NULL) {
        pRBT->root_node = NULL;
    }
    return pRBT;
}

Node_t *RBT_get_parent(Node_t *pNode) {
    Node_t *pParent;
    if (pNode != NULL) {
        pParent = pNode->parent_node;
        if (pParent == NULL) {
            printf("There is no parent\n");
        }
    } else {
        printf("GET PARENT: Node is NULL\n");
    }
    return pParent;
}

Node_t *RBT_get_grandparent(Node_t *pNode) {
    Node_t *pGrandparent;
    if (pNode != NULL) {
        Node_t *pParent = RBT_get_parent(pNode);
        if (pParent != NULL) {
            pGrandparent = RBT_get_parent(pParent);
            if (pGrandparent == NULL) {
                printf("There is no grand parent\n");
            }
        }
    } else {
        printf("GET GRANDPARENT: Node is NULL\n");
    }
    return pGrandparent;
}

Node_t *RBT_get_sibling(Node_t *pNode) {
    Node_t *pSibling;
    if(pNode != NULL) {
        Node_t *pParent = RBT_get_parent(pNode);
        if(pParent != NULL) {
            Node_t *leftNode;
            Node_t *rightNode;
            leftNode = pParent->left_node;
            rightNode = pParent->right_node;
            if(leftNode != NULL && leftNode != pParent){
                pSibling = leftNode;
            } else if(rightNode != NULL && rightNode != pParent) {
                pSibling = rightNode;
            }
        }
    }
    return pSibling;
}

Node_t *RBT_get_uncle(Node_t *pNode) {
    Node_t *pUncle;
    if (pNode != NULL) {
        Node_t *pParent = RBT_get_parent(pNode);
        if(pParent != NULL) {
            pUncle = RBT_get_sibling(pParent);
            if(pUncle == NULL) {
                printf("There is no uncle\n");
            }
        }
    } else {
        printf("GET UNCLE: Node is NULL\n");
    }
    return pUncle;
}

_Bool RBT_insert_node(RBT_t *pRBT, int key) {
    if(pRBT != NULL) {
        Node_t * pNewNode;
        pNewNode = (Node_t *) malloc(sizeof(Node_t));
        pNewNode->key = key;
        pNewNode->color = RED;
        pNewNode->left_node = NULL;
        pNewNode->right_node = NULL;
        if(pRBT->root_node == NULL) {
            pRBT->root_node = pNewNode;
        } else {
            printf("There is already a root node!\n");
        }
    }
    return 0;
}

void RBT_clear(Node_t *pNode) {
    if (pNode != NULL) {
        Node_t *leftNode = pNode->left_node;
        Node_t *rightNode = pNode->right_node;
        if (leftNode == NULL && rightNode == NULL) {
            free(pNode);
        } else {
            if(leftNode != NULL) {
                RBT_clear(leftNode);
            }
            if(rightNode != NULL) {
                RBT_clear(rightNode);
            }
        }
    }
}

void RBT_clear_tree(RBT_t *pRBT) {
    if(pRBT->root_node != NULL) {
        RBT_clear(pRBT->root_node);
    }
    free(pRBT);
}