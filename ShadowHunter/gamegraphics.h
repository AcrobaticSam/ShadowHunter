#ifndef GAMEGRAPHICS_H_INCLUDED
#define GAMEGRAPHICS_H_INCLUDED
#include"savegame.h"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::All Graphics Related Codes Are Here:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void menucode()
{
	//Main Menu Page
	if (menu)
	{

		iShowImage(0, 0, 1600, 320, menuimage);
		
		if (menupress[0])
		iShowImage(25, 270, 105, 38, button[3]);
		if (!menupress[0])
		iShowImage(25, 270, 105, 38, button[2]);
		
		if (!menupress[1])
		iShowImage(25, 210, 170, 38, button[4]);
		if (menupress[1])
		iShowImage(25, 210, 170, 38, button[5]);
		
		if (!menupress[2])
		iShowImage(25, 150, 165, 38, button[8]);
		if (menupress[2])
		iShowImage(25, 150, 165, 38, button[9]);
		
		if (!menupress[3])
		iShowImage(25, 90, 156, 38, button[6]);
		if (menupress[3])
		iShowImage(25, 90, 156, 38, button[7]);

		if (!menupress[4])
		iShowImage(25, 30, 105, 38, button[10]);
		if (menupress[4])
			iShowImage(25, 30, 105, 38, button[11]);
		
	}

	//Instructions Page::
	if (instruction)
	{
		iShowImage(0, 0, 1600, 320, instructionimage);
		//home button
		if (press)
			iShowImage(1550, 270, 48, 48, button[0]);
		if (!press)
			iShowImage(1550, 270, 48, 48, button[1]);
	}
	//Credits Page::
	if (credits)
	{
		iShowImage(0, 0, 1600, 320,creditiimage);
		//home button
		if (press)
			iShowImage(1550, 270, 48, 48, button[0]);
		if (!press)
			iShowImage(1550, 270, 48, 48, button[1]);
	}
	//Options Page::
	if (options)
	{
		iShowImage(0, 0, 1600, 320, background[6]);

		//Load Button::
		if (!menupress[8])
		iShowImage(400, 150, 170, 48, button[15]);
		if (menupress[8])
		iShowImage(400, 150, 170, 48, button[16]);

		//Music Button::
		if (menupress[9])
		iShowImage(700, 150, 170, 48, button[17]);
		if (!menupress[9])
		iShowImage(700, 150, 170, 48, button[18]);
		
		//home button::
		if (press)
			iShowImage(1550, 270, 48, 48, button[0]);
		if (!press)
			iShowImage(1550, 270, 48, 48, button[1]);
		
		//music off:: 
		if (!menupress[10])
			iShowImage(1550, 200, 48, 48, button[19]);
		if (menupress[10])
			iShowImage(1550, 200, 48, 48, button[20]);
		
	}

	if (loads)
	{
		loadGame();
	}
}
//level1------------------------------------------------------------------------------------------------------------------------------------------------------
void level1code()
{

if (level1)
	{
		//Background::
		iShowImage(0, 0, 1600, 320, background[1]);
		
		
		//home button::
		if (press)
		iShowImage(1550, 270, 48, 48, button[0]);
		
		if (!press)
		iShowImage(1550, 270, 48, 48, button[1]);
		
		
		//save button
		if (menupress[7])
			iShowImage(1550, 200, 48, 48, button[14]);
		
		if (menupress[6])
			iShowImage(1550, 200, 48, 48, button[12]);
		
		if (!menupress[6] && !menupress[7] || savepress)
			iShowImage(1550, 200, 48, 48, button[13]);
		

		//Object::
		iShowImage(cratex, cratey, 48, 48, crate);

		//portal::
		iShowImage(portalx, portaly, 50, 100, portal[portalindex]);

		//Life

		if (lifcounter >= 1)
			iShowImage(10, 280, 30, 22, boylife[0]);
		if (lifcounter >= 2)
			iShowImage(30, 280, 30, 22, boylife[1]);
		if (lifcounter >= 3)
			iShowImage(50, 280, 30, 22, boylife[2]);
		if (lifcounter >= 4)
			iShowImage(70, 280, 30, 22, boylife[3]);
		if (lifcounter >= 5)
			iShowImage(90, 280, 30, 22, boylife[4]);

		//birds::
		iShowImage(birdsx, birdsy, 52, 30, bird[birdindex]);
		iShowImage(birdsx - 50, birdsy  -20, 52, 30, bird[birdindex]);
		iShowImage(birdsx + 50, birdsy - 20, 52, 30, bird[birdindex]);

	



		//Character::

		//Idle::
		if (standy)
			iShowImage(boyx, boyy, 30, 51, stand[boyindex2]);
		
		if (standyback)
			iShowImage(boyx, boyy, 30, 51, standback[boyindex2]);
		
		//Walk::
		if (!standy)
		{
			if (righty)
			{
				iShowImage(boyx, boyy, 30, 51, boy[boyindex]);
				standcounter++;
				if (standcounter >= 500)
				{
					standcounter = 0;
					boyindex = 0;
					standy = true;
				}
			}
		}

		if (!standyback)
		{
			if (lefty)
			{
				iShowImage(boyx, boyy, 30, 51, lefto[boyindex]);
				standcounter++;
				if (standcounter >= 500)
				{
					standcounter = 0;
					boyindex = 0;
					standyback = true;
				}
			}
		}

		//Instructions::
		if (rightgo)
		{
			iSetColor(255, 255, 0);
			iText(289, 180, "Hold 'D' To GO Right", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (leftgo)
		{
			iSetColor(255, 0, 0);
			iText(289, 180, "Hold 'A' To GO Left", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (upgo)
		{
			iSetColor(255, 0, 255);
			iText(289, 180, "Press 'W' To Jump", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
		if (catchinginfo == 0 && !leftgo && !rightgo && !upgo)
		{
			iSetColor(0, 255, 255);
			iText(500, 180, "Press 'C' To Interact", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
}


//level2------------------------------------------------------------------------------------------------------------------------------------------------------
void level2code()
{

	if (level2)
	{
		//Background::
		iShowImage(0, 0, 1600, 320, background[2]);
		
		//buttons
		if (press)
			iShowImage(1550, 270, 48, 48, button[0]);
		
		if (!press)
			iShowImage(1550, 270, 48, 48, button[1]);
		
		
		//save button
		if (menupress[7])
			iShowImage(1550, 200, 48, 48, button[14]);

		if (menupress[6])
			iShowImage(1550, 200, 48, 48, button[12]);

		if (!menupress[6] && !menupress[7] || savepress)
			iShowImage(1550, 200, 48, 48, button[13]);
		
		
		/*
		//healthbar::
		iSetColor(200, 200, 200);
		iText(0, 290, "Health:", GLUT_BITMAP_HELVETICA_18);
		iSetColor(0,0, 0);
		iRectangle(60, 290, healthbar, 10);
		iSetColor(255, 0, 0);
		iFilledRectangle(60, 290, healthbar, 10);
		*/
		//Life

		if (lifcounter >= 1)
			iShowImage(10, 280, 30, 22, boylife[0]);
		if (lifcounter >= 2)
			iShowImage(30, 280, 30, 22, boylife[1]);
		if (lifcounter >= 3)
			iShowImage(50, 280, 30, 22, boylife[2]);
		if (lifcounter >= 4)
			iShowImage(70, 280, 30, 22, boylife[3]);
		if (lifcounter >= 5)
			iShowImage(90, 280, 30, 22, boylife[4]);

		//portal::
		iShowImage(portalx, portaly, 50, 100, portal2[portalindex]);
		iShowImage(portalx+1540, portaly-10, 50, 100, portal[portalindex]);
		
		//frog 1::
		
		//idle
		if (frogshow&&rocky>=92)
		iShowImage(frogx, frogy, 30, 22, frog[frogindex]);
		
		//bite
		if (frogbite&&rocky>=92)
		{

			iShowImage(frogx, frogy, 30, 22, bite[biteindex]);
			iSetColor(0, 0, 0);
			iFilledCircle(bit, frogy + 10, 5);
			
		}
		
		
		//frog 2::
		
		//idle
		if (frogshow2 && rocky2 >= 64)
			iShowImage(frogx2, frogy2, 30, 22, frog[frogindex]);
		
		//bite
		if (frogbite2 && rocky2 >= 64)
		{
			iShowImage(frogx2, frogy2, 30, 22, bite[biteindex]);
			iSetColor(0, 0, 0);
			iFilledCircle(bit2, frogy2 + 10, 5);
		}



		//rock1::
		iShowImage(rockx, rocky, 43, 45, rock);
		
		//rock2::
		iShowImage(rockx2, rocky2, 43, 45, rock);
		
		
		
		//trigger::
		if (!trigger)
		{
			iShowImage(40, 136, 50, 50, triggers[0]);
			iShowImage(397, 260, 60, 60, chain[0]);
		}

		if (trigger)
		{

			iShowImage(40, 136, 80, 100, triggers[4]);
			iShowImage(397, 260, 60, 60, chain[1]);
		}

		//biting trigger frog1
		if (boyx >= 310 && rocky>=200)
		{
			frogbite = true;
			frogshow = false;
		}
		else
		{
			frogbite = false;
			frogshow = true;
		}

		//biting trigger frog2
		if (boyx >= 850 && rocky2 >= 80&& boyy<=70)
		{
			frogbite2 = true;
			frogshow2 = false;
		}
		else
		{
			frogbite2 = false;
			frogshow2 = true;
		}

		
		
		//Character::::::::::::::::::::::::::::::::::::::::::
		if (standy)
			iShowImage(boyx, boyy, 30, 51, stand[boyindex2]);

		if (standyback)
			iShowImage(boyx, boyy, 30, 51, standback[boyindex2]);
		
		if (!standy)
		{
			if (righty)
			{
				iShowImage(boyx, boyy, 30, 51, boy[boyindex]);
				standcounter++;
				if (standcounter >= 500)
				{
					standcounter = 0;
					boyindex = 0;
					standy = true;
				}
			}
		}
		
		if (!standyback)
		{
			if (lefty)
			{
				iShowImage(boyx, boyy, 30, 51, lefto[boyindex]);
				standcounter++;
				if (standcounter >= 500)
				{
					standcounter = 0;
					boyindex = 0;
					standyback = true;
				}
			}
		}
	}
}


//level3------------------------------------------------------------------------------------------------------------------------------------------------------
void level3code()
{
	if (level3)
	{
		//Background::
		iShowImage(0, 0, 1600, 320, background[3]);

		//home button
		if (press)
			iShowImage(1550, 270, 48, 48, button[0]);
		if (!press)
			iShowImage(1550, 270, 48, 48, button[1]);

		//save button
		if (menupress[7])
			iShowImage(1550, 200, 48, 48, button[14]);

		if (menupress[6])
			iShowImage(1550, 200, 48, 48, button[12]);

		if (!menupress[6] && !menupress[7] || savepress)
			iShowImage(1550, 200, 48, 48, button[13]);

		//healthbar
		/*
		iSetColor(200, 200, 200);
		iText(0, 290, "Health:", GLUT_BITMAP_HELVETICA_18);
		iSetColor(0, 0, 0);
		iRectangle(60, 290, healthbar, 10);
		iSetColor(255, 0, 0);
		iFilledRectangle(60, 290, healthbar, 10);
		 */

		//health life
		//Life

		if (lifcounter >= 1)
			iShowImage(10, 280, 30, 22, boylife[0]);
		if (lifcounter >= 2)
			iShowImage(30, 280, 30, 22, boylife[1]);
		if (lifcounter >= 3)
			iShowImage(50, 280, 30, 22, boylife[2]);
		if (lifcounter >= 4)
			iShowImage(70, 280, 30, 22, boylife[3]);
		if (lifcounter >= 5)
			iShowImage(90, 280, 30, 22, boylife[4]);
		//portal
		iShowImage(portalx, portaly - 20, 50, 100, portal2[portalindex]);
		iShowImage(portalx + 1540, portaly - 20, 50, 100, portal5[portalindex2]);

		if (angrybirdattack || rockstay)
		{
			iShowImage(rockx5, rocky5, 50, 50, rock);
		}

		if (angrybirdattack)
		{
			iShowImage(angrybirdx, 200, 200, 100, angrybird[angrybirdindex]);

		}
		



		//mushroom trigger
		if (on)
			iShowImage(940, 68, 40, 30, mushroom[0]);
		if (off)
			iShowImage(940, 68, 40, 20, mushroom[1]);

		//Character::
		if (standy)
			iShowImage(boyx, boyy, 30, 51, stand[boyindex2]);
		if (standyback)
			iShowImage(boyx, boyy, 30, 51, standback[boyindex2]);
		if (!standy)
		{
			if (righty)
			{
				iShowImage(boyx, boyy, 30, 51, boy[boyindex]);
				standcounter++;
				if (standcounter >= 500)
				{
					standcounter = 0;
					boyindex = 0;
					standy = true;
				}
			}
		}
		if (!standyback)
		{
			if (lefty)
			{
				iShowImage(boyx, boyy, 30, 51, lefto[boyindex]);
				standcounter++;
				if (standcounter >= 500)
				{
					standcounter = 0;
					boyindex = 0;
					standyback = true;
				}
			}
		}

	
		//Biting tree
		if (boyx >= 600)
			treeshow = true;
		else
			treeshow = false;

		if (treeshow && treealive)
		{
			iShowImage(EatTreex, EatTreey, treewidth, treeheight, Tree[EatTreeindex]);
		}
		else  if (!treeshow&&swordx <= EatTreex&&treealive)
		{
			iShowImage(EatTreex, EatTreey, treewidth, treeheight, Tree[0]);
		}
		//Bitting Tree 2
		if (monstertreestand )
		iShowImage(1170, 70, 46/2, 64/2, monstertrees[monstertreesindex]);
		
		if (monstertreebite )
			iShowImage(1170, 70,monstertreewidth/2, monstertreeheight/2, monstertreebites[monstertreebiteindex]);

		//sword
		if (catches&&treealive)
			iShowImage(boyx + 25, boyy + 15, 65, 17, sword[1]);
		else if (!catches&&!swordthrow && !treeshow&&treealive)
			iShowImage(swordx, swordy, 17, 60, sword[0]);
		if (swordthrow&&treealive)
			iShowImage(swordx, swordy, 65, 17, sword[1]);

	}

}


//level4------------------------------------------------------------------------------------------------------------------------------------------------------
void level4code()
{
	if (level4)
	{
		
		//background::
		iShowImage(0, 0, 1600, 320, background[5]);

		//banner::
		iShowImage(230, 280, 302, 60, chain[1]);
		iShowImage(230, 200, 300, 150, banner);
		
		//button::
		if (press)
			iShowImage(1550, 270, 48, 48, button[0]);
		
		if (!press)
			iShowImage(1550, 270, 48, 48, button[1]);
		
		
		//save button
		if (menupress[7])
			iShowImage(1550, 200, 48, 48, button[14]);

		if (menupress[6])
			iShowImage(1550, 200, 48, 48, button[12]);

		if (!menupress[6] && !menupress[7] || savepress)
			iShowImage(1550, 200, 48, 48, button[13]);

		//portals::
		iShowImage(portalx + 1540, portaly - 30, 50, 100, portal5[portalindex2]);
		iShowImage(0, portaly-30, 50, 100, portal4[portalindex2]);
		
		//beast::
		if (beaststandstart)
			iShowImage(beastx, beasty, 241, 160, beaststand[beaststanndindex]);


		//Enemy::
		if (enemy)
		{
		
			iShowImage(manx, many, 64, 80, evilman3[0]);

			iShowImage(man2x, man2y, 64, 80, evilman3[1]);
		}

		//rocks
		iShowImage(790, rocky4, 43, 45, rock);
		iShowImage(1080, rocky3, 43, 45, rock);
		iShowImage(1010, rocky3, 43, 45, rock);
		iShowImage(1250, rocky4, 43, 45, rock);

		//signs
		iShowImage(225, 27, 62, 64, sign[1]);
		iShowImage(440, 27, 62, 64, sign[0]);
		
		//triggers
		if (!trigger3)
		{

				iShowImage(300, 25, 50, 50, triggers[2]);
				
				iShowImage(784, 260, 60, 60, chain[0]);
				iShowImage(1242, 260, 60, 60, chain[0]);

		}
		if (!trigger2)
		{
			iShowImage(500, 25, 50, 50, triggers[2]);
			iShowImage(1072, 260, 60, 60, chain[0]);
			iShowImage(1002, 260, 60, 60, chain[0]);
		}
		if (trigger3)
		{

			iShowImage(300, 25, 80, 100, triggers[3]);
			iShowImage(784, 260, 60, 60, chain[1]);
			iShowImage(1242, 260, 60, 60, chain[1]);
			
			
		}
		if (trigger2)
		{
			iShowImage(500, 25, 80, 100, triggers[3]);
			iShowImage(1072, 260, 60, 60, chain[1]);
			iShowImage(1002, 260, 60, 60, chain[1]);
		}
		

		//birds
		iShowImage(birdsx, birdsy, 52, 30, bird[birdindex]);
		iShowImage(birdsx - 50, birdsy - 20, 52, 30, bird[birdindex]);
		iShowImage(birdsx + 50, birdsy - 20, 52, 30, bird[birdindex]);



		//Character::
		if (standy&&!jumpy&&!down&&!catches)
			iShowImage(boyx, boyy, 55, 94, Tobistand[0]);

		if (standyback&&!jumpy&&!down&&!catches)
			iShowImage(boyx, boyy, 55, 94, Tobistand[1]);

		if (catches)
		{
			iShowImage(boyx, boyy, 77, 78, tobypush);
		}
		//Jump Animation::
		if (jumpy)
		{
			if (righty)
			{
				iShowImage(boyx, boyy, 55, 94, TobiJump[6]);
			}
			if (lefty)
			{
				iShowImage(boyx, boyy, 55, 94, TobiJumpback[6]);
			}
		}
		//Down Animation::
		if (down)
		{
			if (lefty)
			{
				iShowImage(boyx, boyy, 55, 94, TobiJumpback[14]);
			}
			if (righty)
			{
				iShowImage(boyx, boyy, 55, 94, TobiJump[14]);
			}
		}
		//Run Animations::
		//Right
		if (!standy&&!catches)
		{
			if (righty&&!jumpy&&!down)
			{
				if (!jumpy)
				iShowImage(boyx, boyy, 71, 70, TobiRun[boyindex]);
				standcounter++;
				
				if (standcounter >= 1000)
				{
					standcounter = 0;
					boyindex = 0;
					standy = true;
				}
			}
		}
		//Left
		if (!standyback&&!catches)
		{
			if (lefty&&!jumpy&&!down)
			{
				if (!jumpy)
				iShowImage(boyx, boyy, 71, 70, TobiRunback[boyindex3]);
				standcounter++;
				
				if (standcounter >= 1000)
				{
					standcounter = 0;
					boyindex3 = 0;
					standyback = true;
				}

			}
		}
	}

}


//level5------------------------------------------------------------------------------------------------------------------------------------------------------
void level5code()
{
	if (level5)
	{
	
	//background
	iShowImage(0, 0, 1600, 320, background[4]);
	
	//home button
	if (press)
		iShowImage(1550, 270, 48, 48, button[0]);
	
	if (!press)
		iShowImage(1550, 270, 48, 48, button[1]);

	
	//save button
	if (menupress[7])
		iShowImage(1550, 200, 48, 48, button[14]);

	if (menupress[6])
		iShowImage(1550, 200, 48, 48, button[12]);

	if (!menupress[6] && !menupress[7] || savepress)
		iShowImage(1550, 200, 48, 48, button[13]);
	
	//portal
	iShowImage(portalx + 1540, portaly - 30, 50, 100, portal5[portalindex2]);
	iShowImage(0, portaly - 30, 50, 100, portal4[portalindex2]);
	
	//beast
	if (beaststandstart)
		iShowImage(beastx, beasty, 241, 160, beaststand[beaststanndindex]);


	//birds
	iShowImage(birdsx, birdsy, 52, 30, bird[birdindex]);
	iShowImage(birdsx - 50, birdsy - 20, 52, 30, bird[birdindex]);
	iShowImage(birdsx + 50, birdsy - 20, 52, 30, bird[birdindex]);


	//Character::
	if (standy&&!jumpy&&!down&&!catches)
	iShowImage(boyx, boyy, 55, 94, Tobistand[0]);
	
	if (standyback&&!jumpy&&!down&&!catches)
	iShowImage(boyx, boyy, 55, 94, Tobistand[1]);

	if (catches)
	{
		iShowImage(boyx, boyy, 77, 78, tobypush);
	}
	//Jump Animaton::
	if (jumpy)
	{
		if (righty)
		{
			iShowImage(boyx, boyy, 55, 94, TobiJump[6]);
		}
		
		if (lefty)
		{
			iShowImage(boyx, boyy, 55, 94, TobiJumpback[6]);
		}
	}
	
	//Jumping Down Animation
	if (down)
	{
		if (lefty)
		{
			iShowImage(boyx, boyy, 55, 94, TobiJumpback[14]);
		}

		if (righty)
		{
			iShowImage(boyx, boyy, 55, 94, TobiJump[14]);
		}
	}
	
	//Running Aniamtion::
	//Right
	if (!standy&&!catches)
	{
		if (righty&&!jumpy&&!down)
		{
			if (!jumpy)
			iShowImage(boyx, boyy, 71, 70, TobiRun[boyindex]);
			standcounter++;
			
			if (standcounter >= 2000)
			{
				standcounter = 0;
				boyindex = 0;
				standy = true;
			}
		}
	}
	
	//Left
	if (!standyback&&!catches)
	{
		if (lefty&&!jumpy&&!down)
		{
			if (!jumpy)
			iShowImage(boyx, boyy, 71, 70, TobiRunback[boyindex3]);
			standcounter++;
			if (standcounter >= 2000)
			{
				standcounter = 0;
				boyindex3 = 0;
				standyback = true;
			}

		}
	}
}
}
//level6------------------------------------------------------------------------------------------------------------------------------------------------------

//level7------------------------------------------------------------------------------------------------------------------------------------------------------
void  level7code()
{
	if (level7)
	{
		iShowImage(0, 0, 1600, 320, background[7]);


		if (boyx > 1300)
		{
			standy = false;
			standyback = false;
			jumpy = false;
			down = false;
			catches = false;
			righty = false;
			lefty = false;
			congrats = true;
			congratsanimation = true;
		}

		if (congrats)
		{
			if(congratsanimation)
			iShowImage(500, 80, 600, 200, congratspic[congratsindex]);
		}
		//Character::
		if (standy&&!jumpy&&!down&&!catches)
			iShowImage(boyx, boyy, 55, 94, Tobistand[0]);

		if (standyback&&!jumpy&&!down&&!catches)
			iShowImage(boyx, boyy, 55, 94, Tobistand[1]);

		if (catches)
		{
			iShowImage(boyx, boyy, 77, 78, tobypush);
		}
		//Jump Animaton::
		if (jumpy)
		{
			if (righty)
			{
				iShowImage(boyx, boyy, 55, 94, TobiJump[6]);
			}

			if (lefty)
			{
				iShowImage(boyx, boyy, 55, 94, TobiJumpback[6]);
			}
		}

		//Jumping Down Animation
		if (down)
		{
			if (lefty)
			{
				iShowImage(boyx, boyy, 55, 94, TobiJumpback[14]);
			}

			if (righty)
			{
				iShowImage(boyx, boyy, 55, 94, TobiJump[14]);
			}
		}

		//Running Aniamtion::
		//Right
		if (!standy&&!catches)
		{
			if (righty&&!jumpy&&!down)
			{
				if (!jumpy)
					iShowImage(boyx, boyy, 71, 70, TobiRun[boyindex]);
				standcounter++;

				if (standcounter >= 2000)
				{
					standcounter = 0;
					boyindex = 0;
					standy = true;
				}
			}
		}

		//Left
		if (!standyback&&!catches)
		{
			if (lefty&&!jumpy&&!down)
			{
				if (!jumpy)
					iShowImage(boyx, boyy, 71, 70, TobiRunback[boyindex3]);
				standcounter++;
				if (standcounter >= 2000)
				{
					standcounter = 0;
					boyindex3 = 0;
					standyback = true;
				}

			}
		}
	}
}

void cutscenescodes()
{
	if (cutscenes[0])
	{
		iShowImage(0, 0, 1600, 320, cutsceneimage[0]);

		iShowImage(1370, 10, 600, 50, cutsceneimage[1]);

		iShowImage(300, 150, 1090, 72, intromessages[intromessageindex]);
	}

	if (cutscenes[1])
	{
		iShowImage(0, 0, 1600, 320, cutsceneimage[2]);

		iShowImage(1370, 10, 600, 50, cutsceneimage[1]);

		iShowImage(200, 150, 1030, 65, intromessages[intromessageindex]);
	}
}


#endif // GAMEGRAPHICS_H_INCLUDED
