SRC=$(wildcard src/*c)
OBJ=$(patsubst %c, %o, $(SRC))
INC=inc/
EXESRC=$(wildcard exesrc/*.c)
EXEOBJ=$(patsubst %.c, %.o, $(EXESRC))
EXE=$(patsubst exesrc/%.c, exe/%.elf, $(EXESRC))

CFLAGS=-I $(INC)



all: $(EXE)

exe/%.elf: exesrc/%.o $(OBJ)
	gcc $^ -o $@ -lm
	
.SECONDARY :
%.o: %.c
	gcc -c $< $(CFLAGS) -o $@ 

.PHONY: clean run

clean:
	rm -f $(OBJ) $(EXE) $(EXEOBJ)

run:
	for x in exe/*.elf; do ./$$x; done