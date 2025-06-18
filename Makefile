CC = gcc
CFLAGS = -Wall -Wextra -Isrc -Iinclude
OBJDIR = objs

OBJS = $(OBJDIR)/main.o \
       $(OBJDIR)/tree.o \
       $(OBJDIR)/exprvalidator.o \
       $(OBJDIR)/exprparser.o

all: tree_builder

tree_builder: $(OBJS)
	$(CC) $(CFLAGS) -o tree_builder $(OBJS)

$(OBJDIR)/main.o: src/main.c include/tree.h
	$(CC) $(CFLAGS) -c src/main.c -o $@ 

$(OBJDIR)/tree.o: src/tree.c include/tree.h include/exprparser.h include/exprvalidator.h
	$(CC) $(CFLAGS) -c src/tree.c -o $@ 

$(OBJDIR)/exprvalidator.o: src/exprvalidator.c include/exprvalidator.h
	$(CC) $(CFLAGS) -c src/exprvalidator.c -o $@ 

$(OBJDIR)/exprparser.o: src/exprparser.c include/exprparser.h
	$(CC) $(CFLAGS) -c src/exprparser.c -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJS): | $(OBJDIR) 

clean:
	rm -rf tree_builder $(OBJDIR)

 