#include "DivideAndRule.hpp"

Account::Account(int id) : _refundRate(0), _value(0), _loan(0), _id(id) {

}

Account::~Account() {

}

void    Account::printAccountStatus() const {
    std::cout << "Accout :" << std::endl;
    std::cout << "Id : " << this->_id << std::endl;
    std::cout << "Value : " << this->_value << std::endl;
    std::cout << "Loan : " << this->_loan << std::endl;
    std::cout << "Refound rate : " << this->_refundRate << std::endl;
}

Bank::Bank() : _liquidity(0), _nextClient(1) {

}

Bank::~Bank() {

}

const Account	&Bank::createAccount() {
    Account *client = new Account(_nextClient);
    this->_clientAccounts[this->_nextClient] = client;
    this->_clientMap[this->_nextClient] = true;
    std::cout << "Account n" << this->_nextClient << " created" << std::endl;
    this->_nextClient++;
    return (getAccount(this->_nextClient - 1));
}

void    Bank::deleteAccount(int id) {
    if (isActive(id) == false)
        return;
    if (this->_clientAccounts[id]->_loan != 0) {
        std::cout << "You cannot close your account with a loan active" << std::endl;
        return;
    }
    Account *client = this->_clientAccounts[id];
    this->_clientAccounts.erase(id);
    delete client;
    this->_clientMap[id] = false;
    std::cout << "Account n" << id << " deleted" << std::endl;
}

void    Bank::addMoney(int id, float amount) {
    if (isActive(id) == false)
        return;
    this->_liquidity += amount * 0.05;
    this->_clientAccounts[id]->_value += amount * 0.95;
    std::cout << "Account n" << id << " credited of "  << amount * 0.95 << "$" << std::endl;
}

void    Bank::removeMoney(int id, float amount) {
    if (isActive(id) == false)
        return;
    this->_clientAccounts[id]->_value -= amount;
    std::cout << "Account n" << id << " debited of "  << amount << "$" << std::endl;
}

void    Bank::assignLoan(int id, float amount, float rate) {
    if (isActive(id) == false)
        return;
    if (this->_clientAccounts[id]->_loan != 0) {
        std::cout << "You already have a loan" << std::endl;
        return;
    }
    if (this->_liquidity < amount) {
        std::cout << "Bank account to low for the loan" << std::endl;
        return;
    }
    this->_liquidity -= amount;
    this->_clientAccounts[id]->_loan = amount;
    this->_clientAccounts[id]->_refundRate = rate;
    this->_clientAccounts[id]->_value += amount;
    std::cout << "Account n" << id << " loaned of "  << amount << "$" << std::endl;
}

void	Bank::refoundLoan(int id) {
    if (isActive(id) == false)
        return;
    if (this->_clientAccounts[id]->_loan == 0) {
        std::cout << "You don't have any loan" << std::endl;
        return;
    }
    if (this->_clientAccounts[id]->_value < this->_clientAccounts[id]->_loan * ((this->_clientAccounts[id]->_refundRate / 100) + 1)) {
        std::cout << "You cannot refound your loan" << std::endl;
        return;
    }
    this->_clientAccounts[id]->_value -= this->_clientAccounts[id]->_loan * ((this->_clientAccounts[id]->_refundRate / 100) + 1);
    this->_liquidity += this->_clientAccounts[id]->_loan * ((this->_clientAccounts[id]->_refundRate / 100) + 1);
    std::cout << "Account n" << id << " loan refound (" << this->_clientAccounts[id]->_loan * ((this->_clientAccounts[id]->_refundRate / 100) + 1) << "$)" << std::endl;
    this->_clientAccounts[id]->_loan = 0;
    this->_clientAccounts[id]->_refundRate = 0;
}

bool	Bank::isActive(int id) {
    if (id >= this->_nextClient) {
        // std::cout << "This client dosen't exist" << std::endl;
        return false;
    }
    if (this->_clientMap[id] == true) {
        return true;
    }
    // std::cout << "This client dosen't exist" << std::endl;
    return false;
}

void	Bank::printBankStatus() {
    int Active = countActive();
    std::cout << "Bank :" << std::endl;
    std::cout << "Liquidity : " << this->_liquidity << std::endl;
    std::cout << "Actve Account : " << Active << std::endl;
}

int		Bank::countActive() {
    int count = 0;
    for (int i = 1; i < this->_nextClient; i++) {
        if (this->_clientMap[i] == true)
            count++;
    }
    return count;
}

const Account	&Bank::getAccount(int id) {
    if (isActive(id) == false)
        throw AccountFailed();
    return (*this->_clientAccounts[id]);
}

const char *Bank::AccountFailed::what() const throw() {
    return ("This id is not affiliated with an account.");
}