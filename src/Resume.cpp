/**
 * Created by David Balan
 */

#include "main.h"
#include <ctime>

using namespace rsm;

Resume::Resume(string firstname, string lastname):_birth(0),_startingAt(0),_job(""),_hobbies(NULL),_firstname(firstname),_lastname(lastname)
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

vector<Hobby>* Resume::hobbies()
{
    if(this->_hobbies == NULL)
        this->_hobbies = new vector<Hobby>();
    return this->_hobbies;
}

vector<Skill>* Resume::skills()
{
    if(this->_skills == NULL)
        this->_skills = new vector<Skill>();
    return this->_skills;
}

vector<PersonnalLink>* Resume::personnalLinks()
{
    if(this->_personnalLinks == NULL)
        this->_personnalLinks = new vector<PersonnalLink>();
    return this->_personnalLinks;
}

vector<Training>* Resume::trainings()
{
    if(this->_trainings == NULL)
        this->_trainings = new vector<Training>();
    return this->_trainings;
}

Resume::~Resume()
{
    if(this->_hobbies != NULL)
        delete this->_hobbies;
    if(this->_skills != NULL)
        delete this->_skills;
    if(this->_personnalLinks != NULL)
        delete this->_personnalLinks;
}
