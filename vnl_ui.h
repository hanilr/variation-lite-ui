/* VARIATION LITE UI (LIBRARY) */
/*     MADE BY @hanilr     */
#ifndef _VNL_UI_H
#define _VNL_UI_H
    /* ASCII ESCAPE SEQUENCE RESET CODE */
    #define vnl_reset "\033[0m" /* Use after text. */

    /* ASCII ESCAPE SEQUENCE TEXT STYLES */
    #define vnl_bold "\033[1m" /* [ASCII] Text Style: BOLD */
    #define vnl_italic "\033[3m" /* [ASCII] Text Style: ITALIC */
    #define vnl_underline "\033[4m" /* [ASCII] Text Style: UNDERLINE */
    #define vnl_blink "\033[5m" /* [ASCII] Text Style: BLINK */
    #define vnl_strikethrough "\033[9m" /* [ASCII] Text Style: STRIKETHROUGH */

    /* ASCII ESCAPE SEQUENCE UTILITY CODES */
    #define clear_screen "\033[2J\033[H" /* Clear terminal screen. */
    #define cursor_visible "\033[?25h" /* Set cursor to visible. */
    #define cursor_invisible "\033[?25l" /* Set cursor to invisible. */

    /* Variation Lite Colorizer: RGB and HEX color linker. */
    char *vnl_colorizer(char *color_code, int base);

    /* Variation Lite Cursorizer: Cursor settings linker. */
    void vnl_cursorizer(char *cursor_code);

    /* Variation Lite Terminal: Terminal settings and specification linker. */
    int vnl_terminalizer(char *terminal_code);

    /* Variation Lite Color: RGB and HEX colorizer. */
    /* _______________________________________________ */
    /* 'color_code': "#a1b2c3" or "001 024 200" */
    /* Foreground: (base = 0), Background: (base = 1) */
    #define vnl_color(color_code, base) (vnl_colorizer(color_code, base))

    /* Variation Lite Cursorizer: Cursor settings. */
    /* _______________________________________________ */
    /* [position:goto(position_x:position_y)] Go to x and y position. */
    /* [position:next_line] Go to next line. */
    /* [position:previous_line] Go back to previous line. */
    /* [position:save] Save cursor position. */
    /* [position:restore] Restore cursor position. */
    /* [screen:save] Save terminal screen. */
    /* [screen:restore] Restore terminal screen */
    /* [visibility:on] Set visible to cursor. */
    /* [visibility:off] Set invisible to cursor. */
    #define vnl_cursor(cursor_code) (vnl_cursorizer(cursor_code))

    /* Variation Lite Terminal: Terminal settings and specification. */
    /* _______________________________________________ */
    /* [display:clear] Clear terminal screen. */
    /* [io:raw] Terminal input/output raw mode. */
    /* [io:cooked] Normal terminal mode. */
    /* [get:width] Get terminal width as integer. */
    /* [get:height] Get terminal height as integer. */
    /* [Other Inputs] General purpose stuff. */
    #define vnl_terminal(terminal_code) (vnl_terminalizer(terminal_code))
#endif /* SUMMARY SECTION */

#ifdef VNL_UI_IMPLEMENTATION
    #include <stdio.h> /* STANDARD INPUT AND OUTPUT LIBRARY */
    #include <stdlib.h> /* GENERAL PURPOSE STANDARD LIBRARY */
    #include <string.h> /* STRING LIBRARY */
    #include <ctype.h> /* TESTING AND MAPPING LIBRARY */
    #include <sys/ioctl.h> /* DEVICE-SPECIFIC INPUT AND OUTPUT OPERATIONS LIBRARY */

    /* Variation Lite Colorizer: RGB colorizer for ui. */
    /* _______________________________________________ */
    /* Take red, green and blue int values from user */
    /* then convert to escape sequence string then return. */
    /* Simple and easy way for colorization. Better than HEX. */
    /* _______________________________________________ */
    /* 'base': Decision of foreground or background. */
    /* Foreground: (base = 0), Background: (base = 1)  */
    char *vnl_colorizer_rgb(int red, int green, int blue, int base) {
        char *color = (char*) malloc(32);
        if (base == 0) { /* FOREGROUND */
            sprintf(color, "\033[38;2;%d;%d;%dm", red, green, blue);
        }
        if (base == 1) { /* BACKGROUND */
            sprintf(color, "\033[48;2;%d;%d;%dm", red, green, blue);
        }
        return color;
    }

    /* Utility for HEX number colorizer */
    /* _______________________________________________ */
    /* True: (left_side = 0), False: (left_side = 1) */
    int vnl_hex_number(int number, int left_side) {
        if (left_side == 0) { return number; }
        else if (left_side == 1) { return number*16; }
    }

    /* Utility for HEX letter colorizer */
    /* _______________________________________________ */
    /* True: (left_side = 0), False: (left_side = 1) */
    int vnl_hex_letter(char letter, int left_side) {
        int result;
        if (letter == 'a') { result = 10; }
        else if (letter == 'b') { result = 11; }
        else if (letter == 'c') { result = 12; }
        else if (letter == 'd') { result = 13; }
        else if (letter == 'e') { result = 14; }
        else if (letter == 'f') { result = 15; }
        if (left_side == 1) { result*=16; }
        return result;
    }

    /* Variation Lite Colorizer: HEX colorizer for ui. */
    /* _______________________________________________ */
    /* Inspect 'hex' variable byte by byte then compare */
    /* if number or letter then send to rgb function. */
    /* _______________________________________________ */
    /* Example for Hex Color: #123456 */
    /* Red: 12 => 1*16 + 2 = 18 */
    /* Green: 34 => 3*16 + 4 = 52 */
    /* Blue: 56 => 5*16 + 6 = 86 */
    /* _______________________________________________ */
    /* Example for Hex Color: #a12bc3 */
    /* Red: a1 => 10*16 + 1 = 161 */
    /* Green: 2b => 2*16 + 11 = 43 */
    /* Blue: c3 => 12*16 + 3 = 195 */
    /* _______________________________________________ */
    /* 'base': Decision of foreground or background. */
    /* Foreground: (base = 0), Background: (base = 1)  */
    char *vnl_colorizer_hex(char hex[8], int base) {
        int red, green, blue;
        int red_x, red_y, green_x, green_y, blue_x, blue_y;

        if (isalpha(hex[0]) != 0) { red_x = vnl_hex_letter(hex[0], 1); }
        else { red_x = vnl_hex_number(hex[0] - '0', 1); }
        if (isalpha(hex[1]) != 0) { red_y = vnl_hex_letter(hex[1], 0); }
        else { red_y = vnl_hex_number(hex[1] - '0', 0); }
        if (isalpha(hex[2]) != 0) { green_x = vnl_hex_letter(hex[2], 1); }
        else { green_x = vnl_hex_number(hex[2] - '0', 1); }
        if (isalpha(hex[3]) != 0) { green_y = vnl_hex_letter(hex[3], 0); }
        else { green_y = vnl_hex_number(hex[3] - '0', 0); }
        if (isalpha(hex[4]) != 0) { blue_x = vnl_hex_letter(hex[4], 1); }
        else { blue_x = vnl_hex_number(hex[4] - '0', 1); }
        if (isalpha(hex[5]) != 0) { blue_y = vnl_hex_letter(hex[5], 0); }
        else { blue_y = vnl_hex_number(hex[5] - '0', 0); }

        red = red_x + red_y;
        green = green_x + green_y;
        blue = blue_x + blue_y;

        return vnl_colorizer_rgb(red, green, blue, base);
    }

    /* Variation Lite Colorizer: Colorizer input parser. */
    /* _______________________________________________ */
    /* Inspect 'color_code' then parse to decide topic. */
    /* Example of HEX color parameter: '#a1b2c3' */
    /* If you want to use HEX then do not forget '#' */
    /* _______________________________________________ */
    /* Example of RGB color parameter: '199 054 002' */
    /* If you want to use RGB then you must use '0' */
    /* _______________________________________________ */
    /* 'base': Decision of foreground or background. */
    /* Foreground: (base = 0), Background: (base = 1)  */
    char *vnl_colorizer(char *color_code, int base) {
        int color_code_length = 0, i = 0;
        while(1) { /* FIND 'color_code' LENGTH */
            if (color_code[i] == '\0') break;
            else { color_code_length += 1; }
            i+=1;
        } i = 0;

        if (color_code_length == 7 && color_code[0] == '#') { /* HEX COLOR */
            char color[8];
            while(1) { /* PARSE HEX COLOR */
                if (i == color_code_length) {
                    color[i] = '\0';
                    break;
                }
                color[i] = color_code[i+1];
                i+=1;
            }
            return vnl_colorizer_hex(color, base);
        }
        else { /* RGB COLOR */
            char red_chr[8], green_chr[8], blue_chr[8];
            int red, green, blue;

            while(1) { /* PARSE RGB COLOR */
                if (i == 3) {
                    red_chr[i] = '\0';
                    green_chr[i] = '\0';
                    blue_chr[i] = '\0';
                    break;
                }
                red_chr[i] = color_code[i];
                green_chr[i] = color_code[i+4];
                blue_chr[i] = color_code[i+8];
                i+=1;
            }

            red = atoi(red_chr);
            green = atoi(green_chr);
            blue = atoi(blue_chr);

            return vnl_colorizer_rgb(red, green, blue, base);
        }
    }

    /* Variation Lite Cursor Visibility: Switch visibility. */
    /* _______________________________________________ */
    /* Visible: (visibility_switch = on) */
    /* Invisible: (visibility_switch = off) */
    void vnl_cursor_visibility_switcher(char *visibility_switch) {
        if (!strcmp(visibility_switch, "on")) printf("%s", cursor_visible);
        if (!strcmp(visibility_switch, "off")) printf("%s", cursor_invisible);
    }

    /* Variation Lite Set Cursor Position-x Position-y */
    void vnl_gotoxy(int pos_x, int pos_y) { printf("\033[%d;%dH", pos_y, pos_x); }

    /* Variation Lite Goto Next Line: */
    /* _______________________________________________ */
    /* Moves cursor to beginning of next line, 'line' lines down */
    void vnl_goto_next_line(int line) { printf("\033[%dE", line); }

    /* Variation Lite Goto Previous Line: */
    /* _______________________________________________ */
    /* Moves cursor to beginning of previous line, 'line' lines up */
    void vnl_goto_previous_line(int line) { printf("\033[%dF", line); }

    /* Variation Lite Save Position: Save terminal cursor position. */
    void vnl_savexy(void) { printf("\033[s"); }

    /* Variation Lite Restore Position: Restore terminal cursor position. */
    void vnl_restorexy(void) { printf("\033[u"); }

    /* Variation Lite Save Screen: Save terminal Screen. */
    /* _______________________________________________ */
    /* Only work with supported terminals. */
    void vnl_savescr(void) { printf("\033[?47h"); } 

    /* Variation Lite Restore Screen: Restore terminal screen. */
    /* _______________________________________________ */
    /* Only work with supported terminals. */
    void vnl_restorescr(void) { printf("\033[?47l"); }

    /* Variation Lite Cursorizer: Cursor settings linker. */
    /* _______________________________________________ */
    /* [position:goto(position_x:position_y)] Go to x and y position. */
    /* [position:next_line] Go to next line. */
    /* [position:previous_line] Go back to previous line. */
    /* [position:save] Save cursor position. */
    /* [position:restore] Restore cursor position. */
    /* [screen:save] Save terminal screen. */
    /* [screen:restore] Restore terminal screen */
    /* [visibility:on] Set visible to cursor. */
    /* [visibility:off] Set invisible to cursor. */
    void vnl_cursorizer(char *cursor_code) {
        if (strstr(cursor_code, "position:goto")) {
            int i = 14, n = 0, k = 0;
            char pos_temp_x[8], pos_temp_y[8];

            while(1) {
                if (cursor_code[i] == ')') {
                    pos_temp_y[n] = '\0';
                    break;
                }
                if (cursor_code[i] == ':') {
                    pos_temp_x[n] = '\0';
                    k+=1;
                    n = 0;
                    i+=1;
                }
                if (k == 0) pos_temp_x[n] = cursor_code[i];
                if (k == 1) pos_temp_y[n] = cursor_code[i];
                n+=1;
                i+=1;
            }
            int pos_x = atoi(pos_temp_x), pos_y = atoi(pos_temp_y);
            vnl_gotoxy(pos_x, pos_y);
        }
        if (!strcmp(cursor_code, "position:next_line")) vnl_goto_next_line(1);
        if (!strcmp(cursor_code, "position:previous_line")) vnl_goto_previous_line(1);
        if (!strcmp(cursor_code, "position:save")) vnl_savexy();
        if (!strcmp(cursor_code, "position:restore")) vnl_restorexy();
        if (!strcmp(cursor_code, "screen:save")) vnl_savescr();
        if (!strcmp(cursor_code, "screen:restore")) vnl_restorescr();
        if (!strcmp(cursor_code, "visibility:on")) vnl_cursor_visibility_switcher("on");
        if (!strcmp(cursor_code, "visibility:off")) vnl_cursor_visibility_switcher("off");
    }

    /* Variation Lite Terminal With: Get terminal's width size. */
    int vnl_terminal_width(void) {
        struct winsize terminal_size;
        ioctl(0, TIOCGWINSZ, &terminal_size);
        return terminal_size.ws_col;
    }

    /* Variation Lite Terminal With: Get terminal's height size. */
    int vnl_terminal_height(void) {
        struct winsize terminal_size;
        ioctl(0, TIOCGWINSZ, &terminal_size);
        return terminal_size.ws_row;
    }

    /* Variation Lite Terminal: Terminal settings and specification linker. */
    /* _______________________________________________ */
    /* [display:clear] Clear terminal screen. */
    /* [io:raw] Terminal input/output raw mode. */
    /* [io:cooked] Terminal normal mode. */
    /* [get:width] Get terminal width as integer. */
    /* [get:height] Get terminal height as integer. */
    /* [Other Inputs] General purpose stuff. */
    int vnl_terminalizer(char *terminal_code) {
        if(!strcmp(terminal_code, "display:clear")) printf("%s", clear_screen);
        else if(!strcmp(terminal_code, "io:raw")) system("stty raw"); /* The input and output is not processed, just sent straight through. */
        else if(!strcmp(terminal_code, "io:cooked")) system("stty cooked"); /* Terminal normal mode. */
        else if(!strcmp(terminal_code, "get:width")) return vnl_terminal_width();
        else if(!strcmp(terminal_code, "get:height")) return vnl_terminal_height();
        else { system(terminal_code); } /* General purpose. */
        return 0;
    }
#endif /* VNL_UI_IMPLEMENTATION */