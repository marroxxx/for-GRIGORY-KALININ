BINDIR = ../lib/bin/
SRCDIR = ../lib/src/

compressor.out: compressor.o $(BINDIR)libcompress_stdio.so
	gcc $< -L$(BINDIR) -o $@ -lcompress_stdio

compressor.o: compressor.c
	gcc -c compressor.c -o compressor.o -Wall

$(SRCDIR)compress.o: $(SRCDIR)compress.c
	gcc -c $< -o $@

$(BINDIR)libcompress_stdio.so: $(SRCDIR)compress.c
	gcc -c --shared $< -o $@
run:
	./compressor.out input.txt output.txt
