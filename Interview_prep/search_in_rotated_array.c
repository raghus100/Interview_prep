//
//  search_in_rotated_array.c
//  Interview_prep
//
//  Created by ragsekar on 12/28/19.
//  Copyright © 2019 ragsekar. All rights reserved.
//

#include "main.h"

int pivot(int* nums, int numsSize)
{

    int lo = 0, hi = numsSize-1;
    int mid;
    while(lo < hi) {
        if(nums[lo] < nums[hi])
            return lo;
        else {
            mid = ((hi-lo)/2) + lo;
            if(nums[mid] >=  nums[lo]) lo = mid+1;
            else hi = mid;
        }
    }
    return lo;

}

int b_search(int* nums, int lo, int hi, int target)
{
    int mid;
    while(lo <= hi) {
        mid = ((hi-lo)/2) + lo;
        if(target == nums[mid])
            return mid;
        else if (target < nums[mid]) hi = mid-1;
        else lo = mid+1;
    }
    return -1;
}

int search(int* nums, int numsSize, int target)
{
    int piv = pivot(nums, numsSize);
    if(numsSize < 1) return -1;
    printf("pivot: %d\n", piv);
    int r_idx = b_search(nums, piv, numsSize-1, target);
    int l_idx = b_search(nums, 0, piv-1, target);
    if(r_idx != -1) return r_idx;
    else if(l_idx != -1) return l_idx;
    else return -1;
}



void search_in_rotated_array()
{
    int nums[] = {4,5,6,7,0,1,2};
    int size = sizeof(nums)/sizeof(nums[0]);
    int target = 0;
    
    printf("Target index: %d\n", search(nums, size, target));
    return;
}
