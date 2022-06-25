#include "lib/debugger.hpp"

#include <iostream>

void error::buffer::push(const std::string &err)
{
    errorBuffer.push_back(err);
}

void error::buffer::push(const char err[])
{
    errorBuffer.push_back((std::string)err);
}

std::string error::buffer::getLast(void)
{
    return errorBuffer.back();
}

/* Remove the last element (also print error?)
 *
 */
std::string error::buffer::pop(int count)
{
    std::string ret = errorBuffer.back();
    errorBuffer.pop_back();
    return ret;
}

/* Empty the error buffer 
 *
 */
void error::buffer::dump()
{
    printAll();
    errorBuffer.erase(errorBuffer.begin(), errorBuffer.end());
}

/* Print all errors stored
 *
 */
void error::buffer::printAll()
{
    std::cout << "Errors:" << errorBuffer.size() << std::endl;
    for (std::string str : errorBuffer)
    {
        std::cout << str << std::endl;
    }
}

/* Choose between printing the errors as soon as they appear 
 * or to store them until the user manually decides to print them (using printAll)
 */
void error::buffer::setManualBuffering(bool bufferingMode)
{
    this->manualBuffering = bufferingMode;
}