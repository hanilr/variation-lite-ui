<!-- ![vnl](../img/vnl.png) -->
<!-- ![vnl_info](../img/vnl_info.png) -->
<!-- ![vnl_warn](../img/vnl_warn.png) -->
<!-- ![vnl_example](../img/vnl_example.png) -->
<!-- ![vnl_wiki](../img/vnl_wiki.png) -->

# <div align="center"> ![vnl](../img/vnl.png) <span style="color:#3737c8">Demo List</span> ![vnl](../img/vnl.png)</div>

![vnl_info](../img/vnl_info.png) <span style="color:#e9e9e9">These demos exist because of library test.</span>

* Colored Responsive Frame
* Complete Test
* Loading Screen
* Word Guess Game

### ![vnl_example](../img/vnl_example.png) Colored Responsive Frame ![vnl_example](../img/vnl_example.png)

```c
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
```

### ![vnl_example](../img/vnl_example.png) Complete Test ![vnl_example](../img/vnl_example.png)

```c
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

int main() { vnl_terminal("display:clear");
    vnl_cursor("visibility:off");

    printf("\n\t\t%s[%sTest Sections%s]%s\n\n", gray_fg, red_fg, gray_fg, vnl_reset);
    printf("\t%s1. %sTerminal %s`ASCII` %stest.%s\n", green_fg, white_fg, gray_fg, white_fg, vnl_reset);
    printf("\t%s2. %s`vnl_color` %sfunction test.%s\n", green_fg, gray_fg, white_fg, vnl_reset);

    int i = 0;
    while(48 > i) {
        printf("%s_%s", gray_fg, vnl_reset);
        i+=1;
    } i = 0;

    printf("\n\n\t\t%s[%sASCII Test%s]%s\n\n", gray_fg, blue_fg, gray_fg, vnl_reset);
    printf("\t* This is normal text.\n");
    printf("\t* %sThis is bold text.%s\n", vnl_bold, vnl_reset);
    printf("\t* %sThis is italic text.%s\n", vnl_italic, vnl_reset);
    printf("\t* %sThis is underline text.%s\n", vnl_underline, vnl_reset);
    printf("\t* %sThis is blink text.%s\n", vnl_blink, vnl_reset);
    printf("\t* %sThis is strikethrough text.%s\n", vnl_strikethrough, vnl_reset);
    
    printf("\n\t%sEverything seems alright? %s(%sy%s\\%sn%s)%s > %s", blue_fg, gray_fg, green_fg, gray_fg, red_fg, gray_fg, white_fg, vnl_reset);
    vnl_cursor("position:save");
    vnl_terminal("io:raw");
    char test_one = getchar();
    vnl_terminal("io:cooked");
    vnl_cursor("position:restore");

    if (test_one == 'y') printf("%sy%s", green_fg, vnl_reset);
    else if (test_one == 'n') printf("%sn%s", red_fg, vnl_reset);
    else { printf("%s?%s", white_fg, vnl_reset); }

    printf("\n\n");
    while(48 > i) {
        printf("%s_%s", gray_fg, vnl_reset);
        i+=1;
    } i = 0;

    printf("\n\n\t\t%s[%sColor Test%s]%s\n\n", gray_fg, blue_fg, gray_fg, vnl_reset);
    printf("\t* This is normal text.\n");

    printf("\t* %sThis is HEX foreground red text.%s\n", vnl_color("#ff0000", 0), vnl_reset);
    printf("\t* %sThis is RGB foreground red text.%s\n", vnl_color("255 000 000", 0), vnl_reset);

    printf("\t* %sThis is HEX foreground green text.%s\n", vnl_color("#00ff00", 0), vnl_reset);
    printf("\t* %sThis is RGB foreground green text.%s\n", vnl_color("000 255 000", 0), vnl_reset);

    printf("\t* %sThis is HEX foreground blue text.%s\n", vnl_color("#0000ff", 0), vnl_reset);
    printf("\t* %sThis is RGB foreground blue text.%s\n", vnl_color("000 000 255", 0), vnl_reset);

    printf("\t* %sThis is HEX foreground yellow text.%s\n", vnl_color("#ffff00", 0), vnl_reset);
    printf("\t* %sThis is RGB foreground yellow text.%s\n", vnl_color("255 255 000", 0), vnl_reset);

    printf("\t* %sThis is HEX foreground orange text.%s\n", vnl_color("#ffa500", 0), vnl_reset);
    printf("\t* %sThis is RGB foreground orange text.%s\n", vnl_color("255 165 000", 0), vnl_reset);

    printf("\t* %sThis is HEX foreground purple text.%s\n", vnl_color("#a020f0", 0), vnl_reset);
    printf("\t* %sThis is RGB foreground purple text.%s\n", vnl_color("160 032 240", 0), vnl_reset);
    
    printf("\t* %sThis is HEX background red text.%s\n", vnl_color("#ff0000", 1), vnl_reset);
    printf("\t* %sThis is RGB background red text.%s\n", vnl_color("255 000 000", 1), vnl_reset);

    printf("\t* %sThis is HEX background green text.%s\n", vnl_color("#00ff00", 1), vnl_reset);
    printf("\t* %sThis is RGB background green text.%s\n", vnl_color("000 255 000", 1), vnl_reset);

    printf("\t* %sThis is HEX background blue text.%s\n", vnl_color("#0000ff", 1), vnl_reset);
    printf("\t* %sThis is RGB background blue text.%s\n", vnl_color("000 000 255", 1), vnl_reset);

    printf("\t* %sThis is HEX background yellow text.%s\n", vnl_color("#ffff00", 1), vnl_reset);
    printf("\t* %sThis is RGB background yellow text.%s\n", vnl_color("255 255 000", 1), vnl_reset);

    printf("\t* %sThis is HEX background orange text.%s\n", vnl_color("#ffa500", 1), vnl_reset);
    printf("\t* %sThis is RGB background orange text.%s\n", vnl_color("255 165 000", 1), vnl_reset);

    printf("\t* %sThis is HEX background purple text.%s\n", vnl_color("#a020f0", 1), vnl_reset);
    printf("\t* %sThis is RGB background purple text.%s\n", vnl_color("160 032 240", 1), vnl_reset);
    
    printf("\n\t%sEverything seems alright? %s(%sy%s\\%sn%s)%s > %s", blue_fg, gray_fg, green_fg, gray_fg, red_fg, gray_fg, white_fg, vnl_reset);
    vnl_cursor("position:save");
    vnl_terminal("io:raw");
    char test_two = getchar();
    vnl_terminal("io:cooked");
    vnl_cursor("position:restore");

    if (test_two == 'y') printf("%sy%s", green_fg, vnl_reset);
    else if (test_two == 'n') printf("%sn%s", red_fg, vnl_reset);
    else { printf("%s?%s", white_fg, vnl_reset); }

    printf("\n\n");
    while(48 > i) {
        printf("%s_%s", gray_fg, vnl_reset);
        i+=1;
    } i = 0;

    vnl_terminal("display:clear");
    vnl_cursor("position:goto(0:0)");
    printf("\t%s%s[%sASCII%s]%s ", vnl_bold, gray_fg, blue_fg, gray_fg, vnl_reset);
    if (test_one == 'y') printf("%s[%sY%s]%s\n\n", gray_fg, green_fg, gray_fg, vnl_reset);
    else if (test_one == 'n') printf("%s[%sN%s]%s\n\n", gray_fg, red_fg, gray_fg, vnl_reset);
    else { printf("%s[%s?%s]%s\n\n", gray_fg, white_fg, gray_fg, vnl_reset); }

    printf("\t%s%s[%sCOLOR%s]%s ", vnl_bold, gray_fg, blue_fg, gray_fg, vnl_reset);
    if (test_two == 'y') printf("%s[%sY%s]%s\n\n", gray_fg, green_fg, gray_fg, vnl_reset);
    else if (test_two == 'n') printf("%s[%sN%s]%s\n\n", gray_fg, red_fg, gray_fg, vnl_reset);
    else { printf("%s[%s?%s]%s\n\n", gray_fg, white_fg, gray_fg, vnl_reset); }
    vnl_cursor("position:save");

    printf("\t%s[%sWas everything ok so far?%s] (%sy%s\\%sn%s)%s > %s", gray_fg, blue_fg, gray_fg, green_fg, gray_fg, red_fg, gray_fg, white_fg, vnl_reset);
    vnl_terminal("io:raw");
    char test_three = getchar();
    vnl_terminal("io:cooked");

    vnl_cursor("position:goto(0:5)");
    while(48 > i) {
        printf(" ");
        i+=1;
    }

    vnl_cursor("position:restore");
    printf("\t%s%s[%sEverything Else%s]%s ", vnl_bold, gray_fg, blue_fg, gray_fg, vnl_reset);
    if (test_three == 'y') printf("%s[%sY%s]%s\n\n", gray_fg, green_fg, gray_fg, vnl_reset);
    else if (test_three == 'n') printf("%s[%sN%s]%s\n\n", gray_fg, red_fg, gray_fg, vnl_reset);
    else { printf("%s[%s?%s]%s\n\n", gray_fg, white_fg, gray_fg, vnl_reset); }

    vnl_cursor("position:goto(0:7)");
    vnl_cursor("visibility:on");
    return 0;
} /* MADE BY @hanilr */
```

### ![vnl_example](../img/vnl_example.png) Loading Screen ![vnl_example](../img/vnl_example.png)

```c
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
```

### ![vnl_example](../img/vnl_example.png) Word Guessing Game ![vnl_example](../img/vnl_example.png)

```c
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
} /* MADE BY @hanilr */
```