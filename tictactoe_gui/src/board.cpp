#include "board.h"
#include <iostream>


void boardnull(char **x, int n)
{
     for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            x[i][j]=' ';
}


