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


//apeller fonction collision dans le mouvement du personnage left right .. (!checkCollisionn (..)) apres chaque mouvement 


