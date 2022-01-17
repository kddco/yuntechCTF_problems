#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define scanf_s scanf

unsigned char* decode_1(unsigned char* code)
{

    int table[] = { 0,0,0,0,0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,62,0,0,0,
             63,52,53,54,55,56,57,58,
             59,60,61,0,0,0,0,0,0,0,0,
             1,2,3,4,5,6,7,8,9,10,11,12,
             13,14,15,16,17,18,19,20,21,
             22,23,24,25,0,0,0,0,0,0,26,
             27,28,29,30,31,32,33,34,35,
             36,37,38,39,40,41,42,43,44,
             45,46,47,48,49,50,51
    };
    long len;
    long str_len;
    unsigned char* res;
    int i, j;


    len = strlen(code);

    if (strstr(code, "=="))
        str_len = len / 4 * 3 - 2;
    else if (strstr(code, "="))
        str_len = len / 4 * 3 - 1;
    else
        str_len = len / 4 * 3;

    res = malloc(sizeof(unsigned char) * str_len + 1);
    res[str_len] = '\0';

    //以4個字元爲一位進行解碼  
    for (i = 0, j = 0; i < len - 2; j += 3, i += 4)
    {
        res[j] = ((unsigned char)table[code[i]]) << 2 | (((unsigned char)table[code[i + 1]]) >> 4); //取出第一個字元對應base64表的十進制數的前6位與第二個字元對應base64表的十進制數的後2位進行組合  
        res[j + 1] = (((unsigned char)table[code[i + 1]]) << 4) | (((unsigned char)table[code[i + 2]]) >> 2); //取出第二個字元對應base64表的十進制數的後4位元與第三個字元對應bas464表的十進制數的後4位元進行組合  
        res[j + 2] = (((unsigned char)table[code[i + 2]]) << 6) | ((unsigned char)table[code[i + 3]]); //取出第三個字元對應base64表的十進制數的後2位與第4個字元進行組合  
    }

    return res;
}
void hacked(){
    // oh hacked
	
    char* c= decode_1("Q1RGe29rLi4uSVNfQV9lYXN5X3JldmVyc2VfcmlnaHQ/fQ==");
    printf("%s\n", c);

}
int main() {
    printf("input password to get flag!!!!\n");
    char charbuf[5] = { '\0' };
    scanf_s("%s", charbuf, 5);
    if (strlen(charbuf) == 3) {
        if (strncmp(charbuf, "xyz", 3)==0){
        hacked();

    }
}



    return 0;
}
