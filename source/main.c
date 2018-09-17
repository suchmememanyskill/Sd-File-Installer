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

	printf("\x1b[3;1H\x1b[32m----------------------.CIA------------------------\x1b[37m");
	printf("\x1b[4;3H[ ] Anemone3ds v2.0.1 by astronautlevel2"); //A
	printf("\x1b[5;3H[ ] Checkpoint v3.4.2 by BernardoGiordano") ; //B
	printf("\x1b[6;3H[ ] Homebrewlauncher v1.0 by mariohackandglitch"); //C
	printf("\x1b[7;3H[ ] DSP1 v1.0 by zoogie"); //D
	printf("\x1b[8;3H[ ] Lumaupdater v2.3 by KunoichiZ"); //E
	printf("\x1b[9;3H[ ] FBI v2.5.3 by Steveice10 (.cia)"); //F

	printf("\x1b[11;1H\x1b[32m----------------------.3DSX-----------------------\x1b[37m");
	printf("\x1b[12;3H[ ] ctrnotimeoffset v1.0 by ihaveamac"); //G
	printf("\x1b[13;3H[ ] FBI v2.5.3 by Steveice10 (.3dsx)"); //H

	printf("\x1b[15;1H\x1b[32m----------------------Luma------------------------\x1b[37m");
	printf("\x1b[16;3H[ ] GodMode9 v1.7.1 by d0k3"); //I
	printf("\x1b[17;3H[ ] Luma3DS v9.1 by AuroraWright"); //J

	printf("\x1b[19;1H\x1b[32m---------------------Extras-----------------------\x1b[37m");
	printf("\x1b[20;3H[ ] CVS v1.0.2 by BernardoGiordano (.cia)"); //K
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
printf("\x1b[1;1H\x1b[32m--------.CIA Files (Install them via fbi)---------\x1b[37m");
mkdir("sdmc:/cias/", 0777);
mkdir("sdmc:/3ds/", 0777);
printf("\x1b[1;1H");

if (A == true){
printf("\n");
Q = "Anemone3ds";
O = "997KB";

copy("romfs:/Anemone3DS.cia", "/cias/Anemone3DS.cia");
}

if (B == true){
printf("\n");

Q = "Checkpoint";
O = "509KB";

copy("romfs:/Checkpoint.cia", "/cias/Checkpoint.cia");
}

if (C == true){
printf("\n");

Q = "Homebrew_launcher";
O = "369KB";

copy("romfs:/Homebrew_Launcher.cia", "/cias/Homebrew_Launcher.cia");
}

if (D == true){
printf("\n");

Q = "DSP1";
O = "235KB";

copy("romfs:/DSP1.cia", "/cias/DSP1.cia");
}

if (E == true){
printf("\n");

Q = "Lumaupdater";
O = "1458KB";

copy("romfs:/lumaupdater.cia", "/cias/lumaupdater.cia");
}

if (F == true){
printf("\n");

Q = "FBI (.cia)";
O = "781KB";

copy("romfs:/FBI.cia", "/cias/FBI.cia");
}

if (K == true){
printf("\n");

Q = "Custom Version Setter";
O = "293KB";

copy("romfs:/CVS.cia", "/cias/CVS.cia");
}

if (L == true){
printf("\n");

Q = "FTPD";
O = "571KB";

copy("romfs:/ftpd.cia", "/cias/ftpd.cia");
}

printf("\n\n\x1b[32m----.3DSX Files (Open them using Hb launcher)-----\x1b[37m");


if (G == true){
printf("\n");

Q = "ctrnotimeoffset";
O = "218KB";

copy("romfs:/ctr-no-timeoffset.3dsx", "/3ds/ctr-no-timeoffset.3dsx");
}

if (H == true){
printf("\n");

Q = "Fbi (.3dsx)";
O = "555KB";

copy("romfs:/FBI.3dsx", "/3ds/FBI.3dsx");
}

printf("\n\n\x1b[32m-------.firm Files (System Critical Files)--------\x1b[37m");

if (I == true){
printf("\n");

Q = "GodMode9";
O = "416KB";

mkdir("sdmc:/luma/payloads/", 0777);

copy("romfs:/GodMode9.firm", "/luma/payloads/GodMode9.firm");

mkdir("sdmc:/gm9/", 0777);
mkdir("sdmc:/gm9/scripts/", 0777);

printf("\n");

Q = "GM9Megascript.gm9";
O = "60KB";

copy("romfs:/GM9Megascript.gm9", "/gm9/scripts/GM9Megascript.gm9");

printf("\n");

Q = "NANDManager.gm9";
O = "7KB";

copy("romfs:/NANDManager.gm9", "/gm9/scripts/NANDManager.gm9");
}

if (J == true){
printf("\n");

Q = "Luma v9.1";
O = "182KB";

copy("romfs:/boot.firm", "/boot.firm");
}



printf("\nDone! Install all the .cia files in FBI\nFBI should be installed in hblauncher now\nWaiting 5 Seconds til exit\n:D");
svcSleepThread(5000000000);

	Exit:
	romfsExit();
	gfxExit();
	return 0;
}
