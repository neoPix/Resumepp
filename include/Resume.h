/**
 * Created by David Balan
 */

#ifndef RESUME_H
#define RESUME_H

#include<iostream>
#include<vector>
#include "Training.h"
#include "Hobby.h"
#include "Skill.h"
#include "PersonnalLink.h"
#include "Experience.h"
using namespace std;

namespace rsm{
    class Resume
    {
        public:
            Resume(string firstname, string lastname);
            ~Resume();
            string job() { return _job; }
            Resume* job(string val) { _job = val; return this; }
            string firstname() { return _firstname; }
            string lastname() { return _lastname; }
            unsigned int birth() { return _birth; }
            Resume* birth(unsigned int val) { _birth = val; return this; }
            unsigned int startingAt() { return _startingAt; }
            Resume* startingAt(unsigned int val) { _startingAt = val; return this; }
            vector<Hobby*>* hobbies();
            vector<Skill*>* skills();
            vector<PersonnalLink*>* personnalLinks();
            vector<Training*>* trainings();
            vector<Experience*>* experiences();

            double age();
            double experience();
        protected:
            string _job, _firstname, _lastname;
            unsigned int _birth;
            unsigned int _startingAt;
            vector<Hobby*>* _hobbies;
            vector<Skill*>* _skills;
            vector<PersonnalLink*>* _personnalLinks;
            vector<Training*>* _trainings;
            vector<Experience*>* _experiences;
        private:

    };
}

#endif // RESUME_H
