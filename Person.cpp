//
//  Person.cpp
//  Databased 1.1
//
//  Created by Dustin Watkins on 7/11/17.
//  Copyright © 2017 Dustin Watkins. All rights reserved.
//

#include "Person.h"

Person::Person(double ar, double sr, double shwr, double oc, double cr, double ads, string n)
{
    answerRate = ar;
    setRate = sr;
    showRate = shwr;
    opConversion = oc;
    closeRate = cr;
    avgDealSize = ads;
    name = n;
}

Person::~Person()
{
    
}

double Person::get_answerRate()
{
    return answerRate;
}

double Person::get_setRate()
{
    return setRate;
}

double Person::get_showRate()
{
    return showRate;
}

double Person::get_opConversion()
{
    return opConversion;
}

double Person::get_closeRate()
{
    return closeRate;
}

double Person::get_avgDealSize()
{
    return avgDealSize;
}

string Person::get_name()
{
    return name;
}

void Person::outputInfo()
{
    cout << name << "'s statistics..." << endl;
    cout << "Answer Rate = " << answerRate << endl;
    cout << "Set Rate = " << setRate << endl;
    cout << "Show Rate = " << showRate << endl;
    cout << "Opportunity Conversion Rate = " << opConversion << endl;
    cout << "Close Rate = " << closeRate << endl;
    cout << "Average Deal Size = " << avgDealSize << endl;
}










