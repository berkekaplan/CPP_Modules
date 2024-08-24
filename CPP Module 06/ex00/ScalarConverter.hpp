#pragma once

#include <iostream>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

#define IS_IN_INT_RANGE(value) ((value >= -2147483647 - 1) && (value <= 2147483647))

class ScalarConverter {
    private:
        ScalarConverter(void);
        ~ScalarConverter(void);
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter &operator=(const ScalarConverter& copy);
    public:
        static void convert(const std::string& arg);
        static int findType(const std::string& arg);
        static int checkPseudoLiteralsFloat(const std::string& arg);
        static int checkPseudoLiteralsDouble(const std::string& arg);
        static int isChar(const std::string& arg);
        static int isInt(const std::string &arg);
        static int isFloat(const std::string &arg);
        static int isDouble(const std::string &arg);
        static void printLiterals(const std::string &_char,
                                  const std::string &_int,
                                  const std::string _float,
                                  const std::string _double);
};
