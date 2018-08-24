#ifndef SAVEGAME_H_INCLUDED
#define SAVEGAME_H_INCLUDED

//::::::::::::::::::::::::::::::Structure:::::::::::::::::::::::::::::::
struct levels
{
	int Boyx;
    int Boyy;
	char Level[100];
};

//::::::::::::::::::::::::::::::File Handling:::::::::::::::::::::::::::

//Receives Boy co -ordinates from game and stores it in a text file
void saveGame(int boyx,int boyy,char *level)
{
    FILE *fp= fopen("save.txt","w");
    fprintf(fp,"%d %d %s",boyx,boyy,level);
    fclose(fp);
}

//Reads Data From The Text File & Feeds Data to the game
void loadGame()
{
		
	FILE *fp = fopen("save.txt", "r");
	fscanf(fp,"%d %d %s", &Boyx, &Boyy, Level);
	
	boyx = Boyx;
	boyy = Boyy;
	
	if (Level[5] == '1')
	{
		level1 = true;
		level2 = false;
		level3 = false;
		level4 = false;
		level5 = false;
		
		menu   = false;
		loads  = false;

	}
	if (Level[5] == '2')
	{
		
		menu   = false;
		loads  = false;

		level1 = false;
		level2 = true;
		level3 = false;
		level4 = false;
		level5 = false;
		
	}
	if (Level[5] == '3')
	{
		
		menu = false;
		loads = false;

		level1 = false;
		level2 = false;
		level3 = true;
		level4 = false;
		level5 = false;
		
	}
	if (Level[5] == '4')
	{
		
		menu   = false;
		loads  = false;

		level1 = false;
		level2 = false;
		level3 = false;
		level4 = true;
		level5 = false;
	
	}
	if (Level[5] == '5')
	{
		
		menu   = false;
		loads  = false;

		level1 = false;
		level2 = false;
		level3 = false;
		level4 = false;
		level5 = true;
		
	}
}

#endif // SAVEGAME_H_INCLUDED
