#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<string>
#include<random>

namespace alldata
{
	char room[10][10];
	int x=0,y=0;
}

using namespace std;
using namespace alldata;

int main();

void instructions()
{
	cout<<"\n\n\ttHIS GamE _s verY Easy 2 plAy .FOLLow ThE rulz ....ortherWISE u die."<<endl<<endl;
	
	cout<<"		->  d\t-\tTO GO RIGHT"<<endl;
	cout<<"		->  a\t-\tTO GO LEFT"<<endl;
	cout<<"		->  w\t-\tTO GO UP"<<endl;
	cout<<"		->  s\t-\tTO GO DOWN\n"<<endl;
	
	cout<<"\tyOUr GOAL Is 2 Get t_e gOLd, anD SoMe_1 is WaiTInG f_r U....\n\n";
	
	cout<<"   pRess ENTER t_o kontinew...........";
	cin.get();
	static short num=0;
	if(num>0)
	{
		cin.get();
	}
	num++;
	main();
}

void how_play()
{
	cout<<"\n\tVampire world is welcoming you. You are going to die."<<endl;
	cout<<"\n\tI am your instructuor, Dr.TGK. In this world your only goal is to survive and grab gold."<<endl;
	cout<<"\n\tIf you wanna be alive follow my instruction andd if you violate you die ..."<<endl;
	cout<<"\n\tThere is a gold in one room its your victory point,"<<endl;
	cout<<"\n\tdont feel happy but there is a vampire waiting for your BLOOD."<<endl;
	cout<<"\n\tIf you open the gold room you won,"<<endl;
	cout<<"\n\tanyways if you enterd in vampires room he taste your blood ubtill the last drop empty."<<endl<<endl;
	cout<<"\n\tCAREFULLY FOLLOW THE INSTRUCTIONS .......BE CAUTIOUS....."<<endl;
	
	instructions();
}

void place()
{
	string d="_|_";string top="__________";
	cout<<endl<<endl<<endl;
	for(short x=0;x<10;x++)
	{
	if(x==0) {cout<<"\t\t\t"<<top<<top<<top<<top<<"_"<<endl;}
	cout<<"\t\t\t|_"<<::room[x][0]<<d<<::room[x][1]<<d<<::room[x][2]<<d<<::room[x][3]<<d<<::room[x][4];
	cout<<d<<::room[x][5]<<d<<::room[x][6]<<d<<::room[x][7]<<d<<::room[x][8]<<d<<::room[x][9]<<"_|\n";
	}
}

void toend()
{
	
	system("cls");
	
	cout<<"\n\n\n\n\t tan(q) WE WIll meet so0n.....\n\tvamPIRe _s wa_tinG foR YOuR bl00d......\n\n\n\n\n\n\n";
	exit(0);
}

void easy_level(bool tf=false)
{
	
	srand(time(0));
	short win1=rand()%5+4;
	srand(time(0));
	short win2=rand()%7+3;
	
	if(tf)
	{
		::room[win1][win2]='G';
	}
	place();
	
	char ch;
	A:
	//::room[win1][win2]='G';
	for(short chance=40;chance>0;chance++)
	{
		g:
		cout<<"\n\n\tG0 to_ : ";
		cin>>ch;
	
	if(ch == 'd')
	{
		//::room[win1][win2]='G';
		system("cls");
		swap(::room[::x][::y],::room[::x][::y++]);
	}
	else if(ch == 'a')
	{
		//::room[win1][win2]='G';//
		system("cls");
		swap(::room[::x][::y],::room[::x][::y--]);
	}
	else if(ch == 'w')
	{
		//::room[win1][win2]='G';//
		system("cls");
		swap(::room[::x][::y],::room[::x--][::y]);
	}
	else if(ch == 's')
	{
		//::room[win1][win2]='G';//
		system("cls");
		swap(::room[::x][::y],::room[::x++][::y]);
	}
	else if(ch == 'e')
	{
		gaap:
		
		char end;
		cout<<"DO u wANt to end tHe game - ";
		cin>>end;
		
		if(end=='s')
		{
			exit (0);
		}
		else if(end=='n')
		{
			toend();
			goto g;
		}
		else
		{
			cout<<"\n\tIn_ValiD inpUT....";
			goto gaap;
		}
	}
	else
	{			
		static short c=1;
		cout<<"\n\n\n\tINVALID INPUT....."<<endl;
		
		if(c<3)
		{
			cout<<"\n\tRemaININg "<<3-c<<" cHancES..."<<endl;
			c++;
		}
		else if(c==3)
		{
			cout<<"\n\tChAnce is empty...beTTer lUcK nxt TiME..."<<endl;
			exit(0);
		}
		goto  A;
	}
		string d="_|_";string top="__________";
		cout<<endl<<endl<<endl;
		for(short x=0;x<10;x++)
		{
			if(x==0) {cout<<"\t\t\t"<<top<<top<<top<<top<<"_"<<endl;}
			cout<<"\t\t\t|_"<<::room[x][0]<<d<<::room[x][1]<<d<<::room[x][2]<<d<<::room[x][3]<<d<<::room[x][4];
			cout<<d<<::room[x][5]<<d<<::room[x][6]<<d<<::room[x][7]<<d<<::room[x][8]<<d<<::room[x][9]<<"_|\n";
		}
		if(::x==win1&&::y==win2)
		{
			system("cls");
			cout<<"\n\n\n\n\n\nYou woN tHe gAme....\n\n\n"<<endl<<endl;
			
			char cs;
			
			abc:
			
			cout<<"\tyou waNT to coNTInuE...(s/n : ";
			cin>>cs;
			
			switch (cs)
			{
				case 's':
					::x=0;
					::y=0;
					main();					
					break;
				case 'n':
					toend();
					exit(0);
				default:
					cout<<"\n\tInvaliD inpUt..";
					goto abc;
			}
		
		}
		else if(::x==0&&::y==3||::x==3&&::y==2||::x==0&&::y==9||::x==1&&::y==6||::x==4&&::y==5||::x==5&&::y==0)
		{
			system("cls");
			cout<<"\n\n\n\n\n\n\tvaMPIre suKing yOUr BLOOD.\n\n\n\n\n\n";
			sleep(1);
			system("cls");
			cout<<"\n\n\n\n\n\n\tvaMPIre suKing yOUr BLOOD..\n\n\n\n\n\n";
			sleep(1);
			system("cls");
			cout<<"\n\n\n\n\n\n\tvaMPIre suKing yOUr BLOOD...\n\n\n\n\n\n";
			sleep(1);
			system("cls");
			cout<<"\n\n\n\n\n\n\tvaMPIre suKing yOUr BLOOD.\n\n\n\n\n\n";
			sleep(1);
			system("cls");
			cout<<"\n\n\n\n\n\n\tvaMPIre suKing yOUr BLOOD..\n\n\n\n\n\n";
			sleep(1);
			system("cls");
			cout<<"\n\n\n\n\n\n\tvaMPIre suKing yOUr BLOOD...\n\n\n\n\n\n";
			sleep(1);
			system("cls");
			cout<<"\n\n\n\n\n\n\tYou loSt, YoU diED.....\n\n\n\n\n\n";
			
			char cs;
			
			cny31:
			cout<<"\tyou waNT to coNTInuE...(s/n : ";
			cin>>cs;
			switch (cs)
			{
				case 's':
					main();
					break;
				case 'n':
					toend();
					exit(0);
				default:
					cout<<"\n\tInvaliD inpUt..";
					goto cny31;
			}
		}
		else if(::x==5&&::y==8||::x==6&&::y==6||::x==7&&::y==3||::x==8&&::y==7||::x==9&&::y==1)
		{
			system("cls");
			cout<<"\n\n\n\n\n\n\tYoU aRE droWninG in A piT.\n\n\n\n\n\n";
			sleep(1);
			system("cls");
			cout<<"\n\n\n\n\n\n\tYoU aRE droWninG in A piT..\n\n\n\n\n\n";
			sleep(1);
			system("cls");
			cout<<"\n\n\n\n\n\n\tYoU aRE droWninG in A piT...\n\n\n\n\n\n";
			sleep(1);
			system("cls");
			cout<<"\n\n\n\n\n\n\tYoU aRE droWninG in A piT.\n\n\n\n\n\n";
			sleep(1);
			system("cls");
			cout<<"\n\n\n\n\n\n\tYoU aRE droWninG in A piT..\n\n\n\n\n\n";
			sleep(1);
			system("cls");
			cout<<"\n\n\n\n\n\n\tYoU aRE droWninG in A piT...\n\n\n\n\n\n";
			sleep(1);
			system("cls");
			cout<<"\n\n\n\n\n\n\tyoU DroWned iN pIt.\n\n\n\n\n\n";
				
			char cs;
			
			gny33:
			cout<<"\tyou waNT to coNTInuE...(s/n : ";
			cin>>cs;
			
			switch (cs)
			{
				case 's':
					main();
					break;
				case 'n':
					toend();
					exit(0);
				default:
					cout<<"\n\tInvaliD inpUt..";
					goto gny33;
			}
			
		}
		else if(::x==0&&::y==2||::x==0&&::y==4||::x==0&&::y==8||::x==0&&::y==6||::x==1&&::y==3||::x==1&&::y==7||::x==1&&::y==5||::x==2&&::y==2||::x==2&&::y==6)
		{
			cout<<"\n\tyOu R iN DanGeR...hE is sMEllInG uR bLOod...";
		}
		else if(::x==3&&::y==1||::x==3&&::y==3||::x==3&&::y==5||::x==4&&::y==0||::x==4&&::y==2||::x==4&&::y==4||::x==4&&::y==6||::x==4&&::y==8||::x==5&&::y==1)
		{
			cout<<"\n\tyOu R iN DanGeR...hE is sMEllInG uR bLOod...";
		}
		else if(::x==5&&::y==5||::x==5&&::y==7||::x==5&&::y==9||::x==6&&::y==0||::x==6&&::y==8)
		{
			cout<<"\n\tyOu R iN DanGeR...hE is sMEllInG uR bLOod...";
		}
		else if(::x==5&&::y==6||::x==6&&::y==3||::x==6&&::y==5||::x==6&&::y==7||::x==7&&::y==2||::x==7&&::y==4||::x==7&&::y==6||::x==7&&::y==7)
		{
			cout<<"\n\tthIS plACE is tOO SlopPY...MOve AWAy..";
		}
		else if(::x==8&&::y==1||::x==8&&::y==6||::x==8&&::y==8||::x==9&&::y==0||::x==9&&::y==2||::x==9&&::y==7)
		{
			cout<<"\n\tthIS plACE is tOO SlopPY...MOve AWAy..";
		}
		else 
		{
			cout<<"\n\tThIs PLacE iS saFE foR a WHilE... ";
		}
}
}

void before_start(bool tf=false)
{
	for(short x=5;x>0;x--)
	{
		system("cls");
		
		COORD point;
		point.X=21;
		point.Y=10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
		
		cout<<"PLEASE WAIT YOUR GAME IS ABOUT TO START IN "<<x<<" SEC";
		
		sleep(1);
		
	}
	system("cls");
	if(tf)
	{
		easy_level(true);
	}
	else
	{
		easy_level();
	}
}

int main()
{
	::x=0;
	::y=0;
	
	static short num=1;
	if(num>0)
	{
		num--;
		instructions();	
	}
	
	system("cls");
	
	int a1,b1;
	cout<<"\n\n";
	string d="\t---------------------------------------------------------------------\n";
	cout<<d<<endl<<"\t\t\tVAMPIRE_W0RLD - DEAD or ALIVE\n"<<endl<<d<<endl;
	
	for(a1=0;a1<10;a1++)
	{
		for(b1=0;b1<10;b1++)
		{
			::room[a1][b1]='_';
		}
	}
	
	::room[::x][::y]='U';
	
	cout<<"\t1.bEFore StaRT\n\t2.Ezy LevEl\n\t3.MeDi_m leVEL\n\t4.En_d\n";
		
	start:
	
	cout<<"\n\n\n\tYouR ch0iCE : ";
	cin>>a1;
	
	switch (a1)
	{
		case 1:
			system("cls");
			how_play();
			break;
		case 2:
			system("cls");
			before_start(true);
			break;
		case 3:
			system("cls");
			before_start();
		case 4:
			system("cls");
			toend();
			break;
		default:
			cout<<"\tinVALID inpuT......";
			goto start;
			break;
	}
	
	return 0;
	
	//end of the program
}
