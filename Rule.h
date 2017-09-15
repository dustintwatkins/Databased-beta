//
//  Rule.h
//  Databased 1.1
//
//  Created by Dustin Watkins on 7/12/17.
//  Copyright © 2017 Dustin Watkins. All rights reserved.
//

#ifndef Rule_h
#define Rule_h

#include <stdio.h>
#include <iostream> 
#include "Norms.h"
#include "Parser.h"
#include "Person.h"
#include "Skill.h"

using namespace std;

class Rule
{
public:
    Rule(){};
    ~Rule(){};
    
    bool check_input(vector<Person> &employees, string &name_selector);
    
    void eval_employee(Person &p, Norms &norm);
    
    Skill createSkill(string &name, double &increase, int &pLevel);
    void eval_skills(vector<Skill> &skills);
    int findIndex(vector<Skill> &skills, Skill &name);
    
};

#endif /* Rule_h */
