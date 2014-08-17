#ifndef EXPERIENCE_H
#define EXPERIENCE_H


#include<iostream>
#include<vector>
using namespace std;
namespace rsm{
    class Experience
    {
        public:
            enum EXPERIENCE_TYPE{
                STAGE,
                DETERMINED,
                UNDETERMINED
            };

            Experience(unsigned int start, unsigned int end, string compagny, string where, string what, EXPERIENCE_TYPE type);
            Experience(unsigned int start, unsigned int end, string compagny, string where, string what, EXPERIENCE_TYPE type, vector<string> *technologies, vector<string> *tasks);
            virtual ~Experience();

            unsigned int start() { return this->_start; }
            Experience* start(unsigned int value) { this->_start = value; return this; }
            unsigned int end() { return this->_end; }
            Experience* end(unsigned int value) { this->_end = value; return this; }
            string compagny() { return this->_compagny; }
            Experience* compagny(string value) { this->_compagny = value; return this; }
            string where() { return this->_where; }
            Experience* where(string value) { this->_where = value; return this; }
            string what() { return this->_what; }
            Experience* what(string value) { this->_what = value; return this; }
            vector<string>* technologies();
            vector<string>* tasks();
            EXPERIENCE_TYPE type() { return this->_type; }
            Experience* type(EXPERIENCE_TYPE value) { this->_type = value; return this; }
        protected:
        private:
            unsigned int _start, _end;
            string _compagny, _where, _what;
            vector<string> *_technologies, *_tasks;
            EXPERIENCE_TYPE _type;
    };
}

#endif // EXPERIENCE_H
