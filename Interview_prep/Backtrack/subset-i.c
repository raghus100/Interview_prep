//
//  subset-i.c
//  Interview_prep
//
//  Created by ragsekar on 11/11/19.
//  Copyright © 2019 ragsekar. All rights reserved.
//

#include "main.h"

void backtrack(int* nums, int numsSize, int **res, int *res_idx, int *subset, int sub_size, int num_idx, int * returnColumnSizes)
{
    res[*res_idx] = calloc(1, sizeof(int) * sub_size);
    returnColumnSizes[*res_idx] = sub_size;
    memcpy(res[*res_idx], subset, sizeof(int) * sub_size);
    (*res_idx)++;
    for(int i = num_idx; i < numsSize; i++) {
        subset[sub_size] = nums[i];
        backtrack(nums, numsSize, res, res_idx, subset, sub_size+1, i+1, returnColumnSizes);
    }
    
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 2 << (numsSize-1);
    int *subset = calloc(1, sizeof(int) * (*returnSize));
    int sub_size = 0;
    int res_idx = 0;
    int num_idx = 0;
    int **res = calloc(1, sizeof(*res) * (*returnSize));
    *returnColumnSizes = calloc(1, sizeof(*returnColumnSizes) * (*returnSize));
    backtrack(nums, numsSize, res,  &res_idx, subset, sub_size, num_idx, *returnColumnSizes);
    return res;
}

void subset()
{
    int size = 3;
    int returnSize = 0;
    int *returnColumnSizes;
    int *nums = calloc(1, sizeof(int) * size);
    for(int i = 0; i < size; i++)
        nums[i] = i+1;
    int **res = subsets(nums, size, &returnSize, &returnColumnSizes);
    for(int i = 0; i < returnSize; i++) {
        for(int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return;
}
