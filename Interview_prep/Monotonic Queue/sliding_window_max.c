//
//  sliding_window_max.c
//  Interview_prep
//
//  Created by ragsekar on 12/27/19.
//  Copyright © 2019 ragsekar. All rights reserved.
//

#include "main.h"
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    int temp_res[126];
    int res_size = 0;
    int *res;
    GQueue *q = g_queue_new();
    for(int i = 0; i < numsSize; i++) {
        if(!g_queue_is_empty(q) && GPOINTER_TO_INT(g_queue_peek_head(q)) < (i-k+1)) {
            g_queue_pop_head(q);
        }
        while(!g_queue_is_empty(q) && nums[GPOINTER_TO_INT(g_queue_peek_tail(q))] < nums[i]) {
            g_queue_pop_tail(q);
        }
        g_queue_push_tail(q, GINT_TO_POINTER(i));
        if(i >= k-1)
            temp_res[res_size++] = nums[GPOINTER_TO_INT(g_queue_peek_head(q))];
    }
    res = calloc(1, (sizeof(int)*(res_size)));
    memcpy(res, temp_res, sizeof(int) * res_size);
    *returnSize = res_size;
    return res;
}

void sliding_winow_max()
{
    int nums[] = {1, -1};
    int k = 1;
    int size = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int *res = maxSlidingWindow(nums, size, k, &returnSize);
    for(int i = 0; i < returnSize; i++)
        printf("%d \n", res[i]);
}
