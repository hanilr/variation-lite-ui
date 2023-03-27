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
}