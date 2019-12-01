#include "main.h"

typedef struct{
    int parent;
    int child;
    bool isLeft;
}relation;

typedef struct node{
    int id;
    struct node * left;
    struct node * right;
}node;

node *buildTree(relation *relation_list)
{
    node* malloc_hash[100] = {NULL};
    node * temp1, *temp2;
    node * res = NULL;
    for(int i = 0; i < 7; i++) {
        temp1 = malloc_hash[relation_list[i].parent];
        if(!temp1) {
            temp1 = calloc(1, sizeof(*temp1));
            temp1->id = relation_list[i].parent;
            malloc_hash[temp1->id] = temp1;
        }
        temp2 = malloc_hash[relation_list[i].child];
        if (!temp2) {
            temp2 = calloc(1, sizeof(*temp2));
            temp2->id = relation_list[i].child;
            malloc_hash[temp2->id] = temp2;
        }
        
        if(!temp1->id) res = temp2;
        if(relation_list[i].isLeft)
            temp1->left = temp2;
        else
            temp1->right = temp2;
            
    }
    return res;
}

void print_tree(node *root)
{
    if(!root)return;
    printf("%d ", root->id);
    print_tree(root->left);
    
    print_tree(root->right);
}

void build_binary_tree()
{
    /*15 20 true
    19 80 true
    17 20 false
    16 80 false
    80 50 false
    50 null false
    20 50 true*/
    relation *relation_list = calloc(1, sizeof(*relation_list)*7);
    relation_list[0].child = 15;
    relation_list[0].parent = 20;
    relation_list[0].isLeft = true;
    relation_list[1].child = 19;
    relation_list[1].parent = 80;
    relation_list[1].isLeft = true;
    relation_list[2].child = 17;
    relation_list[2].parent = 20;
    relation_list[2].isLeft = false;
    relation_list[3].child = 16;
    relation_list[3].parent = 80;
    relation_list[3].isLeft = false;
    relation_list[4].child = 80;
    relation_list[4].parent = 50;
    relation_list[4].isLeft = false;
    relation_list[5].child = 50;
    relation_list[5].parent = 0;
    relation_list[5].isLeft = false;
    relation_list[6].child = 20;
    relation_list[6].parent = 50;
    relation_list[6].isLeft = true;
    node *res = buildTree(relation_list);
    print_tree(res);
    printf("\n");
    return;
}
