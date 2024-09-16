
#include <sys/types.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <psxgte.h>
#include <psxgpu.h>

//Define environment pairs and buffer counter
DISPENV disp[2];
DRAWENV draw[2];
int db;

void init(){
	ResetGraph(0);
	SetDefDispEnv(&disp[0],0,0,320,240);
	SetDefDispEnv(&disp[1],0,240,320,240);
	
	SetDefDrawEnv(&draw[0],0,240,320,240);
	SetDefDrawEnv(&draw[1],0,0,320,240);
	
	setRGB0(&draw[0],63,0,12);
	setRGB0(&draw[1],63,0,12);
	
	draw[0].isbg=1;
	draw[1].isbg=1;
	
	PutDispEnv(&disp[0]);
	PutDrawEnv(&draw[0]);

	db=0;
}

void display(){
	DrawSync(0);
	VSync(0);

	//Flip buffer counter
	db = !db;

	PutDispEnv(&disp[db]);
	PutDrawEnv(&draw[db]);

	SetDispMask(1);
}

int main (){	
	init();

	while(1){
		display();
	}

	return 0;
}