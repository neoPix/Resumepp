#include "main.h"

namespace rsm{
    Experience::Experience(unsigned int start, unsigned int end, string compagny, string where, string what, EXPERIENCE_TYPE type)
        :_start(start),_end(end),_compagny(compagny),_where(where),_what(what),_technologies(NULL),_tasks(NULL),_type(type)
    {}

    Experience::Experience(unsigned int start, unsigned int end, string compagny, string where, string what, EXPERIENCE_TYPE type, vector<string> *technologies, vector<string> *tasks)
        :_start(start),_end(end),_compagny(compagny),_where(where),_what(what),_technologies(technologies),_tasks(tasks),_type(type)
    {}

    vector<string>* Experience::technologies()
    {
        if(this->_technologies == NULL)
            this->_technologies = new vector<string>();
        return this->_technologies;
    }

    vector<string>* Experience::tasks()
    {
        if(this->_tasks == NULL)
            this->_tasks = new vector<string>();
        return this->_tasks;
    }

    Experience::~Experience()
    {
        if(this->_technologies != NULL)
            delete this->_technologies;
        if(this->_tasks != NULL)
            delete this->_tasks;
    }
}
