#include "iGraphics.h"
#include "bitmap_loader.h"
#include"variables.h"
#include"Highscores.h"
#include"animation.h"

void iDraw()
{
	
	iClear();
	if (menu)
	{
		iShowImage(0, 0, 1900, 1000, menupage);
		if (buttonanimation[1])
		iShowImage(80, 700, buttonwidth, buttonheight, button[0]);
		if (!buttonanimation[1])
		iShowImage(80, 700, buttonwidth, buttonheight, button[4]);
		if (buttonanimation[2])
		iShowImage(80, 600, buttonwidth, buttonheight, button[1]);
		if (!buttonanimation[2])
		iShowImage(80, 600, buttonwidth, buttonheight, button[7]);
		if (buttonanimation[3])
		iShowImage(80, 500, buttonwidth, buttonheight, button[2]);
		if (!buttonanimation[3])
		iShowImage(80, 500, buttonwidth, buttonheight, button[5]);
		if (buttonanimation[4])
		iShowImage(80, 400, buttonwidth, buttonheight, button[3]);
		if (!buttonanimation[4])
		iShowImage(80, 400, buttonwidth, buttonheight, button[6]);
		
	}
	if (option)
	iShowImage(0, 0, 1900, 1000, optionpage);
	if (credit)
	iShowImage(0, 0, 1900, 1000, creditpage);
	if (game)
	{
		//Backgrounds
		//iShowImage(backgroundx,backgroundy, 8096, 1000, image[0]);
		//iShowImage(background2x, background2y, 8096, 1000, image[1]);
		iShowImage(backgroundx, backgroundy, 8090, 1000, background[0]);
		iShowImage(background2x, background2y, 8090, 1000, background[1]);
		//Ironman
		iShowImage(ironmanx, ironmany, 250, 250, image[2]);
		if (!play)
		{
			iSetColor(r, g, b);
			iText(850, 30, "Press Space to start", GLUT_BITMAP_TIMES_ROMAN_24);
		}

		//Scoring
		sprintf_s(score, "%d", s);
		//Lives
		sprintf_s(lifes, "%d", life); 
		//Shooting By Ironman
		if (shoot)
		{
			iShowImage(bulletx+20, ironmany + 170, 56, 29, shoots);
			iShowImage(bulletx+20, ironmany + 160, 56, 29, shoots);
		}

		//For Enemeies
		if (play)
		{
			for (int i = 0; i < 3; i++)
			{
				if (plane[i].start)
				{
					//Enemy 
					//ultron
					if (s<6)
					iShowImage(plane[i].enemyx, plane[i].enemyy, 194, 260, doramammu);
					//doramammu
					else if (s >= 6 && s < 12)
					iShowImage(plane[i].enemyx, plane[i].enemyy, 221, 202, ultrons);
					//Thanos
					else if (s >= 12 && s < 18)
					{
						iShowImage(plane[i].enemyx, plane[i].enemyy, 190, 240, Thanos[0]);
					}
					else if (s >= 18 && s<24 )
					{
						iShowImage(plane[i].enemyx, plane[i].enemyy, 190, 240, Thanos[1]);
					}
					else if (s >= 24 && s < 30)
					{
						iShowImage(plane[i].enemyx, plane[i].enemyy, 190, 240, Thanos[2]);
					}
					else if (s >= 30 && s <36)
					{
						iShowImage(plane[i].enemyx, plane[i].enemyy, 190, 240, Thanos[3]);
					}
					else if (s >= 36 )
					{
						iShowImage(plane[i].enemyx, plane[i].enemyy, 190, 240, Thanos[4]);
					}
					
					//Enemy Shooting
					if (plane[i].bombing)
					{
						if (plane[i].enemyy >= -200 && plane[i].enemyy <= 900)
						{
							if (s<6)
							iShowImage(plane[i].bomby + 35, plane[i].enemyy + 150, 95, 75, fire[1]);
							
							else if (s>=6 && s<12)
							iShowImage(plane[i].bomby + 35, plane[i].enemyy + 100, 95, 75, ultronfire);
							
							else  if (s >= 12 && s < 18)
							iShowImage(plane[i].bomby + 35, plane[i].enemyy + 150, 238, 72, Thanosfire[0]);
							
							else  if (s >= 18 && s<24 )
							iShowImage(plane[i].bomby + 35, plane[i].enemyy + 150, 238, 75, Thanosfire[1]);
							
							else  if (s >= 24 && s < 30)
								iShowImage(plane[i].bomby + 35, plane[i].enemyy + 150, 160, 82, Thanosfire[2]);
							
							else  if (s >= 30 && s < 36)
								iShowImage(plane[i].bomby + 35, plane[i].enemyy + 150, 240, 74, Thanosfire[3]);
							
							else  if (s >= 36 )
								iShowImage(plane[i].bomby + 35, plane[i].enemyy + 150, 250, 60, Thanosfire[4]);
							
						}
					}
				}
				if (blast)
				{
					//iShowImage(plane[i].enemyx, plane[i].enemyy, 160, 160, image[9]);
					blast = false;

				}
			}
		}

		//Scoring
		iSetColor(150, 250, 250);
		iText(1800, 950, "Score : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1870, 950, score, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowImage(1750, 940, 40, 50, ironmanhead);
		iShowImage(10, 900, 600, 80, healthbar);
		iSetColor(255, 0, 0);
		iFilledRectangle(183, 931, life, 10);
		//iSetColor(0, 0, 0);
		//iRectangle(1870, 800, 11, 102);
		//iSetColor(255, 0, 0);
		//iText(1780, 880, "Health : ", GLUT_BITMAP_TIMES_ROMAN_24);
		//iFilledRectangle(1870, 800, 10, life);
	}

	//GameoverPage
	if (over)
	{
		iShowImage(0, 0, 1900, 1000, gameover);
		iSetColor(150, 250, 250);
		iText(900, 500, "Score : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(970, 500, score, GLUT_BITMAP_TIMES_ROMAN_24);
		highScores=highscore(s);
		sprintf_s(HIGHSCORE, "%d", highScores);
		iSetColor(240, 25, 25);
		iText(880, 300, "HighScore : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1020, 300, HIGHSCORE, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(r, g, b);
		iText(850, 30, "Press Space To Play Again", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	

}


void iMouseMove(int mx, int my)
{
	
	
}
void iMouse(int button, int state, int mx, int my)
{
	printf("%d \n %d\n",mx,my);
	if (my >= 700 && my <= 732)
	{

		if (mx >= 80 && mx <= 300)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{

				menu = false;
				option = false;
				credit = false;
				game = true;
			}
		}
	}
	if (my >= 600 && my <= 632)
	{
		
		if (mx >= 80 && mx <= 300)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{

				menu = false;
				option = true;
				credit = false;
				game = false;
			}
		}
	}
	if (my >= 500 && my <= 532)
	{
		
		if (mx >= 80 && mx <= 300)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{
				menu = false;
				option = false;
				credit = true;
				game = false;
			}
		}
	}
	if (my >= 400 && my <= 432)
	{

		if (mx >= 80 && mx <= 300)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			exit(0);
		}
	}

}
void iPassiveMouse(int mx, int my)
{
	if (my >= 700 && my <= 732)
	{

		if (mx >= 80 && mx <=300)
		{
			buttonanimation[1] = false;
		}
		else
		buttonanimation[1] = true;
	}
	else
	buttonanimation[1] = true;

	if (my >=600 && my <= 632)
	{

		if (mx >= 80 && mx <=300 )
		{
			buttonanimation[2] = false;
		}
		else
		buttonanimation[2] = true;
	}
	else
	buttonanimation[2] = true;
	
	if (my >= 500 && my <= 532)
	{

		if (mx >= 80 && mx <=300 )
		{
			
			buttonanimation[3] = false;
		}
		else
		buttonanimation[3] = true;
	}
	else
	buttonanimation[3] = true;
	
	if (my >= 400 && my <= 432)
	{

		if (mx >= 80 && mx <= 300)
		{
			
			buttonanimation[4] = false;
			
		}
		else
		buttonanimation[4] = true;
	}
	else
	buttonanimation[4] = true;
}

void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	else if (key == 'w')
	{

		if (ironmany<780)
		ironmany += speed;

	}
	else if (key == 's')
	{
		if (ironmany>0)
		ironmany -= speed;

	}
	if (key == 'e')
	{
		shoot = true;
	}

	if (key == '\b')
	{
		menu = true;
		option = false;
		credit = false;
		game = false;
	}
	if (key == ' ')
	{
		play = true;
		if (over)
		{
			reset();
			game = true;
			play = false;
			over = false;
			
		}
	}
	if (key == 'm')
	{
		PlaySound("music//intro", NULL, SND_LOOP | SND_ASYNC);
	}
	if (key == 'n')
	{
		PlaySound(0, 0, 0);
	}
		
}


void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_HOME)
	{
		menu =false;
		game=true;
	}
	if (key == GLUT_KEY_F1)
	{
		menu =true;
		game = false;

	}
	//place your codes for other keys here
}


int main()
{
	iSetTimer(50, change);
	setplane();
	planes = iSetTimer(80, planechange);
	bullets = iSetTimer(20, bulletchange);
	bombs = iSetTimer(20, bombchange);
	
	iInitialize(1900, 1000, "Demo");
	image[0] = iLoadImage("images\\main3.png");
	image[1] = iLoadImage("images\\main2.png");
	image[2] = iLoadImage("images\\ironmanfly.png");
	image[3] = iLoadImage("images\\star.png");
	shoots = iLoadImage("images\\shoot.png");
	menupage = iLoadImage("images\\menu\\mainmenu.jpg");

	button[0] = iLoadImage("images\\newgame.png");
	button[2] = iLoadImage("images\\credits.png");
	button[3] = iLoadImage("images\\quit.png");
	button[1] = iLoadImage("images\\option.png");

	button[4] = iLoadImage("images\\newgame2.png");
	button[5] = iLoadImage("images\\credits2.png");
	button[6] = iLoadImage("images\\quit2.png");
	button[7] = iLoadImage("images\\option2.png");

	ironmanhead = iLoadImage("images\\ironman\\score.png");

	ultrons = iLoadImage("images\\ironman\\ultron2.png");
	fire[0] = iLoadImage("images\\ironman\\fire.png");
	fire[1] = iLoadImage("images\\ironman\\fire2.png");
	ultronfire = iLoadImage("images\\ironman\\ultronfire.png");
	doramammu = iLoadImage("images\\ironman\\doramammu.png");

	Thanos[0]= iLoadImage("images\\ironman\\Thanos (1).png");
	Thanos[1] = iLoadImage("images\\ironman\\Thanos (2).png");
	Thanos[2] = iLoadImage("images\\ironman\\Thanos (3).png");
	Thanos[3] = iLoadImage("images\\ironman\\Thanos (4).png");
	Thanos[4] = iLoadImage("images\\ironman\\Thanos (5).png");
	

	Thanosfire[0] = iLoadImage("images\\ironman\\thanosfire.png");
	Thanosfire[1] = iLoadImage("images\\ironman\\thanosfire2.png");
	Thanosfire[2] = iLoadImage("images\\ironman\\thanosfire3.png");
	Thanosfire[3] = iLoadImage("images\\ironman\\thanosfire4.png");
	Thanosfire[4] = iLoadImage("images\\ironman\\thanosfire5.png");
	
	creditpage = iLoadImage("images\\ME.png");
	optionpage = iLoadImage("images\\instructions.png");
	gameover = iLoadImage("images\\over.png");

	healthbar = iLoadImage("images\\bar.png");

	background[0] = iLoadImage("images\\BG.png");
	background[1] = iLoadImage("images\\BG2.png");
	
	iStart(); // it will start drawing

	return 0;
}

