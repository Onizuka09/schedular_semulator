#include <stdio.h>
#define RESET_TEXT              "\x1b[0m"
#define black_text              "\x1b[1m"
#define grey_text               "\x1b[2m"
#define RED_TEXT                "\x1b[31m"
#define GREEN_TEXT              "\x1b[32m"
#define YELLOW_TEXT             "\x1b[33m"
#define DARKBLUE_TEXT           "\x1b[34m"
#define purpple_text            "\x1b[35m"
#define sky_blue_text           "\x1b[36m"
#define light_grey              "\x1b[90m"
#define light_red_text          "\x1b[91m"
#define light_green_text        "\x1b[92m"
#define light_yellow            "\x1b[93m"
#define light_DARKBLUE_text     "\x1b[94m"
#define light_puple_text        "\x1b[95m"
#define light_BLUE_SKY_text     "\x1b[96m"

int main(void)
{
    int i, j, n;

    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 10; j++)
        {
            n = 10 * i + j;
            if (n > 108)
                break;
            printf("\033[%dm %3d\033[m", n, n);
        }
        printf("\n");
    }
    return 0;
}