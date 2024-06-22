#ifndef LOAN_H
#define LOAN_H

#include <string>

class Loan {
public:
    int loanId;
    std::string borrowerName;
    double loanAmount;
    double interestRate;
    int loanTerm;
    double outstandingBalance;
    std::string lastInterestCalcDate;

    Loan(int id, std::string name, double amount, double rate, int term, double balance, std::string date)
        : loanId(id), borrowerName(name), loanAmount(amount), interestRate(rate), loanTerm(term),
          outstandingBalance(balance), lastInterestCalcDate(date) {}
};

#endif
