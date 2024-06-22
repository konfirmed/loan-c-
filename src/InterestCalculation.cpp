#include "InterestCalculation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>

InterestCalculation::InterestCalculation(const std::string& filePath) : filePath(filePath) {}

void InterestCalculation::calculateInterest() {
    auto loans = loadLoans();
    for (auto& loan : loans) {
        double interest = loan.outstandingBalance * (loan.interestRate / 100);
        loan.outstandingBalance += interest;
        time_t now = time(0);
        char* dt = ctime(&now);
        loan.lastInterestCalcDate = std::string(dt);
    }
    saveLoans(loans);
    std::cout << "Interest calculation completed." << std::endl;
}

std::vector<Loan> InterestCalculation::loadLoans() {
    std::vector<Loan> loans;
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int loanId, loanTerm;
        std::string borrowerName, lastInterestCalcDate;
        double loanAmount, interestRate, outstandingBalance;
        ss >> loanId >> borrowerName >> loanAmount >> interestRate >> loanTerm >> outstandingBalance >> lastInterestCalcDate;
        loans.push_back(Loan(loanId, borrowerName, loanAmount, interestRate, loanTerm, outstandingBalance, lastInterestCalcDate));
    }
    return loans;
}

void InterestCalculation::saveLoans(const std::vector<Loan>& loans) {
    std::ofstream file(filePath);
    for (const auto& loan : loans) {
        file << loan.loanId << " " << loan.borrowerName << " " << loan.loanAmount << " "
             << loan.interestRate << " " << loan.loanTerm << " " << loan.outstandingBalance << " "
             << loan.lastInterestCalcDate << std::endl;
    }
}
