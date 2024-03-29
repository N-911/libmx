NAME = libmx.a

INC = libmx.h

INCI = inc/libmx.h

SRC = mx_isalpha.c mx_clear_list.c mx_create_node.c mx_pop_back.c mx_pop_front.c mx_push_front.c mx_push_back.c mx_list_size.c mx_atoi.c mx_count_substr.c mx_count_words.c mx_del_strarr.c mx_file_to_str.c mx_foreach.c mx_get_char_index.c mx_get_sub_index.c mx_isdigit.c mx_isspace.c mx_itoa.c mx_printchar.c mx_printerr.c mx_printint.c mx_printstr.c mx_str_reverse.c mx_strcat.c mx_strcmp.c mx_strcpy.c mx_strdel.c mx_strdup.c mx_strjoin.c mx_strlen.c mx_strncmp.c mx_strncpy.c mx_strndup.c mx_strnew.c mx_strstr.c mx_swap_char.c


SRCS = $(addprefix src/, mx_isalpha.c mx_clear_list.c mx_create_node.c mx_pop_back.c mx_pop_front.c mx_push_front.c mx_push_back.c mx_list_size.c mx_atoi.c mx_count_substr.c mx_count_words.c mx_del_strarr.c mx_file_to_str.c mx_foreach.c mx_get_char_index.c mx_get_sub_index.c mx_isdigit.c mx_isspace.c mx_itoa.c mx_printchar.c mx_printerr.c mx_printint.c mx_printstr.c mx_str_reverse.c mx_strcat.c mx_strcmp.c mx_strcpy.c mx_strdel.c mx_strdup.c mx_strjoin.c mx_strlen.c mx_strncmp.c mx_strncpy.c mx_strndup.c mx_strnew.c mx_strstr.c mx_swap_char.c)


OBJ = mx_isalpha.o mx_clear_list.o mx_create_node.o mx_pop_back.o mx_pop_front.o mx_push_front.o mx_push_back.o mx_list_size.o mx_atoi.o mx_count_substr.o mx_count_words.o mx_del_strarr.o mx_file_to_str.o mx_foreach.o mx_get_char_index.o mx_get_sub_index.o mx_isdigit.o mx_isspace.o mx_itoa.o mx_printchar.o mx_printerr.o mx_printint.o mx_printstr.o mx_str_reverse.o mx_strcat.o mx_strcmp.o mx_strcpy.o mx_strdel.o mx_strdup.o mx_strjoin.o mx_strlen.o mx_strncmp.o mx_strncpy.o mx_strndup.o mx_strnew.o mx_strstr.o mx_swap_char.o

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean
install:
	@cp $(SRCS) .
	@cp $(INCI) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@ar -rcs $(NAME) $(OBJ)
	@mkdir obj
	@mv $(OBJ) ./obj

uninstall:
	@rm -rf $(NAME)

clean:
	@rm -rf $(INC)
	@rm -rf ./obj
	@rm -rf $(SRC) 
	@rm -rf $(OBJ)

reinstall: uninstall all
