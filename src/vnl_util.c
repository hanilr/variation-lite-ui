/* VARIATION LITE UI (UTILITY) */
/*      MADE BY @hanilr      */
#include <stdio.h> /* STANDARD INPUT AND OUTPUT LIBRARY */
#include <stdlib.h> /* GENERAL PURPOSE STANDARD LIBRARY */
#include <string.h> /* STRING LIBRARY */
#include <sys/ioctl.h> /* DEVICE-SPECIFIC INPUT AND OUTPUT OPERATIONS LIBRARY */
#include "lib/vnl_util.h" /* LINKING */

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