.PHONY: clean


object = build/main.o build/snake.o 
objectWin = build/mainWin.o build/snakeWin.o 

main : $(object)
	gcc $(object) -o $@

build/snake.o : snake_core/snake.c
	gcc -c $< -o $@ 

build/main.o : main.c
	gcc -c $< -o $@ 

main.exe : $(objectWin)
	x86_64-w64-mingw32-gcc $(objectWin) -o $@

build/snakeWin.o : snake_core/snake.c
	x86_64-w64-mingw32-gcc -c $< -o $@ 

build/mainWin.o : main.c
	x86_64-w64-mingw32-gcc -c $< -o $@ 



clean :
	rm -rf build/* main main.exe

