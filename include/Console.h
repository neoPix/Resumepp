/**
 * Created by David Balan
 */
#ifndef CONSOLE_H
#define CONSOLE_H

#include "DavidBalan.h"
#include <map>

namespace rsm{
    class Console
    {
        public:
            Console();
            virtual ~Console();
            void start();
        protected:
            bool manageCommand(string command);
        private:
            DavidBalan *_davidbalan;
            map<string, bool (*)(DavidBalan *davidbalan)> *_functions;
    };
}

#endif // CONSOLE_H
