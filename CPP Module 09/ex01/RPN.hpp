#ifndef RPN_HPP
 #define RPN_HPP
 
# include <iostream>
# include <stack>

class RPN{

private:
	static std::string					_input;
	static std::string					_allowedChars;
	static std::string					_allowedOperators;
	static std::stack<int>				_arr;

public:

	static void						checkArg( int argc, char **argv );
	static void						checkvalue(void);
	static void						setContesetContainer(void);
	static void						printRPN(void);
	class NotEnoughtInputs : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ("Error: not enought inputs!");
			}
	};

	class TooManyInputs : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ("Error: too many inputs!");
			}
	};

	class ContainsUnwantedChars : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ("Error: input contains disallowed characters!");
			}
	};

	class WrongInputs : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ("Error: wrong inputs!");
			}
	};
};

#endif
