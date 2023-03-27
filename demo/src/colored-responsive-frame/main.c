#include <stdio.h>
#include <unistd.h>

#define VNL_UI_IMPLEMENTATION
#include "../../../vnl_ui.h"

/* COLOR DEFINATION */
#define red_fg (vnl_color("#c83737", 0))
#define green_fg (vnl_color("#37c837", 0))
#define blue_bg (vnl_color("#3737c8", 1))

/* SIMPLE FRAME */
void do_frame(int width, int height) {
    int i = 0;
    vnl_gotoxy(0, 0);
    printf("%s%s", green_fg, blue_bg);

    while(width > i) {
        printf("-");
        i+=1;
    } i = 0;
    printf("\n");

    while(height-2 > i) { int n = 0;
        printf("|");
        while(width-2 > n) { printf("%s", vnl_reset);
            printf(" ");
            n+=1;
        } n = 0;
        printf("%s%s", green_fg, blue_bg);
        printf("|\n");
        i+=1;
    }i = 0;

    while(width > i) {
        printf("-");
        i+=1;
    }

    printf("%s\n", vnl_reset);
}

int main() {
    while(1) { vnl_terminal("display:clear");
        int terminal_width = vnl_terminal("get:width");
        int terminal_height = vnl_terminal("get:height");
        do_frame(terminal_width, terminal_height-1);

        int pos_x = (terminal_width/2)-8, pos_y = (terminal_height-1)/2;
        vnl_gotoxy(pos_x, pos_y);
        printf("%sThis is The Frame%s", red_fg, vnl_reset);
        vnl_gotoxy(terminal_width, terminal_height-1);
        printf("\n");
        usleep(100000);
    }

    return 0;
} /* MADE BY @hanilr */