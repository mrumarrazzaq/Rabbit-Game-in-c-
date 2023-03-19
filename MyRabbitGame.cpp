#include<iostream>
#include <iomanip>
#include<conio.h>
#include<fstream>
#include<time.h>
#include<windows.h>
using namespace std;


ifstream fin;


void gotoxy(int x,int y);
char getCharAtxy(short int x,short int y);

void writeInFile(int score,int damage,bool isWin);
void readFromFile();

bool isOneDigit(int n);

void myMainDisplay();
int menu();
void keysinfo();
void sartGame();


void shoot1(int y,int limit);
void shoot2(int y,int limit);
void shoot3(int y,int limit);
void shoot4(int y,int limit);
void shoot5(int y,int limit);

void maze();

void rabbit(int x,int y);
void rabbitRight(int x,int y);
void rabbitLeft(int x,int y);
void hideRabbit(int x,int y);
bool isRabbitFindSomeThing(int x,int y,char ch, bool isRight);
void removeLeftRight(int x,int y);
void removeUpDown(int x,int y);
void life(int x,int y);
void noLife(int x,int y);
void heart(int x,int y);
void heartClear(int x,int y);
void myScore(int &s,int &d);
void carrot(int x,int y);
void hideCarrot(int x,int y);
void home(int x, int y);

void dogLeft(int x,int y);
void dogRight(int x,int y);
void dogClear(int x,int y);

void clearLastRow(int x,int y);

void gameOver(int x, int y);
void gameWin(int x, int y);

int score = 0;
int damage = 0;


void gotoxy(int x,int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x,short int y)
{
	CHAR_INFO ci;
	COORD xy={0,0};
	SMALL_RECT rect={x,y,x,y};
	COORD coordBufSize;
	coordBufSize.X=1;
	coordBufSize.Y=1;
	return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci,coordBufSize,xy, &rect)? ci.Char.AsciiChar : ' ';
}

void writeInFile(int score,int damage,bool isWin)
{
	ofstream fout;
	fout.open("GameData.txt",ios::app); // Append mode
	
	string str = "Win";
	if(isWin)
	{
		str = "Win";
	}else{
		str = "Lose";
	}
	
	if(isOneDigit(score))
	{
		fout<<setfill('0') << std::setw(2)<<score<<",";
	}
	else
	{
		fout<<score<<",";
	}
	
	if(isOneDigit(damage))
	{
		fout<<setfill('0') << std::setw(2)<<damage<<",";
	}
	else
	{
		fout<<score<<",";	
	}
	fout<<str<<endl;
	fout.close();
}

void readFromFile()
{
	char ch;
	fin.open("GameData.txt");
	
	fin.get(ch);
	
	
	cout<<"   ______                        ____                  ____          "<<endl;
	cout<<"  / ____/___ _____ ___  ___     / __ \\___  _______  __/ / /______   "<<endl;
	cout<<" / / __/ __ `/ __ `__ \\/ _ \\   / /_/ / _ \\/ ___/ / / / / __/ ___/ "<<endl;
	cout<<"/ /_/ / /_/ / / / / / /  __/  / _, _/  __(__  ) /_/ / / /_(__  )     "<<endl;
	cout<<"\\____/\\__,_/_/ /_/ /_/\\___/  /_/ |_|\\___/____/\\__,_/_/\\__/____/"<<endl;
	cout<<"__________________________\n";
	cout<<"SCORE  | DAMAGE  | STATUS"<<endl;
	while(!fin.eof())
	{
		if(ch==',')
		{
			cout<<"     |  ";
		}
		else
		{
			cout<<ch;
		}
		fin.get(ch);
	}
	fin.close();
	cout<<"__________________________\n";
}



bool isOneDigit(int n)
{
	if (n == 0)
		return 1;
	int count = 0;
	while (n != 0) {
		n = n / 10;
		++count;
	}
	if(count==1)
	{
		return true;	
	}else{
		return false;
	}
	
}



void myMainDisplay()
{
	
cout<<"     / \\"<<endl;
cout<<"    / _ \\"<<endl;
cout<<"   | / \\ |"<<endl;
cout<<"   ||   || _______"<<endl;
cout<<"   ||   || |\\     \\"<<"\t"<<"   _____ _____.___.   ________    _____      _____  ___________"<<endl;
cout<<"   ||   || ||\\     \\"<<"\t"<<"  /     \\\\__  |   |  /  _____/   /  _  \\    /     \\ \\_   _____/"<<endl;
cout<<"   ||   || || \\    |"<<"\t"<<" /  \\ /  \\/   |   | /   \\  ___  /  /_\\  \\  /  \\ /  \\ |    __)_ "<<endl;
cout<<"   ||   || ||  \\__/"<<"\t"<<"/    Y    \\____   | \\    \\_\\  \\/    |    \\/    Y    \\|        \\"<<endl;
cout<<"   ||   || ||   ||"<<"\t"<<"\\____|__  / ______|  \\______  /\\____|__  /\\____|__  /_______  /"<<endl;
cout<<"    \\\\_/ \\_/ \\_//"<<"\t"<<"        \\/\\/                \\/         \\/         \\/        \\/ "<<endl;
cout<<"   /   _     _   \\"<<endl;
cout<<"  /               \\"<<endl;
cout<<"  |    O     O    |"<<endl;
cout<<"  |   \\  ___  /   |"<<"\t"<<" ______ ____   ____  _____    ______ _____ _____ _    _ _______ "<<endl;
cout<<" /     \\ \\_/ /     \\"<<"\t"<<"|  ____/ __ \\ / __ \\|  __ \\  |  ____|_   _/ ____| |  | |__   __|"<<endl;
cout<<"/  -----  |  -----  \\"<<"\t"<<"| |__ | |  | | |  | | |  | | | |__    | || |  __| |__| |  | |   "<<endl;
cout<<"|     \\__/|\\__/     |"<<"\t"<<"|  __|| |  | | |  | | |  | | |  __|   | || | |_ |  __  |  | |   "<<endl;
cout<<"\\       |_|_|       /"<<"\t"<<"| |   | |__| | |__| | |__| | | |     _| || |__| | |  | |  | |   "<<endl;
cout<<" \\_____       _____/"<<"\t"<<"|_|    \\____/ \\____/|_____/  |_|    |_____\\_____|_|  |_|  |_|   "<<endl;
cout<<"       \\     /"<<endl;
cout<<"       |     |"<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;
}

int menu()
{
    int choice;
    
    cout<<"_________________________"<<endl;
	cout<<" __  __                  "<<endl;
	cout<<"|  \\/  | ___ _ __  _   _ "<<endl;
	cout<<"| |\\/| |/ _ \\ '_ \\| | | |"<<endl;
	cout<<"| |  | |  __/ | | | |_| |"<<endl;
	cout<<"|_|  |_|\\___|_| |_|\\__,_|"<<endl;
   	cout<<"_________________________"<<endl;
    cout<<"1.Start game"<<endl;
    cout<<"2.Keys"<<endl;
    cout<<"3.Get Game Record"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your choice :";
    cin>>choice;
    return choice;
}

void keysinfo()
{
	cout<<"_________________________"<<endl;
	cout<<" _  __             		"<<endl;
	cout<<"| |/ /___ _   _ ___ 		"<<endl;
	cout<<"| ' // _ \\ | | / __|	"<<endl;
	cout<<"| . \\  __/ |_| \\__ \\	"<<endl;
	cout<<"|_|\\_\\___|\\__, |___/	"<<endl;
	cout<<"          |___/    		"<<endl;
	cout<<"_________________________"<<endl;
	
    cout<<"LEFT    ----->      Go Left 		"<<endl;
    cout<<"RIGHT   ----->      Go Right 	"<<endl;
    cout<<"UP      ----->      Go Upward "<<endl;
    cout<<"DOWN    ----->      Go Downward "<<endl;
    cout<<"Esc     ----->      Back to Home "<<endl;
    
}

void shoot1(int y,int limit)
{
	
		static int x=5;
		if(x<limit)
		{
			gotoxy(x,y);cout<<"  ";
			x++;
			gotoxy(x,y);cout<<"->";
			if(getCharAtxy(x+2,y)!=' ')
	    	{
	    		damage++;
				myScore(score,damage);
			}
			
		}
		else
		{
			gotoxy(x,y);cout<<"  ";
			x = 5;
		}
		Sleep(40);
	
}

void shoot2(int y,int limit)
{
	
		static int x = 5;
		if(x<limit)
		{
			
			gotoxy(x,y);cout<<"  ";
			x += 2;
			gotoxy(x,y);cout<<"->";
			
			
			
			if(getCharAtxy(x+2,y)!=' ')
	    	{
	    		damage++;
				myScore(score,damage);
			}
		}
		else
		{
			gotoxy(x,y);cout<<"  ";
			x = 5;
		}
		
	
}

void shoot3(int y,int limit)
{
	
		static int x=5;
		if(x<limit)
		{
			gotoxy(x,y);cout<<"  ";
			x++;
			gotoxy(x,y);cout<<"->";
			if(getCharAtxy(x+2,y)!=' ')
	    	{
	    		damage++;
				myScore(score,damage);
			}
		}
		else
		{
			gotoxy(x,y);cout<<"  ";
			x = 5;
		}
	
}

void shoot4(int x,int limit)
{
	
		static int y=3;
		if(y<limit)
		{
			gotoxy(x,y);cout<<" ";
			y++;
			gotoxy(x,y);cout<<"v";
			if(getCharAtxy(x,y+1)!=' ')
	    	{
	    		damage++;
				myScore(score,damage);
			}
		}
		else
		{
			gotoxy(x,y);cout<<" ";
			y = 3;
		}
		Sleep(50);
}

void shoot5(int x,int limit)
{
	
		static int y=3;
		if(y<limit)
		{
			gotoxy(x,y);cout<<" ";
			y++;
			gotoxy(x,y);cout<<"v";
			if(getCharAtxy(x,y+1)!=' ')
	    	{
	    		damage++;
				myScore(score,damage);
			}
		}
		else
		{
			gotoxy(x,y);cout<<" ";
			y = 3;
		}
}

void dogMovement(int y)
{
	static int x1=5,x2=70;
	
	
	if(x1<x2)
	{
		dogClear(x1,y);
		x1++;
		dogRight(x1,y);
	}else
	{
		dogClear(x1,y);
		dogClear(x2,y);
		x2--;
		dogLeft(x2,y);
		if(x2<6)
		{
			dogClear(x2,y);
			x1=5;
			x2=70;
		}
	}
}

void gameOver(int x, int y)
{
	
	gotoxy(x,y);cout<<"  ________                        ________                     			"<<endl;
	gotoxy(x,y+1);cout<<" /  _____/_____    _____   ____   \\_____  \\___  __ ___________ 		"<<endl;
	gotoxy(x,y+2);cout<<"/   \\  ___\\__  \\  /     \\_/ __ \\   /   |   \\  \\/ // __ \\_  __ \\	"<<endl;
	gotoxy(x,y+3);cout<<"\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  /    |    \\   /\\  ___/|  | \\/	"<<endl;
	gotoxy(x,y+4);cout<<" \\______  (____  /__|_|  /\\___  > \\_______  /\\_/  \\___  >__|   		"<<endl;
	gotoxy(x,y+5);cout<<"        \\/     \\/      \\/     \\/          \\/          \\/       	"<<endl;
 
}

void gameWin(int x, int y)
{
	
	gotoxy(x,y);cout<<"__   __           __        ___  			"<<endl;
	gotoxy(x,y+1);cout<<"\\ \\ / /__  _   _  \\ \\      / (_)_ __  	"<<endl;
	gotoxy(x,y+2);cout<<" \\ V / _ \\| | | |  \\ \\ /\\ / /| | '_ \\"<<endl;
	gotoxy(x,y+3);cout<<"  | | (_) | |_| |   \\ V  V / | | | | |	"<<endl;
	gotoxy(x,y+4);cout<<"  |_|\\___/ \\__,_|    \\_/\\_/  |_|_| |_|	"<<endl;
 
}

void rabbit(int x,int y)
{
	// width of rabbit is 9 and height of rabbit is 4
	gotoxy(x,y);cout<<"    \\\\"<<endl;
    gotoxy(x,y+1);cout<<"     \\\\_"<<endl;
    gotoxy(x,y+2);cout<<"  .---(')"<<endl;
    gotoxy(x,y+3);cout<<"o( )_-\\_"<<endl;
}

void rabbitRight(int x,int y)
{
	// width of rabbit is 9 and height of rabbit is 4
	gotoxy(x,y);cout<<"    \\\\"<<endl;
    gotoxy(x,y+1);cout<<"     \\\\_"<<endl;
    gotoxy(x,y+2);cout<<"  .---(')"<<endl;
    gotoxy(x,y+3);cout<<"o( )_-\\_"<<endl;
}

void rabbitLeft(int x,int y)
{
	// width of rabbit is 9 and height of rabbit is 4
	gotoxy(x,y);  cout<<"   //    "<<endl;
    gotoxy(x,y+1);cout<<" _//     "<<endl;
    gotoxy(x,y+2);cout<<"(')---."<<endl;
    gotoxy(x,y+3);cout<<" _/-_( )o"<<endl;
}

void hideRabbit(int x,int y)
{
	gotoxy(x,y);  cout<<"        "<<endl;
    gotoxy(x,y+1);cout<<"          "<<endl;
    gotoxy(x,y+2);cout<<"         "<<endl;
    gotoxy(x,y+3);cout<<"         "<<endl;
}


bool isRabbitFindSomeThing(int x,int y,char ch, bool isRight)
{
	if(isRight)
	{
		if(getCharAtxy(x+8,y) == ch || getCharAtxy(x+8,y+1) == ch || getCharAtxy(x+8,y+2) == ch || getCharAtxy(x+8,y+3) == ch)
		{
			return true;
		}else
		{
			return false;	
		}
	}
	else if(!isRight)
	{
		if(getCharAtxy(x,y) == ch || getCharAtxy(x,y+1) == ch || getCharAtxy(x,y+2) == ch || getCharAtxy(x,y+3) == ch)
		{
			return true;
		}else
		{
			return false;	
		}
	}
	
}

void removeLeftRight(int x,int y)
{
	gotoxy(x,y);  cout<<"         ";
    gotoxy(x,y+1);cout<<"         ";
    gotoxy(x,y+2);cout<<"         ";
    gotoxy(x,y+3);cout<<"         ";
}

void removeUpDown(int x,int y)
{
	gotoxy(x,y);  cout<<"         ";
	gotoxy(x,y+1);cout<<"         ";
	gotoxy(x,y+2);cout<<"         ";
	gotoxy(x,y+3);cout<<"         ";
}

void life(int x,int y)
{
	gotoxy(x,y);  cout<<"_|        _|      _|_|            "<<endl;
	gotoxy(x,y+1);cout<<"_|              _|        _|_|    "<<endl;
	gotoxy(x,y+2);cout<<"_|        _|  _|_|_|_|  _|_|_|_|  "<<endl;
	gotoxy(x,y+3);cout<<"_|        _|    _|      _|        "<<endl;
	gotoxy(x,y+4);cout<<"_|_|_|_|  _|    _|        _|_|_|  "<<endl;                             
}

void noLife(int x,int y)
{
	gotoxy(x,y);  cout<<"                                  "<<endl;
	gotoxy(x,y+1);cout<<"                                  "<<endl;
	gotoxy(x,y+2);cout<<"                                  "<<endl;
	gotoxy(x,y+3);cout<<"                                  "<<endl;
	gotoxy(x,y+4);cout<<"                                  "<<endl;                             
}

void heart(int x,int y)
{
	
	gotoxy(x,y); cout<<"  ,d88b.d88b,    "<<endl;
	gotoxy(x,y+1);cout<<"  88888888888    "<<endl;
	gotoxy(x,y+2);cout<<"  `Y8888888Y'    "<<endl;
	gotoxy(x,y+3);cout<<"    `Y888Y'      "<<endl;
	gotoxy(x,y+4);cout<<"      `Y'        "<<endl;
}

void heartClear(int x,int y)
{
	
	gotoxy(x,y);  cout<<"                 "<<endl;
	gotoxy(x,y+1);cout<<"                 "<<endl;
	gotoxy(x,y+2);cout<<"                 "<<endl;
	gotoxy(x,y+3);cout<<"                 "<<endl;
	gotoxy(x,y+4);cout<<"                 "<<endl;
}

void myScore(int &s,int &d)
{
	gotoxy(0,0);cout<<"Score : "<<s<<" Damage : "<<d<<endl;
}


void carrot(int x,int y)
{
	gotoxy(x,y);cout<<"_\\/_"<<endl;
	gotoxy(x,y+1);cout<<"\\  /"<<endl;
	gotoxy(x,y+2);cout<<" \\/ "<<endl;
}

void hideCarrot(int x,int y)
{
	gotoxy(x,y);  cout<<"     "<<endl;
	gotoxy(x,y+1);cout<<"     "<<endl;
	gotoxy(x,y+2);cout<<"     "<<endl;
}

void home(int x, int y)
{
	
	gotoxy(x,y+1);cout<<"# SWEET HOME"<<endl; 
	gotoxy(x,y+2);cout<<"# /\\-_--\\ "<<endl; 
	gotoxy(x,y+3);cout<<"#/  \\_-__\\"<<endl; 
	gotoxy(x,y+4);cout<<"#|[]| [] |  "<<endl; 
}

void maze()
{
	
	gotoxy(0,1);cout<<" ____________________________________________________________________________________________________________________ "<<endl;
	gotoxy(0,2);cout<<"|  ________________________________________________________________________________________________________________  |"<<endl;
	gotoxy(0,3);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,4);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,5);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,6);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,7);cout<<"| |]-                                                                                                              | |"<<endl;
	gotoxy(0,8);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,9);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,10);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,11);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,12);cout<<"| |]-                                                                                                              | |"<<endl;
	gotoxy(0,13);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,14);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,15);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,16);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,17);cout<<"| |]-                                                                                                              | |"<<endl;
	gotoxy(0,18);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,19);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,20);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,21);cout<<"| |                                                                                                                | |"<<endl;
	gotoxy(0,22);cout<<"| |________________________________________________________________________________________________________________| |"<<endl;
	gotoxy(0,23);cout<<"|____________________________________________________________________________________________________________________|"<<endl;
}


void dogLeft(int x,int y)
{
	gotoxy(x,y);  cout<<"  __      _"<<endl;
	gotoxy(x,y+1);cout<<"o'')}____//"<<endl;
	gotoxy(x,y+2);cout<<" `_/      )"<<endl;
	gotoxy(x,y+3);cout<<" (_(_/-(_/"<<endl;
}

void dogRight(int x,int y)
{
	gotoxy(x,y);  cout<<" _       __"<<endl;
	gotoxy(x,y+1);cout<<"//______{(''o"<<endl;
	gotoxy(x,y+2);cout<<" (       \\_`"<<endl;
	gotoxy(x,y+3);cout<<" \\_)-\\_)_)"<<endl;
}

void dogClear(int x,int y)
{
	gotoxy(x,y);  cout<<"           "<<endl;
	gotoxy(x,y+1);cout<<"             "<<endl;
	gotoxy(x,y+2);cout<<"            "<<endl;
	gotoxy(x,y+3);cout<<"           "<<endl;
}

void clearLastRow(int x,int y)
{
	gotoxy(x,y);cout<<"                                                                                                                "<<endl;
	gotoxy(x,y+1);cout<<"                                                                                                                "<<endl;
	gotoxy(x,y+2);cout<<"                                                                                                                "<<endl;
	gotoxy(x,y+3);cout<<"                                                                                                                "<<endl;
}


void sartGame()
{
	bool isRight = true;
	bool heart1_fill = true, heart2_fill = true, heart3_fill = true;
	bool isWin = false;
	bool isEscaped = false;
	const int left_limit = 5;
	const int right_limit = 106;
	const int top_limit = 3;
	const int bottom_limit = 18;	
	
	int x=left_limit, y=top_limit;
	
	
	myScore(score,damage);
	maze();
	
	// Row 1 carrots
	carrot(25,4);
	carrot(45,4);
	carrot(65,4);
	carrot(95,4);
	carrot(110,4);
	//	Row 2 carrots
	carrot(15,9);
	carrot(35,9);
	carrot(55,9);
	carrot(75,9);	
	// Row 3 carrots
	carrot(25,14);
	carrot(45,14);
	carrot(65,14);
	carrot(95,14);
	carrot(110,14);
	


	life(0,24);
	heart(35,24);
	heart(50,24);
	heart(65,24);
	home(103,17);
	
	
	while((heart1_fill || heart2_fill || heart3_fill) && !isWin)
	{
		
		if(isRight)
		{
			rabbitRight(x,y);	
		}else{
			rabbitLeft(x,y);
		}
			
		shoot1(7,80);	
		shoot2(12,80);	
		shoot3(17,80);
		
		shoot4(85,20);
		shoot5(104,15);
		
		dogMovement(18);
//		getch();

		if(damage > 10 && heart1_fill)
		{
			heartClear(65,24);
			heart1_fill = false;
		}else if(damage > 20 && heart2_fill)
		{
			heartClear(50,24);
			heart2_fill = false;
		}if(damage >30 && heart3_fill)
		{
			heartClear(35,24);
			heart3_fill = false;
		}
		
		 if (GetAsyncKeyState(VK_UP)) {
		 	if(y>top_limit)
		 	{
		 		removeUpDown(x,y);
        		y -= 1; // move up
			}
    	}else
    	if (GetAsyncKeyState(VK_DOWN)) {
    		if(y<bottom_limit)
    		{
    			removeUpDown(x,y);
        		y += 1; // move down
			}
    	}else
	    if (GetAsyncKeyState(VK_LEFT)) {
	    	if(x>left_limit)
	    	{
	    		isRight = false;
	    		removeLeftRight(x,y);
	        	x -= 1; // move left	
			}
	    	
	    }else
	    if (GetAsyncKeyState(VK_RIGHT)) {
	    	if(x<right_limit)
	    	{
	    		isRight = true;
	    		removeLeftRight(x,y);
	        	gotoxy(40,0);getCharAtxy(x+2,y+1);
	        	x += 1; // move right
			}
	    }
	    
	    if(GetAsyncKeyState(VK_ESCAPE))
	    {
	    	heartClear(65,24);
			heartClear(50,24);
			heartClear(35,24);
	    	heart1_fill = false;
	    	heart2_fill = false;
	    	heart3_fill = false;
	    	isWin = true;
	    	isEscaped = true;
		}
	    
	    if(isRabbitFindSomeThing(x,y,'_',isRight) || isRabbitFindSomeThing(x,y,'/',isRight) || isRabbitFindSomeThing(x,y,'\\',isRight))
	    {
	    	score++;
			myScore(score,damage);
		}
		
		if(isRabbitFindSomeThing(x,y,'o',isRight) || isRabbitFindSomeThing(x,y,'{',isRight)  || isRabbitFindSomeThing(x,y,'`',isRight))
	    {
	    	if(score > 0)
	    	{
	    		score--;
			}
	    	damage++;
			myScore(score,damage);
		}
		
		if(isRabbitFindSomeThing(x,y,'#',isRight))
	    {
	    	isWin = true;
		}
		
		
	    
//	    getch();
		
	}

	hideRabbit(x,y);
	noLife(0,24);
	// Row 1 carrots
	hideCarrot(25,4);
	hideCarrot(45,4);
	hideCarrot(65,4);
	hideCarrot(95,4);
	hideCarrot(110,4);
	//	Row 2 carrots
	hideCarrot(15,9);
	hideCarrot(35,9);
	hideCarrot(55,9);
	hideCarrot(75,9);	
	// Row 3 carrots
	hideCarrot(25,14);
	hideCarrot(45,14);
	hideCarrot(65,14);
	hideCarrot(95,14);
	hideCarrot(110,14);
	clearLastRow(3,18);
	
	
	if(isWin && !isEscaped)
	{
		heartClear(35,24);
		heartClear(50,24);
		heartClear(65,24);
		gameWin(40,10);	
	}else
	{
		gameOver(28,9);
	}
	
	if(!isEscaped)
	{
		writeInFile(score,damage,isWin);
	}
	score=0;
	damage=0;
	
	cout<<"\n\n\n\n\n\n\n\n";
	getch();
	cin.ignore();
}

int main()
{	
	bool flag = true;
	
	while(flag)
    {
		myMainDisplay();
    	int choice=menu();
    	if(choice==1)
        {
            system("cls");
            sartGame();
            cout<<"\n\n";
            cout<<endl<<"Press Any Key to Continue..." << endl<<endl;
            getch();
            cin.ignore();
            system("cls");
        }
		else if (choice==2)
        {
            system("cls");
            keysinfo();
            cout<<endl<<"Press Any Key to Continue..." << endl;
            getch();
            cin.ignore();
        }
        else if(choice==3)
        {
        	system("cls");
        	readFromFile();
        	cout<<endl<<"Press Any Key to Continue..." << endl;
            getch();
            cin.ignore();
            system("cls");
		}
        else if (choice==4)
        {
        	flag = false;
        }
    }
	return 0;
}
