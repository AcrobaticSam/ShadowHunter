#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED
//::::::::::::::::::::::::::::::::::::::::::::::All Keyboard Control Functions Are Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//level1------------------------------------------------------------------------------------------------------

void level1left()
{
   if (level1)
		{
			//left move instructions
			if (!rightgo)
				setkey2++;
			if (setkey2 >= 5)
			{
				leftgo = false;
				upgo = true;
				setkey = 200;
			}
			//Boy move left
			if (boyx >= 0)
				boyx -= speed;
			//sliding
			//start
			if (boyx + 30 >= 1240)
			//slides = true;
			//stop
			if (boyx + 30 >= 1290)
			{
				slides = false;
				boyy += 4;
				boyx -= speed;
			}
			//Rendering
			boyindex++;
			if (boyindex == 7)
				boyindex = 0;

			//object move left
			if (catches)
			{
				if (cratex >= 0)
					cratex -= speed;
			}
			//drop from crate::
			if (boyx <= 800)
			{
				//right
				if (!(boyx >= cratex &&boyx <= cratex + 30))
				{
					if (boyy >= cratey + 25)
					{
						drop2 = true;
					}

				}
				//left
				if ((boyx - 10 >= cratex &&boyx <= cratex + 30))
				{
					if (boyy >= cratey + 40)
					{
						drop2 = true;
					}

				}
			}
		}
}
void level1right()
{
   if (level1)
		{
			//right move instructions
			setkey++;
			if (setkey == 10)
			{
				rightgo = false;
				leftgo = true;
			}
			if (boyx + 30 <= 520)
			{
				if (setkey4 == 0)
				{
					catchgo = true;
				}
			}
			if (boyx + 30 >= 980)
			{
				if (boyy + 30 >= 130)
				{
					catches = false;
				}
			}
			//Boy move right
			if (boyx + 30 <= 833)
				boyx += speed;
			if (boyx + 30 >= 833 && boyx + 30 <= 1242 && boyy >= 116)
				boyx += speed;
			//sliding
			if (boyx + 30 >= 1240)
				slides = true;

			if (boyx + 30 >= 1270)
			{
				slides = false;
				boyx += speed;
			}
			if (boyx + 30 >= 1475)
			{
				drop = true;
			}
			if (boyx + 30 >= 1480 && boyy <= 68)
			{
				drop = false;
			}
			//activating level2::
			if (boyx >= 1530)
			{
				level2 = true;
				level1 = false;
				//release
				catches = false;
				//reseting boy
				boyx = 130;
				boyy = 34;
				//resetig portal
				portalx = 10;
				portaly = 30;
			}
			//Rendering
			boyindex++;
			if (boyindex == 7)
				boyindex = 0;

			//object move right
			if (catches)
			{
				if (cratex + 48 <= 833)
					cratex += speed;
			}
			//dropping again
			if (boyx <= 800)
			{
				if (!(boyx >= cratex &&boyx <= cratex + 30))
				{
					if (boyy >= cratey + 25)
					{
						drop2 = true;
					}

				}
			}
		}
}
void level1up()
{
    if (level1)
		{
			//UP instructions
			if (!leftgo)
				setkey3++;
			if (setkey3 >= 2)
			{
				if (!leftgo&&!rightgo)
					setkey2 = -600;
				upgo = false;

			}

			//Jump

			//cratejump
			if (boyy >= cratey + 25)
			{
				if (boyx >= cratex &&boyx <= cratex + 48)
				{
					cratejump = true;
					cratejumpup = true;

				}
				else
				{
					cratejump = false;
					cratejumpup = false;
					jumpy = true;
				}
			}
			//normal jump
			else
			{

				if (!jumpy&&!down)
				{
					jumpy = true;
				}
			}

		}
}
void level1grab()
{
	//for grabing objects
	if (level1)
	{
		if (boyx + 30 >= cratex && boyx + 30 <= cratex + 48)
			catches = true;
		else
			catches = false;
		
		if (catchgo)
		{
			setkey4 = -420;
			catchgo = false;
		}
	}
}


//level2------------------------------------------------------------------------------------------------------

void level2left()
{
	if (level2)
	{
		//Rendering
		boyindex++;
		if (boyindex == 7)
			boyindex = 0;
		//movement
		if (boyx + 30 >= 30 || boyx + 30 >= 270)
			boyx -= speed;
		//slide	down
		if (boyx + 30 >= 186 && boyx + 30 <= 270 && boyy <= 90)
		{
			boyy -= 4;
			boyx -= speed;
		}
		//slide up
		if (boyx + 30 >= 186 && boyx + 30 <= 270 && boyy >= 90)
		{
			boyy += 5;
			boyx -= speed;
		}

		if (boyx + 30 <= 640)
		{
			if (boyy >= 160)
				drop = true;
		}
		if (boyx + 30 <= 1098 && boyx + 30 >= 1090)
		{
			boyy -= 23;
			boyx -= 20;
		}
		if (boyx + 30 >= 1355 && boyx + 30 <= 1415)
		{
			boyy += 3;
		}

	}
}
void level2right()
{
	if (level2)
	{
		//Rendering
		boyindex++;
		if (boyindex == 7)
			boyindex = 0;
		//rightmove
		if (boyx + 30 <= 186 || boyx + 30 >= 270)
		{
			if (!(boyx >= 960 && boyy >= 150))
			{
				if (!frogbite || boyx <= 370)
				{
					boyx += speed;
				}

			}

		}


		//sliding up
		if (boyx + 30 >= 186 && boyx + 30 <= 270 && boyx + 30 <= 490 && boyy <= 90)
		{
			boyy += 2;
			boyx += speed;
		}
		//2,
		if (boyx + 30 >= 1355 && boyx + 30 <= 1415)
		{
			boyy -= 3;
		}
		//sliding down
		if (boyx + 30 >= 186 && boyx + 30 <= 270 && boyx + 30 <= 490 && boyy >= 90)
		{
			boyy -= 3;
			boyx += speed;
		}

		//boyfall trigger
		//1,
		if (boyx + 30 >= 298 && boyx + 30 <= 530 && boyy >= 73)
		{
			drop = true;
		}
		//2,
		if (boyx + 30 >= 530 && boyx + 30 <= 580 && boyy >= 60 && boyy <= 65)
		{
			drop = true;
		}
		//3,
		if (boyx + 30 >= 1000)
		{
			if (boyy >= 160)
				drop = true;
		}
		//activating level3::
		if (boyx >= 1530)
		{
			level3 = true;
			level2 = false;
			//reseting boy
			boyx = 130;
			boyy = 34;
			//resetig portal
			portalx = 10;
			portaly = 55;
		}
		//rockfall trigger
		if (catches)
		{
			if (boyy <= 150)
			{
				rockx += speed;

				if (rockx >= 506)
				{
					catches = false;
					drop2 = true;
				}
			}
			//rock2
			if (boyy >= 150)
			{
				rockx2 += speed;

				if (rockx2 >= 985)
				{
					catches = false;
					drop2 = true;
				}
			}

		}
	}
}
void level2up()	   
{
	if (level2)
	{
		if (!jumpy&&!down && (!(boyx + 30 >= 186 && boyx + 30 <= 270)))
		{
			jumpy = true;
		}
	}
}
void level2grab()	
{
	if (level2)
	{
		//for interact with trigger
		if (boyx >= 78 && boyx <= 109)
		{
			if (boyy >= 130 && rocky >= 100)
			{

				trigger = true;
			}
			else
				trigger = false;
		}
		//trigger
		if (trigger)
		{
			rockfall = true;
		}

		//for interacting with rock

		if (boyx + 30 >= rockx && boyx + 30 <= rockx + 30)
		{
			if (rocky <= 200 && rocky >= 0)
			{
				catches = true;
			}
			else
				catches = false;
		}

		//for interacting with rock2
		if (boyx + 30 >= rockx2 && boyx + 30 <= rockx2 + 30)
		{
			if (rocky2 <= 200 && rocky2 >= 0)
			{
				catches = true;
			}
			else
				catches = false;
		}
	}
}
//level3------------------------------------------------------------------------------------------------------

void level3left()	 
{
	if (level3)
	{
		//Rendering
		boyindex++;
		if (boyindex == 7)
			boyindex = 0;
		//movement
		if (boyx + 55 >= 55 || boyx + 55 >= 270)
			boyx -= speed;
		//tree trigger
		if (boyx + 30 <= 1125)
		{
			monstertreebite = false;
			monstertreestand = true;
		}
		//slide	down
		if (boyx + 55 >= 186 && boyx + 55 <= 270 && boyy <= 90)
		{
			boyy -= 5;
			boyx -= speed;
		}
		//slide up
		if (boyx + 55 >= 186 && boyx + 55 <= 270 && boyy >= 90 || boyx + 30 >= 1345 && boyx + 30 <= 1450)
		{
			boyy += 5;
			boyx -= speed;
		}
	}
}
void level3right()	  
{
	if (level3)
	{
		//Rendering
		boyindex++;
		if (boyindex == 7)
			boyindex = 0;
		//rightmove
		if (boyx + 30 <= 186 || boyx + 30 >= 270)
		{
			if (!(boyx >= 960 && boyy >= 150))
			{
				if (!frogbite || boyx <= 370)
				{
					boyx += speed;
				}

			}

		}
		//Triggerrig Monster tree
		if (boyx + 30 >= 1140 && rocky5>=66 )
		{
			monstertreebite = true;
			monstertreestand = false;
		}
		//killing boy
		if (boyx + 30 >= 1150)
		{
			if (monstertreebite)
			{
				lifcounter--;

				boyx = 130;
				boyy = 31;
				monstertreestand = true;
				monstertreebite = false;
			}

		}
		//sliding up
		if (boyx + 30 >= 186 && boyx + 30 <= 270 && boyx + 30 <= 490 && boyy <= 90)
		{
			boyy += 2;
			boyx += speed;
		}
		//down
		if (boyx + 30 >= 186 && boyx + 30 <= 270 && boyx + 30 <= 490 && boyy >= 90 || boyx + 30 >= 1345 && boyx + 30 <= 1450)
		{
			boyy -= 3;
			boyx += speed;
		}

		

		//boyfall trigger
		//1,
		if (boyx + 30 >= 298 && boyx + 30 <= 530 && boyy >= 73)
		{
			drop = true;
		}
		//activating level3::
		if (boyx >= 1530)
		{
			level4 = true;
			level3 = false;
			//reseting boy
			boyx = 130;
			boyy = 27;
			//resetig portal
			portalx = 10;
			portaly = 30;
		}


	}
}
void level3up()		   
{
	if (level3)
	{
		if (!jumpy&&!down && (!(boyx + 30 >= 186 && boyx + 30 <= 270)))
		{
			jumpy = true;
		}
		
	}
}
void level3grab()		
{
	if (level3)
	{
		//grabbing sword
		if (boyx<swordx + 50 && boyx>swordx-20 && boyy > 60)
		{
			catches = true;
		}
	}
}

//level4------------------------------------------------------------------------------------------------------

void level4left()
{
	if (level4||level5||level7)
	{
		//render
		boyindex3++;
		if (boyindex3 == 29)
			boyindex3 = 0;
		//move
		if (boyx >= 0)
			boyx -= speed;
	}
}
void level4right()	 
{
	if (level4||level5||level7)
	{
		//move
		if (boyx + 30 <= 1580)
			boyx += speed;

		//render
		boyindex++;
		if (boyindex == 24)
			boyindex = 0;

		//activating level4::
		if (level4)
		{

			if (boyx >= 1530)
			{
				level5 = true;
				level4 = false;
				//reseting boy
				boyx = 130;
				boyy = 34;
				//resetig portal
				portalx = 10;
				portaly = 55;
			}
		}
	}

	if (level5)
	{
		if (boyx >= 1530)
		{
			level7 = true;
			level6 = false;
			//reseting boy
			boyx = 50;
			boyy = 97;

		}
			

	}
}
void level4up()		  
{
	if (level4||level5)
	{
		if (!jumpy&&!down)
		{
			jumpy = true;
		}
	}
}
void level4grab()		
{
	if (level4)
	{
		//for interact with trigger
		if (boyx + 55 >= 300 && boyx + 55 <= 350)
		{
			trigger3 = true;
			killenemy = true;
			killbeast = false;
		}
		if (boyx + 55 >= 500 && boyx + 55 <= 550)
		{
			trigger2 = true;
			killenemy = false;
			killbeast = true;
		}
		//Triggering Rock falls
		//rock 1
		if (trigger3)
		{
			if (killbeast)
				rockfall = true;
			if (killenemy)
				rockfall = true;
		}
		//rock2
		if (trigger2)
		{
			if (killbeast)
				rockfall = true;
			if (killenemy)
				rockfall = true;
		}


	}
}


//level5------------------------------------------------------------------------------------------------------
void level5left() {}
void level5right(){}
void level5up()	  {}
void level5grab() {}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void specialkey(unsigned char key)
{
	//Master keys to manually changing levels
	if (key == GLUT_KEY_HOME)
	{
		menu = true;
		instruction = false;
		credits = false;
		level1 = false;
		level2 = false;
		level3 = false;
		level4 = false;
		level5 = false;
		level6 = false;
		level7 = false;
		
		cutscenes[0] = false;
		cutscenes[1] = false;
	}
	//level1:
	if (key == GLUT_KEY_F2)
	{
		level1 = true;
		level2 = false;
		level3 = false;
		level4 = false;
		level5 = false;
		menu = false;

		cutscenes[0] = false;
		cutscenes[1] = false;
		//reseting boy position
		boyx = 323;
		boyy = 31;
	}
	//level2:
	if (key == GLUT_KEY_F3)
	{
		level1 = false;
		level2 = true;
		level3 = false;
		level4 = false;
		level5 = false;
		menu = false;

		cutscenes[0] = false;
		cutscenes[1] = false;

		//reseting boy position
		boyx = 130;
		boyy = 34;
		rocky2 = 165;
	}
	//level3:
	if (key == GLUT_KEY_F4)
	{
		level3 = true;
		level2 = false;
		level1 = false;
		level4 = false;
		level5 = false;
		menu = false;

		cutscenes[0] = false;
		cutscenes[1] = false;

		//reseting boy position
		boyx = 130;
		boyy = 34;
	}
	//level4:
	if (key == GLUT_KEY_F1)
	{
		level3 = false;
		level2 = false;
		level1 = false;
		level4 = false;
		level5 = false;
		menu = true;

		cutscenes[0] = false;
		cutscenes[1] = false;
	}
	//level5:
	if (key == GLUT_KEY_F5)
	{
		level3 = false;
		level2 = false;
		level1 = false;
		level4 = true;
		level5 = false;
		menu = false;

		//reseting boy position
		boyx = 70;
		boyy = 28;
		rocky2 = 268;
		beastx = 925;

		cutscenes[0] = false;
		cutscenes[1] = false;

	}
	//level6:
	if (key == GLUT_KEY_F6)
	{
		level3 = false;
		level2 = false;
		level1 = false;
		level4 = false;
		level5 = true;
		menu = false;

		//reseting boy position
		boyx = 300;
		boyy = 28;
		beastx = 70;

		cutscenes[0] = false;
		cutscenes[1] = false;

	}
	//Exit key
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}
void masterkey(unsigned char key)
{
	
	//left move key
	if (key == 'a'||key=='A')
	{
		
		PlaySound("music//walk", NULL, SND_ASYNC);
		
		//Triggers
		lefty = true;
		righty = false;
		standy = false;
		standyback = false;

		//Mainfunctions
		level1left();
		level2left();
		level3left();
		level4left();

		
		if (!menu)
		{
			menupress[7] = false;
			//menupress[6] = true;
			savepress = true;
		}
	}

	//Right move key
	if (key == 'd'||key =='D')
	{
		PlaySound("music//walk", NULL, SND_ASYNC);
		//Triggers
		lefty = false;
		righty = true;
		standy = false;
		standyback = false;

		//Main Functions
		level1right();
		level2right();
		level3right();
		level4right();

		if (!menu)
		{
			menupress[7] = false;
			//menupress[6] = true;
			savepress = true;
		}
	}

	//Jumpkey
	if (key == 'w'||key =='W')
	{
		//Triggers
		standy = false;
		//Main Functions
		level1up();
		level2up();
		level3up();
		level4up();

		if (!menu)
		{
			menupress[7] = false;
			menupress[6] = true;
			savepress = true;
		}

	}
	if (key == 'c'||key=='C')
	{
		//for grabing objects
		level1grab();
		level2grab();
		level3grab();
		level4grab();
		//counter
		catchinginfo++;


	}
	if (key == 'r' || key == 'R')
	{
		//For releasing
		catches = false;
	}
	if (key == 'e' || key == 'E')
	{
		//For throwing
		if (level3&&catches)
		{
			catches = false;
			swordthrow = true;
			swordx = boyx + 25;
			swordy = boyy + 15;

			PlaySound("music//throw", NULL, SND_ASYNC);
		}						
	}
	if (key == ' ')
	{
	
		if (cutscenes[0])
		{
			level1 = true;
			level2 = false;
			level3 = false;
			level4 = false;

			menu = false;
			loads = false;
			options = false;

			//reseting boy position
			boyx = 200;
			boyy = 31;

			//deactivating cutscenes
			cutscenes[0] = false;
		}

		if(level7)
		{
			level3 = false;
			level2 = false;
			level1 = false;
			level4 = false;
			level5 = false;
			level7 = false;
			menu = false;

			cutscenes[0] = false;
			cutscenes[1] = true;

			intromessageindex = 3;
			boyx = 50;
			boyy = 97;
		}
		if (cutscenes[1])
		{
			menu = true;
			instruction = false;
			credits = false;
			level1 = false;
			level2 = false;
			level3 = false;
			level4 = false;
			level5 = false;
			level6 = false;
			level7 = false;

			cutscenes[0] = false;
			cutscenes[1] = false;
		}
	
	}
	//GAME SAVING WITH KEY keyboard shortcut
	if (key == 's' || key == 'S')
	{
		if (level1)
			saveGame(boyx, boyy, "level1");
		if (level2)
			saveGame(boyx, boyy, "level2");
		if (level3)
			saveGame(boyx, boyy, "level3");
		if (level4)
			saveGame(boyx, boyy, "level4");
		if (level5)
			saveGame(boyx, boyy, "level4");
	}

	
	//Controlling sounds with keyboard shortcut
	if (key == 'm' || key == 'M')
	{
		//sound on
		PlaySound("music//game", NULL, SND_LOOP | SND_ASYNC);
	}
	if (key == 'n' || key == 'N')
	{
		//sound off
		PlaySound(0,0,0);
	}

	//Master key to control player without any limitation
	if (key == 'i')
	{
		//up
		boyy += speed;
	}							
	if (key == 'l')
	{
		//right
		boyx += speed;
	}
	if (key == 'j')
	{
		//down
		boyx -= speed;
	}
	if (key == 'k')
	{
		//left
		boyy -= speed;
	}

	//Exiting Game With keyboard shortcut
	if (key == 'q')
	{
		exit(0);
	}
	//Going back to menu from anywhere
	/*
	if (key = '\b')
	{
		menu = true;
		instruction = false;
		credits = false;
		options = false;
		level1 = false;
		level2 = false;
		level3 = false;
		level4 = false;
		level5 = false;
		level6 = false;
		level7 = false;

		cutscenes[0] = false;
		cutscenes[1] = false;
	}
	 */
	//Alternative testing keys

	if (key == '1')
	{
		level3 = false;
		level2 = false;
		level1 = false;
		level4 = false;
		level5 = false;
		level7=   true;
		menu = false;

		boyx = 50;
		boyy = 97;
	}


	if (key == '2')
	{
		level3 = false;
		level2 = false;
		level1 = false;
		level4 = false;
		level5 = false;
		level7 = false;
		menu = false;

		cutscenes[0] = true;

		boyx = 50;
		boyy = 97;
	}
	if (key == '3')
	{
		level3 = false;
		level2 = false;
		level1 = false;
		level4 = false;
		level5 = false;
		level7 = false;
		menu = false;

		cutscenes[0] = false;
		cutscenes[1] = true;

		intromessageindex = 3;
		boyx = 50;
		boyy = 97;
	}

}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif // KEYBOARD_H_INCLUDED
