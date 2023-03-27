#include <stdio.h>
#include <unistd.h>

#define VNL_UI_IMPLEMENTATION
#include "../../../vnl_ui.h"

/* COLOR DEFINATION */
#define white_fg (vnl_color("#e9e9e9", 0))
#define gray_fg (vnl_color("#505050", 0))
#define red_fg (vnl_color("#c83737", 0))
#define green_fg (vnl_color("#37c837", 0))
#define blue_fg (vnl_color("#3737c8", 0))

/* SIMPLE FRAME */
void do_frame(int width, int height) {
    int i = 0;
    printf("%s", green_fg);

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
        printf("%s", green_fg);
        printf("|\n");
        i+=1;
    }i = 0;

    while(width > i) {
        printf("-");
        i+=1;
    }

    printf("%s\n", vnl_reset);
}

/* SIMPLE PROGRESS */
void do_progress(int width, int height, int progress_value)
{
    int x = 0, y = 0;

    while(height > y)
    { /* COLUMN */
        printf("%s%s[", blue_fg, vnl_bold); /* PROGRESS BAR STARTING SYMBOL */
        while(progress_value > x)
        { /* COMPLETED PROGRESS SECTION */
            printf("%s#", red_fg);
            x+=1;
        }
        while(width > x)
        { /* NOT COMPLETED PROGRESS SECTION */
            printf(".");
            x+=1;
        }
        printf("%s", vnl_reset); /* RESETTING */
        printf("%s%s]%s", blue_fg, vnl_bold, vnl_reset); /* PROGRESS BAR ENDING SYMBOL */
        x=0;
        y+=1;
    }
}

int main() { vnl_terminal("display:clear");
    vnl_cursor("position:goto(1:1)");
    printf("%s[%sHorizontal Symbol%s]%s ", gray_fg, blue_fg, gray_fg, vnl_reset);
    vnl_terminal("io:raw");
    char hor = getchar();
    vnl_terminal("io:cooked");

    vnl_cursor("position:goto(1:2)");
    printf("%s[%sVertical Symbol%s]%s ", gray_fg, blue_fg, gray_fg, vnl_reset);
    vnl_terminal("io:raw");
    char ver = getchar();
    vnl_terminal("io:cooked");

    int i = 0;
    while(20 >= i) {
        vnl_terminal("display:clear");
        vnl_cursor("position:goto(0:0)");
        do_frame(vnl_terminal("get:width"), vnl_terminal("get:height")-6);
        vnl_gotoxy(0, vnl_terminal("get:height")-6);
        do_frame(vnl_terminal("get:width"), 5);

        vnl_gotoxy((vnl_terminal("get:width")/2)-12, (vnl_terminal("get:height")-6)/2);
        printf("%sThis is a loading screen%s", gray_fg, vnl_reset);

        vnl_gotoxy((vnl_terminal("get:width")/2)-10, vnl_terminal("get:height")-4);
        do_progress(20, 1, i);
        vnl_gotoxy(0, vnl_terminal("get:height")-1);
        printf("\n");
        sleep(1);
        i+=1;
    }

    vnl_gotoxy(0, vnl_terminal("get:height"));
    return 0;
} /* MADE BY @hanilr */