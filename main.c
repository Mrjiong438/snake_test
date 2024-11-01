#include "snake_core/snake.h"

#define logg \
	printf("x:%d,y:%d\ninput:%d,lastinput:%d\ngtime:%d,move:%d\n", \
			head.x,head.y,gc,lastgc,gtime,move);

void draw();

int main(int argc, char *argv[]){
	
	for(int i=1;i<argc;i++){
	if (strcmp(argv[i],"--no-hitwall")==0 ||
		strcmp(argv[i],"-w")==0 
		)
		hitwall=0;
	}

	int move =0;
	srand((unsigned)time(NULL));
	genfood();
	//setchar(6,6,'^');
	//setpos(&head,6,6);
	//setpos(&tail,6,6);
	initHeadPos(6,6,'^');
	clear
	logg
	draw();
	while(lastgc=gc,gc=getchar()){
		gtime++;
		if (gc == '\n')
			gc='N';
		if (gc == 'q')
			break;
		switch(gc){
			case 'W':
			case 'w':
				move=setdirUP();
				break;
			case 'A':
			case 'a':
				move=setdirLEFT();
				break;
			case 'S':
			case 's':
				move=setdirDOWN();
				break;
			case 'D':
			case 'd':
				move=setdirRIGHT();
				break;
		}
		clear
		if (lastgc=='N' && gc=='N')
			switch (change()){
				case 1:
					printf("gameover\n");
					return 0;
				case 2:
					printf("win\n");
					return 0;
			}
		logg
		draw();

	}
	return 0;
}

void draw(){
	printf("%c",'#');
	for(int y=0;y<MAPSIZE;y++)
		printf("--");
	printf("%c\n",'#');
	for(int y=0;y<MAPSIZE;y++){
		printf("|");
		for(int x=0;x<MAPSIZE;x++){
			switch (map[x][y]){
				case  0 :
					printf("  ");
					break;
				case '@':
					printf("@@");
					break;
				default:
					printf("%c%c",map[x][y],map[x][y]);
			}
		}
		printf("|\n");
	}
	printf("%c",'#');
	for(int y=0;y<MAPSIZE;y++)
		printf("--");
	printf("%c\n",'#');
}

