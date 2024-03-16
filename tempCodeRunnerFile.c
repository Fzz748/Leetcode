#include <stdio.h>

int main() {
    char str[100];
    char letters[] = "йцукенгшщзхъфывапролджэячсмитьбюё";
    int numbers[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33};
    int i, j;
    
    printf("请输入一个俄语字符串: \n");
    scanf("%s", &str);
    
    for(i = 0; str[i] != '\0'; i++){
        for(j = 0; j<33; j++){
            if(str[i] == letters[j]) {
                if(i == 0) {
                    printf("1");
                    printf("Char168_Russian_%d,", numbers[j]);
                } else {
                  printf("2");
                    printf("Char168_Russian_lower_%d,", numbers[j]);
                }
                break;
            }
        }
    }
    printf("Characterend\n");
    return 0;
}

