#ifndef LIB_DEBUGGER_HPP
#define LIB_DEBUGGER_HPP

#include <vector>
#include <string>
#define debug printf("FUNC[%s] LINE[%d] \n", __func__, __LINE__);

namespace error
{
    class buffer
    {
        std::vector<std::string> errorBuffer;
        bool manualBuffering;

    public:
        void push(const std::string &err);
        void push(const char err[]);
        std::string getLast(void);
        std::string pop(int count);

        void dump();
        void printAll();
        void setManualBuffering(bool bufferingMode);
    };
}
#endif // LIB_DEBUGGER_HPP
