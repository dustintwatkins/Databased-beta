//
//  Skill.h
//  Databased 1.1
//
//  Created by Dustin Watkins on 7/14/17.
//  Copyright © 2017 Dustin Watkins. All rights reserved.
//

#ifndef Skill_h
#define Skill_h

#include <stdio.h>
#include <iostream>

using namespace std;

class Skill
{
public:
    Skill();
    ~Skill();
    
    string name;
    double increase;
    int pLevel;
    
    string get_name();
    double get_incrase();
    int get_pLevel();
};

#endif /* Skill_h */
