exec = pacl
sources = $(wildcard main.c)  $(wildcard core/*/*.c)
objects = $(sources:.c=.o)
flags = -g 


$(exec): $(objects)
	gcc $(objects) $(flags) -o bin/$(exec)
	xxd -b bin/$(exec) >> bin/bin.txt	

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	cp bin/pacl /usr/local/bin/pacl

clean:
	-rm bin/*
	-rm $(objects)