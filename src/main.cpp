#include "../include/main.h"

using namespace std;
using namespace rsm;

int main()
{
    Console *c = new Console();
    c->start();
    delete c;
}
