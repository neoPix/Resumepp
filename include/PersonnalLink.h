/**
 * Created by David Balan
 */

#ifndef PERSONNALLINK_H
#define PERSONNALLINK_H

#include<iostream>
using namespace std;
namespace rsm{
    class PersonnalLink
    {
        public:
            enum PERSONNALLINK_TYPE{
                WEB_SITE,
                TWITTER,
                EMAIL
            };
            PersonnalLink(string value, PERSONNALLINK_TYPE type);
            string value() { return this->_value; }
            PersonnalLink* value(string value) { this->_value = value; return this; }
            PERSONNALLINK_TYPE type() { return this->_type; }
            PersonnalLink* value(PERSONNALLINK_TYPE value) { this->_type = value; return this; }
        protected:
        private:
            string _value;
            PERSONNALLINK_TYPE _type;
    };
}

#endif // PERSONNALLINK_H
