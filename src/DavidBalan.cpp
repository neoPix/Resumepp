/**
 * Created by David Balan
 */

#include "main.h"
#include <algorithm>
#include <time.h>

namespace rsm{
    DavidBalan::DavidBalan():
        Resume("David", "Balan")
    {
        this->job("Programmeur informatique")
            ->birth(663634800)
            ->startingAt(1346450400);

        this->initTrainings()->initHobbies()->initSkills()->initPersonnalLinks()->initExperiences();
    }

    DavidBalan* DavidBalan::initTrainings()
    {
        vector<Training*>* trainings = this->trainings();
        {
            trainings->push_back(new Training(2015, "Nantes - France", "Manager des Systèmes d’Information et d’Infrastructure – Systèmes d’Information", "ENI Ecole Informatique"));
            trainings->push_back(new Training(2014, "Rennes - France", "Concepteur Développeur Informatique", "ENI Ecole Informatique"));
            trainings->push_back(new Training(2012, "Rennes - France", "BTS Informatique de Gestion – Développeur d’application", "Lycée Victor et Hélène Bash"));
            trainings->push_back(new Training(2010, "Saint Brieuc - France", "Bac Professionnel MRIM", "Lycée sacré cœur"));
            trainings->push_back(new Training(2008, "Saint Brieuc - France", "BEP Métiers de l’électronique", "Lycée sacré cœur"));
        }

        return this;
    }

    DavidBalan* DavidBalan::initHobbies()
    {
        vector<Hobby*>* hobbies = this->hobbies();
        {
            hobbies->push_back(new Hobby("Tir à l'arc"));
            hobbies->push_back(new Hobby("Batterie"));
            hobbies->push_back(new Hobby("Guitare"));
            hobbies->push_back(new Hobby("Nouvelles technologies"));
        }

        return this;
    }

    bool skillCompareFunction (Skill *i,Skill *j) { return ((*j)<(*i)); }

    DavidBalan* DavidBalan::initSkills()
    {
        vector<Skill*>* skills = this->skills();
        {
            //languages
            skills->push_back(new Skill("C#", 1, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(new Skill("JavaScript", 0.9, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(new Skill("PHP", 0.86f, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(new Skill("SQL", 0.7f, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(new Skill("C++", 0.6f, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(new Skill("AINSI-C", 0.5f, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(new Skill("Visual Basic.Net", 0.3f, Skill::PROGRAMMING_LANGUAGE));
            skills->push_back(new Skill("Java", 0.2f, Skill::PROGRAMMING_LANGUAGE));
            //databases
            skills->push_back(new Skill("MySQL", 0.7f, Skill::DATABASE));
            skills->push_back(new Skill("Microsoft SQL Server", 0.65f, Skill::DATABASE));
            //projects
            skills->push_back(new Skill("UML", 0.8f, Skill::PROJECT));
            skills->push_back(new Skill("Merise", 0.85f, Skill::PROJECT));
            skills->push_back(new Skill("SVN", 0.7f, Skill::PROJECT));
            skills->push_back(new Skill("GIT", 0.6f, Skill::PROJECT));
            //knowledges
            skills->push_back(new Skill("3D temps réel", 0.75f, Skill::OTHER));
            skills->push_back(new Skill("Administration Serveur", 0.6f, Skill::OTHER));
            skills->push_back(new Skill("Ergonnomie", 0.4f, Skill::OTHER));
            skills->push_back(new Skill("Graphisme", 0.4f, Skill::OTHER));
        }

        sort(skills->begin(), skills->end(), skillCompareFunction);

        return this;
    }

    DavidBalan* DavidBalan::initExperiences()
    {
        vector<Experience*>* experiences = this->experiences();
        {
            experiences->push_back(new Experience(1409529600, time(0), "CYIM", "Rennes", "Analyste programmeur", Experience::UNDETERMINED));
            {
                string technologies[] = { "C#", "Javascript", "JQuery", "VB.Net", "ASP.Net", "SQL Server" };
                string tasks[] = { "Maintenance et mise à jour des sites web existants.", "Développement d’une application web de type SAAS visant à simplifier le processus de soumission scientifique." };
                experiences->push_back(new Experience(this->startingAt(), 1409443200, "CYIM", "Rennes", "Analyste programmeur", Experience::DETERMINED,
                 createVector<string>(technologies),
                 createVector<string>(tasks)));
            }
            {
                string technologies[] = { "PHP", "MySQL", "Javascript", "JQuery", "Apache" };
                string tasks[] = {"Développement d’une application internet permettant aux experts immobiliers de France de simplifier le processus de rédaction d’une expertise immobilière."};
                experiences->push_back(new Experience(1325376000, 1330387200, "SIT", "Rennes", "Analyste programmeur", Experience::STAGE,
                 createVector<string>(technologies),
                 createVector<string>(tasks)));
            }
            {
                string technologies[] = { "PHP", "MySQL", "Javascript", "JQuery", "Apache" };
                string tasks[] = {"Développement d’une application internet permettant la gestion des demandes clients, le suivi des dossiers."};
                experiences->push_back(new Experience(1309478400, 1314748800, "SIT", "Rennes", "Analyste programmeur", Experience::DETERMINED,
                 createVector<string>(technologies),
                 createVector<string>(tasks)));
            }
            {
                string technologies[] = { "PHP", "MySQL", "Javascript", "JQuery", "Apache" };
                string tasks[] = {"Développement d’une application internet permettant aux notaires d’Ille-et-Vilaine de répertorier les baux commerciaux."};
                experiences->push_back(new Experience(1304208000, 1309392000, "SIT", "Rennes", "Analyste programmeur", Experience::STAGE,
                 createVector<string>(technologies),
                 createVector<string>(tasks)));
            }
        }
        return this;
    }

    DavidBalan* DavidBalan::initPersonnalLinks()
    {
        vector<PersonnalLink*>* links = this->personnalLinks();
        {
            links->push_back(new PersonnalLink("http://www.balandavid.com", PersonnalLink::WEB_SITE));
            links->push_back(new PersonnalLink("contact [at] balandavid [dot] com", PersonnalLink::EMAIL));
            links->push_back(new PersonnalLink("@neopixel22", PersonnalLink::TWITTER));
        }

        return this;
    }

    DavidBalan::~DavidBalan()
    {}
}
