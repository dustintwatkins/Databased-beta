//
//  Person.h
//  Databased 1.1
//
//  Created by Dustin Watkins on 7/11/17.
//  Copyright © 2017 Dustin Watkins. All rights reserved.
//

#ifndef Person_h
#define Person_h

#include <stdio.h>
#include <string> 
#include <vector> 
#include <iostream>

using namespace std;

class Person
{
public:
    Person(double answerRate, double setRate, double showRate, double opConversion, double closeRate, double avgDealSize, string name);
    ~Person();
    
    double answerRate;
    double setRate;
    double showRate;
    double opConversion;
    double closeRate;
    double avgDealSize;
    string name;
    
    double get_answerRate();
    double get_setRate();
    double get_showRate();
    double get_opConversion();
    double get_closeRate();
    double get_avgDealSize();
    string get_name();
    
    void outputInfo();
    
    
};


#endif /* Person_h */
