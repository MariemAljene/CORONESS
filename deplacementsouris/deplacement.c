#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "deplacement.h"
void animated(SDL_Surface *screen ,  SDL_Surface *Background ,SDL_Surface *image2, SDL_Rect *positionFond  , int *running)
{
SDL_Rect rect ;
rect.x=0;
rect.y=535;
rect.h=800 ; 
rect.w=600 ;
int right,left,up;
 SDL_BlitSurface(Background ,positionFond,screen,NULL);
SDL_Flip(screen) ; 
while(*running){
SDL_Event Event;
         SDL_WaitEvent(&Event);
        switch(Event.type)
        {
 /*case SDL_QUIT:
         continuer = 0;
         break;*/

         case SDL_MOUSEBUTTONUP:
             if(Event.button.button==SDL_BUTTON_LEFT)
              {
             rect.x= Event.button.x-513;


             if(rect.x>=640)
{
right=1;
left=0;
 positionFond->x+=640;
rect.x=0;
}
else if ( rect.x<=0 )
{
right=0;
left=1;
 positionFond->x-=640;
rect.x=640-rect.x ; 

}
SDL_BlitSurface(Background,positionFond,screen,NULL); 
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ;
              }

              else if (Event.button.button==SDL_BUTTON_RIGHT)
             {
if(right==1)
{
while((rect.y>400)&&(up==0))
{
rect.x+=40;
rect.y-=30;
 scrollingright(&rect , positionFond );
SDL_BlitSurface(Background,positionFond,screen,NULL);
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ; 
}
if(rect.y<=400)
{
up=1;
rect.x+=40;
SDL_BlitSurface(Background,positionFond,screen,NULL);
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ; 
}
while((rect.y<535)&&(up==1))
{
rect.y+=30;
rect.x+=40;
scrollingright(&rect , positionFond );
SDL_BlitSurface(Background,positionFond,screen,NULL);
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ; 
}
if(rect.y==535)
{
up=0;
}
}
else if(left==1) 
{
while((rect.y>400)&&(up==0))
{
rect.x-=40;
rect.y-=30;
scrollingleft(&rect ,positionFond );
 
SDL_BlitSurface(Background,positionFond,screen,NULL);
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ; 
}
if(rect.y<=400)
{
up=1;
rect.x-=40;
SDL_BlitSurface(Background,positionFond,screen,NULL);
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ; 
}
while((rect.y<535)&&(up==1))
{
rect.y+=30;
rect.x-=40;
scrollingleft(&rect ,positionFond );
 
SDL_BlitSurface(Background,positionFond,screen,NULL);
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ; 
}
if(rect.y==535)
{
up=0;
}
}

}
            break ;
          }
}
}


