//
//  average_of_levels.c
//  Interview_prep
//
//  Created by ragsekar on 12/18/19.
//  Copyright © 2019 ragsekar. All rights reserved.
//

#include "main.h"

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/*Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]*/

/*int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

    GList *l = NULL;
    GQueue *q = g_queue_new();
    g_queue_push_tail(q, root);
    while(!g_queue_is_empty(q)) {
        int size = g_queue_get_length(q);
        for(int i = 0; i < size; i++) {
            struct TreeNode *node = g_queue_pop_head(q);
            
        }
    }
    
    for(int i = 0; i < level; i++) {
        GList *l = g_hash_table_lookup(hash, GINT_TO_POINTER(i));
        col_len = g_list_length(l);
        res[i] = calloc(1, sizeof(int) * col_len);
        returnColumnSizes[i][0] = col_len;
        
        if(left2right) {
            l = g_list_reverse(l);
            for(int j = 0; j < col_len; j++) {
                res[i][j] = GPOINTER_TO_INT(g_list_next(l));
            }
            left2right = false;
        } else {
            for(int j = col_len-1; j >= 0; j--) {
                res[i][j] = GPOINTER_TO_INT(g_list_next(l));
            }
            left2right = true;
        }
    }
    *returnSize = level;
    return res;
}

*/
double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
    GQueue *queue = g_queue_new();
    g_queue_push_tail(queue, root);
    int no_of_ele = 0;
    int level = 0;
    double temp_res[1000] = {0};
    double *res;
    double sum = 0;
    struct TreeNode *temp = NULL;
    while(!g_queue_is_empty(queue)) {
        no_of_ele = g_queue_get_length(queue);
        sum = 0;
        for(int i = 0 ; i < no_of_ele; i++) {
            temp = g_queue_pop_head(queue);
            sum += temp->val;
            if(temp->left)
                g_queue_push_tail(queue, temp->left);
            if(temp->right)
            g_queue_push_tail(queue, temp->right);
        }
        temp_res[level] = sum / no_of_ele;
        level++;
    }
    res = calloc(1, sizeof(*res) * level);
    for(int i = 0; i < level; i++)
        res[i] = temp_res[i];
    *returnSize = level;
    return res;
}

void average_of_levels()
{
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *root = calloc(1, sizeof(*root));
    root->val = 3;
    left = calloc(1, sizeof(*left));
    left->val = 9;
    right = calloc(1, sizeof(*right));
    right->val = 20;
    root->left = left;
    root->right = right;
    right->left = calloc(1, sizeof(*left));
    right->right = calloc(1, sizeof(*right));
    right->left->val = 15;
    right->right->val = 7;
    int returnSize = 0;
    double *res = averageOfLevels(root, &returnSize);
    for(int i = 0; i < returnSize; i++) {
        printf("%f ", res[i]);
    }
    printf("\n");
    returnSize = 0;
    int **returnColumnSizes = calloc(1, sizeof(int *) * 100);
    for(int i = 0; i < 100; i++)
        returnColumnSizes[i] = calloc(1, sizeof(int) * 1);
    /*int **result = zigzagLevelOrder(root, &returnSize, returnColumnSizes);
    for(int i = 0; i < returnSize; i++) {
        for(int j = 0; j < returnColumnSizes[i][0]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }*/
    return;
}


