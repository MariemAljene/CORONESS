#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
/////initialiser mechant 
typedef struct
{
	int x;
	int y;
}TailleImage; 
typedef struct 
{ int droite ;  // appuie sur 1 ; 
  int gauche ;  // appuie sur 2
  int haut  ; // appuie sur 3
  int bas ; // appuie sur 4 
} Direction ;  
typedef struct 
{ int posx ; //position de l ennemi sur l axe des x ; 
  int posy ; // position de l ennemi sur l axe des y ; 
}position ; 
typedef struct
{
	Direction direction;
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

 
