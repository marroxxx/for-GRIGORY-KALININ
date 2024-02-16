BINDIR = ../lib/bin/
SRCDIR = ../lib/src/

all: Vector.out List.out Deque.out

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
	
Deque.out: Deque.o $(BINDIR)libdeque_stdio.so
	gcc $< -L$(BINDIR) -o $@ -ldeque_stdio -llist_stdio

Deque.o: Deque.c
	gcc -c Deque.c -o Deque.o -Wall

$(SRCDIR)deque.o: $(SRCDIR)deque.c
	gcc -c $< -o $@

$(BINDIR)libdeque_stdio.so: $(SRCDIR)deque.c
	gcc -c --shared $< -o $@
	
run:
	./Deque.out input.txt output.txt
