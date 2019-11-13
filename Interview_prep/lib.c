//
//  lib.c
//  Interview_prep
//
//  Created by ragsekar on 11/3/19.
//  Copyright © 2019 ragsekar. All rights reserved.
//
int min_of_2(int a, int b)
{
    if(a < b) return a;
    else return b;
}
int max_of_2(int a, int b)
{
    if (a > b) return a;
    else return b;
}
int max_of_3(int a, int b, int c)
{
    if(a>=b && a >=c) return a;
    else if(b >=a && b >=c) return b;
    else return c;
}
