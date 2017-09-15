//
//  Norms.cpp
//  Databased 1.1
//
//  Created by Dustin Watkins on 7/11/17.
//  Copyright © 2017 Dustin Watkins. All rights reserved.
//

#include "Norms.h"

Norms::Norms(double ar, double setr, double showr, double opc, double cr, double ads)
{
    answerRate = ar;
    setRate = setr;
    showRate = showr;
    opConversion = opc;
    closeRate = cr;
    avgDealSize = ads;
}

Norms::~Norms()
{
    
}

double Norms::get_answerRate()
{
    return answerRate;
}

double Norms::get_setRate()
{
    return setRate;
}

double Norms::get_showRate()
{
    return showRate;
}

double Norms::get_opConversion()
{
    return opConversion;
}

double Norms::get_closeRate()
{
    return closeRate;
}

double Norms::get_avgDealSize()
{
    return avgDealSize;
}

int Norms::get_p_ansRate()
{
    return p_ansRate;
}

int Norms::get_p_setRate()
{
    return p_setRate;
}

int Norms::get_p_showRate()
{
    return p_showRate;
}

int Norms::get_p_opConv()
{
    return p_opConv;
}

int Norms::get_p_closeRate()
{
    return p_closeRate;
}

int Norms::get_p_avgDealSize()
{
    return p_avgDealSize;
}

void Norms::outputNorms()
{
    cout << "*** Industry Norms ***" << endl;
    cout << "Answer Rate = " << answerRate << endl;
    cout << "Set Rate = " << setRate << endl;
    cout << "Show Rate = " << showRate << endl;
    cout << "Opportunity Conversion Rate = " << opConversion << endl;
    cout << "Close Rate = " << closeRate << endl;
    cout << "Average Deal Size = " << avgDealSize << endl;
    
}











