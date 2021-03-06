/**
 * Created by David Balan
 */

#include "main.h"
#include <iomanip>
#include <sstream>

namespace rsm{

    vector<string> commands;

    bool consoleHelp(DavidBalan *davidbalan)
    {
        cout << "Liste des commandes disponnibles : " << endl;
        for(vector<string>::iterator it = commands.begin(); it != commands.end(); ++it)
            cout << setw(20) << left << *it;
        cout << endl;
        return true;
    }

    bool consoleGetInfo(DavidBalan *davidbalan)
    {
        double experience = davidbalan->experience();
        int experienceY = experience, experienceM = (experience - experienceY) * 12;

        cout << davidbalan->firstname() << " " << davidbalan->lastname() << " est un " << davidbalan->job()
             << " de " << (int)davidbalan->age() << " ans avec " << experienceY << " années et " << experienceM << " mois d'experiences." << endl;

        cout << "Passionné de " << davidbalan->hobbies()->at(0)->name() << " et de " << davidbalan->hobbies()->at(1)->name()
             << " il est aussi tres compétent en " << davidbalan->skills()->at(0)->what() << ", " << davidbalan->skills()->at(1)->what()
             << " et " << davidbalan->skills()->at(2)->what() << "." << endl;

        return true;
    }

    bool consoleClose(DavidBalan *davidbalan)
    {
        cout << "fermeture de la console.";
        return false;
    }

    bool consoleJoke(DavidBalan *davidbalan)
    {
        cout << "1 - Je connais 10 blagues, celle-ci et l'autre."<<endl;
        cout << "2 - Pour comprendre la recurssivite, il faut avant tout comprendre la recurssivite."<<endl;
        return true;
    }

    bool consoleListHobbies(DavidBalan *davidbalan)
    {
        for(vector<Hobby*>::iterator it = davidbalan->hobbies()->begin(); it != davidbalan->hobbies()->end(); ++it)
            cout << setw(8) << right << "- " << (*it)->name() << endl;
        return true;
    }

    bool consoleListSkills(DavidBalan *davidbalan)
    {
        stringstream languages, databases, projects, others;
        for(vector<Skill*>::iterator it = davidbalan->skills()->begin(); it != davidbalan->skills()->end(); ++it)
            switch((*it)->kind())
            {
                case Skill::PROGRAMMING_LANGUAGE:
                    languages << setw(8) << right << "- " << (*it)->what() << endl;
                    break;
                case Skill::DATABASE:
                    databases << setw(8) << right << "- " << (*it)->what() << endl;
                    break;
                case Skill::PROJECT:
                    projects << setw(8) << right << "- " << (*it)->what() << endl;
                    break;
                case Skill::OTHER:
                    others << setw(8) << right << "- " << (*it)->what() << endl;
                    break;
            }
            cout << "  Languages de programmation : " << endl << languages.str();
            cout << "  Bases de données : " << endl << databases.str();
            cout << "  Gestion de projet : " << endl << projects.str();
            cout << "  Divers : " << endl << others.str();
        return true;
    }

    bool consoleWhereAmI(DavidBalan *davidbalan)
    {
        cout << "il y a 99,999999999999999999% de chances que votre localisation soit :" << endl
             << "\"Voie lactée, Système solaire, Terre\"" << endl
             << "Si vous faites partie des 0.000000000000000001% restant, veuillez me contacter." << endl;
        return true;
    }

    bool consoleListLinks(DavidBalan *davidbalan)
    {
        for(vector<PersonnalLink*>::iterator it = davidbalan->personnalLinks()->begin(); it != davidbalan->personnalLinks()->end(); ++it)
            cout << setw(8) << right << "- " << (*it)->value() << endl;
        return true;
    }

    bool consoleListTrainnings(DavidBalan *davidbalan)
    {
        for(vector<Training*>::iterator it = davidbalan->trainings()->begin(); it != davidbalan->trainings()->end(); ++it)
        {
            cout << setw(4) << right << " - " << setw(5) << left << (*it)->year() << (*it)->what() << endl;
            cout << setw(8) << right << "" << (*it)->school() << " - " << (*it)->where() << endl;
        }
        return true;
    }

    bool consoleListExperiences(DavidBalan *davidbalan)
    {
        for(vector<Experience*>::iterator it = davidbalan->experiences()->begin(); it != davidbalan->experiences()->end(); ++it)
        {
            string type = "";
            switch((*it)->type())
            {
                case Experience::STAGE:
                    type = "Stage";
                    break;
                 case Experience::DETERMINED:
                    type = "CDD";
                    break;
                case Experience::UNDETERMINED:
                    type = "CDI";
                    break;
            }
            cout << setw(4) << right << " - " << setw(5) << left << (*it)->compagny() << "   " << (*it)->where() << "  " << (*it)->what() << " " << type << endl;
            for(vector<string>::iterator iti = (*it)->tasks()->begin(); iti != (*it)->tasks()->end(); ++iti)
                cout << setw(8) << right << " - " << *iti << endl;
            cout << "    ";
            for(vector<string>::iterator iti = (*it)->technologies()->begin(); iti != (*it)->technologies()->end(); ++iti)
                cout << setw(4) << right << "" << *iti;
            cout<<endl;
        }
        return true;
    }

    bool consoleGetResume(DavidBalan *davidbalan)
    {
        double experience = davidbalan->experience();
        int experienceY = experience, experienceM = (experience - experienceY) * 12;

        cout << davidbalan->firstname() << " " << davidbalan->lastname() << endl;
        cout << (int)davidbalan->age() << " ans" << endl;
        cout << experienceY << " ans et " << experienceM << " mois d'experience." << endl;
        cout << setfill('*') << setw(30) << '*' << endl << setfill(' ');
        cout << " Formation" << endl;
        consoleListTrainnings(davidbalan);
        cout << setfill('*') << setw(30) << '*' << endl << setfill(' ');
        cout << " Expériences" << endl;
        consoleListExperiences(davidbalan);
        cout << setfill('*') << setw(30) << '*' << endl << setfill(' ');
        cout << " Compétences" << endl;
        consoleListSkills(davidbalan);
        cout << setfill('*') << setw(30) << '*' << endl << setfill(' ');
        cout << " Occupations" << endl;
        consoleListHobbies(davidbalan);
        return true;
    }

    bool consoleGenerateHtml(DavidBalan *davidbalan)
    {
        HtmlResume rsm(davidbalan);
        rsm.generate();
        return true;
    }

    Console::Console()
    {
        this->_davidbalan = new DavidBalan();
        this->_functions = new map<string, bool (*)(DavidBalan *davidbalan)>();

        (*this->_functions)["info"] = &consoleGetInfo;
        (*this->_functions)["resume"] = &consoleGetResume;
        (*this->_functions)["training"] = &consoleListTrainnings;
        (*this->_functions)["hobbies"] = &consoleListHobbies;
        (*this->_functions)["skills"] = &consoleListSkills;
        (*this->_functions)["links"] = &consoleListLinks;
        (*this->_functions)["joke"] = &consoleJoke;
        (*this->_functions)["help"] = &consoleHelp;
        (*this->_functions)["ls"] = &consoleHelp;
        (*this->_functions)["exit"] = &consoleClose;
        (*this->_functions)["whereami"] = &consoleWhereAmI;
        (*this->_functions)["experiences"] = &consoleListExperiences;
        (*this->_functions)["html"] = &consoleGenerateHtml;

        for(map<string,bool (*)(DavidBalan *davidbalan)>::iterator it = this->_functions->begin(); it != this->_functions->end(); ++it)
          commands.push_back(it->first);
    }

    Console::~Console()
    {
        delete this->_davidbalan;
        delete this->_functions;
    }

    void Console::start()
    {
        bool goOn = true;
        string input;
        do
        {
            cout << "cv/David Balan> ";
            getline(cin, input);
            goOn = this->manageCommand(input);
        }while(goOn);
    }

    bool Console::manageCommand(string command)
    {
        if(!command.compare(""))
            return true;
        else if(this->_functions->count(command)==1)
            return (*this->_functions)[command](this->_davidbalan);
        else
        {
            cout << "Commande inconnue."<<endl<<"tappez help pour obtenir la liste des commandes disponnibles"<<endl;
            return true;
        }
    }
}
