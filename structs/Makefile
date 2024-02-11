BINDIR = ../lib/bin/
SRCDIR = ../lib/src/

all: Vector.out List.out

Vector.out: Vector.o $(BINDIR)libvector_stdio.so
	gcc $< -L$(BINDIR) -o $@ -lvector_stdio

Vector.o: Vector.c
	gcc -c Vector.c -o Vector.o -Wall

$(SRCDIR)vector.o: $(SRCDIR)vector.c
	gcc -c $< -o $@

$(BINDIR)libvector_stdio.so: $(SRCDIR)vector.c
	gcc -c --shared $< -o $@

List.out: List.o $(BINDIR)liblist_stdio.so
	gcc $< -L$(BINDIR) -o $@ -llist_stdio

List.o: List.c
	gcc -c List.c -o List.o -Wall

$(SRCDIR)list.o: $(SRCDIR)list.c
	gcc -c $< -o $@

$(BINDIR)liblist_stdio.so: $(SRCDIR)list.c
	gcc -c --shared $< -o $@
run:
	./List.out input.txt output.txt
