#ifndef _BUREAUCRAT_H_
# define _BUREAUCRAT_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const std::string& name);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();
		void		verifGrade();
		const std::string&	getName( void ) const;
		int			getGrade( void ) const;
		void		incrementGrade( void );
		void		decrementGrade( void );
		void		signForm(Form &form);
		void		executeForm(Form const &form);
		Bureaucrat &operator = (const Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what()const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what()const throw();
		};
	private:
		const std::string&	_name;
		int			_grade;
};

std::ostream& operator << (std::ostream& out, Bureaucrat const& bureaucrat);

#endif