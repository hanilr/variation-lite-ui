<!-- ![vnl](img/vnl.png) -->
<!-- ![vnl_info](img/vnl_info.png) -->
<!-- ![vnl_warn](img/vnl_warn.png) -->
<!-- ![vnl_example](img/vnl_example.png) -->
<!-- ![vnl_wiki](img/vnl_wiki.png) -->

# <div align="center"> ![vnl](img/vnl.png) <span style="color:#c83737">Variation-Lite</span>: UI ![vnl](img/vnl.png)</div>

> ![vnl_info](img/vnl_info.png) This library is optimized Lite version of [Variation-ui](https://github.com/hanilr/variation-ui). ![vnl_info](img/vnl_info.png)

> ![vnl_warn](img/vnl_warn.png) This library not contain widgets. If you want to use widgets then you need to use [Variation-ui](https://github.com/hanilr/variation-ui) ![vnl_warn](img/vnl_warn.png)

## <div align="center"> ![vnl](img/vnl.png) <span style="color:#3737c8">About The Project</span> ![vnl](img/vnl.png) </div>

After I made [Variation-ui](https://github.com/hanilr/variation-ui) I worked with widgets, but then I never used widgets so I didn't make widgets in this library. Then I realized that my code wasn't working well enough and I changed the algorithm. Then, when I saw that there were too many commands to remember, I categorized all the commands into 3 topics. After doing all this, I realized that this library doesn't even need a wiki page. But there is a wiki document in case you get stuck somewhere.

> ![vnl_info](img/vnl_info.png) You can see html version of wiki documentation in `doc/html/wiki.html` or you can see markdown version of documentation in `doc/markdown/wiki.md` or click: [![vnl_wiki](img/vnl_wiki.png)](doc/markdown/wiki.md)

---

## <div align="center"> ![vnl](img/vnl.png) <span style="color:#37c837">Installation</span> ![vnl](img/vnl.png) </div>

### ![vnl_warn](img/vnl_warn.png) Dependencies ![vnl_warn](img/vnl_warn.png)
1. First of all this library can work on `Linux` systems.
2. Your terminal must support `ASCII Escape Sequences`
3. C programming language compiler: `gcc`
    * [GNU Compiler Collection](https://gcc.gnu.org/)
4. Build program: `make`
    * [GNU Make](https://www.gnu.org/software/make/)
5. Debug program: `gdb`
    * [The GNU Project Debugger](https://sourceware.org/gdb/)

### ![vnl_example](img/vnl_example.png) Installation Steps ![vnl_example](img/vnl_example.png)
1. Clone this repository.
```
$ git clone https://github.com/hanilr/variation-lite-ui.git
```
2. Enter inside of `variation-lite-ui` folder.
    * You can see list if you write `make` inside this folder.
```
$ cd variation-lite-ui
```
3. Write `make install` to terminal.
    * Will be installed in `/usr/include/vn/` direction.
```
$ make install
```
4. If you want to uninstall this library write `make uninstall` to terminal in `variation-lite-ui` folder.
```
$ make uninstall
```

### ![vnl_example](img/vnl_example.png) Shared Library Steps ![vnl_example](img/vnl_example.png)
1. Do the first 2 steps at [Installation Steps](#vnl_example-installation-stepsvnl_example).
2. Write `make compile` to terminal
```
$ make compile
```
3. You can use the library as `vnl_ui.so`
4. If you want to delete compiled shared library file then write `make clean` to terminal.
```
$ make clean
```

---

## <div align="center"> ![vnl](img/vnl.png) <span style="color:#37c837">Code Example</span> ![vnl](img/vnl.png) </div>

> ![vnl_info](img/vnl_info.png) If you using as local library then you need to define `VNL_UI_IMPLEMENTATION` before including library.
>> ```c
>> #define VNL_UI_IMPLEMENTATION
>> #include "vnl_ui.h"
>> ```
> ![vnl_info](img/vnl_info.png) If you installed the library then you don't need to define. You can find this in `<vn/vnl_ui.h>`
>> ```c
>> #define VNL_UI_IMPLEMENTATION
>> #include <vn/vnl_ui.h>
>> ```

<details>
<summary>Example</summary>

```c
#include <stdio.h> /* 'printf();', 'getchar();' */
#include <ctype.h> /* 'toupper();' */
#include <unistd.h> /* 'sleep();', 'usleep();' */

#define VNL_UI_IMPLEMENTATION /* UNLOCK THE LIBRARY */
#include <vn/vnl_ui.h> /* USE LIKE THAT IF YOU INSTALLED THE LIBRARY */

/* Foreground Colors */
#define black_fg (vnl_color("#161616", 0))
#define white_fg (vnl_color("#e9e9e9", 0))
#define red_fg (vnl_color("#c83737", 0))
#define green_fg (vnl_color("#37c837", 0))
#define blue_fg (vnl_color("#3737c8", 0))
#define gray_fg (vnl_color("#303030", 0))
/* Background Colors */
#define black_bg (vnl_color("#161616", 1))
#define white_bg (vnl_color("#e9e9e9", 1))
#define red_bg (vnl_color("#c83737", 1))
#define green_bg (vnl_color("#37c837", 1))
#define blue_bg (vnl_color("#3737c8", 1))
#define gray_bg (vnl_color("#303030", 1))

int main() {
    int term_width = vnl_terminal("get:width"); /* Get terminal screen width. */
    int term_height = vnl_terminal("get:height"); /* Get terminal screen height. */
    char *user_name = getenv("USER");
    
    char term_width_chr[16], term_height_chr[16];
    sprintf(term_width_chr, "%d", term_width);
    sprintf(term_height_chr, "%d", term_height);

    int term_width_len = strlen(term_width_chr); /* Get width length. */
    int term_height_len = strlen(term_height_chr); /* Get height length. */
    int user_name_len = strlen(user_name);

    vnl_cursor("visibility:off"); /* Terminal cursor is no longer visible. */
    vnl_terminal("display:clear"); /* Clean terminal screen. */

    /* Print terminal specs. */
    vnl_gotoxy(term_width-18-(term_width_len+term_height_len), 1); /* Go to rigth in firt line. */
    printf("%s[%swidth: %s%d%s, height: %s%d%s]%s", green_fg, white_fg, blue_fg, term_width, white_fg, blue_fg, term_height, green_fg, vnl_reset);
    
    vnl_gotoxy(term_width-1-user_name_len, 2); /* Go to rigth in second line. */
    printf("%s[%s%s%s]%s", green_fg, red_fg, user_name, green_fg, vnl_reset);

    vnl_cursor("position:goto(0:0)"); /* Go to first line. */
    printf("%sWhat will you do if you want to quit %svim%s?%s\n\n", white_fg, green_fg, white_fg, vnl_reset);
    printf("%sA. %sI will restart the pc!%s\n", blue_fg, white_fg, vnl_reset);
    printf("%sB. %sType %s%s:w %s\n", blue_fg, white_fg, red_fg, gray_bg, vnl_reset);
    printf("%sC. %sType %s%s:q %s\n", blue_fg, white_fg, red_fg, gray_bg, vnl_reset);
    printf("%sD. %sI have to buy a new pc.%s\n", blue_fg, white_fg, vnl_reset);

    vnl_cursor("position:goto(0:2)"); /* Go to x: 0, y: 2. */
    printf(" %s%s>%s ", green_fg, vnl_blink, vnl_reset); /* Blink current cursor position. */
    usleep(500000); /* Wait for 1 second to user focus. */
    vnl_cursor("position:goto(0:2)"); /* Go to x: 0, y: 2. */
    printf(" %s>%s ", green_fg, vnl_reset); /* Answer section. */

    char answer_key; /* Answer buffer. */
    vnl_terminal("io:raw"); /* Terminal input/output mode. */
    answer_key = getchar(); /* Get char without return key. */
    vnl_terminal("io:cooked"); /* Normal terminal mode. */

    /* Answer check section. */
    if (answer_key == 'a') vnl_cursor("position:goto(0:3)");
    else if (answer_key == 'b') vnl_cursor("position:goto(0:4)");
    else if (answer_key == 'c') {
        vnl_cursor("position:goto(0:5)");
        printf("%s%s%c.%s", blue_fg, green_bg, toupper(answer_key), vnl_reset);

        vnl_cursor("position:goto(4:2)");
        printf("%s[%sCorrect Answer%s]%s", white_fg, green_fg, white_fg, vnl_reset);
    }
    else if (answer_key == 'd') vnl_cursor("position:goto(0:6)");
    else {
        vnl_cursor("position:goto(4:2)");
        printf("%s[%sWrong Key%s]%s", white_fg, red_fg, white_fg, vnl_reset);
    }
    if (answer_key == 'a' || answer_key == 'b' || answer_key == 'd')
    {
        printf("%s%s%c.%s", blue_fg, red_bg, toupper(answer_key), vnl_reset);
        vnl_cursor("position:goto(4:2)");
        printf("%s[%sIncorrect Answer%s]%s", white_fg, red_fg, white_fg, vnl_reset);
    }

    vnl_cursor("screen:save"); /* Save terminal screen. */
    vnl_terminal("display:clear"); /* Clean terminal screen. */
    printf("Can you see this text? Then your terminal doesn't support screen save/restore feature!");
    vnl_cursor("screen:restore"); /* Restore saved terminal screen. */

    sleep(2);
    vnl_cursor("position:goto(0:7)"); /* Go to x: 0, y: 7. */
    printf("%s[%sScreen Restored%s]%s", white_fg, green_fg, white_fg, vnl_reset);

    vnl_cursor("position:goto(0:8)"); /* Go to x: 0, y: 8. */
    vnl_cursor("visibility:on"); /* Terminal cursor is now visible. If you change this setting then you need to do that when your program finish. If you don't then terminal cursor will be not visible until you close the terminal. */
    return 0;
}
```

</details>

### <div align="center"> ![vnl_info](img/vnl_info.png) License ![vnl_info](img/vnl_info.png) </div>
```
MIT License

Copyright (c) 2023 Hakkı Anıl Ragıboğlu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
