#include "additionalfunctions.h"

AdditionalFunctions::AdditionalFunctions()
{

}

void AdditionalFunctions::removeWhiteSpace(std::string& w) {
    if(w.size() != 0) {
        w.replace(w.end() - 1, w.end(), "");
    }
}
