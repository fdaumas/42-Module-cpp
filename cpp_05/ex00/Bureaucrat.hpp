#ifndef _BUREAUCRAT_H_
# define _BUREAUCRAT_H_

#include <iostream>
#include <string>

class Bureaucrat {
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(std::string name);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();
		void		verifGrade() ;
		std::string	getName( void ) const;
		int			getGrade( void ) const;
		void		incrementGrade( void );
		void		decrementGrade( void );
		Bureaucrat &operator = (const Bureaucrat &bureaucrat);

	private:
		std::string	_name;
		int			_grade;
};

std::ostream& operator << (std::ostream& out, const Bureaucrat bureaucrat);

#endif