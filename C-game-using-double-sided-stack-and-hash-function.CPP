#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
int play(int);
int check_s(int);
void move(int);
void push1(int);
int pop1();
int peek1();
int isempty1();
int size1();
int isfull();
void push2(int);
int pop2();
int peek2();
int isempty2();
int size2();
struct site
{
	int x;
	int y;
	char status[9];
}si8[406];
struct player
{
	char character;
	char tree;
	char choice;
	char up;
	char down;
	char left;
	char right;
	int start;
	int ID;
	int life;
	int spower_1;
	int spower_2;
	int surrounding;
};
struct player player_1={2,30,'n','w','s','a','d',0,1,2,2,4,4};
struct player player_2={1,31,'n','i','k','j','l',0,2,2,2,4,4};
int stack[406],top1=-1,top2=406;
void main()
{
	clrscr();
	textbackground(RED);
	char a,l;
	int i,j,index,game=1,chance=0;
	_setcursortype(_NOCURSOR);
	clrscr();
	delay(200);
	gotoxy(27,10);
	printf("..____FOREST WARS____..");
	delay(400);
	gotoxy(10,12);
	printf("'Forest wars' is a 2019 strategic maze based multiplayer game;");
	gotoxy(10,13);
	delay(200);
	printf("developed using the double sided stack data structure and ");
	gotoxy(10,14);
	delay(200);
	printf("hashing algorithms, as a tribute to the video game developers ");
	gotoxy(10,15);
	delay(200);
	printf("of the golden era...");
	sleep(4);
	clrscr();
	delay(200);
	for(i=1;i<=2;i++)
	{
		clrscr();
		gotoxy(37,11);
		printf("-------");
		gotoxy(37,13);
		printf("-------");
		gotoxy(38,12);
		printf("START");
		delay(600);
		gotoxy(25,14);
		printf("(Press any key to start the game)");
		sleep(1);
	}
	getch();
	delay(600);
	for(i=1;i<=2;i++)
	{
		clrscr();
		textbackground(GREEN);
		textcolor(WHITE);
	}
	l=3;
	a=4;
	gotoxy(35,12);
	printf("loading...");
	for(i=1;i<=35;i++)
	{
		delay(100);
		gotoxy(i,1);
		printf("%c",a);
	}
	delay(100);
	gotoxy(35,12);
	printf("          ");
	delay(100);
	gotoxy(35,12);
	printf("loading...");
	for(i=1;i<=35;i++)
	{
		delay(100);
		gotoxy(i,25);
		printf("%c",a);
	}
	delay(100);
	gotoxy(35,12);
	printf("          ");
	delay(100);
	gotoxy(35,12);
	printf("loading...");
	for(i=2;i<25;i++)
	{
		delay(100);
		gotoxy(1,i);
		printf("%c",a);
	}
	delay(100);
	gotoxy(35,12);
	printf("          ");
	for(i=2;i<25;i++)
	{
		delay(100);
		gotoxy(35,i);
		printf("%c",a);
	}
	delay(100);
	gotoxy(35,1);
	printf("%c\t\t     WELCOME",a);
	delay(200);
	gotoxy(2,3);
	printf("     ..____FOREST WARS____..     ");
	delay(400);
	gotoxy(35,3);
	printf("%c\t     ..____FOREST WARS____..     ",a);
	delay(200);
	gotoxy(35,6);
	printf("%c\tTRAP TO WIN",a);
	gotoxy(35,7);
	printf("%c\tCan you survive this mystical forest ?",a);
	gotoxy(35,9);
	printf("%c\tFate decides where you land but you",a);
	gotoxy(35,10);
	printf("%c\tdecide your destiny; trap and win or get",a);
	gotoxy(35,11);
	printf("%c\ttrapped.",a);
	gotoxy(35,13);
	printf("%c\tThe landscape can be filled with trees",a);
	gotoxy(35,14);
	printf("%c\taccording to your moves.On your each",a);
	gotoxy(35,15);
	printf("%c\tmove, a tree shall sprung up at the spot",a);
	gotoxy(35,16);
	printf("%c\tyou left. Build the trap as you move.",a);
	gotoxy(35,17);
	printf("%c\tTo win; always have an escape route.",a);
	gotoxy(35,19);
	printf("%c\tControls:   Player 1    Player 2",a);
	delay(200);
	gotoxy(35,20);
	printf("%c\tUp             w           i",a);
	delay(200);
	gotoxy(35,21);
	printf("%c\tLeft           a           j",a);
	delay(200);
	gotoxy(35,22);
	printf("%c\tDown           s           k",a);
	delay(200);
	gotoxy(35,23);
	printf("%c\tRight          d           l",a);
	a=5;
	for(i=5;i<=18;i++)
	{
		gotoxy(32,i);
		printf("%c",a);
		index=387+i;
		strcpy(si8[index].status,"Active");
		si8[index].x=32;
		si8[index].y=i;
	}
	for(i=5;i<=18;i++)
	{
		gotoxy(4,i);
		printf("%c",a);
		index=i-5;
		strcpy(si8[index].status,"Active");
		si8[index].x=4;
		si8[index].y=i;
	}
	a=6;
	for(i=5;i<32;i++)
	{
		gotoxy(i,5);
		printf("%c",a);
		index=(i-4)*14;
		strcpy(si8[index].status,"Active");
		si8[index].x=i;
		si8[index].y=5;
	}
	for(i=5;i<32;i++)
	{
		gotoxy(i,18);
		printf("%c",a);
		index=((i-4)*14)+13;
		strcpy(si8[index].status,"Active");
		si8[index].x=i;
		si8[index].y=18;
	}
	gotoxy(2,20);
	printf(" (%c) Player 1       (%c) Player 2",player_1.character,player_2.character);
	gotoxy(8,21);
	for(i=1;i<=player_1.life;i++)
	printf("%c",l);
	gotoxy(23,21);
	for(i=1;i<=player_2.life;i++)
	printf("%c",l);
	gotoxy(10,22);
	printf("Make your choice");
	for(i=5;i<=31;i++)
	{
		for(j=6;j<=17;j++)
		{
			index=((i-4)*14)+(j-5);
			strcpy(si8[index].status,"Inactive");
			si8[index].x=i;
			si8[index].y=j;
		}
	}
	do
	{
		if((chance%2)==0)
		game=play(player_1.ID);
		else
		game=play(player_2.ID);
		chance+=1;
	}
	while(game==1);
	gotoxy(10,22);
	for(i=1;i<=16;i++)
	printf(" ");
	if((chance%2)==0)
	{
	  gotoxy(10,23);
	  printf("PLAYER 1 WINSS!!!");
	  sleep(2);
	  gotoxy(7,24);
	  printf("(Press any key to exit)");
	}
	else
	{
	  gotoxy(10,23);
	  printf("PLAYER 2 WINSS!!!");
	  sleep(2);
	  gotoxy(7,24);
	  printf("(Press any key to exit)");
	}
	getch();
}
int play(int ID)
{
	int game=1;
	game=check_s(ID);
	if(game==0)
	return 0;
	else
	{
		move(ID);
		return 1;
	}
}
int check_s(int ID)
{
	int i,j,index,l=3;
	if(player_1.ID==ID)
	{
		if(player_1.start==1)
		{
			index=peek1();
			player_1.surrounding=0;
			if(strcmpi(si8[index+14].status,"Inactive")==0)
			player_1.surrounding=1;
			else if(strcmpi(si8[index-14].status,"Inactive")==0)
			player_1.surrounding=1;
			else if(strcmpi(si8[index+1].status,"Inactive")==0)
			player_1.surrounding=1;
			else if(strcmpi(si8[index-1].status,"Inactive")==0)
			player_1.surrounding=1;
			if(player_1.surrounding==1)
			return 1;
			else
			{
				player_1.life--;
				gotoxy(8,21);
				printf("  ");
				gotoxy(8,21);
				for(i=1;i<=player_1.life;i++)
				printf("%c",l);
				l=peek1();
				for(i=top1;i>=0;i--)
				{
					index=pop1();
					gotoxy(si8[index].x,si8[index].y);
					delay(200);
					if(index==l)
					;
					else
					{
					printf(" ");
					strcpy(si8[index].status,"Inactive");
					}
				}
				gotoxy(18,23);
				index=l;
				push1(index);
				if(player_1.life==1)
				return 1;
				else
				return 0;
			}
		}
		else
		{
			randomize();
			i=random(27)+5;
			j=random(5)+6;
			index=((i-4)*14)+(j-5);
			push1(index);
			strcpy(si8[index].status,"Active");
			player_1.start=1;
			gotoxy(i,j);
			sleep(1);
			printf("%c",player_1.character);
			i=random(27)+5;
			j=random(5)+12;
			index=((i-4)*14)+(j-5);
			push2(index);
			strcpy(si8[index].status,"Active");
			player_2.start=1;
			gotoxy(i,j);
			delay(400);
			printf("%c",player_2.character);
			check_s(ID);
		}
	}
	else
	{
		index=peek2();
		player_2.surrounding=0;
		if(strcmp(si8[index+14].status,"Inactive")==0)
		player_2.surrounding=1;
		else if(strcmp(si8[index-14].status,"Inactive")==0)
		player_2.surrounding=1;
		else if(strcmp(si8[index+1].status,"Inactive")==0)
		player_2.surrounding=1;
		else if(strcmp(si8[index-1].status,"Inactive")==0)
		player_2.surrounding=1;
		if(player_2.surrounding==1)
		return 1;
		else
		{
			player_2.life--;
			gotoxy(23,21);
			printf("  ");
			gotoxy(23,21);
			for(i=1;i<=player_2.life;i++)
			printf("%c",l);
			l=peek2();
			for(i=top2;i<406;i++)
			{
				index=pop2();
				gotoxy(si8[index].x,si8[index].y);
				delay(200);
				if(index==l)
				;
				else
				{
					printf(" ");
					strcpy(si8[index].status,"Inactive");
				}
			}
			gotoxy(18,23);
			index=l;
			push2(index);
			if(player_2.life==1)
			return 1;
			else
			return 0;
		}
	}
}
void move(int ID)
{
     int index,temp,i,Move=0;
     do
	{
		if(player_1.ID==ID)
		{
			_setcursortype(_NORMALCURSOR);
			gotoxy(13,23);
			index=peek1();
			printf("(1): ");
			player_1.choice=getch();
			if(player_1.choice==player_1.up)
			{
				if(strcmpi(si8[index-1].status,"Inactive")==0)
				{
					gotoxy(si8[index-1].x,si8[index-1].y);
					printf("%c",player_1.character);
					push1(index-1);
					strcpy(si8[index-1].status,"Active");
					gotoxy(si8[index].x,si8[index].y);
					printf("%c",player_1.tree);
					Move=1;
				}
			}
			else if(player_1.choice==player_1.down)
			{
				if(strcmpi(si8[index+1].status,"Inactive")==0)
				{
					gotoxy(si8[index+1].x,si8[index+1].y);
					printf("%c",player_1.character);
					push1(index+1);
					strcpy(si8[index+1].status,"Active");
					gotoxy(si8[index].x,si8[index].y);
					printf("%c",player_1.tree);
					Move=1;
				}
			}
			else if(player_1.choice==player_1.left)
			{
				if(strcmpi(si8[index-14].status,"Inactive")==0)
				{
					gotoxy(si8[index-14].x,si8[index-14].y);
					printf("%c",player_1.character);
					push1(index-14);
					strcpy(si8[index-14].status,"Active");
					gotoxy(si8[index].x,si8[index].y);
					printf("%c",player_1.tree);
					Move=1;
				}
			}
			else if(player_1.choice==player_1.right)
			{
				if(strcmpi(si8[index+14].status,"Inactive")==0)
				{
					gotoxy(si8[index+14].x,si8[index+14].y);
					printf("%c",player_1.character);
					push1(index+14);
					strcpy(si8[index+14].status,"Active");
					gotoxy(si8[index].x,si8[index].y);
					printf("%c",player_1.tree);
					Move=1;
				}
			}
			else if(player_1.choice=='@')
			{
				if(player_1.spower_1>0)
				{
					index=peek1();
					for(i=1;(i<=6)&&(!isempty1());i++)
					{
						temp=pop1();
						gotoxy(si8[temp].x,si8[temp].y);
						delay(200);
						if(temp==index)
						;
						else
						{
							printf(" ");
							strcpy(si8[temp].status,"Inactive");
						}
					}
					gotoxy(si8[index].x,si8[index].y);
					printf("%c",player_1.character);
					push1(index);
					player_1.spower_1--;
					Move=1;
				}
			}
			else if(player_1.choice=='#')
			{
				 if(player_1.spower_2>0)
				 {
					player_1.spower_2--;
					Move=1;
				 }
			}
			else if(player_1.choice=='E')
			{
				delay(600);
				clrscr();
				gotoxy(37,12);
				printf("Exiting...");
				sleep(1);
				exit(0);
			}
	}
	else
	{
		index=peek2();
		_setcursortype(_NORMALCURSOR);
		gotoxy(13,23);
		printf("(2): ");
		player_2.choice=getch();
		if(player_2.choice==player_2.up)
		{
			if(strcmpi(si8[index-1].status,"Inactive")==0)
			{
				gotoxy(si8[index-1].x,si8[index-1].y);
				printf("%c",player_2.character);
				push2(index-1);
				strcpy(si8[index-1].status,"Active");
				gotoxy(si8[index].x,si8[index].y);
				printf("%c",player_2.tree);
				Move=1;
			}
		}
		else if(player_2.choice==player_2.down)
		{
			if(strcmpi(si8[index+1].status,"Inactive")==0)
			{
				gotoxy(si8[index+1].x,si8[index+1].y);
				printf("%c",player_2.character);
				push2(index+1);
				strcpy(si8[index+1].status,"Active");
				gotoxy(si8[index].x,si8[index].y);
				printf("%c",player_2.tree);
				Move=1;
			}
		}
		else if(player_2.choice==player_2.left)
		{
			if(strcmpi(si8[index-14].status,"Inactive")==0)
			{
				gotoxy(si8[index-14].x,si8[index-14].y);
				printf("%c",player_2.character);
				push2(index-14);
				strcpy(si8[index-14].status,"Active");
				gotoxy(si8[index].x,si8[index].y);
				printf("%c",player_2.tree);
				Move=1;
			}
		}
		else if(player_2.choice==player_2.right)
		{
			if(strcmpi(si8[index+14].status,"Inactive")==0)
			{
				gotoxy(si8[index+14].x,si8[index+14].y);
				printf("%c",player_2.character);
				push2(index+14);
				strcpy(si8[index+14].status,"Active");
				gotoxy(si8[index].x,si8[index].y);
				printf("%c",player_2.tree);
				Move=1;
			}
		}
		else if(player_2.choice=='@')
		{
			if(player_2.spower_1>0)
			{
				index=peek2();
				for(i=1;(i<=6)&&(!isempty2());i++)
				{
					temp=pop2();
					gotoxy(si8[temp].x,si8[temp].y);
					delay(200);
					if(temp==index)
					;
					else
					{
						printf(" ");
						strcpy(si8[temp].status,"Inactive");
					}
				}
				gotoxy(si8[index].x,si8[index].y);
				printf("%c",player_2.character);
				push2(index);
				player_2.spower_1--;
				Move=1;
			}
		}
		else if(player_2.choice=='#')
		{
			 if(player_2.spower_2>0)
			 {
				player_2.spower_2--;
				Move=1;
			 }
		}
		else if(player_2.choice=='E')
		{
			delay(600);
			clrscr();
			gotoxy(37,12);
			printf("Exiting...");
			sleep(1);
			exit(0);
		}
	}
	_setcursortype(_NOCURSOR);
     }
     while(Move==0);
}
void push1(int item)
{
	if(isfull()==1)
	printf("OVERFLOW");//overflow never reached
	else
	{
		top1++;
		stack[top1]=item;
	}
}
int pop1()
{
	int temp;
	if(isempty1()==1)
	printf("UNDERFLOW");//underflow never reached
	else
	{
		temp=stack[top1];
		top1--;
		return temp;
	}
}
int peek1()
{
	return stack[top1];
}
int isempty1()
{
	if(top1==-1)
	return 1;
	else
	return 0;
}
int size1()
{
	return (top1+1);
}
int isfull()
{
	if(size1()+size2()==406)
	return 1;
	else
	return 0;
}
void push2(int item)
{
	if(isfull()==1)
	printf("OVERFLOW");//overflow never reached
	else
	{
		top2--;
		stack[top2]=item;
	}
}
int pop2()
{
	int temp;
	if(isempty2()==1)
	printf("UNDERFLOW");//underflow never reached
	else
	{
		temp=stack[top2];
		top2++;
		return temp;
	}
}
int peek2()
{
	return stack[top2];
}
int isempty2()
{
	if(top2==406)
	return 1;
	else
	return 0;
}
int size2()
{
	return (406-top2);
}