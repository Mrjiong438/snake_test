.PHONY: clean


object = build/main.o build/snake.o 
objectWin = build/mainWin.o build/snakeWin.o 
CFLUG = -s -O2 -Wl,--gc-sections

main : $(object)
	gcc $(CFLUG) $(object) -o $@

build/snake.o : snake_core/snake.c
	gcc $(CFLUG) -c $< -o $@ 

build/main.o : main.c
	gcc $(CFLUG) -c $< -o $@ 

main.exe : $(objectWin)
	x86_64-w64-mingw32-gcc $(CFLUG)  $(objectWin) -o $@

build/snakeWin.o : snake_core/snake.c
	x86_64-w64-mingw32-gcc $(CFLUG) -c $< -o $@ 

build/mainWin.o : main.c
	x86_64-w64-mingw32-gcc $(CFLUG) -c $< -o $@ 



clean :
	rm -rf build/* main main.exe

