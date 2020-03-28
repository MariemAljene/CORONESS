#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "functions.h"


SDL_Surface * initEcran(char * titre, char * icone, int largeur, int hauteur)
{
    SDL_Surface *ecran = NULL;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(IMG_Load(background), NULL);
    ecran = SDL_SetVideoMode(largeur, hauteur, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption(titre, NULL);

    return ecran;
}

int attendreAvantDeQuitter(Uint8 typeEvenement)
{
    int continuer = 1 ;
    switch(typeEvenement)
    {
        case SDL_QUIT:
            continuer = 0;break;
        default : break;
    }
    return continuer;
}

void backgroundColorSurface(SDL_Surface * surface, Uint8 rouge, Uint8 vert, Uint8 bleu)
{
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, rouge, vert, bleu));
}

void afficheMessage(SDL_Surface * surfaceBlit, char * texte, int tailleText, char * fontFile, SDL_Color textColor, SDL_Rect position)
{
    SDL_Surface *message = NULL;
    TTF_Font *police=NULL;

    TTF_Init();
    police = TTF_OpenFont(fontFile, tailleText);
    message = TTF_RenderText_Solid(police, texte, textColor);
    SDL_BlitSurface(message, NULL, surfaceBlit, &position);

    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(message);
}

int verifEtatToucheClavier()
{
    Uint8 *keystates = SDL_GetKeyState(NULL);

    if( keystates[SDLK_UP] )
        return SDLK_UP;

    if( keystates[ SDLK_DOWN ] )
        return SDLK_DOWN;

    if( keystates[ SDLK_LEFT ] )
         return SDLK_LEFT;

    if( keystates[ SDLK_RIGHT ] )
        return SDLK_RIGHT;

    return RIEN;
}

void blitImageSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect *position)
{
    SDL_Surface* loadedImage = NULL;
    loadedImage = IMG_Load(fileImage);
    position->h = loadedImage->h;
    position->w = loadedImage->w;
    SDL_BlitSurface(loadedImage, NULL, surfaceBlit, position);
    SDL_FreeSurface(loadedImage);
}

SDL_Rect * decoupeSprite(char * fileSprite, int nbCaseLigne, int nbCaseCol)
{
    SDL_Surface * feuilleDeSprite = NULL;
    SDL_Rect * tabperssonage;
    SDL_Rect coupe;
    int i,j;
    int nbCase=0;

    tabpersonnage= malloc((nbCaseCol*nbCaseLigne)*sizeof(SDL_Rect));
    personnage = IMG_Load(fileSprite);
    coupe.h = feuilleDeSprite->h/nbCaseLigne;
    coupe.w =feuilleDeSprite->w/nbCaseCol;

    for(i=0; i < nbCaseLigne; i++)
    {
        coupe.y = coupe.h*i;
        for(j=0;j<nbCaseCol; j++)
        {
            coupe.x = coupe.w*j;
            tabperssonage[nbCase] = coupe;
            nbCase++;
        }
    }
    SDL_FreeSurface(feuilleDeSprite);
    return tabSprite;
}

void blitSpriteSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect position, SDL_Rect * clip)
{
    SDL_Surface* loadedImage = NULL;
    loadedImage = IMG_Load(fileImage);
    SDL_BlitSurface(loadedImage, clip, surfaceBlit, &position);
    SDL_FreeSurface(loadedImage);
}


bool checkCollision( SDL_Rect a, SDL_Rect b )//adresse ou valeur *? 
{
    //les cotes des rectangles
    int gaucheA, gaucheB;
    int droitA, droitB;
    int hautA, hautB;
    int basA, basB;

    //calculer les cotes  rect A
    gaucheA = a.x;
    droitA = a.x + a.w;
    hautA = a.y;
    basA = a.y + a.h;

    //calculer les cotes  rect B
    gaucheB = b.x;
    droitB = b.x + b.w;
    hautB = b.y; 
    basB = b.y + b.h;

    //si un des cotes de A sont en dehors de B
    if( basA <= hautB )
    {
        return false;
    }

    if( hautA >= basB )
    {
        return false;
    }

    if( droitA <= gaucheB )
    {
        return false;
    }

    if( gaucheA >= droitB )
    {
        return false;
    }

    // si aucun des cotes cotes de A n est en dehors du B
    return true;
}




void Animer_Personnage(int *frametime ,int nmb_frame,int *frame,Player *hero,Direction *Sens ,Etat *State)
{
int FPS=60;					
switch (*State)
{case IDLE: 
*frametime=0;*frame=0;
switch (*Sens)
{	case LEFT:
hero->perso=hero->perso_idle[1];
break;
case RIGHT:
hero->perso=hero->perso_idle[0];
break;	}
break;
case ATTACK:	
(*frametime)++;
switch (*Sens)
 {
case LEFT:
hero->perso=hero>perso_attack_left[*frame];								if(FPS(*frametime)==8)								{(*frametime)=0;								(*frame)++;			
if (*frame==nmb_frame)					{*frame=0;*State=IDLE;}}
	break;
	case RIGHT:	
hero>perso=hero>perso_attack_right[*frame];								if(FPS(*frametime)==8)							{(*frametime)=0;							(*frame)++;							if(*frame==nmb_frame)								{*frame=0;*State=IDLE;}}
break;	}break;
case WALK :  				
 switch (*Sens)
{
case DOWN:	
	break;					
case UP:
break;				
case LEFT:	
(*frametime)++;
hero>perso=hero>perso_mv_left[*frame];					
hero->perso=hero->perso_mv_left[*frame];
if (FPS(*frametime)==8)						{(*frametime)=0;							(*frame)++:						
if (*frame==nmb_frame)					{*frame=0;*State=IDLE;}
};
break;
						
case RIGHT:						
(*frametime)++;
hero->perso=hero->perso_mv_right[*frame];
hero->perso=hero->perso_mv_right[*frame];
if (FPS/(*frametime)==8)
{(*frametime)=0;
(*frame)++;		
if (*frame==nmb_frame)
{*frame=0;*State=IDLE;}}	
break;					
} break;
}
}
