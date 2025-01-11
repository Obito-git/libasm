LIB_NAME = libasm.a

NAME = libasm.a
CC = clang
ASM = nasm
CFLAGS = -Wall -Werror -Wextra -g3 -Iinc -Itest
ASMFLAGS = -f elf64

SRCS_DIR = src/
OBJ_DIR = obj/
TEST_DIR = test/

SRCS = $(wildcard $(SRCS_DIR)*.s)
OBJS = $(patsubst $(SRCS_DIR)%.s, $(OBJ_DIR)%.o, $(SRCS))
TEST_SRCS = $(wildcard $(TEST_DIR)*.c)

all: $(NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.s Makefile | $(OBJ_DIR)
	$(ASM) $(ASMFLAGS) -o $@ $<

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -f .*.swp

fclean: clean
	rm -f $(NAME)
	rm -f test_bin

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) -g3 -o test_bin $(TEST_SRCS) $(NAME)

runtest: test
	./test_bin

.PHONY: all clean fclean re test
