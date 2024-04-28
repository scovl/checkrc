TARGET = main
CC = clang
CFLAGS = -Wall -Wextra -pedantic -std=c99
SRCDIR = src
INCDIR = include
OBJDIR = obj

SOURCES = src/main.c
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
INCLUDES = -I$(INCDIR)

all: $(TARGET)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean all
