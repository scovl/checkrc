TARGET = checkrc
CC = clang
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c17
SRCDIR = src
INCDIR = include

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=%.o)
INCLUDES = -I$(INCDIR)

all: $(TARGET)

# main includes config.h, so it needs to depend on it
main.o: $(INCDIR)/config.h

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)

%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean all
