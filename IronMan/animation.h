#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

void change()
{
	backgroundx -= speedy;
	if (backgroundx <= -8090)
		backgroundx = 8090;
	background2x -= speedy;
	if ((background2x <= -8090))
		background2x = 8090;

	//for bullet
	bulletx += 100;
	if (bulletx >= 1800)
		bulletx = ironmanx + 200;

}
void restart()
{
	int a = 2000;
	int bo = 10;
	for (int i = 0; i < n; i++)
	{
		plane[i].enemyx = a;
		plane[i].enemyy = bo;
		plane[i].bomby = plane[i].enemyx + 50;
		plane[i].start = true;
		plane[i].bombing = true;

		bo += 250;
		a += rand() % 400;
	}


}
void reset()
{
	play = false;
	shoot = false;
	life = 375;
	s = 0;
	restart();
}
void planechange()
{
	if (play)
	{

		//Enemy's Movement
		for (int i = 0; i < n; i++)
		{
			//change
			plane[i].enemyx -= enemyspeed;
			//Restarting
			if (plane[i].enemyx <= -200)
			{
				plane[i].enemyx = 2000;
			}

		}

		//Bullet ironman Collisons
		for (int i = 0; i < n; i++)
		{
			if (plane[i].start)
			{
					//attacking enemy
					if (ironmany + 190 >= plane[i].enemyy&&ironmany + 190 <= plane[i].enemyy + 250)
					{
						if (bulletx+50 >= plane[i].enemyx+250 && bullety <= plane[i].enemyx)
						{
							plane[i].start = false;
							blast = true;
							s++;
						}
					}
					else if (bulletx + 50 >= plane[i].enemyx + 250 && bullety <= plane[i].enemyx)
					{
						if (ironmany + 190 >= plane[i].enemyy&&ironmany + 190 <= plane[i].enemyy + 250)
						{
							plane[i].start = false;
							blast = true;
							s++;
						}

					}

				//taking Hits from enemy
				//player damage
				if (plane[i].enemyy + 150 > ironmany && plane[i].enemyy + 150 < ironmany + 250)
				{
					if (plane[i].bomby + 130<ironmanx + 250 && plane[i].bomby + 130>ironmanx)
						life-=5;
					if (life == 0)
					{
						game = true;
						over = true;
						play = false;
						//reset();
					}
				}

			}

			//Restarting
			if (!plane[0].start  && !plane[1].start  && !plane[2].start  /*&& !plane[3].start  && !plane[4].start && !plane[5].start && !plane[6].start && !plane[7].start && !plane[8].start && !plane[9].start && !plane[10].start && !plane[11].start && !plane[12].start && !plane[13].start*/)
			{
				restart();

			}

		}
	}
	//RGB Coloring
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;


}

void bulletchange()
{
	if (play)
	{
		if (shoot)
		{
			bullety += speed;
			if (bullety >= screenheight || bullety <= 0)
			{
				bullety = planey + 130;
			}
		}
	}
}

int a = 2000;
int bo = 10;
void setplane()
{
	for (int i = 0; i < n; i++)
	{

		plane[i].enemyx = a;
		plane[i].enemyy = bo ;
		plane[i].bomby = plane[i].enemyx + 50;

		plane[i].start = true;
		plane[i].bombing = true;

		bo += 250;
		a += rand() % 400;

	}


}
void bombchange()
{
	if (play)
	{
		for (int i = 0; i < n; i++)
		{
			if (s >= 0 && s < 6)
			{

				if (plane[i].bomby < -200)
					plane[i].bomby = plane[i].enemyx +50;
			}
			if (s >= 6 && s < 12)
			{

				if (plane[i].bomby < -200)
					plane[i].bomby = plane[i].enemyx - 100;
			}
			if (s >= 12 )
			{

				if (plane[i].bomby < -200)
					plane[i].bomby = plane[i].enemyx - 150;
			}

			plane[i].bomby -= 20;

		}
	}
}


#endif // ANIMATION_H_INCLUDED
