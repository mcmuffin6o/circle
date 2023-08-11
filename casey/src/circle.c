#include <stdio.h>

int main(void)
{
    char Bitmap[64][64] = {};

    // NOTE(casey): Center and radius of the circle
    int Cx = 32;
    int Cy = 32;
    int R = 20;
    
    // NOTE(casey): Loop that draws the circle
    {
        int R2 = R+R;
        
        int X = R;
        int Y = 0;
        int dY = -2;
        int dX = R2+R2 - 4;
        int D = R2 - 1;
        
        while(Y <= X)
        {
            Bitmap[Cy - Y][Cx - X] = 1;
            Bitmap[Cy - Y][Cx + X] = 1;
            Bitmap[Cy + Y][Cx - X] = 1;
            Bitmap[Cy + Y][Cx + X] = 1;
            Bitmap[Cy - X][Cx - Y] = 1;
            Bitmap[Cy - X][Cx + Y] = 1;
            Bitmap[Cy + X][Cx - Y] = 1;
            Bitmap[Cy + X][Cx + Y] = 1;
            
            D += dY;
            dY -= 4;
            ++Y;
        
#if 0
            // NOTE(casey): Branching version
            if(D < 0)
            {
                D += dX;
                dX -= 4;
                --X;
            }
#else
            // NOTE(casey): Branchless version
            int Mask = (D >> 31);
            D += dX & Mask;
            dX -= 4 & Mask;
            X += Mask;
#endif
        }
    }
    
    // NOTE(casey): Output the bitmap using roughly square elements
    for(int Y = 0; Y < 64; ++Y)
    {
        for(int X = 0; X < 64; ++X)
        {
            char L = ' ';
            char R = ' ';
            if(Bitmap[Y][X] == 1)
            {
                L = '[';
                R = ']';
            }
            printf("%c%c", L, R);
        }
        printf("\n");
    }
}
