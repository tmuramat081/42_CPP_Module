#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm(target, 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!AForm::isSigned())
	{
		return ;
	}
	else if (executor.getGrade() > AForm::getExecutableGrade())
	{
		return ;
	}
	const std::string filename = AForm::getName() + "_shrubbery";

	std::ofstream outFile(filename);
	if (!outFile)
	{
		std::cerr << "Error: can't open " << filename << std::endl;
		return ;
	}
	outFile << this->ASCII_TREE;
	outFile.close();
}

const std::string ShrubberyCreationForm::ASCII_TREE = "...........`....`...`...`...`...`...`...`.......................................\r\n.....`..`...`.`..`.`.`.`.``.`.``.```.``.`.```.``.``.`.`.........................\r\n...`...`.`.....`..`...`..`.`.`.`.`..``.`.`.`.`.`..`..`.`.`.`.`..`...............\r\n....`...`.``.`..`.``.``.`.`.``.``.``.``.```.```.``.``..`.`..`.....`..`..`.......\r\n..`..`..`..`.```.`.``.``````````````````````.````.``.``.`.``..``...`............\r\n.`.`.```.``.`.`````.```.````.``.```````````````````````````.``.``.`..`..........\r\n.`.`..`.``.````.`````````````````````````````````````.``.````.``.``.`.``.`......\r\n`.`.````.`````````````````````````````````````````````````.````.``.``.`.`.`.....\r\n`.``.``````.`````````````````````````````````````````````````````.``.`.`..``....\r\n``````.```````````````````````` `` ` `         ```````````````.````.``.``..`.``.\r\n.``.````````````````````` ``      ....((wwAkVUI+((..  ```````````````.`.``..`...\r\n`````````````````````` ` `  ` .(1zdwrZ0XY1odWkWHHXZwXXn... ````````.````.``.`.`.\r\n`.`````````````````` `` ``  `(+z111w2jIjwXWKzOOwXXHWkWWWdkS```````````.``.``...`\r\n``.`````````````````` ``   .jC1j21XWUy+wdXV+uwAdWXkZrXHHNQc` ````.``.`.`.`..`...\r\n```.``.``````````` ``` `  (OxzzUWSZUOVWXydSodWWHHHHkHWWWWHkd<````````.``.``.``..\r\n.````.``````````````` ` .(<uJZzZZZ9zdWHkXHHSWVWBdkHMWHKWWHHHD ````````.``..`..`.\r\n>.```````````````` `` .(dz1vuUAyv3jgAWHVVzUAH0XWHSwXXkdWWMHHe.........`.``.`...(\r\nI``.` ...```` ......,` ?vzAVwwCzwwddUSzwuAKHNWWQHwXMWHHdWWHHHWk0kAHHkOVwky&+.(Ow\r\nM8+++JwwXWSUI-O0XUdHHR->zOIJOC+wW0ZWmzjHkWHHMMNMMHHHHHMMHMHHwWAdWkHgHfywKWXXXOdk\r\nNMNywwwWk9ZOZwGWyXXWHqWkvI+jdwZOwzWkXUH0XSdWHMMXWHHMMNNWMgHHkdWWH@@HMMkWKkWNHHWM\r\nMNMHmkmQkQVkwWWHHVWHHHmH9+1zXU3XX9WHUdkXWHHMMHkHMMMMHHHg@HHHHWHHMHfWMMMMHHUWkWWU\r\nYM#Y\"YT\"B\"WBU9YWMMTMW96OIOXUkv1OdWXYHSvOVSWHH9WH7TUMHHHHHgHh(.(+wzjzrI<(((((<<<<\r\n<<<<88<?<?<?<<88<<<~~~<<<<<<<<<<<<<<<~_~~~(WD_~~~~_~~~~_~_~~~~_~~~~~~~~~~~~~:~~:\r\n~~~~~~~~~~~~~~~~<~<<<<<<<<<<<<<<<<<<?<88<<88<?77777777<<<<<<<<<<<<<<<<<<<<<<~<<~\r\n::::<<:<<~~~:~:~<<~~~~~~~~~_~~__~~~~~_~..._~.~.~~.~~_.._.~__~..~_____..~~.__~~~~\r\n(--(((((((-((-(-(+(<+<;;::<~~::~~____~~~~~~_~___~<<~<<<<~~~~~~~~~~_~~__~~~_~_~_:\r\n___~____~_~___~~~~~~~~~~~~~~~~_~~~~~~~~~~_~~~~~_~~~~~~_____~~::~<<<<<<<<<<<<<<<<";
