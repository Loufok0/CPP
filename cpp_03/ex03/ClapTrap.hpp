#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

class ClapTrap
{
	private:

		const char *_name;
		int _hitPoint;
		int _energyPoint;
		int _attackDamage;

	public:

		ClapTrap();
		ClapTrap(const char *name);
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator = (const ClapTrap &other);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		const char* getName() const {return (_name);};
		void setEp(const int n) {this->_energyPoint = n;};
		int getEp() const {return (_energyPoint);};
		void setHp(const int n) {this->_hitPoint = n;};
		int getHp(void) const {return (_hitPoint);};
		void setAtt(const int n) {this->_attackDamage = n;};
		int getAtt() const {return (_attackDamage);};

};
