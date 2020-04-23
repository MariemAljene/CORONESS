prog:main.o AffichageObj.o InitObjet.o collisionbb.o
	gcc main.o AffichageObj.o InitObjet.o collisionbb.o -o prog -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g

AffichageObj.o:AffichageObj.c
	gcc -c AffichageObj.c -lSDL -lSDL_image -g
InitObjet.o:InitObjet.c 
	gcc -c InitObjet.c -lSDL -lSDL_image -g  
collisionbb.o:collisionbb.c 
	gcc -c collisionbb.c -lSDL -lSDL_image -g  

