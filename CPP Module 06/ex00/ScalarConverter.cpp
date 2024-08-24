#include "ScalarConverter.hpp"
#include <cstdlib>

void ScalarConverter::convert(const std::string& arg)
{
    if (checkPseudoLiteralsFloat(arg) || checkPseudoLiteralsDouble(arg))
        return ;
    if (!findType(arg))
        printLiterals("impossible", "impossible", "impossible", "impossible");
}

int ScalarConverter::findType(const std::string& arg)
{
    if (isChar(arg))
        return 1;
    if (arg.find('.') != std::string::npos)
    {
        if (arg.find('.') == std::string::npos)
        {
            for (size_t i = 0; i < arg.size() ; ++i) {
                if ((i == 0 && (arg[0] == '+' && arg[0] == '-')) || (i == arg.size() - 1 && arg[i] == 'f'))
                    continue;
                else
                    continue;
            }
        }
        else
        {
            for (size_t i = 0; i < arg.find('.'); ++i) {
                if ((i == 0 && (arg[0] == '+' || arg[0] == '-')) || isdigit(arg[i]))
                    continue;
                else
                    return 0;
            }
            for (size_t i = arg.find('.') + 1; i < arg.size() ; ++i) {
                if ((i == 0 && (arg[0] == '+' && arg[0] == '-')) || (i == arg.size() - 1 && arg[i] == 'f'))
                    continue;
                else
                    continue;
            }
        }
        if ((isFloat(arg) || isDouble(arg)))
            return 1;
    }
    else if (isInt(arg))
        return 1;
    return 0;
}

int ScalarConverter::isDouble(const std::string& arg)
{
    double n = atof(arg.c_str());
    if (isascii(n))
    {
        if (isprint(n))
            std::cout << BLUE << "char: '" << static_cast<char>(n) << "'"  << RESET << std::endl;
        else
            std::cout << BLUE << "char: Non displayable" << RESET << std::endl;
    }
    else
        std::cout << BLUE << "char: impossible" << RESET << std::endl;
    long long tmp = n;
    if (IS_IN_INT_RANGE(tmp))
        std::cout << BLUE << "int: " << static_cast<int>(n) << RESET << std::endl;
    else
        std::cout << BLUE << "int: impossible" << RESET << std::endl;
    if (tmp - n != 0)
    {
        std::cout << BLUE << "float: " << static_cast<float>(n) << "f" << RESET << std::endl;
        std::cout << BLUE << "double: " << n << RESET << std::endl;
    }
    else
    {
        std::cout << BLUE << "float: " << static_cast<float>(n) << ".0f" << RESET << std::endl;
        std::cout << BLUE << "double: " << n << ".0" << RESET << std::endl;
    }
    return 1;
}

int ScalarConverter::isFloat(const std::string& arg)
{
    if (arg[arg.size() - 1] == 'f')
    {
        float n = atof(arg.c_str());
        if (isascii(n))
        {
            if (isprint(n))
                std::cout << YELLOW << "char: '" << static_cast<char>(n) << "'"  << RESET << std::endl;
            else
                std::cout << YELLOW << "char: Non displayable" << RESET << std::endl;
        }
        else
            std::cout << YELLOW << "char: impossible" << RESET << std::endl;
        long long tmp = n;
        if (IS_IN_INT_RANGE(tmp))
            std::cout << YELLOW << "int: " << static_cast<int>(n) << RESET << std::endl;
        else
            std::cout << YELLOW << "int: impossible" << RESET << std::endl;
        if (tmp - n != 0)
        {
            std::cout << YELLOW << "float: " << n << "f" << RESET << std::endl;
            std::cout << YELLOW << "double: " << static_cast<double>(n) << RESET << std::endl;
        }
        else
        {
            std::cout << YELLOW << "float: " << n << ".0f" << RESET << std::endl;
            std::cout << YELLOW << "double: " << static_cast<double>(n) << ".0" << RESET << std::endl;
        }
        return 1;
    }
    return 0;
}

int ScalarConverter::isInt(const std::string& arg)
{
    for (size_t i = 0; i < arg.size(); ++i) {
        if (isdigit(arg[i]) || (arg[0] == '+' || arg[0] == '-'))
        {
            if (i != 0)
                continue;
        }
        else
            return 0;
    }
    if (IS_IN_INT_RANGE(atoll(arg.c_str())))
    {
        int n = atoi(arg.c_str());
        if (isascii(n))
        {
            if (isprint(n))
                std::cout << GREEN << "char: '" << static_cast<char>(n) << "'"  << RESET << std::endl;
            else
                std::cout << GREEN << "char: Non displayable" << RESET << std::endl;
        }
        else
            std::cout << GREEN << "char: impossible" << RESET << std::endl;
        std::cout << GREEN << "int: " << n << RESET << std::endl;
        std::cout << GREEN << "float: " << static_cast<float>(n) << ".0f" << RESET << std::endl;
        std::cout << GREEN << "double: " << static_cast<double>(n) << ".0" << RESET << std::endl;
        return 1;
    }
    return 0;
}

int ScalarConverter::isChar(const std::string& arg)
{
    if (arg.size() == 1 && isascii(arg[0]) && !isdigit(arg[0]))
    {
        char a = arg[0];
        std::cout << RED << "char: '" << a << "'" << RESET << std::endl;
        std::cout << RED << "int: " << static_cast<int>(a) << RESET << std::endl;
        std::cout << RED << "float: " << static_cast<float>(a) << ".0f" << RESET << std::endl;
        std::cout << RED << "double: " << static_cast<double>(a) << ".0" << RESET << std::endl;
        return 1;
    }
    return 0;
}

int ScalarConverter::checkPseudoLiteralsFloat(const std::string &arg)
{
    if (arg == "-inff" || arg == "+inff" || arg == "inff" || arg == "nanf")
    {
        printLiterals("impossible", "impossible", arg, arg.substr(0, arg.size() - 1));
        return 1;
    }
    return 0;
}

int ScalarConverter::checkPseudoLiteralsDouble(const std::string &arg)
{
    if (arg == "-inf" || arg == "+inf" || arg == "inf" || arg == "nan")
    {
        printLiterals("impossible", "impossible", arg + "f", arg);
        return 1;
    }
    return 0;
}

void ScalarConverter::printLiterals(const std::string &_char,
                                  const std::string &_int,
                                  const std::string _float,
                                  const std::string _double)
{
    std::cout << RED << "char: " << _char << std::endl;
    std::cout << GREEN << "int: " << _int << std::endl;
    std::cout << YELLOW << "float: " << _float << std::endl;
    std::cout << BLUE  << "double: " << _double << std::endl;
}
