exec = a.out
sources = $(wildcard main.c)  $(wildcard core/*/*.c)
objects = $(sources:.c=.o)
flags = -g


$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)
	rm bin.txt
	xxd -b $(exec) >> bin.txt

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	cp ./a.out /usr/local/bin/pacl

clean:
	-rm *.out 
	-rm $(objects)

link: 
