# --------------------------------------------------------- #
# SINGLE-HEADER TERMINAL USER INTERFACE | VARIATION-LITE-UI #
#                    DEMO FILES MAKEFILE                    #
# --------------------------------------------------------- #

# CONFIGURATION #
CC = gcc
ANSI = -std=c89
DEBUG = -g
# ------------- #

# ASCII DEFINATIONS #
end_text = \033[0m

white_fg = \033[38;2;233;233;233m
gray_fg = \033[38;2;50;50;50m
red_fg = \033[38;2;200;55;55m
green_fg = \033[38;2;55;200;55m
blue_fg = \033[38;2;55;55;200m

text_bold = \033[1m
text_italic = \033[3m
text_underline = \033[4m
text_strikethrough = \033[9m
# ----------------- #

# DEMO LIST #
CT = $(gray_fg)($(green_fg)complete-test$(gray_fg))$(end_text)
CRF =  $(gray_fg)($(green_fg)colored-responsive-frame$(gray_fg))$(end_text)
LS =  $(gray_fg)($(green_fg)loading-screen$(gray_fg))$(end_text)
WGG = $(gray_fg)($(green_fg)word-guess-game$(gray_fg))$(end_text)
DEMO_LIST = $(blue_fg)Demo$(gray_fg)[$(red_fg)4$(gray_fg)]$(white_fg): $(CT)$(white_fg), $(CRF)$(white_fg),  $(LS)$(white_fg), $(WGG)$(white_fg).$(end_text)
demo_list = all-tests colored-responsive-frame loading-screen word-guess-game
# --------- #

.PHONY: run compile debug clean

run:
	@echo ""
	@echo "\t\t\$(blue_fg)[$(white_fg)Make List$(blue_fg)]"
	@echo "$(end_text)"
	@echo "$(green_fg)1.$(white_fg) Show make list $(red_fg)$(text_bold)'make' $(white_fg)or $(red_fg)'make run'$(end_text)"
	@echo "$(green_fg)2.$(white_fg) Compile demo file $(red_fg)$(text_bold)'make compile'$(end_text)"
	@echo "$(green_fg)2.$(white_fg) Compile demo debug file $(red_fg)$(text_bold)'make debug'$(end_text)"
	@echo "$(green_fg)3.$(white_fg) Clean compiled files $(red_fg)$(text_bold)'make clean'$(end_text)"
	@echo ""

compile:
	@echo ""
	@echo "\t\t$(gray_fg)[$(blue_fg)Demo List$(gray_fg)]$(end_text)"; \
	echo "$(DEMO_LIST)"; \
	echo ""; \
	echo "$(gray_fg)[$(blue_fg)Enter Demo Name$(white_fg):$(gray_fg)]$(end_text)"; \
	read demo_name; $(CC) src/$$demo_name/main.c $(ANSI) -o $$demo_name; \

	@echo ""
	@echo "\t$(green_fg)[$(blue_fg) -------------------------------- $(green_fg)] "
	@echo "\t$(green_fg)[ $(red_fg)$(text_underline)Demo File$(end_text)$(white_fg) successfully compiled! $(green_fg)] "
	@echo "\t$(green_fg)[$(blue_fg) -------------------------------- $(green_fg)] "
	@echo "$(end_text)"

debug:
	@echo ""
	@echo "\t\t$(gray_fg)[$(blue_fg)Demo List$(gray_fg)]$(end_text)"; \
	echo "$(DEMO_LIST)"; \
	echo ""; \
	echo "$(gray_fg)[$(blue_fg)Enter Demo Name$(white_fg):$(gray_fg)]$(end_text)"; \
	read demo_name; $(CC) $(DEBUG) src/$$demo_name/main.c $(ANSI) -o $$demo_name; \

	@echo ""
	@echo "\t$(green_fg)[$(blue_fg) -------------------------------------- $(green_fg)] "
	@echo "\t$(green_fg)[ $(red_fg)$(text_underline)Demo Debug File$(end_text)$(white_fg) successfully compiled! $(green_fg)] "
	@echo "\t$(green_fg)[$(blue_fg) -------------------------------------- $(green_fg)] "
	@echo "$(end_text)"

clean:
	@rm -f $(demo_list)

	@echo ""
	@echo "\t$(green_fg)[$(blue_fg) ----------------------------------------- $(green_fg)] "
	@echo "\t$(green_fg)[ $(red_fg)$(text_strikethrough)Compiled Demo Files$(end_text)$(white_fg) successfully cleaned! $(green_fg)] "
	@echo "\t$(green_fg)[$(blue_fg) ----------------------------------------- $(green_fg)] "
	@echo "$(end_text)"

# MADE BY @hanilr #