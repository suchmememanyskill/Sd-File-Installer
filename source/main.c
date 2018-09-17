#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>


int menu = 4, installbyte = 0;
bool A = false, B = false, C = false, D = false, E = false, F = false, G = false, H = false, I = false, J = false, K = false, L = false;
char*(Q);
char*(O);

void copy(const char* src, const char* dst)
{
    FILE* in = fopen(src, "rb");
    FILE* out = fopen(dst, "wb");
    if(in == NULL || out == NULL)
    {
        printf("An error occured");
    }
    else
    {
    	installbyte = 0;
        size_t len = 0;
        char buffer[BUFSIZ];
        while((len = fread(buffer, 1, BUFSIZ, in)) > 0)
        {
            fwrite(buffer, 1, len, out);
            installbyte = installbyte+1;
            printf("Copying %s [%dKB / %s]\r", Q, installbyte, O);
        }
    }
    if(in)
        fclose(in);
    if(out)
        fclose(out);
}

void cleararrow(){
	printf("\x1b[4;1H \n \n \n \n \n \n\n\n \n \n\n\n \n \n\n\n \n \n\n\n \n \n ");
}

void drawX(){
	printf("\x1b[33m");
	if (A == true) printf("\x1b[4;4HX");
	if (A == false) printf("\x1b[4;4H ");
	if (B == true) printf("\x1b[5;4HX");
	if (B == false) printf("\x1b[5;4H ");
	if (C == true) printf("\x1b[6;4HX");
	if (C == false) printf("\x1b[6;4H ");
	if (D == true) printf("\x1b[7;4HX");
	if (D == false) printf("\x1b[7;4H ");
	if (E == true) printf("\x1b[8;4HX");
	if (E == false) printf("\x1b[8;4H ");
	if (F == true) printf("\x1b[9;4HX");
	if (F == false) printf("\x1b[9;4H ");

	if (G == true) printf("\x1b[12;4HX");
	if (G == false) printf("\x1b[12;4H ");
	if (H == true) printf("\x1b[13;4HX");
	if (H == false) printf("\x1b[13;4H ");

	if (I == true) printf("\x1b[16;4HX");
	if (I == false) printf("\x1b[16;4H ");
	if (J == true) printf("\x1b[17;4HX");
	if (J == false) printf("\x1b[17;4H ");

	if (K == true) printf("\x1b[20;4HX");
	if (K == false) printf("\x1b[20;4H ");
	if (L == true) printf("\x1b[21;4HX");
	if (L == false) printf("\x1b[21;4H ");
	printf("\x1b[0m");
}

void check(){
	if (menu == 4 && A == false) {A = true; goto dpress;}
	if (menu == 4 && A == true) A = false;
	if (menu == 5 && B == false) {B = true; goto dpress;}
	if (menu == 5 && B == true) B = false;
	if (menu == 6 && C == false) {C = true; goto dpress;}
	if (menu == 6 && C == true) C = false;
	if (menu == 7 && D == false) {D = true; goto dpress;}
	if (menu == 7 && D == true) D = false;
	if (menu == 8 && E == false) {E = true; goto dpress;}
	if (menu == 8 && E == true) E = false;
	if (menu == 9 && F == false) {F = true; goto dpress;}
	if (menu == 9 && F == true) F = false;

	if (menu == 12 && G == false) {G = true; goto dpress;}
	if (menu == 12 && G == true) G = false;
	if (menu == 13 && H == false) {H = true; goto dpress;}
	if (menu == 13 && H == true) H = false;

	if (menu == 16 && I == false) {I = true; goto dpress;}
	if (menu == 16 && I == true) I = false;
	if (menu == 17 && J == false) {J = true; goto dpress;}
	if (menu == 17 && J == true) J = false;

	if (menu == 20 && K == false) {K = true; goto dpress;}
	if (menu == 20 && K == true) K = false;
	if (menu == 21 && L == false) {L = true; goto dpress;}
	if (menu == 21 && L == true) L = false; //doing this cause my better methods don't work so /shrug
	dpress:
	menu = menu;
}

int main(int argc, char* argv[])
{
	gfxInitDefault();
	PrintConsole topScreen, bottomScreen;
	consoleInit(GFX_BOTTOM, &bottomScreen);
	consoleInit(GFX_TOP, &topScreen);
	romfsInit();
	printf("   SD Files Installer, By Such Meme, Many Skill");
	printf("\x1b[30;1HPress A to apply, Dpad to move the cursor");

	printf("\x1b[3;1H\x1b[32m------------------Emulators&Games------------------\x1b[37m");
	printf("\x1b[4;3H[ ] Snes9X"); //A
	printf("\x1b[5;3H[ ] GameYob") ; //B
	printf("\x1b[6;3H[ ] mGBA"); //C
	printf("\x1b[7;3H[ ] VirtualNES"); //D
	printf("\x1b[8;3H[ ] Cookie Clicker v1.0 by TheMachinumps"); //E
	printf("\x1b[9;3H[ ] 2048-3ds v0.3.2 by MrJPGames"); //F

	printf("\x1b[11;1H\x1b[32m------------------Save Manageing------------------\x1b[37m");
	printf("\x1b[12;3H[ ] JKSM by J_D_K"); //G
	printf("\x1b[13;3H[ ] PKSM v5.1.4 by BernardoGiordano"); //H

	printf("\x1b[15;1H\x1b[32m-----------------Theme Manageing------------------\x1b[37m");
	printf("\x1b[16;3H[ ] Anemone3ds by astronautlevel2"); //I
	printf("\x1b[17;3H[ ] GYTB by MrCheeze"); //J

	printf("\x1b[19;1H\x1b[32m---------------------Extras-----------------------\x1b[37m");
	printf("\x1b[20;3H[ ] PlayCoin setter by MrCheeze"); //K
	printf("\x1b[21;3H[ ] FTPD v2.2 by mtheall (.cia)"); //L




	printf("\x1b[24;3H\x1b[30;47mInstall Selected ");
	printf("\x1b[25;3HSelect All");
	printf("\x1b[26;3HExit\x1b[0m");

	if ( access("/luma/config.bin", F_OK ) == -1) printf("\x1b[28;1H\x1b[31mLuma config missing, are you sure you have cfw?\x1b[0m");

	while (aptMainLoop())
	{	
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_DUP) menu = menu-1, cleararrow();
		if (kDown & KEY_DDOWN) menu = menu+1, cleararrow();
		if (menu == 3) menu = 26;
		if (menu == 10) menu = 12;
		if (menu == 11) menu = 9;
		if (menu == 14) menu = 16;
		if (menu == 15) menu = 13;
		if (menu == 18) menu = 20;
		if (menu == 19) menu = 17;
		if (menu == 22) menu = 24;
		if (menu == 23) menu = 21;
		if (menu == 27) menu = 4;

		printf("\x1b[36m\x1b[%d;1H>\x1b[0m", menu);

		if (menu == 26 && kDown & KEY_A) goto Exit;
		if (menu == 25 && kDown & KEY_A) A = true, B = true, C = true, D = true, E = true, F = true, G = true, H = true, I = true, J = true, K = true, L = true, drawX();
		if (menu == 24 && kDown & KEY_A) break;


		if (kDown & KEY_A) check(), drawX();

//mkdir("sdmc:/seedstarter/", 0777);

		gfxFlushBuffers();
		gspWaitForVBlank();
		gfxSwapBuffers();
	}

consoleInit(GFX_TOP, &topScreen);
printf("\x1b[30;1HThis might take a while, sit back and relax");
printf("\x1b[1;1H\x1b[32m--------------------------------------------------\x1b[37m");
mkdir("sdmc:/3ds/", 0777);
printf("\x1b[1;1H");

if (A == true){
printf("\n");
Q = "Snes9X";
O = "2052KB";

copy("romfs:/snes9x_3ds.3dsx", "/3ds/snes9x_3ds.3dsx");
}

if (B == true){
printf("\n");

Q = "GameYob";
O = "1001KB";

copy("romfs:/GameYob.3dsx", "/3ds/GameYob.3dsx");
}

if (C == true){
printf("\n");

Q = "mGBA";
O = "1385KB";

copy("romfs:/mgba.3dsx", "/3ds/mgba.3dsx");
}

if (D == true){
printf("\n");

Q = "VirtualNES";
O = "1090KB";

copy("romfs:/virtuanes_3ds.3dsx", "/3ds/virtuanes_3ds.3dsx");
}

if (E == true){
printf("\n");

Q = "Cookie Clicker 3DS";
O = "202KB";

copy("romfs:/CookieClicker3DS.3dsx", "/3ds/CookieClicker3DS.3dsx");
}

if (F == true){
printf("\n");

Q = "2048";
O = "436KB";

copy("romfs:/2048-3D.3dsx", "/3ds/2048-3D.3dsx");
}

if (G == true){
printf("\n");

Q = "JKSM";
O = "1453KB";

copy("romfs:/JKSM.3dsx", "/3ds/JKSM.3dsx");
}

if (H == true){
printf("\n");

Q = "PKSM";
O = "2853KB";

copy("romfs:/PKSM.3dsx", "/3ds/PKSM.3dsx");
}

if (I == true){
printf("\n");

Q = "Anemone3ds";
O = "650KB";

copy("romfs:/Anemone3DS.3dsx", "/3ds/Anemone3DS.3dsx");
}

if (J == true){
printf("\n");
mkdir("sdmc:/3ds/GYTB/", 0777);

Q = "GYTB";
O = "310KB";

copy("romfs:/GYTB.3dsx", "/3ds/GYTB/GYTB.3dsx");

printf("\n");

Q = "GYTB.xml";
O = "1KB";

copy("romfs:/GYTB.xml", "/3ds/GYTB/GYTB.xml");

mkdir("sdmc:/3ds/GYTB/badges/", 0777);
printf("\n");

Q = "Badge1";
O = "6KB";

copy("romfs:/Lenny.00021700.png", "/3ds/GYTB/badges/Lenny.00021700.png");

printf("\n");

Q = "Badge2";
O = "14KB";

copy("romfs:/ElfsWorld.png", "/3ds/GYTB/badges/ElfsWorld.png");
}

if (K == true){
printf("\n");

Q = "PlayCoin Setter";
O = "228KB";

copy("romfs:/playcoin.3dsx", "/3ds/playcoin.3dsx");
}

if (L == true){
printf("\n");

Q = "FTPD";
O = "261KB";

copy("romfs:/ftpd.3dsx", "/3ds/ftpd.3dsx");
}



printf("\nDone! Waiting 5 Seconds til exit\n:D");
svcSleepThread(5000000000);

	Exit:
	romfsExit();
	gfxExit();
	return 0;
}
