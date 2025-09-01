#pragma once

#include <iostream>

#define NBLEVEL 4

class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		std::string _name[NBLEVEL];
		void (Harl::*_f[NBLEVEL])(void);

	public:
		Harl (void);
		~Harl (void);
		void	complain( std::string level );
};
