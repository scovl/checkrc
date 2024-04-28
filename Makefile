TARGET = main
CC = clang
CFLAGS = -Wall -Wextra -pedantic -std=c99
SRCDIR = src
INCDIR = include
OBJDIR = obj

# Listagem manual dos arquivos fonte
SOURCES = src/main.c
# Conversão manual dos arquivos fonte para caminhos de arquivos objeto
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

INCLUDES = -I$(INCDIR)

# A regra all para construir o executável final
all: $(TARGET)

# Criando o diretório obj antes da compilação dos objetos
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Linkagem dos objetos para formar o executável
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

# Compilação de cada arquivo objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Regra para limpeza dos arquivos compilados
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean all
