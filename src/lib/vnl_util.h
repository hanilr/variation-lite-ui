/* VARIATION LITE UI (UTILITY) */
/*      MADE BY @hanilr      */
#ifndef _VNL_UTIL_H
#define _VNL_UTIL_H
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

    /* Variation Lite Cursorizer: Cursor settings linker. */
    void vnl_cursorizer(char *cursor_code);

    /* Variation Lite Terminal: Terminal settings and specification linker. */
    int vnl_terminalizer(char *terminal_code);

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
    /* [stty:raw] Terminal input/output raw mode. */
    /* [stty:cooked] Normal terminal mode. */
    /* [get:width] Get terminal width as integer. */
    /* [get:height] Get terminal height as integer. */
    #define vnl_terminal(terminal_code) (vnl_terminalizer(terminal_code))
#endif /* VNL_UTIL_H */