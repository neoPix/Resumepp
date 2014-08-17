/**
 * Created by David Balan
 */

#include "main.h"
#include <ctime>

using namespace rsm;
Resume::Resume(string firstname, string lastname):_birth(0),_startingAt(0),_job(""),_firstname(firstname),_lastname(lastname),
    _hobbies(NULL),_experiences(NULL),_skills(NULL),_personnalLinks(NULL)
{
}

double Resume::age()
{
    unsigned int now = time(0);
    return ((difftime(now, this->_birth) + 86400L/2) / 86400L)/365.0;
}

double Resume::experience()
{
    unsigned int now = time(0);
    return ((difftime(now, this->_startingAt) + 86400L/2) / 86400L)/365.0;
}

vector<Hobby*>* Resume::hobbies()
{
    if(this->_hobbies == NULL)
        this->_hobbies = new vector<Hobby*>();
    return this->_hobbies;
}

vector<Skill*>* Resume::skills()
{
    if(this->_skills == NULL)
        this->_skills = new vector<Skill*>();
    return this->_skills;
}

vector<PersonnalLink*>* Resume::personnalLinks()
{
    if(this->_personnalLinks == NULL)
        this->_personnalLinks = new vector<PersonnalLink*>();
    return this->_personnalLinks;
}

vector<Training*>* Resume::trainings()
{
    if(this->_trainings == NULL)
        this->_trainings = new vector<Training*>();
    return this->_trainings;
}

vector<Experience*>* Resume::experiences()
{
    if(this->_experiences == NULL)
        this->_experiences = new vector<Experience*>();
    return this->_experiences;
}

template<typename T> void unAllocateVector(vector<T*> *v)
{
    while (!v->empty()){
        T* f = v->back();
        v->pop_back();
        delete f;
    }
}

Resume::~Resume()
{
    if(this->_hobbies != NULL)
    {
        unAllocateVector(this->_hobbies);
        delete this->_hobbies;
    }
    if(this->_skills != NULL)
    {
        unAllocateVector(this->_skills);
        delete this->_skills;
    }
    if(this->_personnalLinks != NULL)
    {
        unAllocateVector(this->_personnalLinks);
        delete this->_personnalLinks;
    }
    if(this->_trainings != NULL)
    {
        unAllocateVector(this->_trainings);
        delete this->_trainings;
    }
    if(this->_experiences != NULL)
    {
        unAllocateVector(this->_experiences);
        delete this->_experiences;
    }

}
