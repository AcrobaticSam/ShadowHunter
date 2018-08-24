#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::ALL Variable Declarations ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//For images:::::::::::
//Background::
int background[500];
int menuimage;
int instructionimage;
int creditiimage;
int congratspic[10];
int cutsceneimage[100];
int intromessages[100];


//Charcacter::
int boy[20];
int Tobistand[500];
int TobiRun[500];
int TobiRunback[500];
int TobiDead[500];
int TobiJump[500];
int TobiJumpback[500];
int lefto[20];
int stand[20];
int standback[20];
int tobypush;
int beaststand[50];
int beastwalk[50];
int beastrun[50];
int beastfire[50];
int evilman[50];
int evilman2[50];
int evilman3[30];
int boylife[5];
int angrybird[500];
int mushroom[50];

//Objects::
int crate;
int portal[500];
int portal2[500];
int portal3[20];
int portal4[50];
int portal5[52];
int bird[200];
int frog[200];
int bite[200];
int rock;
int banner;
int triggers[20];
int chain[50];
int Tree[50];
int sword[50];
int sign[5];
int monstertrees[50];
int monstertreebites[50];


//buttons
int button[500];
bool press = false;
bool menupress[100] = { false, false, false, false ,false,false,false,false,false,false,false,false,false,false};
bool cutscenes[200] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false };
bool savepress = false;



//For co ordination::::::::::::::::::
//for crate
int cratex = 560;
int cratey = 34;
//for boy
int boyx = 200; 
int boyy = 31;
//for portal
int portalx = 1550;
int portaly = 60;
//bird
int birdsx = -30;
int birdsy = 280;
//frog
int frogx = 415;
int frogy = 68;
int frogx2 = 990;
int frogy2 = 38;
//rock
int rockx = 405;
int rocky = 268;
int rockx2 = 680;
int rocky2 = 165;
int rock3 = 405; 
int rocky3 = 268;
int rockx4 = 680; 
int rocky4 = 268;
//tree
int EatTreex = 750; 
int EatTreey = 68;
//sword
int swordx = 35; 
int swordy = 137;
//beast
int beastx = 925; 
int beasty = 0;
//evil man 1
int manx = 780;
int many = 20;
//evil man 2
int man2x = 1245;
int man2y = 20;
//angry bird
int angrybirdx = -200;
//rock5
int rockx5 = angrybirdx + 120;
int rocky5 = 159;


//for saving games
int Boyx;
int Boyy; 
char Level[50];



//For changes::::::::::::::::::::::::::
int bit   = frogx;
int bit2  = frogx2;
int speed = 6;
int limit = boyy + 60;
int bitespeed = 10;
int downlimit = 31;
int x=0,y=0;
int treewidth = 55;
int treeheight= 80;
int healthbar = 200;
int beastwalkspeed = 5;
int beastrunspeed  = 10;
int monstertreeheight = 66;
int monstertreewidth = 82;


//Counters::::::::::::::::::::::::::::
int standcounter = 0;
int portalindex = 0;
int catchinginfo = 0;
int lifcounter = 5;



//For Rendering:::::::::::::::::::::::
int manshot = 0;
int boyindex = 0;
int boyindex2 = 0;
int boyindex3 = 0;
int birdindex = 0;
int frogindex = 0;
int biteindex = 0;
int portalindex2 = 0;
int EatTreeindex = 0;
int jumpindex = 0;
int jumpindex2 = 0;
int beastwalkindex = 0;
int beastrunindex = 0;
int beastfireindex = 0;
int beaststanndindex = 5;
int monstertreesindex = 0;
int monstertreebiteindex = 0;
int welcomeindex = 0;
int congratsindex = 0;
int intromessageindex = 0;
int angrybirdindex = 1;
int cutscenecounter = 0;



//For instructions::::::::
bool upgo    = false;
bool leftgo  = false;
bool rightgo = true;
bool catchgo = false;



//For Game movements ::::::
bool standy     = true;
bool standyback = false;
bool lefty  = false;
bool righty = false;
bool jumpy  = false;
bool down   = false;
bool catches= false;
bool congrats = false;
bool cratejump     = false;
bool cratejumpup   = false;
bool cratejumpdown = false;
bool killenemy = false;
bool killbeast = false;
bool menusound = true;
bool gamesound = false;



//animations:::::::::::::::
bool drop   = false;
bool drop2  = false;
bool slides = false;
bool enemy  = true;
bool trigger  = false;
bool trigger2 = false;
bool trigger3 = false;
bool frogshow = true;
bool frogshow2= true;
bool rockfall = false;
bool frogbite = false;
bool frogbite2= false;
bool treebite = false;
bool treeshow = false;
bool swordthrow = false;
bool treealive  = true;
bool rockfall4 = false;
bool rockstay = false;
bool beastwalkstart = false;
bool beastrunstart  = false;
bool beaststandstart= true;
bool beastfirestart = false;
bool monstertreestand = true;
bool monstertreebite = false;
bool congratsanimation = false;
bool angrybirdattack = false;


//instruction::::::::::::
int setkey = 1, setkey2 = 1, setkey3 = 1,setkey4 = 1;

//Levels::::::::::
bool level1 = false;
bool level2 = false;
bool level3 = false;
bool level4 = false;
bool level5 = false;
bool level6 = false;
bool level7 = false;
bool on     = true;
bool off    = false;
bool menu   = true;
bool loads  = false;
bool credits= false;
bool options= false;
bool instruction = false;

#endif // VARIABLES_H_INCLUDED
