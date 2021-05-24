#include "moves.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

bool movesAI_2(char **x,int n,int il,int &x_AI,int &y_AI)
{int czy=0,pom1=0,p,q,pom2=0;
    char zn='X';
    char zn2='O';


 // ten switch sprawdza ciagi znakow komputera (O) i jezeli wystepuje ciag o dlugosci
 // wystarczajacej do wygranej ale posiadajacy wewnatrz jedno pole puste
 // np. OO OO to jest tam wstawiany znak O -> wygrana komputera
    switch (il)
    {
    case 5:

    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(j+4<n)
        {pom1=0;
            if(x[i][j]==zn2 && x[i][j+4]==zn2)
            {pom2=0;
                for(int g=1;g<=3;g++)
                {
                    if(x[i][j+g]==zn2) pom1++;
                    if(x[i][j+g]==' ') {p=i;q=j+g;pom2=1;}
                }
                if(pom1==2 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
            }
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(j+4<n)
            {pom1=0;
                if(x[j][i]==zn2 && x[j+4][i]==zn2)
                {pom2=0;
                    for(int g=1;g<=3;g++)
                    {
                        if(x[j+g][i]==zn2) pom1++;
                        if(x[j+g][i]==' ') {p=j+g;q=i;pom2=1;}
                    }
                    if(pom1==2 && pom2==1) {x[p][q]='O'; x_AI=q;y_AI=p;czy=1; return czy;}
                }
            }
    for(int k=n-1;k>=0;k--)
      for(int i=0;i<n-k;i++)
          if(i+4<n && i+k+4<n)
          {pom1=0;
              if(x[i][i+k]==zn2 && x[i+4][i+k+4]==zn2)
              {pom2=0;
                  for(int g=1;g<=3;g++)
                  {
                      if(x[i+g][i+k+g]==zn2) pom1++;
                      if(x[i+g][i+k+g]==' ') {p=i+g;q=i+k+g;pom2=1;}
                  }
                  if(pom1==2 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
              }

          }
     for(int k=1;k<n;k++)
       for(int i=k;i<n;i++)
          if(i+4<n && i-k+4<n)
          {pom1=0;
              if(x[i][i-k]==zn2 && x[i+4][i-k+4]==zn2)
              {pom2=0;
                  for(int g=1;g<=3;g++)
                  {
                      if(x[i+g][i-k+g]==zn2) pom1++;
                      if(x[i+g][i-k+g]==' ') {p=i+g;q=i-k+g;pom2=1;}
                  }
                  if(pom1==2 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
              }

          }

      for(int k=1;k<=n;k++)
         for(int i=1;i<=k;i++)
            if(k-i-4>=0 && i+3<n)
            {pom1=0;
                if(x[k-i][i-1]==zn2 && x[k-i-4][i+3]==zn2)
                {pom2=0;
                    for(int g=1;g<=3;g++)
                    {
                        if(x[k-i-g][i-1+g]==zn2) pom1++;
                        if(x[k-i-g][i-1+g]==' ') {p=k-i-g;q=i-1+g;pom2=1;}
                    }
                    if(pom1==2 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                }

            }
       for(int k=1;k<n;k++)
          for(int i=0;i<n-k;i++)
             if(k+i+4<n && n-i-5>=0)
             {pom1=0;
                 if(x[k+i][n-i-1]==zn2 && x[k+i+4][n-i-5]==zn2)
                 {pom2=0;
                     for(int g=1;g<=3;g++)
                     {
                         if(x[k+i+g][n-i-1-g]==zn2) pom1++;
                         if(x[k+i+g][n-i-1-g]==' ') {p=k+i+g;q=n-i-1-g;pom2=1;}
                     }
                     if(pom1==2 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                 }

             }
        break;

      case 4:
                     for(int i=0;i<n;i++)
                       for(int j=0;j<n;j++)
                         if(j+3<n)
                         {pom1=0;
                             if(x[i][j]==zn2 && x[i][j+3]==zn2)
                             {pom2=0;
                                 for(int g=1;g<=2;g++)
                                 {
                                     if(x[i][j+g]==zn2) pom1++;
                                     if(x[i][j+g]==' ') {p=i;q=j+g;pom2=1;}
                                 }
                                 if(pom1==1 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                             }
                         }
                     for(int i=0;i<n;i++)
                         for(int j=0;j<n;j++)
                             if(j+3<n)
                             {pom1=0;
                                 if(x[j][i]==zn2 && x[j+3][i]==zn2)
                                 {pom2=0;
                                     for(int g=1;g<=2;g++)
                                     {
                                         if(x[j+g][i]==zn2) pom1++;
                                         if(x[j+g][i]==' ') {p=j+g;q=i;pom2=1;}
                                     }
                                     if(pom1==1 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                                 }
                             }
                     for(int k=n-1;k>=0;k--)
                       for(int i=0;i<n-k;i++)
                           if(i+3<n && i+k+3<n)
                           {pom1=0;
                               if(x[i][i+k]==zn2 && x[i+3][i+k+3]==zn2)
                               {pom2=0;
                                   for(int g=1;g<=2;g++)
                                   {
                                       if(x[i+g][i+k+g]==zn2) pom1++;
                                       if(x[i+g][i+k+g]==' ') {p=i+g;q=i+k+g;pom2=1;}
                                   }
                                   if(pom1==1 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                               }

                           }
                      for(int k=1;k<n;k++)
                        for(int i=k;i<n;i++)
                           if(i+3<n && i-k+3<n)
                           {pom1=0;
                               if(x[i][i-k]==zn2 && x[i+3][i-k+3]==zn2)
                               {pom2=0;
                                   for(int g=1;g<=2;g++)
                                   {
                                       if(x[i+g][i-k+g]==zn2) pom1++;
                                       if(x[i+g][i-k+g]==' ') {p=i+g;q=i-k+g;pom2=1;}
                                   }
                                   if(pom1==1 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                               }

                           }

                       for(int k=1;k<=n;k++)
                          for(int i=1;i<=k;i++)
                             if(k-i-3>=0 && i+2<n)
                             {pom1=0;
                                 if(x[k-i][i-1]==zn2 && x[k-i-3][i+2]==zn2)
                                 {pom2=0;
                                     for(int g=1;g<=2;g++)
                                     {
                                         if(x[k-i-g][i-1+g]==zn2) pom1++;
                                         if(x[k-i-g][i-1+g]==' ') {p=k-i-g;q=i-1+g;pom2=1;}
                                     }
                                     if(pom1==1 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                                 }

                             }
                        for(int k=1;k<n;k++)
                           for(int i=0;i<n-k;i++)
                              if(k+i+3<n && n-i-4>=0)
                              {pom1=0;
                                  if(x[k+i][n-i-1]==zn2 && x[k+i+3][n-i-4]==zn2)
                                  {pom2=0;
                                      for(int g=1;g<=2;g++)
                                      {
                                          if(x[k+i+g][n-i-1-g]==zn2) pom1++;
                                          if(x[k+i+g][n-i-1-g]==' ') {p=k+i+g;q=n-i-1-g;pom2=1;}
                                      }
                                      if(pom1==1 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                                  }

                              }
                           break;
      case 3:
                                      for(int i=0;i<n;i++)
                                        for(int j=0;j<n;j++)
                                          if(j+2<n)
                                           if(x[i][j]==zn2 && x[i][j+2]==zn2 && x[i][j+1]==' ')
                                              {
                                                x[i][j+1]='O';x_AI=j+1;y_AI=i; czy=1; return czy;
                                              }
                                      for(int i=0;i<n;i++)
                                          for(int j=0;j<n;j++)
                                              if(j+2<n)
                                               if(x[j][i]==zn2 && x[j+2][i]==zn2 && x[j+1][i]==' ')
                                                  {
                                                   x[j+1][i]='O';x_AI=i;y_AI=j+1; czy=1; return czy;
                                                  }

                                      for(int k=n-1;k>=0;k--)
                                        for(int i=0;i<n-k;i++)
                                            if(i+2<n && i+k+2<n)
                                             if(x[i][i+k]==zn2 && x[i+2][i+k+2]==zn2 && x[i+1][i+k+1]==' ')
                                                {
                                                   x[i+1][i+k+2]='O';x_AI=i+k+2;y_AI=i+1; czy=1; return czy;
                                                }


                                       for(int k=1;k<n;k++)
                                         for(int i=k;i<n;i++)
                                            if(i+2<n && i-k+2<n)
                                              if(x[i][i-k]==zn2 && x[i+2][i-k+2]==zn2 && x[i+1][i-k+1]==' ')
                                                {
                                                   x[i+1][i-k+1]='O';x_AI=i-k+1;y_AI=i+1; czy=1; return czy;
                                                }



                                        for(int k=1;k<=n;k++)
                                           for(int i=1;i<=k;i++)
                                              if(k-i-2>=0 && i+1<n)
                                                if(x[k-i][i-1]==zn2 && x[k-i-2][i+1]==zn2 && x[k-i-1][i]==' ')
                                                  {
                                                     x[k-i-1][i]='O';x_AI=i;y_AI=k-i-1; czy=1; return czy;
                                                  }


                                         for(int k=1;k<n;k++)
                                            for(int i=0;i<n-k;i++)
                                               if(k+i+2<n && n-i-3>=0)
                                                 if(x[k+i][n-i-1]==zn2 && x[k+i+2][n-i-3]==zn2 && x[k+i+1][n-i-2]==' ')
                                                   {
                                                      x[k+i+1][n-i-2]='O'; x_AI=n-i-2;y_AI=k+i+1;czy=1; return czy;
                                                   }


                                            break;

    }
    // ten switch sprawdza ciagi znakow gracza (X) i jezeli wystepuje ciag o dlugosci
    // wystarczajacej do wygranej ale posiadajacy wewnatrz jedno pole puste
    // np. XX XX to to jest tam wstawiany znak O -> obrona, gracz nie wygrywa
    switch (il)
    {

    case 5:

    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(j+4<n)
        {pom1=0;
            if(x[i][j]==zn && x[i][j+4]==zn)
            {pom2=0;
                for(int g=1;g<=3;g++)
                {
                    if(x[i][j+g]==zn) pom1++;
                    if(x[i][j+g]==' ') {p=i;q=j+g;pom2=1;}
                }
                if(pom1==2 && pom2==1) {x[p][q]='O'; x_AI=q;y_AI=p;czy=1; return czy;}
            }
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(j+4<n)
            {pom1=0;
                if(x[j][i]==zn && x[j+4][i]==zn)
                {pom2=0;
                    for(int g=1;g<=3;g++)
                    {
                        if(x[j+g][i]==zn) pom1++;
                        if(x[j+g][i]==' ') {p=j+g;q=i;pom2=1;}
                    }
                    if(pom1==2 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                }
            }
    for(int k=n-1;k>=0;k--)
      for(int i=0;i<n-k;i++)
          if(i+4<n && i+k+4<n)
          {pom1=0;
              if(x[i][i+k]==zn && x[i+4][i+k+4]==zn)
              {pom2=0;
                  for(int g=1;g<=3;g++)
                  {
                      if(x[i+g][i+k+g]==zn) pom1++;
                      if(x[i+g][i+k+g]==' ') {p=i+g;q=i+k+g;pom2=1;}
                  }
                  if(pom1==2 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
              }

          }
     for(int k=1;k<n;k++)
       for(int i=k;i<n;i++)
          if(i+4<n && i-k+4<n)
          {pom1=0;
              if(x[i][i-k]==zn && x[i+4][i-k+4]==zn)
              {pom2=0;
                  for(int g=1;g<=3;g++)
                  {
                      if(x[i+g][i-k+g]==zn) pom1++;
                      if(x[i+g][i-k+g]==' ') {p=i+g;q=i-k+g;pom2=1;}
                  }
                  if(pom1==2 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
              }

          }

      for(int k=1;k<=n;k++)
         for(int i=1;i<=k;i++)
            if(k-i-4>=0 && i+3<n)
            {pom1=0;
                if(x[k-i][i-1]==zn && x[k-i-4][i+3]==zn)
                {pom2=0;
                    for(int g=1;g<=3;g++)
                    {
                        if(x[k-i-g][i-1+g]==zn) pom1++;
                        if(x[k-i-g][i-1+g]==' ') {p=k-i-g;q=i-1+g;pom2=1;}
                    }
                    if(pom1==2 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                }

            }
       for(int k=1;k<n;k++)
          for(int i=0;i<n-k;i++)
             if(k+i+4<n && n-i-5>=0)
             {pom1=0;
                 if(x[k+i][n-i-1]==zn && x[k+i+4][n-i-5]==zn)
                 {pom2=0;
                     for(int g=1;g<=3;g++)
                     {
                         if(x[k+i+g][n-i-1-g]==zn) pom1++;
                         if(x[k+i+g][n-i-1-g]==' ') {p=k+i+g;q=n-i-1-g;pom2=1;}
                     }
                     if(pom1==2 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                 }

             }
        break;

      case 4:
                     for(int i=0;i<n;i++)
                       for(int j=0;j<n;j++)
                         if(j+3<n)
                         {pom1=0;
                             if(x[i][j]==zn && x[i][j+3]==zn)
                             {pom2=0;
                                 for(int g=1;g<=2;g++)
                                 {
                                     if(x[i][j+g]==zn) pom1++;
                                     if(x[i][j+g]==' ') {p=i;q=j+g;pom2=1;}
                                 }
                                 if(pom1==1 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                             }
                         }
                     for(int i=0;i<n;i++)
                         for(int j=0;j<n;j++)
                             if(j+3<n)
                             {pom1=0;
                                 if(x[j][i]==zn && x[j+3][i]==zn)
                                 {pom2=0;
                                     for(int g=1;g<=2;g++)
                                     {
                                         if(x[j+g][i]==zn) pom1++;
                                         if(x[j+g][i]==' ') {p=j+g;q=i;pom2=1;}
                                     }
                                     if(pom1==1 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                                 }
                             }
                     for(int k=n-1;k>=0;k--)
                       for(int i=0;i<n-k;i++)
                           if(i+3<n && i+k+3<n)
                           {pom1=0;
                               if(x[i][i+k]==zn && x[i+3][i+k+3]==zn)
                               {pom2=0;
                                   for(int g=1;g<=2;g++)
                                   {
                                       if(x[i+g][i+k+g]==zn) pom1++;
                                       if(x[i+g][i+k+g]==' ') {p=i+g;q=i+k+g;pom2=1;}
                                   }
                                   if(pom1==1 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                               }

                           }
                      for(int k=1;k<n;k++)
                        for(int i=k;i<n;i++)
                           if(i+3<n && i-k+3<n)
                           {pom1=0;
                               if(x[i][i-k]==zn && x[i+3][i-k+3]==zn)
                               {pom2=0;
                                   for(int g=1;g<=2;g++)
                                   {
                                       if(x[i+g][i-k+g]==zn) pom1++;
                                       if(x[i+g][i-k+g]==' ') {p=i+g;q=i-k+g;pom2=1;}
                                   }
                                   if(pom1==1 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                               }

                           }

                       for(int k=1;k<=n;k++)
                          for(int i=1;i<=k;i++)
                             if(k-i-3>=0 && i+2<n)
                             {pom1=0;
                                 if(x[k-i][i-1]==zn && x[k-i-3][i+2]==zn)
                                 {pom2=0;
                                     for(int g=1;g<=2;g++)
                                     {
                                         if(x[k-i-g][i-1+g]==zn) pom1++;
                                         if(x[k-i-g][i-1+g]==' ') {p=k-i-g;q=i-1+g;pom2=1;}
                                     }
                                     if(pom1==1 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                                 }

                             }
                        for(int k=1;k<n;k++)
                           for(int i=0;i<n-k;i++)
                              if(k+i+3<n && n-i-4>=0)
                              {pom1=0;
                                  if(x[k+i][n-i-1]==zn && x[k+i+3][n-i-4]==zn)
                                  {pom2=0;
                                      for(int g=1;g<=2;g++)
                                      {
                                          if(x[k+i+g][n-i-1-g]==zn) pom1++;
                                          if(x[k+i+g][n-i-1-g]==' ') {p=k+i+g;q=n-i-1-g;pom2=1;}
                                      }
                                      if(pom1==1 && pom2==1) {x[p][q]='O';x_AI=q;y_AI=p; czy=1; return czy;}
                                  }

                              }
                           break;
      case 3:
                                      for(int i=0;i<n;i++)
                                        for(int j=0;j<n;j++)
                                          if(j+2<n)
                                           if(x[i][j]==zn && x[i][j+2]==zn && x[i][j+1]==' ')
                                              {
                                                x[i][j+1]='O';x_AI=j+1;y_AI=i; czy=1; return czy;
                                              }
                                      for(int i=0;i<n;i++)
                                          for(int j=0;j<n;j++)
                                              if(j+2<n)
                                               if(x[j][i]==zn && x[j+2][i]==zn && x[j+1][i]==' ')
                                                  {
                                                   x[j+1][i]='O';x_AI=i;y_AI=j+1; czy=1; return czy;
                                                  }

                                      for(int k=n-1;k>=0;k--)
                                        for(int i=0;i<n-k;i++)
                                            if(i+2<n && i+k+2<n)
                                             if(x[i][i+k]==zn && x[i+2][i+k+2]==zn && x[i+1][i+k+1]==' ')
                                                {
                                                   x[i+1][i+k+2]='O';x_AI=i+k+2;y_AI=i+1; czy=1; return czy;
                                                }


                                       for(int k=1;k<n;k++)
                                         for(int i=k;i<n;i++)
                                            if(i+2<n && i-k+2<n)
                                              if(x[i][i-k]==zn && x[i+2][i-k+2]==zn && x[i+1][i-k+1]==' ')
                                                {
                                                   x[i+1][i-k+1]='O';x_AI=i-k+1;y_AI=i+1; czy=1; return czy;
                                                }



                                        for(int k=1;k<=n;k++)
                                           for(int i=1;i<=k;i++)
                                              if(k-i-2>=0 && i+1<n)
                                                if(x[k-i][i-1]==zn && x[k-i-2][i+1]==zn && x[k-i-1][i]==' ')
                                                  {
                                                     x[k-i-1][i]='O';x_AI=i;y_AI=k-i-1; czy=1; return czy;
                                                  }


                                         for(int k=1;k<n;k++)
                                            for(int i=0;i<n-k;i++)
                                               if(k+i+2<n && n-i-3>=0)
                                                 if(x[k+i][n-i-1]==zn && x[k+i+2][n-i-3]==zn && x[k+i+1][n-i-2]==' ')
                                                   {
                                                      x[k+i+1][n-i-2]='O';x_AI=n-i-2;y_AI=k+i+1; czy=1; return czy;
                                                   }


                                            break;

    }


    return czy;
}
//*************************************************************************
void movesAI(char **x,int n,int il,int &x_AI,int &y_AI)
{
    char zn='X';
    char zn2='O';
    bool czy=0;
    int pom1=0,pom2=0,max=0,max2=0,gdzie=0,gdzie2=0,pom3=0,pom4=0;
  // instrukcje wewnatrz if maja za zadanie odpowiednie rozpoczecie rozgrywki
  // przez komputer w grze 3x3 (dzieki nim w grze 3x3 komputer zawsze zremisuje)
    if(il==3)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
               if(x[i][j]=='X') pom4++;
        if(pom4==2 && x[1][1]=='X' && x[2][0]=='X')
        {
            x[2][2]='O';
            x_AI=2;y_AI=2;
            czy=1;
        }
        if(pom4==1)
        {
            if(x[1][1]=='X')
            {
                x[0][2]='O';
                x_AI=2;y_AI=0;
                czy=1;
            }
            else
            {
                x[1][1]='O';
                x_AI=1;y_AI=1;
                czy=1;
            }
        }

     }

  // ta sekwencja petli ma za zadanie znalezc najdluzszy lancuch znakow przeciwnika,
  // ktory trzeba przeciac
    for(int i=0;i<n;i++)
    {   pom1=0;
        pom2=0;
        for(int j=0;j<n;j++)
        {
            if(x[i][j]==zn) {pom1++;}
            else pom1=0;
            if((pom1>max && (((j+1)<n && x[i][j+1]==' ')
                        || ((j-pom1)>=0 && x[i][j-pom1]==' ')))
                    || (pom1>=max && (((j+1)<n && x[i][j+1]==' ')
                                     && ((j-pom1)>=0 && x[i][j-pom1]==' '))))
            { max=pom1; gdzie=1;}
            if(x[j][i]==zn) {pom2++;}
            else pom2=0;
            if((pom2>max && (((j+1)<n && x[j+1][i]==' ')
                        || ((j-pom2)>=0 && x[j-pom2][i]==' ')))
                    || (pom2>=max && (((j+1)<n && x[j+1][i]==' ')
                                     && ((j-pom2)>=0 && x[j-pom2][i]==' '))))
            { max=pom2; gdzie=2;}
        }
    }
     for(int k=n-1;k>=0;k--)
    { pom1=0;
        for(int i=0;i<n-k;i++)
        {
            if(x[i][i+k]==zn) {pom1++;}
            else pom1=0;
            if((pom1>max && (((i+1)<n && (i+k+1)<n && x[i+1][i+k+1]==' ')
                        || ((i-pom1)>=0 && (i+k-pom1)>=0 && x[i-pom1][i+k-pom1]==' ')))
                    || (pom1>max && (((i+1)<n && (i+k+1)<n && x[i+1][i+k+1]==' ')
                                     && ((i-pom1)>=0 && (i+k-pom1)>=0 && x[i-pom1][i+k-pom1]==' '))))
            { max=pom1; gdzie=3;}
        }
    }
    for(int k=1;k<n;k++)
    { pom1=0;
        for(int i=k;i<n;i++)
        {
            if(x[i][i-k]==zn) {pom1++;}
            else pom1=0;
            if((pom1>max && (((i+1)<n && (i-k+1)<n && x[i+1][i-k+1]==' ')
                        || ((i-pom1)>=0 && (i-k-pom1)>=0 && x[i-pom1][i-k-pom1]==' ')))
                    || (pom1>max && (((i+1)<n && (i-k+1)<n && x[i+1][i-k+1]==' ')
                                     && ((i-pom1)>=0 && (i-k-pom1)>=0 && x[i-pom1][i-k-pom1]==' '))))
            { max=pom1; gdzie=4;}
        }
    }
    for(int k=1;k<=n;k++)
     {pom1=0;
        for(int i=1;i<=k;i++)
        {
            if(x[k-i][i-1]==zn) {pom1++;}
            else pom1=0;
            if((pom1>max && (((k-i-1)>=0 && (i)<n && x[k-i-1][i]==' ')
                        || ((k-i+pom1)<n && (i-1-pom1)>=0 && x[k-i+pom1][i-1-pom1]==' ')))
                    || (pom1>max && (((k-i-1)>=0 && (i)<n && x[k-i-1][i]==' ')
                                     && ((k-i+pom1)<n && (i-1-pom1)>=0 && x[k-i+pom1][i-1-pom1]==' '))))
            { max=pom1; gdzie=5;}
        }
     }
    for(int k=1;k<n;k++)
     {pom1=0;
        for(int i=0;i<n-k;i++)
        {
            if(x[k+i][n-i-1]==zn) {pom1++;}
            else pom1=0;
            if((pom1>max && (((k+i+1)<n && (n-i-2)>=0 && x[k+i+1][n-i-2]==' ')
                        || ((k+i-pom1)>=0 && (n-i-1+pom1)<n && x[k+i-pom1][n-i-1+pom1]==' ')))
                    || (pom1>max && (((k+i+1)<n && (n-i-2)>=0 && x[k+i+1][n-i-2]==' ')
                                     && ((k+i-pom1)>=0 && (n-i-1+pom1)<n && x[k+i-pom1][n-i-1+pom1]==' '))))
            { max=pom1; gdzie=6;}
        }
     }

  // ta sekwencja petli ma za zadanie znalezc najdluzszy lancuch znakow komputera,
  // ktory w miare mozliwosci trzeba przedluzyc aby komputer wygral

         for(int i=0;i<n;i++)
        {   pom1=0;
            pom2=0;
            for(int j=0;j<n;j++)
            {
                if(x[i][j]==zn2) {pom1++;}
                else pom1=0;
                if((pom1>max2 && (((j+1)<n && x[i][j+1]==' ')
                            || ((j-pom1)>=0 && x[i][j-pom1]==' ')))
                        || (pom1>max2 && (((j+1)<n && x[i][j+1]==' ')
                                          && ((j-pom1)>=0 && x[i][j-pom1]==' '))))
                { max2=pom1; gdzie2=1;}
                if(x[j][i]==zn2) {pom2++;}
                else pom2=0;
                if((pom2>max2 && (((j+1)<n && x[j+1][i]==' ')
                            || ((j-pom2)>=0 && x[j-pom2][i]==' ')))
                        || (pom2>max2 && (((j+1)<n && x[j+1][i]==' ')
                                          && ((j-pom2)>=0 && x[j-pom2][i]==' '))))
                { max2=pom2; gdzie2=2;}
            }
        }
         for(int k=n-1;k>=0;k--)
        { pom1=0;
            for(int i=0;i<n-k;i++)
            {
                if(x[i][i+k]==zn2) {pom1++;}
                else pom1=0;
                if((pom1>max2 && (((i+1)<n && (i+k+1)<n && x[i+1][i+k+1]==' ')
                            || ((i-pom1)>=0 && (i+k-pom1)>=0 && x[i-pom1][i+k-pom1]==' ')))
                        || (pom1>max2 && (((i+1)<n && (i+k+1)<n && x[i+1][i+k+1]==' ')
                                          && ((i-pom1)>=0 && (i+k-pom1)>=0 && x[i-pom1][i+k-pom1]==' '))))
                { max2=pom1; gdzie2=3;}
            }
        }
        for(int k=1;k<n;k++)
        { pom1=0;
            for(int i=k;i<n;i++)
            {
                if(x[i][i-k]==zn2) {pom1++;}
                else pom1=0;
                if((pom1>max2 && (((i+1)<n && (i-k+1)<n && x[i+1][i-k+1]==' ')
                            || ((i-pom1)>=0 && (i-k-pom1)>=0 && x[i-pom1][i-k-pom1]==' ')))
                        || (pom1>max2 && (((i+1)<n && (i-k+1)<n && x[i+1][i-k+1]==' ')
                                          && ((i-pom1)>=0 && (i-k-pom1)>=0 && x[i-pom1][i-k-pom1]==' '))))
                { max2=pom1; gdzie2=4;}
            }
        }
        for(int k=1;k<=n;k++)
         {pom1=0;
            for(int i=1;i<=k;i++)
            {
                if(x[k-i][i-1]==zn2) {pom1++;}
                else pom1=0;
                if((pom1>max2 && (((k-i-1)>=0 && (i)<n && x[k-i-1][i]==' ')
                            || ((k-i+pom1)<n && (i-1-pom1)>=0 && x[k-i+pom1][i-1-pom1]==' ')))
                        || (pom1>max2 && (((k-i-1)>=0 && (i)<n && x[k-i-1][i]==' ')
                                          && ((k-i+pom1)<n && (i-1-pom1)>=0 && x[k-i+pom1][i-1-pom1]==' '))))
                { max2=pom1; gdzie2=5;}
            }
         }
        for(int k=1;k<n;k++)
         {pom1=0;
            for(int i=0;i<n-k;i++)
            {
                if(x[k+i][n-i-1]==zn2) {pom1++;}
                else pom1=0;
                if((pom1>max2 && (((k+i+1)<n && (n-i-2)>=0 && x[k+i+1][n-i-2]==' ')
                            || ((k+i-pom1)>=0 && (n-i-1+pom1)<n && x[k+i-pom1][n-i-1+pom1]==' ')))
                        || (pom1>max2 && (((k+i+1)<n && (n-i-2)>=0 && x[k+i+1][n-i-2]==' ')
                                          && ((k+i-pom1)>=0 && (n-i-1+pom1)<n && x[k+i-pom1][n-i-1+pom1]==' '))))
                { max2=pom1; gdzie2=6;}
            }
         }
 // jezeli komputer w tym ruchu nie moze jeszcze wygrac przedluzajac najdluzszy
 // ciag swoich znakow to sprwdzane sa warunki z funkcji movesAI_2
        if(czy==0 && max2+1!=il)
        czy=movesAI_2(x,n,il,x_AI,y_AI);
 // jesli w funkcji movesAI_2 komputer nie wykonal ruchu to:
        if(czy==0)
        {
 // jezeli nie ma zagrozenia szybkiej wygranej gracza (nie trzeb sie bronic) to
 // komputer koncentruje sie na przedluzaniu ciagow wlasnych znakow
        if((max<=2 && n>5) || (max==1 && n<=5) || (max2+1==il))
        {
        switch(gdzie2)
        {
           case 1:
            for(int i=0;i<n;i++)
            {   pom1=0;
               for(int j=0;j<n;j++)
                {
                    if(x[i][j]==zn2) {pom1++;}
                    else pom1=0;
                    if(pom1==max2)
                    {
                      if((j+1)<n && x[i][j+1]==' ') {x[i][j+1]='O';x_AI=j+1;y_AI=i;czy=1; goto end12;}
                      else
                      if((j-pom1)>=0 && x[i][j-pom1]==' ') { x[i][j-pom1]='O';x_AI=j-pom1;y_AI=i; czy=1; goto end12;}
                    }
                 }
             }
            end12:
            if(czy==1)
              break;
           case 2:
             for(int i=0;i<n;i++)
              {   pom2=0;
               for(int j=0;j<n;j++)
                {
                  if(x[j][i]==zn2) {pom2++;}
                  else pom2=0;
                  if(pom2==max2)
                 {
                  if((j+1)<n && x[j+1][i]==' '){ x[j+1][i]='O';x_AI=i;y_AI=j+1;czy=1;goto end22;}
                  else
                  if((j-pom2)>=0 && x[j-pom2][i]==' ') {x[j-pom2][i]='O';x_AI=i;y_AI=j-pom2;czy=1;goto end22;}
                 }
                }
              }
             end22:
             if(czy==1)
            break;
           case 3:
              for(int k=n-1;k>=0;k--)
              { pom1=0;
                  for(int i=0;i<n-k;i++)
                   {
                      if(x[i][i+k]==zn2) {pom1++;}
                      else pom1=0;
                      if(pom1==max2)
                       {
                           if((i+1)<n && (i+k+1)<n && x[i+1][i+k+1]==' ') { x[i+1][i+k+1]='O';x_AI=i+k+1;y_AI=i+1; czy=1;goto end32;}
                           else
                           if((i-pom1)>=0 && (i+k-pom1)>=0 && x[i-pom1][i+k-pom1]==' ') {x[i-pom1][i+k-pom1]='O';x_AI=i+k-pom1;y_AI=i-pom1;czy=1;goto end32;}
                       }
                     }
              }
              end32:
              if(czy==1)
            break;
           case 4:
             for(int k=1;k<n;k++)
             { pom1=0;
               for(int i=k;i<n;i++)
                {
                  if(x[i][i-k]==zn2) {pom1++;}
                  else pom1=0;
                  if(pom1==max2)
                   {
                       if((i+1)<n && (i-k+1)<n && x[i+1][i-k+1]==' ') {x[i+1][i-k+1]='O';czy=1;goto end42;}
                       else
                       if((i-pom1)>=0 && (i-k-pom1)>=0 && x[i-pom1][i-k-pom1]==' ') {x[i-pom1][i-k-pom1]='O';x_AI=i-k-pom1;y_AI=i-pom1;czy=1;goto end42;}
                   }
                 }
             }
             end42:
             if(czy==1)
            break;
           case 5:
            for(int k=1;k<=n;k++)
             {pom1=0;
                for(int i=1;i<=k;i++)
                {
                    if(x[k-i][i-1]==zn2) {pom1++;}
                    else pom1=0;
                    if(pom1==max2)
                    {
                        if((k-i-1)>=0 && (i)<n && x[k-i-1][i]==' ') {x[k-i-1][i]='O';czy=1;goto end52;}
                            else
                        if((k-i+pom1)<n && (i-1-pom1)>=0 && x[k-i+pom1][i-1-pom1]==' ') {x[k-i+pom1][i-1-pom1]='O';x_AI=i-1-pom1;y_AI=k-i+pom1;czy=1;goto end52;}
                    }
                 }
              }
            end52:
            if(czy==1)
            break;
           case 6:
            for(int k=1;k<n;k++)
             {pom1=0;
                for(int i=0;i<n-k;i++)
                {
                    if(x[k+i][n-i-1]==zn2) {pom1++;}
                    else pom1=0;
                    if(pom1==max2)
                     {
                        if((k+i+1)<n && (n-i-2)>=0 && x[k+i+1][n-i-2]==' ') {x[k+i+1][n-i-2]='O';czy=1;goto end62;}
                        else
                        if((k+i-pom1)>=0 && (n-i-1+pom1)<n && x[k+i-pom1][n-i-1+pom1]==' ') {x[k+i-pom1][n-i-1+pom1]='O';x_AI=n-i-1+pom1;y_AI=k+i-pom1;czy=1;goto end62;}
                     }
                }
             }
            end62:
            if(czy==1)
           break;
        }
    }
    else
    {
   // a jezeli jest zagrozenie wygrana gracza to komputer stara sie mu w tym
   // przeszkodzic przerywajac najdluzsze ciagi znakow przeciwnika
    switch(gdzie)
    {
       case 1:
        for(int i=0;i<n;i++)
        {   pom1=0;
           for(int j=0;j<n;j++)
            {
                if(x[i][j]==zn) {pom1++;}
                else pom1=0;
                if(pom1==max)
                {
                  if((j+1)<n && x[i][j+1]==' ') {x[i][j+1]='O';x_AI=j+1;y_AI=i;czy=1; goto end1;}
                  else
                  if((j-pom1)>=0 && x[i][j-pom1]==' ') { x[i][j-pom1]='O';x_AI=j-pom1;y_AI=i; czy=1; goto end1;}
                }
             }
         }
        end1:
        if(czy==1)
         break;
       case 2:
         for(int i=0;i<n;i++)
          {   pom2=0;
           for(int j=0;j<n;j++)
            {
              if(x[j][i]==zn) {pom2++;}
              else pom2=0;
              if(pom2==max)
             {
              if((j+1)<n && x[j+1][i]==' '){ x[j+1][i]='O';x_AI=i;y_AI=j+1;czy=1;goto end2;}
              else
              if((j-pom2)>=0 && x[j-pom2][i]==' ') {x[j-pom2][i]='O';x_AI=i;y_AI=j-pom2;czy=1;goto end2;}
             }
            }
          }
         end2:
         if(czy==1)
       break;
       case 3:
          for(int k=n-1;k>=0;k--)
          { pom1=0;
              for(int i=0;i<n-k;i++)
               {
                  if(x[i][i+k]==zn) {pom1++;}
                  else pom1=0;
                  if(pom1==max)
                   {
                       if((i+1)<n && (i+k+1)<n && x[i+1][i+k+1]==' ') { x[i+1][i+k+1]='O'; x_AI=i+k+1;y_AI=i+1;czy=1;goto end3;}
                       else
                       if((i-pom1)>=0 && (i+k-pom1)>=0 && x[i-pom1][i+k-pom1]==' ') {x[i-pom1][i+k-pom1]='O';x_AI=i+k-pom1;y_AI=i-pom1;czy=1;goto end3;}
                   }
                 }
          }
          end3:
          if(czy==1)
       break;
       case 4:
         for(int k=1;k<n;k++)
         { pom1=0;
           for(int i=k;i<n;i++)
            {
              if(x[i][i-k]==zn) {pom1++;}
              else pom1=0;
              if(pom1==max)
               {
                   if((i+1)<n && (i-k+1)<n && x[i+1][i-k+1]==' ') {x[i+1][i-k+1]='O';x_AI=i-k+1;y_AI=i+1;czy=1;goto end4;}
                   else
                   if((i-pom1)>=0 && (i-k-pom1)>=0 && x[i-pom1][i-k-pom1]==' ') {x[i-pom1][i-k-pom1]='O';x_AI=i-k-pom1;y_AI=i-pom1;czy=1;goto end4;}
               }
             }
         }
         end4:
         if(czy==1)
        break;
       case 5:
        for(int k=1;k<=n;k++)
         {pom1=0;
            for(int i=1;i<=k;i++)
            {
                if(x[k-i][i-1]==zn) {pom1++;}
                else pom1=0;
                if(pom1==max)
                {
                    if((k-i-1)>=0 && (i)<n && x[k-i-1][i]==' ') {x[k-i-1][i]='O';x_AI=i;y_AI=k-i-1;czy=1;goto end5;}
                        else
                    if((k-i+pom1)<n && (i-1-pom1)>=0 && x[k-i+pom1][i-1-pom1]==' ') {x[k-i+pom1][i-1-pom1]='O';x_AI=i-1-pom1;y_AI=k-i+pom1;czy=1;goto end5;}
                }
             }
          }
        end5:
        if(czy==1)
        break;
       case 6:
        for(int k=1;k<n;k++)
         {pom1=0;
            for(int i=0;i<n-k;i++)
            {
                if(x[k+i][n-i-1]==zn) {pom1++;}
                else pom1=0;
                if(pom1==max)
                 {
                    if((k+i+1)<n && (n-i-2)>=0 && x[k+i+1][n-i-2]==' ') {x[k+i+1][n-i-2]='O';x_AI=n-i-2;y_AI=k+i+1;czy=1;goto end6;}
                    else
                    if((k+i-pom1)>=0 && (n-i-1+pom1)<n && x[k+i-pom1][n-i-1+pom1]==' ') {x[k+i-pom1][n-i-1+pom1]='O';x_AI=n-i-1+pom1;y_AI=k+i-pom1;czy=1;goto end6;}
                 }
            }
         }
        end6:
        if(czy==1)
        break;
    }
    }
 }
  // jesli do tej pory komputer nie postawil nigdzie swojego znaku to wykonywane
  // sa nastepujace instrukcje
    if(czy==0)
    {int p,q,pom4;
        srand(time(0));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(x[i][j]=='O') pom3=1;
   // jezeli to jest pierwszy ruch komputera to stara sie postawic znak mozliwie
   // blisko srodka planszy
        if(pom3==0)
        {pom4=(int)n/2;
            p=pom4-1+rand()%(3);
            q=pom4-1+rand()%(3);
            while(x[p][q]!=' ')
            {
                p=pom4-2+rand()%(3);
                q=pom4-2+rand()%(3);
            }
        }
        else
        {
   // jezeli do tej pory nie byly spelnione zadne warunki wystarczajace do postawienia
   // znaku to komputer losuje puste miejsce na planszy i tam stawia swoj znak
        p=1+rand()%(n-1);
        q=1+rand()%(n-1);
        while(x[p][q]!=' ')
        {
            p=1+rand()%(n-1);
            q=1+rand()%(n-1);
        }
        }
        x[p][q]='O';
        x_AI=q;y_AI=p;
    }

}
