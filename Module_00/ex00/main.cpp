#include "DivideAndRule.hpp"

#include<unistd.h>

int main() {
	// Account accountA = Account();
	// accountA.id = 0;
	// accountA.value = 100;

	// Account accountB = Account();
	// accountB.id = 1;
	// accountB.value = 100;

	// Bank bank = Bank();
	// bank.liquidity = 999;
	// bank.clientAccounts.push_back(&accountA);
	// bank.clientAccounts.push_back(&accountB);

	// bank.liquidity -= 200;
	// accountA.value += 400;

	// std::cout << "Account : " << std::endl;
	// std::cout << accountA << std::endl;
	// std::cout << accountB << std::endl;

	// std::cout << " ----- " << std::endl;

	// std::cout << "Bank : " << std::endl;
	// std::cout << bank << std::endl;

	Bank bank = Bank();
	for (int i = 1; i < 6; i++) {
		bank.createAccount();
	}
	std::cout << "---------------------------" << std::endl;
	bank.deleteAccount(3);
	bank.deleteAccount(7);
	std::cout << "---------------------------" << std::endl;
	for (int i = 1; i < 6; i++) {
		bank.addMoney(i, 100);
	}
	std::cout << "---------------------------" << std::endl;
	for (int i = 1; i < 6; i++) {
		bank.assignLoan(i, 10, 5);
	}
	std::cout << "---------------------------" << std::endl;
	bank.deleteAccount(1);
	std::cout << "---------------------------" << std::endl;
	for (int i = 1; i < 6; i++) {
		bank.refoundLoan(i);
	}
	std::cout << "---------------------------" << std::endl;
	bank.printBankStatus();
	std::cout << "---------------------------" << std::endl;
	Account *account = bank.getAccount(1);
	account->printAccountStatus();
	std::cout << "---------------------------" << std::endl;
	for (int i = 1; i < 6; i++) {
		bank.deleteAccount(i);
	}
	std::cout << "---------------------------" << std::endl;
	return (0);
}
