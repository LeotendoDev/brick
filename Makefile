exec = bin/brick
src = $(wildcard src/*.c)
obj = $(src:.c=.o)
flags = -Wall -g

$(exec): $(obj)
	gcc $(obj) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@
