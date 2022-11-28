#ifndef _ROBOTOMYREQUESTFORM_H_
# define _ROBOTOMYREQUESTFORM_H_

#include "Form.hpp"

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm(const std::string& string);
		RobotomyRequestForm(const RobotomyRequestForm& robotomy);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator =
				(const RobotomyRequestForm& presidential);
		void execute(Bureaucrat const &executor) const;
	private:
		std::string _target;
};

#endif
