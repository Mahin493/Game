#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED
//Function prototype
int highscore(int score);
void restart();
void reset();
//Structures
struct Plane
{
	int enemyx;
	int enemyy;
	int bomby;
	bool start;
	bool bombing;
};

struct Plane plane[15];
//Images
//backgrounds
int menupage;
int optionpage;
int creditpage;
int gameover;
int background[10];
//Icons
int ironmanhead;
int healthbar;
//Ironman
int ironman[200];
int image[100];
//Enemies
int ultrons;
int doramammu;
int fire[200];
int ultronfire;
int Thanos[50];
int Thanosfire[50];
int shoots;
// Height width declaration
//1.Screen
int screenheight = 1900;
int screenwidth = 1000;
//2.Ironman
int ironmanheight = 250;
int ironmanwidth = 250;
//menubutton
int buttonwidth = 220;
int buttonheight = 32;
// Co ordinates::
//Backgrounds
int backgroundx = 0;
int backgroundy = 0;
int background2x = 8090;
int background2y = 0;
int planey = 0;
//1.Ironman
int ironmanx = 30;
int ironmany = 100;
//2.EnemyPlane
int enemyx = 2000;
int enemyy = 10;
//2.Bullet
int bulletx = ironmanx + 200;
int bullety = planey + 130;
//Changes::
int speed = 10;
int planespeed = 50;
int enemyspeed = 10;
int speedy = 10;
//Modes::
bool shoot = false;
bool start = false;
bool game = false;
bool instruction = false;
bool over = false;
bool blast = false;
bool play = false;
bool about = false;
bool menu = true;
bool left = false;
bool right = false;
bool block = false;
int option = false;
int credit = false;
bool me = false;
//Others::
//Rgb Colors
int r, g, b, r1 = 0, r2 = 0, r3 = 0, g1 = 0, g2 = 0, g3 = 0, b1 = 0, b2 = 0, b3 = 0;
int bx, by;
int n = 3;
int planes, bullets, bombs;
int s = 0;
int highScores = 0;
int life = 375;
char score[100];
char lifes[100];
char HIGHSCORE[1000000];
int red = 0, green = 0, blue = 0;
int button[50];
int buttonsize[50];
int buttonanimation[6] = { true, true, true, true, true };


#endif // VARIABLES_H_INCLUDED
