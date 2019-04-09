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
    
    
        printf("Digite a distancia da catapulta ate o castelo: ");
        scanf(" %f",&dist);
        
        
        while((abs(x) > 150) || (abs(y) > 150)){ //verifica se o modulo dos valores digitados pra x e y estao no limite
            fflush(stdin);
            printf("Digite o ponto X e Y da coordenada do alvo (-150 < x & y < 150): ");
            scanf("%d %d",&x,&y);
            
            if(abs(x) < 150 && abs(y) < 150){
                break;
            }
        }
        
        printf("As coordenadas (x,y) digitadas para o alvo foram: %d %d\n",x,y);
        
        fflush(stdin);
        printf("Digite a quantidade de lancamentos: ");
        scanf(" %d",&N);
        
        for(i=0;i<N;i++){
            printf("Digite o angulo de inclinacao do arremesso %d: ",i+1);
            scanf("%f",&ang);
            printf("Digite a velocidade inicial %d: ",i+1);
            scanf("%f",&vel);
            
            
            printf("\n\n");
            
            alcH = calculaDistMax(vel,ang,g);
            alcV = calculaAltMax(vel,ang,g);
            
            difAcerto =  verificaAcerto(alcH,alcV,x,y);

            calculaPontos(difAcerto,&ptsAtc,&ptsDef);
        }
        
        printf("Tabela final da pontuacao:  \n");
        printf("Atacante:\t%d\n",ptsAtc);
        printf("Defensor:\t%d\n\n\n",ptsDef);


    
    printf("\n  █████╗ ██╗    ██╗   ██╗ ██████╗     ███████╗██████╗ ██████╗  █████╗ ██████╗  ██████╗\n");
    printf("    ██╔══██╗██║    ██║   ██║██╔═══██╗    ██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔═══██╗\n");
    printf("    ███████║██║    ██║   ██║██║   ██║    █████╗  ██████╔╝██████╔╝███████║██║  ██║██║   ██║\n");
    printf("    ██╔══██║██║    ╚██╗ ██╔╝██║   ██║    ██╔══╝  ██╔══██╗██╔══██╗██╔══██║██║  ██║██║   ██║\n");
    printf("    ██║  ██║███████╗╚████╔╝ ╚██████╔╝    ███████╗██║  ██║██║  ██║██║  ██║██████╔╝╚██████╔╝\n");
    printf("    ╚═╝  ╚═╝╚══════╝ ╚═══╝   ╚═════╝     ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝  ╚═════╝\n\n");

    printf("\n     █████╗ ██╗    ██╗   ██╗ ██████╗      █████╗ ████████╗██╗███╗   ██╗ ██████╗ ██╗██████╗  ██████╗\n");
    printf("    ██╔══██╗██║    ██║   ██║██╔═══██╗    ██╔══██╗╚══██╔══╝██║████╗  ██║██╔════╝ ██║██╔══██╗██╔═══██╗\n");
    printf("    ███████║██║    ██║   ██║██║   ██║    ███████║   ██║   ██║██╔██╗ ██║██║  ███╗██║██║  ██║██║   ██║\n");
    printf("    ██╔══██║██║    ╚██╗ ██╔╝██║   ██║    ██╔══██║   ██║   ██║██║╚██╗██║██║   ██║██║██║  ██║██║   ██║\n");
    printf("    ██║  ██║███████╗╚████╔╝ ╚██████╔╝    ██║  ██║   ██║   ██║██║ ╚████║╚██████╔╝██║██████╔╝╚██████╔╝\n");
    printf("    ╚═╝  ╚═╝╚══════╝ ╚═══╝   ╚═════╝     ╚═╝  ╚═╝   ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═════╝  ╚═════╝\n\n");

    
    return 0;
}









