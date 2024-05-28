

TARGET = bin/final


SRC  =$(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))


default: $(TARGET)


$(TARGET):$(OBJ)
	gcc -o $@ $?

obj/%.o:src/%.c
	gcc -c $< -o $@ -I./include

clean:
	rm -f bin/*
	rm -f obj/*.o
