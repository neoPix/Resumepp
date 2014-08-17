/**
 * Created by David Balan
 */

#include <iostream>
#include<vector>
#include "Hobby.h"
#include "Training.h"
#include "Skill.h"
#include "PersonnalLink.h"
#include "Experience.h"
#include "Resume.h"
#include "DavidBalan.h"
#include "Console.h"

template<typename T, size_t N>
vector<T>* createVector(T(&tab)[N])
{
    vector<T> *v = new vector<T>();
    for(int i = 0; i < N; i++)
        v->push_back(tab[i]);
    return v;
}
