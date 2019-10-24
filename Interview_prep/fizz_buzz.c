//
//  fizz_buzz.c
//  Interview_prep
//
//  Created by ragsekar on 10/22/19.
//  Copyright © 2019 ragsekar. All rights reserved.
//

#include "main.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize)
{
    char **res;
    *returnSize = n;
    char buf[11];;
    int i = 0;
    res = calloc(1, sizeof(char *)*n);
    for(i = 1; i <= n; i++) {
        if(((i%3)==0) && ((i%5)==0))
            sprintf(buf, "%s", "FizzBuzz");
        else if((i%3)==0)
            sprintf(buf, "%s", "Fizz");
        else if((i%5) == 0)
            sprintf(buf, "%s", "Buzz");
        else
            sprintf(buf, "%d", i);
        res[i-1] = calloc(1, sizeof buf);
        memcpy(res[i-1], buf, strlen(buf)+1);
    }
    return res;
}

void fizz_buzz()
{
    int n = 1;
    int return_size = 0;
    char **res;
    int i = 0;
    res = fizzBuzz(n, &return_size);
    for(i = 0; i < n; i++)
        printf("%s \n", res[i]);
}
