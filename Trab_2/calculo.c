//
//  calculo.c
//  Trab_2
//
//  Created by José Luiz Junior on 05/04/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include "calculo.h"
#include <math.h>

float calculaAltMax(float vel, float ang, float g){
    return ((vel * vel) * (sin(ang) * sin(ang)))/(2*g);
}

float calculaDistMax(float vel, float ang, float g){
    return ((vel * vel) * (cos(ang) * sin(ang))/g);
}

float verificaAcerto(float cordH, float cordV,int x, int y){
    return sqrt(pow(x-cordH,2) + pow(y-cordV,2));
}

void calculaPontos(float difDist, int *ptsAtc,int *ptsDef){
    if(difDist == 0){
        *ptsAtc += 1000;
    }else{
        if(difDist < 0 && difDist < 1){
            *ptsAtc += 500;
            *ptsDef += 500;
        }else{
            if(difDist > 1 && difDist < 3){
                *ptsAtc += 200;
                *ptsDef += 100;
            }else{
                if(difDist > 3 && difDist < 5){
                    *ptsAtc += 100;
                    *ptsDef += 50;
                }else{
                    if(difDist > 5){
                        *ptsAtc += 0;
                        *ptsDef += 20;
                    }
                }
            }
        }
    }
}


