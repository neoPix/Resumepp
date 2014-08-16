/**
 * Created by David Balan
 */
#ifndef DAVIDBALAN_H
#define DAVIDBALAN_H

#include <Resume.h>

namespace rsm{
    class DavidBalan : public Resume
    {
        public:
            DavidBalan();
            virtual ~DavidBalan();
        protected:
            DavidBalan* initTrainings();
            DavidBalan* initHobbies();
            DavidBalan* initSkills();
            DavidBalan* initPersonnalLinks();
        private:
    };
}

#endif // DAVIDBALAN_H
