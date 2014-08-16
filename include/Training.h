/**
 * Created by David Balan
 */

#ifndef TRAINING_H
#define TRAINING_H

#include<iostream>
using namespace std;
namespace rsm{
    class Training
    {
        public:
            Training(unsigned int year, string where, string what, string school);
            unsigned int year(){return this->_year;}
            Training* year(unsigned int val){this->_year = val; return this;}
            string where(){return this->_where;}
            Training* where(string val){this->_where = val; return this;}
            string what(){return this->_what;}
            Training* what(string val){this->_what = val; return this;}
            string school(){return this->_school;}
            Training* school(string val){this->_school = val; return this;}
        protected:
        private:
            unsigned int _year;
            string _where, _what, _school;
    };
}

#endif // TRAINING_H
