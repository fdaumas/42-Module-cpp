#ifndef _FORM_H_
# define _FORM_H_

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(const std::string name, const int gradesigned
			, const int gradeexecute);
		Form(const Form &form);
		virtual ~Form();
		Form& operator = (const Form& form);
		void verifConstructor();
		void verifCanSigned(const Bureaucrat& bureaucrat);
		bool verifCanExecute(const Bureaucrat& bureaucrat) const;
		void beSigned(const Bureaucrat& bureaucrat);
		bool getSigned() const;
		void setsigned(bool signe);
		int getGradeRequiredSign() const ;
		int getGradeRequiredExecute() const ;
		virtual void execute(Bureaucrat const &executor) const = 0;
		std::string getName() const;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class FormNotSigned : public std::exception {
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