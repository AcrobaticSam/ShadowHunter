#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

//Reseting function::::
void reset()
{
	if (level2)
	{
		level1 = false;
		level2 = true;
		level3 = false;
		//reseting boy position
		boyx = 130;
		boyy = 34;
		healthbar = 200;
	}
	if (level3)
	{
		level1 = false;
		level2 = false;
		level3 = true;
		//reseting boy position
		boyx = 130;
		boyy = 34;
		healthbar = 200;
	}
}

//Jump render function::
void jumper()
{
	 //------------------------------------------level1---------------------------------------------------------------------------------
	if (level1)
	{
		//Going up
		if (jumpy)
		{
			if (boyx + 30 >= 850 && boyx <= 880 && boyy <= 120)
			{
				jumpy = false;
				down = false;
			}
			else
			boyy += speed;
			if (boyx <= 880)
			{

				//standing over crate
				if (boyx >= cratex && boyx <= cratex + 48)
				{
					if (boyy >= cratey + 25)
					{
						down = false;
						jumpy = false;

					}

				}

				if (boyy >= limit)
				{
					down = true;
					jumpy = false;
				}
			}

			if (boyx >= 880 && boyy>=100)
			{

				if (boyy >= limit + limit)
				{
					down = true;
					jumpy = false;
				}
			}
			//moving horizontallly right
			if (righty)
				boyx++;
			//moving horizontallly left
			if (lefty)
				boyx--;




		}

		//going down
		if (down)
		{
			//moving horizontallly right
			if (righty)
				boyx++;
			//moving horizontallly left
			if (lefty)
				boyx--;
			//moving down
			boyy -= speed;

			if (boyx <= 880)
			{
				if (boyy <= downlimit)
				{
					down = false;
					jumpy = false;
				}
			}
			if (boyx >= 880 && boyx <= 1231)
			{
				if (boyy <= downlimit + 94)
				{
					down = false;
					jumpy = false;
				}
			}
			if (boyx >= 1231 && boyx <= 1456)
			{
				if (boyy <= downlimit + 60)
				{
					down = false;
					jumpy = false;
				}
			}
			if (boyx >= 1456 && boyx <= 1600)
			{
				if (boyy <= downlimit + 30)
				{
					down = false;
					jumpy = false;
				}
			}

		}

		//Jumping from crate
		if (cratejump)
		{
			if (cratejumpup)
			{
				boyx += 2;
				boyy += speed;
				if (boyy >= limit + 50)
				{
					cratejumpdown = true;
					cratejumpup = false;
				}

			}
			if (cratejumpdown)
			{
				boyx += 2;
				boyy -= speed;
				if (boyx >= 820)
				{
					if (boyy <= 132)
					{
						cratejumpdown = false;
						cratejumpup = false;
					}
				}
				else
				{
					if (boyy <= 36)
					{
						cratejumpdown = false;
						cratejumpup = false;
					}
				}

			}

		}
		//sliding down
		if (slides)
		{
			boyy--;
			boyx += 2;
			if (boyx >= 1280)
				slides = false;

		}
		//dropping down
		if (drop)
		{
			if (level1)
			{
				boyy -= 3;
				if (boyy <= 66)
				{
					drop = false;
				}
			}

		}
		//falling down
		if (drop2)
		{
			boyy -= 3;
			if (boyy <= 36)
			{
				drop2 = false;
			}
		}
	}
	//-------------------------------------------------level2---------------------------------------------------------------------------------
	if (level2)
	{
		//going up
		if (jumpy)
		{

			//changing y co ord
			if (boyx >= 780 && boyx <= 800 && rocky2 >= 140)
			{
				boyy += 3;
			}
			if (boyx >= 780 && boyx <= 800 && rocky2 <= 140 && boyy >= 34)
			{
				boyy -= 3;
			}
			else
			{
				boyy += speed;
			}
			//restricion
			if (boyx + 30 <= 186)
			{
				if (boyy >= limit)
				{
					down = true;
					jumpy = false;
				}
			}
			else if (boyx + 30 >= 256 && boyx + 30 <= 298)
			{
				if (boyy >= 98)
				{
					down = false;
					jumpy = false;
				}
			}
			else if (boyx + 30 >= 298 && boyx + 30 <= 313)
			{
				boyx -= 2;
				if (boyy >= 98)
				{
					down = false;
					jumpy = false;
				}
			}
			else if (boyx+30>=313&&boyx+30<=480)
			{
				if (boyy >= limit + 40)
				{
					down = true;
					jumpy = false;
				}
			}
			else if (boyx+30 >= 480 && boyx<=650 )
			{
				if (boyx+30<=680)
				boyx += 5;
				if (boyy >= limit + 40)
				{
					down = true;
					jumpy = false;
				}
			}
			else if (boyx >= 650&&boyx<=780)
			{
				if (boyy >= limit-10)
				{
					down = true;
					jumpy = false;
				}
			}
			if (boyx >= 780 && boyx <= 800)
			{
				if (boyy >= 158)
				{
					down = false;
					jumpy = false;
				}
			}
			if (boyx >= 800)
			{
				if (boyy >= limit - 10)
				{
					down = true;
					jumpy = false;
				}
			}
			if (boyx+30 >= 1060 && boyx+30 <= 1100)
			{
				boyx += 4;
				if (boyy >= limit)
				{
					down = true;
					jumpy = false;
				}
			}


		}
		//going down
		if (down)
		{
			boyy -= speed;
			if (boyx + 30 <= 186)
			{
				if (boyy <= 34)
				{
					down = false;
					jumpy = false;
				}
			}
			else if (boyx+30>=186 && boyx+30<=480)
			{
				if (boyy <= 66)
				{
					down = false;
					jumpy = false;
				}
			}

		 if (boyx + 30 >= 480 )
		{
			 if (level2)
			 {

				 if (boyx <= 630)
					 boyx += 6;
				
				 if (boyy <= 34)
				 {
					 down = false;
					 jumpy = false;
				 }
			 }
		}
		 if (boyx + 30 >= 1060 && boyx + 30 <= 1600)
		 {
			 boyx += 4;

			 if (boyy <= 64)
			 down = false;
			 jumpy = false;

		 }



		}

		if (drop)
		{
			if (level2||level3)
			{
				if (boyx + 30 <= 510)
				{
					boyy -= 4;
					if (boyy <= 64)
					{
						drop = false;
					}
				}

				if (boyx + 30 >= 510 && boyx + 30 <= 600 )
				{
					boyy -= 4;
					if (boyy <= -80)
					{
						drop = false;
						reset();

					}
				}
			}
		}
		if (drop2)
		{
			if (level2 && boyy<=150)
			{
				rocky -= 5;
				if (rocky <= -100)
					drop2 = false;
			}
			if (level2 && boyy >= 150)
			{
				rocky2 -= 5;
				if (rocky2 <= 39)
					drop2 = false;
			}
		}
	}

	//-----------------------------------------------------------------------------------level3------------------------------------------------------------
	if (level3)
	{
		if (jumpy)
		{

			//changing y co ord
			if (boyx >= 780 && boyx <= 800 && rocky2 >= 140)
			{
				boyy += 3;
			}
			if (boyx >= 780 && boyx <= 800 && rocky2 <= 140 && boyy >= 34)
			{
				boyy -= 3;
			}
			else
			{
				boyy += speed;
			}
			//restricion
			if (boyx + 30 <= 186)
			{
				if (boyy >= limit)
				{
					down = true;
					jumpy = false;
				}
			}
			else if (boyx + 30 >= 256 && boyx + 30 <= 298)
			{
				if (boyy >= 98)
				{
					down = false;
					jumpy = false;
				}
			}
			else if (boyx + 30 >= 298 && boyx + 30 <= 313)
			{
				boyx -= 2;
				if (boyy >= 98)
				{
					down = false;
					jumpy = false;
				}
			}
			else if (boyx + 30 >= 313 && boyx + 30 <= 1300)
			{
				if (boyy >= limit + 40)
				{
					down = true;
					jumpy = false;
				}

			}
		}

		if (down)
		{
			boyy -= speed;
			if (boyx + 30 <= 186)
			{
				if (boyy <= 34)
				{
					down = false;
					jumpy = false;
				}
			}
			else if (boyx + 30 >= 186 && boyx + 30 <= 1300)
			{
				if (boyy <= 66)
				{
					down = false;
					jumpy = false;
				}
			}

			if (boyy <= 70)
			{
				if (boyx >= 940 && boyx <= 980)
				{
					off = true;
					on = false;
					angrybirdattack = true;
					rockstay = true;
				}
			}
		}

		if (drop)
		{
			if (boyx + 30 <= 510)
			{
				boyy -= 4;
				if (boyy <= 64)
				{
					drop = false;
				}
			}
		}

	}
	if (level4||level5)
	{
		if (jumpy)
		{
			boyy += speed;

			//restricion
				if (boyy >= limit)
				{
					down = true;
					jumpy = false;
				}

		}
		if (down)
		{
			boyy -= speed;

			if (boyy <= 25)
			{
				down = false;
				jumpy = false;
			}
		}
			
	}
	
	if (level2)
	{
		//fogbite bullet animation
		if (frogbite)
		{
			bit -= bitespeed;
			if (bit <= 260)
				bit = 415;
			if (boyy <= 100)
			{
				if (bit <= boyx + 30 && bit >= boyx)
				{
					//healthbar -= 50;
					lifcounter--;
					reset();
					/*
						if (boyx + 30 >= 400 || boyx + 30 >= 500)
						{
							healthbar = 0;
						}
						if (healthbar == 0)
							reset();
					*/
				}
			}
		}
		//for frog 2:
		if (frogbite2)
		{
			bit2 -= bitespeed;
			if (bit2 <= 815)
				bit2 = frogx2;
			if (boyy <= 100)
			{
				if (bit2 <= boyx + 30 && bit2 >= boyx)
				{
					//healthbar -= 50;
					lifcounter--;
					reset();
					/*
					if (boyx + 30 >= 980||boyx>=1000)
					{
						healthbar =0;
					}
					if (healthbar == 0)
						reset();
					*/
				}
			}
		}
	}

	if (level3)
	{
		//sword animation
		if (swordthrow)
		{
			swordx += 20;
			if (swordx >= EatTreex + 20)
			{
				swordthrow = false;
				treeshow = false;
				treealive = false;
			}
		}
	}

	//bird attack
	if (angrybirdattack)
	{
		angrybirdindex++;
		if (angrybirdindex == 22)
			angrybirdindex = 1;

		angrybirdx += 5;
		if (angrybirdx >= 1700)
		{
			rockstay = true;
			angrybirdattack = false;
		}
		if (angrybirdx >= 950 && rocky5 >= 65)
		{
			rockfall4 = true;
		}

		if (angrybirdx < 1055)
		{
			rockx5 += 5;
		}
	}

	if (rockfall4)
	{
		rocky5 -= 5;
		if (rocky5 <= 65)
		{
			rockfall4 = false;
			monstertreestand = false;
			monstertreebite = false;
		}
	}


}
void standanimation()
{
	//Stand animation
	boyindex2++;
	if (boyindex2 == 2)
		boyindex2 = 0;

	//frog animation
	frogindex++;
	if (frogindex == 5)
		frogindex = 0;
	if (level3)
	{//Tree animation
		if (treeshow)
		{

			EatTreeindex++;
			treewidth += 5;
			EatTreex -= 20;
			treeheight -= 2;
			if (EatTreeindex == 7)
			{
				treewidth = 55;
				EatTreeindex = 0;
				EatTreex = 750;
				treeheight = 80;
			}
			if (boyx >= 620 && treealive)
			{
				//healthbar -= 40;

				lifcounter--;
				treeshow = false;
				treewidth = 55;
				treeheight = 80;
				EatTreex = 750;
				healthbar = 200;
				reset();


			}
				
			if (healthbar == 0)
			{
				treeshow = false;
				treewidth = 55;
				treeheight = 80;
				EatTreex = 750;
				healthbar = 200;
				reset();

			}
		}
		
	}

	if (level4||level5)
	{
		//beast animation
		//stand
		if (beaststandstart)
		{
			beaststanndindex++;
			if (beaststanndindex == 14)
				beaststanndindex = 5;
		}

		//evil man shot
		if (enemy)
		{
			manshot++;
			if (manshot == 5)
				manshot = 0;
		}
	}


	if (congratsanimation)
	{
		congratsindex++;
		if (congratsindex == 2)
			congratsindex = 0;

		cutscenecounter++;
		if (cutscenecounter == 30)
		{
			level7 = false;
			congratsanimation = false;
			cutscenes[0] = false;
			cutscenes[1] = true;

			intromessageindex = 3;
		}
	}

	
}
void portalanimation()
{
	portalindex++;
	if (portalindex == 7)
		portalindex = 0;

	portalindex2++;
	if (portalindex2 == 3)
		portalindex2 = 0;

	//frog bite animation
	biteindex++;
	if (biteindex == 10)
		biteindex = 0;


	

}
void birdanimation()
{
	//Bird animation
	//bird move
	birdsx += 10;
	if (birdsx >= 1600)
		birdsx = -60;
	
	//render
	birdindex++;
	if (birdindex == 3)
		birdindex = 0;

	 //rock falling animation
	if (rockfall)
	{
		if (!level4)
		{
			if (rocky <= 66)
			{
				rockfall = false;
			}
			if (rocky >= 66)
				rocky -= 10;
			if (rocky <= 92)
			{

				frogshow = false;
				frogbite = false;

			}
		}
		if (level4)
		{
			if (killbeast)
			{
				rocky3 -= 10;
				if (rocky3 <= beasty + 140)
					beaststandstart = false;
				if (rocky3 <= 25)
					rockfall = false;
			}
			if (killenemy)
			{
				rocky4 -= 10;
				if (rocky4 <= many + 70)
					enemy = false;
				if (rocky4 <= 25)
					rockfall = false;
			}
		}




	}

	//CannibalTree Related animation::
	if (level3)
	{
		if (monstertreestand)
		{
			monstertreesindex++;
			if (monstertreesindex == 4)
				monstertreesindex = 0;
		}
		if (monstertreebite)
		{
			monstertreebiteindex++;
			if (monstertreebiteindex == 4)
				monstertreebiteindex = 0;

			if (monstertreebiteindex <= 1)
			{
				int monstertreeheight = 66;
				int monstertreewidth = 82;
			}
			if (monstertreebiteindex <= 2)
			{
				int monstertreeheight = 68;
				int monstertreewidth = 50;
			}
			if (monstertreebiteindex <= 3)
			{
				int monstertreeheight = 68;
				int monstertreewidth = 44;
			}
			if (monstertreebiteindex <= 4)
			{
				int monstertreeheight = 68;
				int monstertreewidth = 46;
			}
		}
		
	}

	
}


//Cutscene related animations::
void cutsceneanmation()
{
	if (cutscenes[0])
	{
		intromessageindex++;
		if (intromessageindex == 2)
			intromessageindex = 0;
	}
	if (cutscenes[1])
	{
		intromessageindex++;
		if (intromessageindex == 5)
			intromessageindex = 3;
	}
}

#endif // ANIMATION_H_INCLUDED
