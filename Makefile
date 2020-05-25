cc = gcc
debug_flags = -ggdb3 -Wall


build_min:
	gcc -Wfatal-errors \
	-std=c99 \
	src/*.c \
	-ggdb3 \
	-I"C:\libsdl32\include" \
	-L"C:\libsdl32\lib" \
	-Isrc/ \
	-lmingw32 \
	-lSDL2main \
	-lSDL2 \
	-o bin/example.exe

run:
	bin/./example.exe

clean: 
	rm bin/example.exe 

gdb:
	gdb bin/example.exe
