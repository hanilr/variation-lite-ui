<!-- ![vnl](img/vnl.png) -->
<!-- ![vnl_info](img/vnl_info.png) -->
<!-- ![vnl_warn](img/vnl_warn.png) -->
<!-- ![vnl_example](img/vnl_example.png) -->
<!-- ![vnl_wiki](img/vnl_wiki.png) -->

# <div align="center"> ![vnl](img/vnl.png) <span style="color:#c83737">Variation-Lite</span><span style="color:#e9e9e9">: UI</span> ![vnl](img/vnl.png)</div>

> ![vnl_info](img/vnl_info.png) <span style="color:#e9e9e9"></span> This library is optimized Lite version of [Variation-ui](https://github.com/hanilr/variation-ui).</span> ![vnl_info](img/vnl_info.png)

> ![vnl_warn](img/vnl_warn.png) This library not contain widgets. If you want to use widgets then you need to use [Variation-ui](https://github.com/hanilr/variation-ui) ![vnl_warn](img/vnl_warn.png)

## <div align="center"> ![vnl](img/vnl.png) <span style="color:#3737c8">About The Project</span> ![vnl](img/vnl.png) </div>

<span style="color:#e9e9e9">After I made [Variation-ui](https://github.com/hanilr/variation-ui) I worked with widgets, but then I never used widgets so I didn't make widgets in this library. Then I realized that my code wasn't working well enough and I changed the algorithm. Then, when I saw that there were too many commands to remember, I categorized all the commands into 3 topics. After doing all this, I realized that this library doesn't even need a wiki page. But there is a wiki document in case you get stuck somewhere.</span>

> ![vnl_info](img/vnl_info.png) You can see html version of wiki documentation in `doc/html/wiki.html` or you can see markdown version of documentation in `doc/markdown/wiki.md` or click: [![vnl_wiki](img/vnl_wiki.png)](doc/markdown/wiki.md)

---

## <div align="center"> ![vnl](img/vnl.png) <span style="color:#37c837">Installation</span> ![vnl](img/vnl.png) </div>

### ![vnl_warn](img/vnl_warn.png) <span style="color:#e9e9e9">Dependencies</span> ![vnl_warn](img/vnl_warn.png)
1. First of all this library can work on `Linux` systems.
2. Your terminal must support `ASCII Escape Sequences`
3. C programming language compiler: `gcc`
    * [GNU Compiler Collection](https://gcc.gnu.org/)
4. Build program: `make`
    * [GNU Make](https://www.gnu.org/software/make/)
5. Debug program: `gdb`
    * [The GNU Project Debugger](https://sourceware.org/gdb/)

### ![vnl_example](img/vnl_example.png) <span style="color:#e9e9e9">Installation Steps</span> ![vnl_example](img/vnl_example.png)
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

### ![vnl_example](img/vnl_example.png) <span style="color:#e9e9e9">Shared Library Steps</span> ![vnl_example](img/vnl_example.png)
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
>> #include <vn/vnl_ui.h>
>> ```

![vnl_example](img/vnl_example.png) <span style="color:#e9e9e9">Colored Terminal Size Responsive Frame</span> ![vnl_example](img/vnl_example.png)
```c
#include <stdio.h>
#include <unistd.h>

#define VNL_UI_IMPLEMENTATION
#include "vnl_ui.h"

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
}
```
> ![vnl_info](img/vnl_info.png) You can find more example in `doc/markdown/demo.md` and `doc/html/demo.html` or you can see live examples in `/demo` ![vnl_info](img/vnl_info.png)

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