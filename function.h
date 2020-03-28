#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#define BOTTOM 1
#define TOP 2
#define LEFT 3
#define RIGHT 4
#define RIEN 0
/////initialiser mechant 
typedef struct
{
	int h;
	int w;
}TailleImage; 

typedef struct 
{ int x ; //position de l ennemi sur l axe des x ; 
  int y ; // position de l ennemi sur l axe des y ; 
}position ; 
typedef struct
{
	
	SDL_Rect position, imageAAfficher;
	//int vitesse;
	char imageActuelle[6];//image en cours :  tab de 6 images  :en face / derriere/ gauche /droite/ haut/ bas 
	SDL_Surface *imageCourante;
	//int tempsAnimation;
	//int nombreImageAnimation;
	//int animationCourante;// animation en cours 
	//int animation;
	// int estAnime;
	TailleImage tailleSprite ; //ennemi ;
        char vie [5] ; //5 vies 
        
} mechant; 
//////////////////////
int attendreAvantDeQuitter(Uint8 typeEvenement);
SDL_Surface * initEcran(char * titre, char * icone, int largeur, int hauteur);
void backgroundColorSurface(SDL_Surface * surface, Uint8 rouge, Uint8 vert, Uint8 bleu);
void afficheMessage(SDL_Surface * surfaceBlit, char * texte, int tailleText, char * fontFile, SDL_Color textColor, SDL_Rect position);
int verifEtatToucheClavier();
void blitImageSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect *position);
SDL_Rect * decoupeSprite(char * personnage, int nbCaseLigne,int nbCaseCol);
void blitSpriteSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect position, SDL_Rect * clip);
bool checkCollision( SDL_Rect a, SDL_Rect b ) ; 
void Animer_Personnage(int *frametime ,int nmb_frame,int *frame,Player *personnage,Direction *Sens ,Etat *State) ; 
 
