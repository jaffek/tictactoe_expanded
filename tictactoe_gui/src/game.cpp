#include "game.h"
#include <iostream>


bool gamecheck(char **y,int z,char zn,int n)
{
    int pom1=0,pom2=0;
    for(int i=0;i<n;i++)
    {   pom1=0;
        pom2=0;
        for(int j=0;j<n;j++)
        {
            if(y[i][j]==zn) pom1++;
            else pom1=0;
            if(pom1==z) return 1;
            if(y[j][i]==zn) pom2++;
            else pom2=0;
            if(pom2==z) return 1;
        }
    }
     for(int k=n-1;k>=0;k--)
    { pom1=0;
        for(int i=0;i<n-k;i++)
        {
            if(y[i][i+k]==zn) pom1++;
            else pom1=0;
            if(pom1==z) return 1;
        }
    }
    for(int k=1;k<n;k++)
    { pom1=0;
        for(int i=k;i<n;i++)
        {
            if(y[i][i-k]==zn) pom1++;
            else pom1=0;
            if(pom1==z) return 1;
        }
    }
    for(int k=1;k<=n;k++)
     {pom1=0;
        for(int i=1;i<=k;i++)
        {
            if(y[k-i][i-1]==zn) pom1++;
            else pom1=0;
            if(pom1==z) return 1;
        }
     }
    for(int k=1;k<n;k++)
     {pom1=0;
        for(int i=0;i<n-k;i++)
        {
            if(y[k+i][n-i-1]==zn) pom1++;
            else pom1=0;
            if(pom1==z) return 1;
        }
     }
    return 0;
}
int gamewin(int N)
{int pom;
    switch(N)
    {
      case 3: pom=3;
        break;
      case 4: pom=4;
        break;
      case 5: pom=4;
        break;
      default: pom=5;
        break;
    }
    return pom;
}
