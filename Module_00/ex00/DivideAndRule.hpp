#pragma once

#include <iostream>
#include <vector>
#include <map>

class Bank;

class Account
{
	private:
		float	refund_rate;
		float	value;
		float	loan;
		int		id;

		friend class Bank;
	public:
		Account(int id);
		~Account();
		void	printAccountStatus();
};

class Bank
{
	private:
		std::map<int, Account *>	clientAccounts;
		std::map<int, bool>			clientMap;
		float						liquidity;
		int							nextClient;

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