//
//  largest_histogram.c
//  Interview_prep
//
//  Created by ragsekar on 12/26/19.
//  Copyright © 2019 ragsekar. All rights reserved.
//

#include "main.h"

int largestRectangleArea(int* heights, int heightsSize)
{
    int current=0, top, h, dist, ans = 0;
    GQueue *stack = g_queue_new();
    int i;
    for(i = 0; i < heightsSize; i++) {
        while(!g_queue_is_empty(stack) && heights[GPOINTER_TO_INT(g_queue_peek_tail(stack))] > heights[current]) {
            top = GPOINTER_TO_INT(g_queue_pop_tail(stack));
            if(g_queue_is_empty(stack)) {
                dist = i;
            } else {
                dist = current - GPOINTER_TO_INT(g_queue_peek_tail(stack)) - 1;
            }
            h = heights[top];
            ans = MAX(ans, h*dist);
        }
        g_queue_push_tail(stack, GINT_TO_POINTER(current++));
    }
    
    while(!g_queue_is_empty(stack)) {
        top = GPOINTER_TO_INT(g_queue_pop_tail(stack));
        h = heights[top];
        if(g_queue_is_empty(stack)) {
            dist = i;
        } else {
            dist = current - GPOINTER_TO_INT(g_queue_peek_tail(stack)) - 1;
        }
        ans = MAX(ans, h*dist);
    }
    return ans;
}

void largest_rectangle_area()
{
    int heights[] = {6, 5, 4};
    int size = sizeof(heights)/sizeof(heights[0]);
    printf("Largest rectangle area: %d\n", largestRectangleArea(heights, size));
    return;
}
