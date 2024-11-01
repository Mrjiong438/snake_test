.PHONY: clean
object = build/main.o build/snake.o 

main : $(object)
	gcc $(object) -o $@

build/snake.o : snake_core/snake.c
	gcc -c $< -o $@ 

build/main.o : main.c
	gcc -c $< -o $@ 

clean :
	rm -rf build/* main:w

