#include "main.h"
#include <algorithm>

namespace rsm{
    DavidBalan::DavidBalan():
        Resume("David", "Balan")
    {
        this->job("Programmeur informatique")
            ->birth(663634800)
            ->startingAt(1346450400);

        this->initHobbies()->initSkills()->initPersonnalLinks();
    }

    DavidBalan* DavidBalan::initHobbies()
    {
        vector<Hobby>* hobbies = this->hobbies();
        {
            hobbies->push_back(Hobby("Tir à l'arc"));
            hobbies->push_back(Hobby("Batterie"));
            hobbies->push_back(Hobby("Guitare"));
            hobbies->push_back(Hobby("Nouvelles technologies"));
        }

        return this;
    }

    bool skillCompareFunction (Skill i,Skill j) { return (j<i); }

    DavidBalan* DavidBalan::initSkills()
    {
        vector<Skill>* skills = this->skills();
        {
            //languages
            skills->push_back(Skill("C#", 1, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(Skill("JavaScript", 0.9, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(Skill("PHP", 0.86f, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(Skill("SQL", 0.7f, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(Skill("C++", 0.6f, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(Skill("AINSI-C", 0.5f, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(Skill("Visual Basic.Net", 0.3f, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(Skill("Java", 0.2f, Skill::PROGRAMMING_LANGUAGE));
            //databases
            skills->push_back(Skill("MySQL", 0.7f, Skill::DATABASE));
            skills->push_back(Skill("Microsoft SQL Server", 0.65f, Skill::DATABASE));
            //projects
            skills->push_back(Skill("UML", 0.8f, Skill::PROJECT));
            skills->push_back(Skill("Merise", 0.85f, Skill::PROJECT));
            skills->push_back(Skill("SVN", 0.7f, Skill::PROJECT));
            skills->push_back(Skill("GIT", 0.6f, Skill::PROJECT));
            //knowledges
            skills->push_back(Skill("3D temps réel", 0.75f, Skill::OTHER));
            skills->push_back(Skill("Administration Serveur", 0.6f, Skill::OTHER));
            skills->push_back(Skill("Ergonnomie", 0.4f, Skill::OTHER));
            skills->push_back(Skill("Graphisme", 0.4f, Skill::OTHER));
        }

        sort(skills->begin(), skills->end(), skillCompareFunction);

        return this;
    }

    DavidBalan* DavidBalan::initPersonnalLinks()
    {
        vector<PersonnalLink>* links = this->personnalLinks();
        {
            links->push_back(PersonnalLink("http://www.balandavid.com", PersonnalLink::WEB_SITE));
            links->push_back(PersonnalLink("contact [at] balandavid [dot] com", PersonnalLink::EMAIL));
            links->push_back(PersonnalLink("@neopixel22", PersonnalLink::TWITTER));
        }

        return this;
    }

    DavidBalan::~DavidBalan()
    {}
}
