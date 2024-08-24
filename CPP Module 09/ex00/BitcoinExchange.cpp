#include "BitcoinExchange.hpp"

std::string			Bitcoin::_input;
std::map<std::string, double>	Bitcoin::_data;

void	Bitcoin::checkArg(int ac, char **av)
{
	if(ac > 2)
		throw(NotEnoughtInputs());
	else if(ac < 2)
		throw(TooLargeNumber());
	Bitcoin::checkFile(av[1]);
}

void Bitcoin::error_w(std::string str, std::string str2)
{
	if(str2 != "NULL")
		std::cerr << RED << str << str2 << END << std::endl;
	else
		std::cerr << RED << str << END << std::endl;
}

bool Bitcoin::DateCheck(std::string date)
{
	size_t pos1;
	size_t pos2;
	std::string date_day;
	std::string date_month;
	std::string date_year;

	pos1 = date.find("-");
    date_year = date.substr(0, pos1);
    pos2 = date.find("-", pos1 + 1);
    date_month = date.substr(pos1 + 1, pos2 - pos1 - 1);
    date_day = date.substr(pos2 + 1);
	if(date_year.length() == 4 || date_month.length() == 2 || date_day.length() == 2)
	{
		if(std::atoi(date_year.c_str()) <= 2008)
			error_w("Error: bad input => ", date);
		else if(std::atoi(date_month.c_str()) > 12 || std::atoi(date_month.c_str()) < 1)
			error_w("Error: bad input => *", date);
		else if(std::atoi(date_day.c_str()) > 31 || std::atoi(date_day.c_str()) < 1)
			error_w("Error: bad input => ", date);
		else if(std::atoi(date_year.c_str()) == 2009 && std::atoi(date_month.c_str()) == 1 && std::atoi(date_day.c_str()) == 1)
			error_w("Error: bad input => ", date);
		else if(std::atoi(date_year.c_str()) > 2022)
			error_w("Error: bad input => ", date);
		else
			return (true);
		return (false);
	}
	else
		return (false);

}

void Bitcoin::checkFile(std::string av)
{
	std::ifstream read;
	size_t delimiterPos;
	std::string date;
	std::string tmp_btc_value;

	Bitcoin::setContainer_data();

	read.open(av.c_str());
	if(!read.is_open())
	{
		throw(FileDoesNotExist());
	}
	_input = av;
	getline(read, av);
	if(av.compare("date | value"))
	{
		error_w("Error: at the beginning of the file should be 'date | value'", "NULL");
		return ;
	}
	while (getline(read, av))
	{
		delimiterPos = av.find("|");
		date = av.substr(0, delimiterPos);
		delimiterPos = date.find(" ");
		date = date.substr(0,delimiterPos);
		delimiterPos = av.find("|");
		if(delimiterPos == std::string::npos)
		{
			error_w("Error: bad input => ", date);
			continue;
		}
		tmp_btc_value = av.substr(delimiterPos, av.length());
		delimiterPos = tmp_btc_value.find(" ") + 1;
		tmp_btc_value = tmp_btc_value.substr(delimiterPos, tmp_btc_value.length());
		if(Bitcoin::DateCheck(date) == false)
			continue;
		if(!tmp_btc_value.compare("|"))
		{
			error_w("Error: Input File Entered Values Are Incorrect.", "NULL");
			continue;
		}
		if(std::strtod(tmp_btc_value.c_str(), NULL) < 0)
		{
			error_w("Error: not a positive number.", "NULL");
			continue;
		}
		if(Bitcoin::setContainer_calculate(date) * std::strtod(tmp_btc_value.c_str(), NULL) > INT_MAX)
		{
			error_w("Error: too large a number.", "NULL");
			continue;
		}
		if(Bitcoin::checkvalue(date) == false)
			continue;
		std::cout << date << " => " << tmp_btc_value << " = "<< std::ends;
		std::cout << Bitcoin::setContainer_calculate(date) * std::strtod(tmp_btc_value.c_str(), NULL) << std::endl;
		continue;
	}
	read.close();
}

void Bitcoin::setContainer_data(void)
{
	std::ifstream file("data.csv");
	if(!file)
		throw(EnteredValuesAreIncorrect());
	std::string line;
	std::string date;
	std::string tmp_btc_value;
	double btc_value;
	size_t delimiterPos;

	getline(file,line);
	while(getline(file, line))
	{
		delimiterPos = line.find(",");
		if(delimiterPos == std::string::npos)
			throw(EnteredValuesAreIncorrect());
		date = line.substr(0,delimiterPos);
		tmp_btc_value = line.substr(delimiterPos+1, line.length());
		btc_value = std::strtod(tmp_btc_value.c_str(), NULL);
		_data[date] = btc_value;
	}
	file.close();
}

bool Bitcoin::checkvalue(std::string date)
{
	std::map<std::string, double>::iterator m;
	m = Bitcoin::_data.find(date);
	if(m == Bitcoin::_data.end())
	{
		m = Bitcoin::_data.upper_bound(date);
	}
	return (true);
}

double Bitcoin::setContainer_calculate(std::string date)
{
	std::map<std::string, double>::iterator m;
	int i = 0;
	m = Bitcoin::_data.find(date);
	if(m == Bitcoin::_data.end())
		m = --Bitcoin::_data.upper_bound(date);
	i++;
	return (m->second);
}
