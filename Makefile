exec = pacl.out
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g


$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)
	rm bin.txt
	xxd -b $(exec) > bin.txt

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	cp ./pacl.out /usr/local/bin/pacl

clean:
	-rm *.out 
	-rm src/*.o

link: 
