//
//  main.c
//  Projetil
//
//  Created by José Luiz Junior , Tássio Silva on 05/04/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "calculo.h"

int main(int argc, const char * argv[]) {
    

    float ang, vel, dist, g = 9.8, difAcerto;
    float alcH, alcV;
    int N, i, ptsAtc = 0, ptsDef = 0, x = 160, y = 160;
    
    
        printf("Informe a distancia da catapulta ate o castelo: ");
        scanf(" %f",&dist);
        
        
        while((abs(x) > 150) || (abs(y) > 150)){ //verifica se o modulo dos valores digitados pra x e y estao no limite
            fflush(stdin);
            printf("Informe as cordenadas X e Y do alvo (-150 < x & y < 150): ");
            scanf("%d %d",&x,&y);
            
            if(abs(x) < 150 && abs(y) < 150){
                break;
            }
        }
        
        printf("As coordenadas sao (%d,%d).\n",x,y);
        
        fflush(stdin);
        printf("Informe a quantidade de lancamentos: ");
        scanf(" %d",&N);
        
        for(i=0;i<N;i++){
            printf("Informe o angulo de inclinacao do arremesso %d: ",i+1);
            scanf("%f",&ang);
            printf("Informe a velocidade inicial do arremesso %d: ",i+1);
            scanf("%f",&vel);
            
            
            printf("\n\n");
            
            alcH = calculaDistMax(vel,ang,g);
            alcV = calculaAltMax(vel,ang,g);
            
            difAcerto =  verificaAcerto(alcH,alcV,x,y);
            printf("Distância entre alvo e acerto: %f \n",difAcerto);

            calculaPontos(difAcerto,&ptsAtc,&ptsDef);
        }
        
        printf("Tabela final da pontuacao:  \n");
        printf("Atacante:\t%d\n",ptsAtc);
        printf("Defensor:\t%d\n\n\n",ptsDef);

    return 0;
}









