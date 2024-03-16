#include <stdio.h>
#include <stdbool.h>

int sum_of_squares(int n) {
    int sum = 0, digit;
    while (n) {
        digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool is_happy(int n) {
    int slow = n, fast = n;
    do {
        slow = sum_of_squares(slow);
        fast = sum_of_squares(sum_of_squares(fast));
    } while (slow != fast);

    return slow == 1;
}

int main() {
    int num;
    printf("������һ������: ");
    scanf("%d", &num);

    if (is_happy(num)) {
        printf("%d �ǿ�����\n", num);
    } else {
        printf("%d ���ǿ�����\n", num);
    }

    return 0;
}