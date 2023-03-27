/* VARIATION LITE UI (COLOR) */
/*      MADE BY @hanilr      */
#ifndef _VNL_COLOR_H
#define _VNL_COLOR_H
    /* Variation Lite Colorizer: RGB and HEX color linker. */
    char *vnl_colorizer(char *color_code, int base);

    /* Variation Lite Color: RGB and HEX colorizer. */
    /* _______________________________________________ */
    /* 'color_code': "#a1b2c3" or "001 024 200" */
    /* Foreground: (base = 0), Background: (base = 1) */
    #define vnl_color(color_code, base) (vnl_colorizer(color_code, base))
#endif /* VNL_COLOR_H */