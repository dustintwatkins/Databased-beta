//
//  Norms.h
//  Databased 1.1
//
//  Created by Dustin Watkins on 7/11/17.
//  Copyright © 2017 Dustin Watkins. All rights reserved.
//

#ifndef Norms_h
#define Norms_h

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Norms
{
public:
    Norms(double answerRate, double setRate, double showRate, double opConversion, double closeRate, double avgDealSize);
    ~Norms();
    
    double answerRate;
    double setRate;
    double showRate;
    double opConversion;
    double closeRate;
    double avgDealSize;
    //Precedence levels
    int p_ansRate = 1;
    int p_setRate = 3;
    int p_showRate = 2;
    int p_opConv = 6;
    int p_closeRate = 7;
    int p_avgDealSize = 4;
    
    double get_answerRate();
    double get_setRate();
    double get_showRate();
    double get_opConversion();
    double get_closeRate();
    double get_avgDealSize();
    
    int get_p_ansRate();
    int get_p_setRate();
    int get_p_showRate();
    int get_p_opConv();
    int get_p_closeRate();
    int get_p_avgDealSize();
    
    void outputNorms();
};

#endif /* Norms_h */
