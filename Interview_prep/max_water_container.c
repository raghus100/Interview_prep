//
//  max_water_container.c
//  Interview_prep
//
//  Created by ragsekar on 11/3/19.
//  Copyright © 2019 ragsekar. All rights reserved.
//

#include "main.h"



int max_crossing(int *height, int start, int mid, int end)
{
    int i = start, j = end;
    int area = 0;
    int h = INT_MAX;
    while(i <= mid && j > mid) {
        h = min_of_2(h, min_of_2(height[i], height[j]));
        area = max_of_2(area, h *(j - i));
        if(i == mid)
            j--;
        else if(j == mid+1)
            i++;
        else {
            if(height[i+1] > height[j-1])
                i++;
            else j--;
        }
    }
    return area;
}
//{10,14,10,4,10,2,6,1,6,12}
//{0, 1,  2,3, 4,5,6,7,8,9 }
int max_area(int *height, int start, int end)
{
    if((end - start) == 1) {
        return min_of_2(height[end], height[start]);
    }
    if(end <= start) return 0;
    
    int mid = (start+end)/2;
    int area1 = max_area(height, start, mid);
    int area2 = max_area(height, mid+1, end);
    int area3 = max_crossing(height, start, mid, end);
    return(max_of_3(area1, area2, area3));
}

int maxArea(int* height, int heightSize)
{
    if(!height || (heightSize < 2)) return 0;
    return max_area(height, 0, heightSize-1);
}

void max_water_cointainer()
{
    //[2,3,4,5,18,17,6]
    //[1,2,4,3]
    //[2,1]
    //[1,1]
    int height[] = {10,14,10,4,10,2,6,1,6,12};
    int heightSize = sizeof(height)/sizeof(height[0]);
    int res = maxArea(height, heightSize);
    printf("Res :%d\n", res);
    return;
}
