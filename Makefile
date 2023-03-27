# --------------------------------------------------------- #
# SINGLE-HEADER TERMINAL USER INTERFACE | VARIATION-LITE-UI #
#             SHARED-LIBRARY CONVERTING MAKEFILE            #
# --------------------------------------------------------- #

# CONFIGURATION #
CC = gcc
ANSI = -std=c89

lib = vnl_ui.h
out = vnl_ui.so
# ------------- #

# ASCII DEFINATIONS #
end_text = \033[0m

white_fg = \033[38;2;233;233;233m
red_fg = \033[38;2;200;55;55m
green_fg = \033[38;2;55;200;55m
blue_fg = \033[38;2;55;55;200m

text_bold = \033[1m
text_italic = \033[3m
text_underline = \033[4m
text_strikethrough = \033[9m
# ----------------- #

.PHONY: run compile clean install uninstall

run:
	@echo ""
	@echo "\t\t\$(blue_fg)[$(white_fg)Make List$(blue_fg)]"
	@echo "$(end_text)"
	@echo "$(green_fg)1.$(white_fg) Show make list $(red_fg)$(text_bold)'make' $(white_fg)or $(red_fg)'make run'$(end_text)"
	@echo "$(green_fg)2.$(white_fg) Compile as shared-library $(red_fg)$(text_bold)'make compile'$(end_text)"
	@echo "$(green_fg)3.$(white_fg) Clean shared-library $(red_fg)$(text_bold)'make clean'$(end_text)"
	@echo "$(green_fg)4.$(white_fg) Install the library $(red_fg)$(text_bold)'make install'$(end_text)"
	@echo "$(green_fg)5.$(white_fg) Uninstall the library $(red_fg)$(text_bold)'make uninstall'$(end_text)"
	@echo ""

compile: $(lib)
	@$(CC) $(ANSI) -shared -fPIC $(lib) -o $(out)
	
	@echo ""
	@echo "\t$(green_fg)[$(blue_fg) ------------------------------------- $(green_fg)] "
	@echo "\t$(green_fg)[ $(red_fg)$(text_underline)Shared-Library$(end_text)$(white_fg) successfully compiled! $(green_fg)] "
	@echo "\t$(green_fg)[$(blue_fg) ------------------------------------- $(green_fg)] "
	@echo "$(end_text)"

clean:
	@rm $(out)
	
	@echo ""
	@echo "\t$(green_fg)[$(blue_fg) ------------------------------------ $(green_fg)] "
	@echo "\t$(green_fg)[ $(red_fg)$(text_strikethrough)Shared-Library$(end_text)$(white_fg) successfully cleaned! $(green_fg)] "
	@echo "\t$(green_fg)[$(blue_fg) ------------------------------------ $(green_fg)] "
	@echo "$(end_text)"

install: $(lib)
	@sudo mkdir -p /usr/include/vn
	@sudo cp vnl_ui.h /usr/include/vn
	@sudo chmod -x /usr/include/vn/vnl_ui.h

	@echo ""
	@echo "\t$(green_fg)[$(blue_fg) ----------------------------------------- $(green_fg)] "
	@echo "\t$(green_fg)[ $(red_fg)$(text_underline)Variation Lite UI$(end_text)$(white_fg) successfully installed! $(green_fg)] "
	@echo "\t$(green_fg)[$(blue_fg) ----------------------------------------- $(green_fg)] "
	@echo "$(end_text)"

uninstall:
	@sudo rm /usr/include/vn/vnl_ui.h
	@if [ "$(ls -A "/usr/include/vn/" 2> /dev/null)" = "" ]; then sudo rm -rf /usr/include/vn/; fi

	@echo ""
	@echo "\t$(green_fg)[$(blue_fg) ------------------------------------------- $(green_fg)] "
	@echo "\t$(green_fg)[ $(red_fg)$(text_strikethrough)Variation Lite UI$(end_text)$(white_fg) successfully uninstalled! $(green_fg)] "
	@echo "\t$(green_fg)[$(blue_fg) ------------------------------------------- $(green_fg)] "
	@echo "$(end_text)"

# MADE BY @hanilr #