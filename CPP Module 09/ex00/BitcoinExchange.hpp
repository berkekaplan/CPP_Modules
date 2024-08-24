#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP
/*-----------color------------------*/
# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define END		"\033[m"
# define RESET		"\033[0m"
/*----------------------------------*/
# include <iostream>
# include <map>
# include <fstream>


class Bitcoin
{

private:
	static std::string						_input;
	static std::map<std::string, double>	_data;

public:
	static void			checkArg( int index, char **str );
	static void			checkFile( std::string variable);
	static void			setContainer_data(void);
	static bool			DateCheck(std::string date);
	static bool 		checkvalue(std::string date);
	static void 		error_w(std::string str, std::string str2);
	static double		setContainer_calculate(std::string date);

	class NotEnoughtInputs : public std::exception
	{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "Error: not enought inputs!" END );
			}
	};

	class TooLargeNumber : public std::exception
	{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "Error: could not open file." END );
			}
	};

	class FileDoesNotExist : public std::exception
	{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "Error: file doesn't exist!" END );
			}
	};

	class EnteredValuesAreIncorrect : public std::exception
	{
		public:
			virtual const char *what(void) const throw()
			{
				return ( RED "Error: Input File Entered Values Are Incorrect." END );
			}
	};

	class EnteredValuesAreIncorrectData : public std::exception
	{
		public:
			virtual const char *what(void) const throw()
			{
				return ( RED "Error: Date File Entered Values Are Incorrect." END );
			}
	};
};
#endif
