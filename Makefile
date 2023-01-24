CC = gcc
CLAGS = -Wall -Werror

CC = gcc  # C compiler
CFLAGS = -fPIC -Wall -Werror -Wextra -Wno-unused-result -O2  # C flags
CFLAGS += 
LDFLAGS = -shared   # linking flags
RM = rm -f   # rm command
TARGET_LIB = libengine.so  # engine lib

SRCS = main.c pixel_handler.c pixel_storage.c screen_handler.c  # source files
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)
