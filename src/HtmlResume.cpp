#include "main.h"
#include <fstream>
#include <sstream>

namespace rsm{
    HtmlResume::HtmlResume(DavidBalan *dbn) : _dbn(dbn)
    {}

    void HtmlResume::generate()
    {
        ofstream myfile;
        myfile.open ("resume.html");
        myfile << "<html><head><meta charset=\"utf-8\"><link rel=\"stylesheet\" type=\"text/css\" href=\"data/style.css\" /><title>" << this->_dbn->firstname() << " " << this->_dbn->lastname() << "</title></head><body>";
        //general informations
        myfile << "<div class=\"general\"><span class=\"firstname\">"<<this->_dbn->firstname()<<"</span><span class=\"lastname\">"<<this->_dbn->lastname()<<"</span><span class=\"age\">"<<(int)this->_dbn->age()<<" ans</span></div>";
        // link informations
        {
            myfile << "<div class=\"links\"><ul>";
            for(vector<PersonnalLink*>::iterator it = this->_dbn->personnalLinks()->begin(); it != this->_dbn->personnalLinks()->end(); ++it)
                myfile << "<li class=\"type_"<< (*it)->type() << "\">" << (*it)->value() << "</li>";
            myfile << "</ul></div>";
        }
        //skills informations
        {
            myfile << "<div class=\"skills\"><h2>Compétences</h2><ol>";
            stringstream languages, databases, projects, others;
            for(vector<Skill*>::iterator it = this->_dbn->skills()->begin(); it != this->_dbn->skills()->end(); ++it)
                switch((*it)->kind())
                {
                    case Skill::PROGRAMMING_LANGUAGE:
                        languages << "<li>" << (*it)->what() << "</li>";
                        break;
                    case Skill::DATABASE:
                        databases << "<li>" << (*it)->what() << "</li>";
                        break;
                    case Skill::PROJECT:
                        projects << "<li>" << (*it)->what() << "</li>";
                        break;
                    case Skill::OTHER:
                        others << "<li>" << (*it)->what() << "</li>";
                        break;
                }

            myfile << "<li class=\"programminglanguages\">Languages de programmation : <ul>"<< languages.str() << "</ul></li>";
            myfile << "<li class=\"databases\">Bases de données : <ul>"<< databases.str() << "</ul></li>";
            myfile << "<li class=\"projects\">Gestion de projet : <ul>"<< projects.str() << "</ul></li>";
            myfile << "<li class=\"misc\">Divers : <ul>"<< others.str() << "</ul></li>";
            myfile << "</ol></div>";
        }
        // experences informations
        {
            myfile << "<div class=\"experiences\"><h2>Expériences</h2><ol>";
            for(vector<Experience*>::iterator it = this->_dbn->experiences()->begin(); it != this->_dbn->experiences()->end(); ++it)
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
                myfile << "<li><span class=\"compagny\">" << (*it)->compagny() << "</span><span class=\"where\">" << (*it)->where() << "</span><span class=\"what\">" << (*it)->what() << "</span><span class=\"type\">" << type << "</span><ol class=\"tasks\">";
                for(vector<string>::iterator iti = (*it)->tasks()->begin(); iti != (*it)->tasks()->end(); ++iti)
                    myfile << "<li>"<< *iti << "</li>";
                myfile << "</ol><ol class=\"technologies\">";
                for(vector<string>::iterator iti = (*it)->technologies()->begin(); iti != (*it)->technologies()->end(); ++iti)
                    myfile << "<li>" << *iti << "</li>";
                myfile<<"</ol></li>";
            }
            myfile << "</ol></div>";
        }
        // training informations
        {
            myfile << "<div class=\"trainning\"><h2>Formations</h2><ol>";
            for(vector<Training*>::iterator it = this->_dbn->trainings()->begin(); it != this->_dbn->trainings()->end(); ++it)
            {
                myfile << "<li><span class=\"year\">" << (*it)->year() << "</span><span class=\"what\">" << (*it)->what() << "</span>";
                myfile << "<span class=\"school\">" << (*it)->school() << "</span><span class=\"where\">" << (*it)->where() << "<span></li>";
            }
            myfile << "</ol></div>";
        }
        // hobbies informations
        {
            myfile << "<div class=\"hobies\"><h2>Occupations</h2><ol>";
            for(vector<Hobby*>::iterator it = this->_dbn->hobbies()->begin(); it != this->_dbn->hobbies()->end(); ++it)
                myfile << "<li>" << (*it)->name() << "</li>";
            myfile << "</ol></div>";
        }
        myfile << "</body></html>";
        myfile.close();
    }
}
