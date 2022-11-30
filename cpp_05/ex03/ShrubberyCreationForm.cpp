#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& string) :
		Form("Shrubberry Creation form", 145, 137), _target(string)
{}

ShrubberyCreationForm::ShrubberyCreationForm
		(const ShrubberyCreationForm &shrubbery) :
		Form(shrubbery.getName(), shrubbery.getGradeRequiredSign(),
			 shrubbery.getGradeRequiredExecute()), _target(shrubbery._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator =
		(const ShrubberyCreationForm& shrubbery) {
	if (this == &shrubbery)
		return (*this);
	this->_target = shrubbery._target;
	this->setsigned(shrubbery.getSigned());
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned())
		throw (Form::FormNotSigned());
	if (!this->verifCanExecute(executor))
		throw (Form::GradeTooLowException());
	const std::string g_trees[] =
			{
					"               ,@@@@@@@,",
					"       ,,,.   ,@@@@@@/@@,  .oo8888o.",
					"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o",
					"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'",
					"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'",
					"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'",
					"   `&%\\ ` /%&'    |.|        \\ '|8'",
					"       |o|        | |         | |",
					"       |.|        | |         | |",
					"     \\/ ._\\//_/__/  ,\\__//__\\/.  \\_//__/_"
			};
	std::string filename = _target + "_shrubbery";
	std::ofstream out(filename);

	if (out.fail())
	{
		std::cerr << "Filed to access " << filename << std::endl;
		return ;
	}
	for (int i = 0; i < 10; i++)
	{
		out << g_trees[i] << std::endl;
	}
	out.close();
}
