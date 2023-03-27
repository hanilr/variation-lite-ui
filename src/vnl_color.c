/* VARIATION LITE UI (COLOR) */
/*      MADE BY @hanilr      */
#include <stdio.h> /* STANDARD INPUT AND OUTPUT LIBRARY */
#include <stdlib.h> /* GENERAL PURPOSE STANDARD LIBRARY */
#include <string.h> /* STRING LIBRARY */
#include <ctype.h> /* TESTING AND MAPPING LIBRARY */
#include "lib/vnl_color.h" /* LINKING */

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