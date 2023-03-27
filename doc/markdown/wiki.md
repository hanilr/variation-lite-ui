<!-- ![vnl](../../img/vnl.png) -->
<!-- ![vnl_info](../../img/vnl_info.png) -->
<!-- ![vnl_warn](../../img/vnl_warn.png) -->
<!-- ![vnl_example](../../img/vnl_example.png) -->
<!-- ![vnl_wiki](../../img/vnl_wiki.png) -->

# <div align="center"> ![vnl_wiki](../../img/vnl_wiki.png) <span style="color:#c83737">Variation-Lite-UI</span><span style="color:#e9e9e9">: </span><span style="color:#3737c8">WIKI ![vnl_wiki](../../img/vnl_wiki.png)</span> </div>

### ![vnl](../../img/vnl.png) <span style="color:#37c837">Wiki Topics</span> ![vnl](../../img/vnl.png)
1. Basics
    * Installation
    * Shared-Library
    * Include System
2. How Colors Work?
    * What is ASCII?
    * What is Escape Sequences?
    * How can we use these?
    * Text Styles
3. The Holy Three
    * Why there is only 3 function?
    * Function list
    * Alternative Functions

---

## <div align="center"> ![vnl_wiki](../../img/vnl_wiki.png) <span style="color:#3737c8">Basics</span> ![vnl_wiki](../../img/vnl_wiki.png) </div>

<span style="color:#e9e9e9">If you are a newbie about single-header libraries. Then you should not skip this section. If you don't know how to install do not skip this section. If you know how to install and how to use this library then you can skip this section.</span>

## ![vnl](../../img/vnl.png) <span style="color:#e9e9e9">Installation</span> ![vnl](../../img/vnl.png)

#### ![vnl_warn](../../img/vnl_warn.png) <span style="color:#e9e9e9">Dependencies</span> ![vnl_warn](../../img/vnl_warn.png)
1. First of all this library can work on `Linux` systems.
2. Your terminal must support `ASCII Escape Sequences`
3. C programming language compiler: `gcc`
    * [GNU Compiler Collection](https://gcc.gnu.org/)
4. Build program: `make`
    * [GNU Make](https://www.gnu.org/software/make/)
5. Debug program: `gdb`
    * [The GNU Project Debugger](https://sourceware.org/gdb/)

## ![vnl](../../img/vnl.png) <span style="color:#e9e9e9">Installation Steps</span> ![vnl](../../img/vnl.png)
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

## ![vnl](../../img/vnl.png) <span style="color:#e9e9e9">Shared Library Steps</span> ![vnl](../../img/vnl.png)
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

## ![vnl](../../img/vnl.png) <span style="color:#e9e9e9">Include System</span> ![vnl](../../img/vnl.png)

![vnl_info](../../img/vnl_info.png) If you using as local library then you need to define `VNL_UI_IMPLEMENTATION` before including library.
> ```c
> #define VNL_UI_IMPLEMENTATION
> #include "vnl_ui.h"
> ```
![vnl_info](../../img/vnl_info.png) If you installed the library then you don't need to define. You can find this in `<vn/vnl_ui.h>`
> ```c
> #include <vn/vnl_ui.h>
> ```

---

## <div align="center"> ![vnl_wiki](../../img/vnl_wiki.png) <span style="color:#3737c8">How Colors Work?</span> ![vnl_wiki](../../img/vnl_wiki.png) </div>

<span style="color:#e9e9e9">![vnl_info](../../img/vnl_info.png) Did you ever heard the tragedy of darth Plagueis? If you heard, good for you, but its out of context. But if you heard the ascii escape sequence you would understand what I'm talking about. Yes, this library made completely with ascii escape sequence. So, what is ascii escape sequence? You can find out [here](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797). So your terminal must support to ascii escape sequence to using this library.</span>

<span style="color:#e9e9e9">![vnl_warn](../../img/vnl_warn.png) Some terminals may not support or not completely support ascii escape sequence.</span>

## ![vnl](../../img/vnl.png) <span style="color:#e9e9e9">What is ASCII?</span> ![vnl](../../img/vnl.png)

<span style="color:#e9e9e9">**ASCII:** American Standard Code for Information Interchange</span>

<span style="color:#e9e9e9">The most common character encoding format for text data in computers and on the internet. In standard ASCII-encoded data, there are unique values for 128 alphabetic, numeric or special additional characters and control codes.</span>

<span style="color:#e9e9e9">But why you have to know why you use ASCII? Because, you can use this library because of ASCII.</span>

## ![vnl](../../img/vnl.png) <span style="color:#e9e9e9">What is Escape Sequences?</span> ![vnl](../../img/vnl.png)

<span style="color:#e9e9e9">**ASCII Escape Sequence:** Character combinations consisting of a backslash (\\) followed by a letter or by a combination of digits are called "escape sequences." To represent a newline character, single quotation mark, or certain other characters in a character constant, you must use escape sequences.</span>

<span style="color:#e9e9e9">So, why you should know escape sequences? Becauese, `new line`, `terminal screen cleaning`, `colors`, `terminal cursor position` or `terminal screen manipulation` those are you can use them because of escape sequences.</span>

## ![vnl](../../img/vnl.png) <span style="color:#e9e9e9">How Can We Use These?</span> ![vnl](../../img/vnl.png)

<span style="color:#e9e9e9">If you have ASCII supported terminal you can use them.</span>

<span style="color:#e9e9e9">For example, if you want to print something with color. Then you should do: `printf("%sHey Sup!%s", "\033[38;2;200;55;55m", "\033[0m");` This code will print `Hey Sup!` but foreground red. </span>

## ![vnl](../../img/vnl.png) <span style="color:#e9e9e9">Text Styles</span> ![vnl](../../img/vnl.png)

<span style="color:#e9e9e9">If you have ASCII supported terminal you can use them. Probably `vnl_blink` doesn't work on you terminal. </span>

<span style="color:#e9e9e9">There is few text styles in ASCII and here how we use them. </span>

1. `vnl_bold`: <span style="color:#e9e9e9">Bold style. </span>
2. `vnl_italic`: <span style="color:#e9e9e9">Italic style.</span>
3. `vnl_underline`: <span style="color:#e9e9e9">Normal text with underline.</span>
4. `vnl_blink`:<span style="color:#e9e9e9">Text will blink.</span>
5. `vnl_strikethrough`: <span style="color:#e9e9e9">Normal text with strikethrough.</span>

---

## <div align="center"> ![vnl_wiki](../../img/vnl_wiki.png) <span style="color:#3737c8">The Holy Three</span> ![vnl_wiki](../../img/vnl_wiki.png) </div>

<span style="color:#e9e9e9">There is 17 function in this library. But 3 of them is important ones. Because, you can use 14 function with this 3 function. Functions seperated to 3 category. </span>

## ![vnl](../../img/vnl.png) <span style="color:#e9e9e9">Function List</span> ![vnl](../../img/vnl.png)

1. `vnl_color`: General purpose color function. Contains 2 feature.
    * HEX Color and Rgb Color.
    * 'base' is means decide to foreground or background.
```c
vnl_color("#a1b2c3", 0); /* Foreground HEX Color */
vnl_color("200 020 002", 1); /* Background RGB Color*/
```
2. `vnl_cursor`: Terminal cursor and screen manipulation function. Contains 9 feature.
    * Curser position save, restore, go to next line, go to previous line, go to specific line.
    * Screen save and restore.
    * Cursor visibility settings.
```c
vnl_cursor("position:goto(42:24)"); /* Go to specific line. */
vnl_cursor("position:next_line"); /* Go to next line. */
vnl_cursor("position:previous_line"); /* Go to previous line. */
vnl_cursor("position:save"); /* Save cursor location. */
vnl_cursor("position:restore"); /* Restore cursor location. */
vnl_cursor("screen:save"); /* Save terminal screen. */
vnl_cursor("screen:restore"); /* Restore terminal screen. */
vnl_cursor("visibility:on"); /* Set cursor visibility to on. */
vnl_cursor("visibility:off"); /* Set cursor visibility to off. */
```
3. `vnl_terminal`: General purpose terminal function. Contains 6 feature.
    * Clear terminal screen, terminal input/output mode, get width/height or execute shell commands.
```c
vnl_terminal("display:clear"); /* Clear terminal screen. */
vnl_terminal("io:raw"); /* Terminal input/output mode. */
vnl_terminal("io:cooked"); /* Normal terminal mode. */
vnl_terminal("get:width"); /* Get terminal width as integer. */
vnl_terminal("get:height"); /* Get terminal height as integer. */
vnl_terminal("Other Inputs"); /* General purpose stuff. */
```

## ![vnl](../../img/vnl.png) <span style="color:#e9e9e9">Alternative Functions</span> ![vnl](../../img/vnl.png)

<span style="color:#e9e9e9">Alternative functions are 14 functions, currently using by the holy three. But why you might need to use these alternatives. For example, you want to set cursor location to specific location. You will use `vnl_cursor` function as `vnl_cursor("position:goto(42:24)")` but you will use this function inside of a loop. And the location will change each time. So you shouldn't use this function. In that case you need to use alternative function. You need to use `vnl_gotoxy` function. At least the algorithm will be not changed. Because `vnl_gotoxy` is `vnl_cursor("position:goto")`. These functions same things because the holy three are functions hubs. So, 3 function literally use 14 function. Also maybe you can save 2-3 byte resource by using these alternative functions.</span>

1. Use `vnl_colorizer_rgb(int red, int green, int blue, int base)` over `vnl_color("199 054 002", base)`
2. Use `vnl_colorizer_hex(char *hex[8], int base)` over `vnl_color("#a1b2c3", base)`
3. Use `vnl_colorizer_rgb(int red, int green, int blue, int base)` over `vnl_colorizer_hex(char *hex[8], int base)`
4. Use `vnl_gotoxy(int pos_x, int pos_y)` over `vnl_cursor(position:goto(pos_x, pos_u))`
5. Use `vnl_goto_next_line(int line)` over `vnl_cursor(position:next_line)`
6. Use `vnl_goto_previous_line(int line)` over `vnl_cursor(position:previous_line)`
---