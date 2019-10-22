//
//  longest_palindrome.c
//  Interview_prep
//
//  Created by ragsekar on 10/22/19.
//  Copyright © 2019 ragsekar. All rights reserved.
//

#include "main.h"
char * longestPalindrome(char * s)
{
    int dp[1000][1000] = {{0}};
    char *res;
    int res_i = 0, res_j = 0;
    int i, j;
    for(i = 0; i < strlen(s); i++)
        dp[i][i] = 1;
    
    for(i = 0; i < strlen(s)-1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            res_i = i; res_j = i+1;
        }
    }
    
    for(i = 0; i < strlen(s)-2; i++) {
        for(j = i+2; j < strlen(s); j++) {
            if((dp[i+1][j-1]) && s[i] == s[j]) {
                dp[i][j] = 1;
                if((res_j-res_i+1) < (j-i+1)){
                   res_j = j; res_i = i;
                }
            }
        }
    }
    res = calloc(1, res_j-res_i+2);
    strncpy(res, s+res_i, res_j-res_i+1);
    return res;
}
void longest_palindrome()
{
    char *s = "badab";
    char *res;
    res = longestPalindrome(s);
    printf("Longest palindrome: %s\n", res);
    free(res);
    return;
}
