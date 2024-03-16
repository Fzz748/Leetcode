#include <stdio.h>

#define SET_BIT_FLAG(flag,n) ((flag)|=(1<<(n)))
#define CLEAR_BIT_FLAG(flag,n) ((flag) &= ~(1 <<(n)))
#define GET_BIT_FLAG(flag, n) (((flag) >> (n)) & 1)

int main(void)
{
    int b[3] = {0x01, 0x02, 0x03};


    return 0;

}