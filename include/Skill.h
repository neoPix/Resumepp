#ifndef SKILL_H
#define SKILL_H

#include<iostream>
using namespace std;
namespace rsm{
    class Skill
    {
        public:
            enum SKILL_KIND {
                PROGRAMMING_LANGUAGE,
                DATABASE,
                PROJECT,
                OTHER
            };

            Skill(string what, float level, SKILL_KIND kind);
            string what() { return this->_what; }
            Skill* what(string val) { this->_what = val; return this; }
            float level() { return this->_level; }
            Skill* level(float val) { this->_level = val; return this; }
            SKILL_KIND kind() { return this->_kind; }
            Skill* kind(SKILL_KIND val) { this->_kind = val; return this; }

            bool operator< (Skill &other) { return (this->_level < other.level());}
        protected:
        private:
            string _what;
            float _level;
            SKILL_KIND _kind;
    };
}

#endif // SKILL_H
