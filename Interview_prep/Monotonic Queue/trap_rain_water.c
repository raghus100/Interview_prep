//
//  trap_rain_water.c
//  Interview_prep
//
//  Created by ragsekar on 12/26/19.
//  Copyright © 2019 ragsekar. All rights reserved.
//

#include "main.h"

int trap(int* height, int heightSize)
{
    GQueue *stack = g_queue_new();
    int current = 0, top, distance, h;
    int ans = 0;
    for(int i = 0; i < heightSize; i++) {
        while(!g_queue_is_empty(stack) && height[current] > height[GPOINTER_TO_INT(g_queue_peek_tail(stack))]) {
            top = GPOINTER_TO_INT(g_queue_pop_tail(stack));
            if(g_queue_is_empty(stack)) break;
            distance = current- GPOINTER_TO_INT(g_queue_peek_tail(stack)) - 1;
            h = MIN(height[current], height[GPOINTER_TO_INT(g_queue_peek_tail(stack))]) - height[top];
            ans += (h * distance);
        }
        g_queue_push_tail(stack, GINT_TO_POINTER(current++));
    }
    return ans;
}

void trap_rain_water()
{
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int size = sizeof(height)/sizeof(height[0]);
    printf("water trap: %d\n", trap(height, size));
    return;
}
