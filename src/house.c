#include "house.h"

int main(void) {
    int width = 0, length = 0, height = 0, money = 0;
    input_data(&width, &length, &height, &money);
    calculating(width, length, height, money);
    exit(EXIT_SUCCESS);
}

void input_data(int *width, int *length, int *height, int *money) {
    if ((scanf("%d %d %d %d", width, length, height, money) != 4) || *width < 0 || *length < 0 ||
        *height < 0 || *money < 0) {
        fck();
        exit(EXIT_FAILURE);
    }
}

void calculating(int width, int length, int height, int money) {
    int price = (width * length * 1000) + 2 * (width * height * 500) + 2 * (length * height * 500) +
                ((width * length * 700) + height * 100);
    if (money >= price)
        printf("YES");
    else
        printf("NO %d", price - money);
}

void fck() { fprintf(stderr, "Puck you, Verter!"); }