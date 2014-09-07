#ifndef HTMLRESUME_H
#define HTMLRESUME_H

#include "DavidBalan.h"

namespace rsm{
    class HtmlResume
    {
        public:
            HtmlResume(DavidBalan *dbn);
            void generate();
        private:
            DavidBalan *_dbn;
    };
}

#endif // HTMLRESUME_H
