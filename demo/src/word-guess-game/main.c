#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define VNL_UI_IMPLEMENTATION
#include "../../../vnl_ui.h"

#define gray_fg (vnl_color("#505050", 0))
#define red_fg (vnl_color("#c83737", 0))
#define green_fg (vnl_color("#37c837", 0))
#define blue_fg (vnl_color("#3737c8", 0))

/* SIMPLE FRAME */
void do_frame(int width, int height) {
    int i = 0;
    printf("%s", blue_fg);

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
        printf("%s", blue_fg);
        printf("|\n");
        i+=1;
    }i = 0;

    while(width > i) {
        printf("-");
        i+=1;
    }

    printf("%s\n", vnl_reset);
}

void do_screen(int len) {
    int i = 0;
    vnl_cursor("position:goto(0:0)");
    do_frame(2*len+3, 5);
    vnl_cursor("position:goto(2:3)");
    while(len > i) {
        printf(" _");
        i+=1;
    }
}

int main() { vnl_terminal("display:clear");
    char *word_list[8] = {"electric.", "logic.", "keyboard.", "mouse.", "monitor.", "key.", "internet.", "game."};

    srand(time(NULL));
    int random = rand() % 7, word_len = 0, i = 0, n = 0, x = 0, y = 0;
    char *word = word_list[random];

    while(1) {
        if (word[i] == '.') break;
        else { word_len += 1; }
        i+=1;
    } i = 0;

    do_screen(word_len);
    while(1) {
        if (x == word_len-2) {
            vnl_cursor("position:goto(4:7)");
            printf("%s%sYou Failed!%s\n", red_fg, vnl_bold, vnl_reset);
            break;
        }
        
        vnl_cursor("position:goto(0:7)");
        printf("%s > %s", gray_fg, vnl_reset);
        vnl_terminal("io:raw");
        char key = getchar();
        vnl_terminal("io:cooked");

        while(1) { if (word[n] == '.')
            {
                x+=1;
                break;
            }
            if (key == word[n]) {
                vnl_gotoxy(3+n*2, 3);
                printf("%s%s%c%s", green_fg, vnl_underline, word[n], vnl_reset);
                i+=1;
                y+=1;
                x-=1;
            }
            n+=1;
        } n = 0;

        vnl_cursor("position:goto(7:7)");
        printf("%s[%s%d%s]%s", gray_fg, red_fg, x, gray_fg, vnl_reset);
        
        if (y == word_len) {
            vnl_cursor("position:goto(4:7)");
            printf("%s%sYou Passed!%s\n", green_fg, vnl_bold, vnl_reset);
            break;
        } 
    }
    
    vnl_cursor("position:goto(0:8)");
    return 0;
}