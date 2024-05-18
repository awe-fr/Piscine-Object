#include "DivideAndRule.hpp"

Account::Account(int id) : refund_rate(0), value(0), loan(0), id(id) {

}

Account::~Account() {

}

void    Account::printAccountStatus() {
    std::cout << "Accout :" << std::endl;
    std::cout << "Id : " << this->id << std::endl;
    std::cout << "Value : " << this->value << std::endl;
    std::cout << "Loan : " << this->loan << std::endl;
    std::cout << "Refound rate : " << this->refund_rate << std::endl;
}

Bank::Bank() : liquidity(0), nextClient(1) {

}

Bank::~Bank() {

}

void    Bank::createAccount() {
    Account *client = new Account(nextClient);
    this->clientAccounts[this->nextClient] = client;
    this->clientMap[this->nextClient] = true;
    std::cout << "Account n" << this->nextClient << " created" << std::endl;
    this->nextClient++;
}

void    Bank::deleteAccount(int id) {
    if (isActive(id) == false)
        return;
    if (this->clientAccounts[id]->loan != 0) {
        std::cout << "You cannot close your account with a loan active" << std::endl;
        return;
    }
    Account *client = this->clientAccounts[id];
    this->clientAccounts.erase(id);
    delete client;
    this->clientMap[id] = false;
    std::cout << "Account n" << id << " deleted" << std::endl;
}

void    Bank::addMoney(int id, float amount) {
    if (isActive(id) == false)
        return;
    this->liquidity += amount * 0.05;
    this->clientAccounts[id]->value += amount * 0.95;
    std::cout << "Account n" << id << " credited of "  << amount * 0.95 << "$" << std::endl;
}

void    Bank::removeMoney(int id, float amount) {
    if (isActive(id) == false)
        return;
    this->clientAccounts[id]->value -= amount;
    std::cout << "Account n" << id << " debited of "  << amount << "$" << std::endl;
}

void    Bank::assignLoan(int id, float amount, float rate) {
    if (isActive(id) == false)
        return;
    if (this->clientAccounts[id]->loan != 0) {
        std::cout << "You already have a loan" << std::endl;
        return;
    }
    if (this->liquidity < amount) {
        std::cout << "Bank account to low for the loan" << std::endl;
        return;
    }
    this->liquidity -= amount;
    this->clientAccounts[id]->loan = amount;
    this->clientAccounts[id]->refund_rate = rate;
    this->clientAccounts[id]->value += amount;
    std::cout << "Account n" << id << " loaned of "  << amount << "$" << std::endl;
}

void	Bank::refoundLoan(int id) {
    if (isActive(id) == false)
        return;
    if (this->clientAccounts[id]->loan == 0) {
        std::cout << "You don't have any loan" << std::endl;
        return;
    }
    if (this->clientAccounts[id]->value < this->clientAccounts[id]->loan * ((this->clientAccounts[id]->refund_rate / 100) + 1)) {
        std::cout << "You cannot refound your loan" << std::endl;
        return;
    }
    this->clientAccounts[id]->value -= this->clientAccounts[id]->loan * ((this->clientAccounts[id]->refund_rate / 100) + 1);
    this->liquidity += this->clientAccounts[id]->loan * ((this->clientAccounts[id]->refund_rate / 100) + 1);
    std::cout << "Account n" << id << " loan refound (" << this->clientAccounts[id]->loan * ((this->clientAccounts[id]->refund_rate / 100) + 1) << "$)" << std::endl;
    this->clientAccounts[id]->loan = 0;
    this->clientAccounts[id]->refund_rate = 0;
}

bool	Bank::isActive(int id) {
    if (id >= this->nextClient) {
        std::cout << "This client dosen't exist" << std::endl;
        return false;
    }
    if (this->clientMap[id] == true) {
        return true;
    }
    std::cout << "This client dosen't exist" << std::endl;
    return false;
}

void	Bank::printBankStatus() {
    int Active = countActive();
    std::cout << "Bank :" << std::endl;
    std::cout << "Liquidity : " << this->liquidity << std::endl;
    std::cout << "Actve Account : " << Active << std::endl;
}

int		Bank::countActive() {
    int count = 0;
    for (int i = 1; i < this->nextClient; i++) {
        if (this->clientMap[i] == true)
            count++;
    }
    return count;
}

Account	*Bank::getAccount(int id) {
    if (isActive(id) == false)
        return NULL;
    return (this->clientAccounts[id]);
}