#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm(target, 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!AForm::isSigned())
	{
		throw AForm::NotSignedException();
	}
	else if (executor.getGrade() > AForm::getExecutableGrade())
	{
		throw AForm::GradeTooHighException();
	}
	const std::string filename = AForm::getName() + "_shrubbery";

	std::ofstream outFile(filename);
	if (!outFile)
	{
		std::cerr << "Error: can't open " << filename << std::endl;
		return ;
	}
	outFile << this->ASCII_BONSAI;
	outFile.close();
	std::cout << GREEN << filename << " is created." << DEFAULT << std::endl;
}

const std::string ShrubberyCreationForm::ASCII_BONSAI =
        "       ,,,\n"
        "      MMMM_    ,..,\n"
        "        \"_ \\\"__\\\"MMMMM          ,...,\n"
        " ,..., __.\\\" --\\\"    ,.,     _-\\\"MMMMMMM\n"
        "MMMMMM\\\"___ \\\"_._   MMM\\\".\\\"\" _ \\\"\\\"\\\"\\\"\\\"\\\"\n"
        " \\\"\\\"\\\"\\\"\\\"    \\\"\\\" , \\_.   \\\"_. .\\\"\n"
        "        ,., _\\\"__ \\__./ .\\\"\n"
        "       MMMMM_\\\"_  \\\"_    ./\n"
        "        ''''      (    )\n"
        " ._______________.-'____\\\"---._.\n"
        "  \\                          /\n"
        "   \\________________________/\n"
        "   (_)                    (_)\n";
