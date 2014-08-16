#ifndef HOBBY_H
#define HOBBY_H

#include<iostream>
using namespace std;
namespace rsm{
    class Hobby
    {
        public:
            Hobby();
            Hobby(string name);
            string name(){ return this->_name; }
            void name(string val) { this->_name = val; }
        protected:
        private:
            string _name;
    };
}

#endif // HOBBY_H
