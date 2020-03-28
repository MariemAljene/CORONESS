#include <stdio.h>
#include <stdlib.h>
#include "function.h"

#define LARGEURECRAN 640
#define HAUTEURECRAN 480
#define TITREECRAN "Ma fenetre SDL"
#define ICONE "packground.png"

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    char fichierSprite[] = "personnage.jpg";
    int nbLigne=1;
    int nbColonne=4;
    SDL_Rect position = {0,0};
    SDL_Rect * tabpersonnage = NULL;

    int continuer = 1;
    int i=0;
    SDL_Event event;

    ecran = initEcran(TITREECRAN, ICONE,LARGEURECRAN , HAUTEURECRAN);
    tabpersonnage = decoupeSprite(personnage, nbLigne, nbColonne);
    while(continuer)
    {
        SDL_PollEvent(&event);
        continuer = attendreAvantDeQuitter(event.type);
        backgroundColorSurface(ecran, 0, 0, 0);

        void Animer_Personnage(int *frametime ,int nmb_frame,int *frame,Player *hero,Direction *Sens ,Etat *State);
        SDL_Flip(ecran);
    }
    SDL_Quit();
    return 0;
}
