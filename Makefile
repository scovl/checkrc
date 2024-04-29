TARGET = checkrc
CC = clang
SRCDIR = src
INCDIR = include

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=%.o)
INCLUDES = -I$(INCDIR)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

%.o: $(SRCDIR)/%.c
	$(CC) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean all
