#include "filemanager.h"
#include "game.h"

FILE * fptr;
int score;
bool read;

void writescore()
{
    fptr = fopen("data/data.txt", "wb");
    fwrite(&Game::score, sizeof(Game::score), 1, fptr);
    fclose(fptr);
}

void readscore()
{
    strcpy(Game::high_score, "high score : ");
    fptr = fopen("data/data.txt", "rb");
    if(fptr == NULL)
    {
        printf("nedokazal jsem otevrit :( vytvorim soubor \n");
        fclose(fptr);
        fptr = fopen("data/data.txt", "wb");
        fclose(fptr);
        strcat(Game::high_score, "none");
    }
    else
    {
        read =  fread(&score, sizeof(Game::score), 1, fptr);
        printf("score je : %d \n", score);
        fclose(fptr);
        if(read)
        {
            char score_str[15];
            sprintf(score_str, "%d", score);
            strcat(Game::high_score, score_str);
        }
        else
        {
            strcat(Game::high_score, "none");
        }
    }
}