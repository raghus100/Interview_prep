#include "main.h"
char * addStrings(char * num1, char * num2){
    int num1_size = strlen(num1);
    int num2_size = strlen(num2);
    int res_idx = max_of_2(num1_size, num2_size)+2;
    char temp[5100] = {0};
    char *res = calloc(1, sizeof(*res) * res_idx);
    int i = num1_size-1;
    int j = num2_size-1;
    res_idx -= 2;
    int sum = 0;
    int carry = 0;

    

    while(i >= 0 && j >= 0) {
        sum = num1[i]-'0' + num2[j]-'0' + carry;
        carry = sum/10;
        sum = sum%10;
        temp[res_idx] = sum+'0';
        i--;j--;res_idx--;
    }
    while( i >= 0) {
        sum = num1[i]-'0' + carry;
        carry = sum/10;
        sum = sum%10;
        temp[res_idx--] = sum+'0';
        i--;
    }
    while(j >= 0) {
        sum = num2[j]-'0' + carry;
        carry = sum/10;
        sum = sum%10;
        temp[res_idx--] = sum+'0';
        j--;
    }

    if (carry) {
        temp[res_idx] = carry+'0';
        strcpy(res, temp);
    } else {
        strcpy(res, temp+1);
    }
    return res;
}

void add_string(void)
{
    char a[] = "999";
    char b[] = "999";
    char *res = addStrings(a, b);
    printf("%s\n", res);
    return;
}
