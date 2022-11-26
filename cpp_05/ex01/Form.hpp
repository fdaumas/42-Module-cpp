#ifndef _FORM_H_
# define _FORM_H_

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(const std::string name, const int gradesigned
			, const int gradeexecute);
		Form(const Form &form);
		~Form();
		Form& operator = (const Form& form);
		void verifConstructor();
		void verifCanSigned(const Bureaucrat& bureaucrat);
		void beSigned(const Bureaucrat& bureaucrat);
		bool getSigned() const;
		std::string getName() const;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
	private:
		const std::string _name;
		bool _signed;
		const int _gradeSigned;
		const int _gradeExecute;
};

std::ostream& operator << (std::ostream& out, Form const& form);

#endif