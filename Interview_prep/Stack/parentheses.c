//
//  valid_parentheses.c
//  Interview_prep
//
//  Created by ragsekar on 12/30/19.
//  Copyright © 2019 ragsekar. All rights reserved.
//

#include "main.h"


bool isValid(char * s)
{
    GQueue *stack = g_queue_new();
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            g_queue_push_tail(stack, GINT_TO_POINTER(s[i]));
        } else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if(g_queue_is_empty(stack)) return false;
            else {
                if(s[i] == ')') {
                    if(GPOINTER_TO_INT(g_queue_peek_tail(stack)) == '(')
                        g_queue_pop_tail(stack);
                } else if(s[i] == '}') {
                    if(GPOINTER_TO_INT(g_queue_peek_tail(stack)) == '{')
                        g_queue_pop_tail(stack);
                } else if(s[i] == ']') {
                    if(GPOINTER_TO_INT(g_queue_peek_tail(stack)) == '[')
                        g_queue_pop_tail(stack);
                }
            }
        } else {
            continue;
        }
    }
    return g_queue_is_empty(stack);
}

void is_valid_paren()
{
    char *s = "{[}";
    printf("%s\n", isValid(s) ? "true" : "false");
}
