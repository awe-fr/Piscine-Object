#pragma once

#include <iostream>
#include <vector>
#include <map>

class Bank;

class Account
{
	private:
		float	_refundRate;
		float	_value;
		float	_loan;
		int		_id;

		friend class Bank;
	public:
		Account(int id);
		~Account();
		void	printAccountStatus();
};

class Bank
{
	private:
		std::map<int, Account *>	_clientAccounts;
		std::map<int, bool>			_clientMap;
		float						_liquidity;
		int							_nextClient;

	public:
		Bank();
		~Bank();
		Account		*getAccount(int id);
		void		assignLoan(int id, float amount, float rate);
		void		removeMoney(int id, float amount);
		void		addMoney(int id, float amount);
		void		deleteAccount(int id);
		void		refoundLoan(int id);
		void		printBankStatus();
		bool		isActive(int id);
		void		createAccount();
		int			countActive();
};