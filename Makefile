SRCDIR = ./src
SRC = $(SRCDIR)/parser.c $(SRCDIR)/to_json.c $(SRCDIR)/utils.c
CMP = main.c $(SRC)
INCDIR = ./include
OUTPUT = ./output/dom.json
TRG = a.out

all: $(TRG)

$(TRG): $(CMP)
	$(CC) $^ -I $(INCDIR)

clean:
	$(RM) $(TRG) $(OUTPUT)

.PHONY: all clean
