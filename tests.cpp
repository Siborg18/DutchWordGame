#include "DutchWordGame.h"

int tests()
{
bool gameIsOn {true};
bool saveFile{true};

assert(2+2==4);
assert(userKnowsWord("ik", "is", "yes", gameIsOn, saveFile) == true);

return 0;
}