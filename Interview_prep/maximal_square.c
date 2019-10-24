//
//  maximal_square.c
//  Interview_prep
//
//  Created by ragsekar on 10/21/19.
//  Copyright © 2019 ragsekar. All rights reserved.
//

#include "main.h"
//#define __DEBUG
int min(int a, int b, int c)
{
    if((a <= b) && (a <= c)) return a;
    else if ((b <= a) && (b <= c)) return b;
    else return c;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
    int i = 0, j = 0;
    int res = 0;
    if(!matrix || !matrixSize || !matrixColSize) return 0;
    int **dp = calloc(matrixSize, sizeof(*dp));
    for(i = 0; i < matrixSize; i++)
        dp[i] = calloc(matrixColSize[0], sizeof(**dp));
    for(i = 0; i < matrixSize; i++) {
        if(matrix[i][0] == '1') {
            dp[i][0] = 1;
            res = 1;
        }
    }
    for(i = 0; i < matrixColSize[0]; i++) {
        if(matrix[0][i] == '1') {
            dp[0][i] = 1;
            res = 1;
        }
    }
    for(i = 1; i < matrixSize; i++) {
        for(j = 1; j < matrixColSize[0]; j++) {
            if(matrix[i][j] == '1') {
                dp[i][j]  = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1;
                if(res < dp[i][j]) res = dp[i][j];
            }
        }
    }
#ifdef __DEBUG
     for(i = 0; i < matrixSize; i++) {
        for(j = 0; j < matrixColSize[0]; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
#endif
    return res*res;
}

void maximal_square()
{
    int row = 4;
    int cols[5] = {5};
    int i = 0;
    char **matrix = calloc(row, sizeof(*matrix));
    for(i = 0; i < row; i++)
        matrix[i] = calloc(cols[0], sizeof(**matrix));
    matrix[1][2] = '1';
    matrix[1][3] = '1';
    matrix[1][4] = '1';
    matrix[2][2] = '1';
    matrix[2][3] = '1';
    matrix[2][4] = '1';
#ifdef __DEBUG
    for(i = 0; i < row; i++){
        for(j = 0; j < cols[0]; j++) {
            if(matrix[i][j] == '\0')
                printf("%c ", '0');
            else
                printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
     printf("\n");
#endif
    printf("Maximal square is: %d\n", maximalSquare(matrix, row, cols));
}
