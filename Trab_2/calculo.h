//
//  calculo.h
//  Trab_2
//
//  Created by José Luiz Junior on 05/04/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#ifndef calculo_h
#define calculo_h

#include <stdio.h>

float calculaAltMax(float vel, float ang, float g);

float calculaDistMax(float vel, float ang, float g);

float verificaAcerto(float cordX, float cordY,int x, int y);

void calculaPontos(float difDist, int *ptsAtc,int *ptsDef);
#endif /* calculo_h */
