#include "LoanManagement.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>

LoanManagement::LoanManagement(const std::string& filePath) : filePath(filePath) {}

void LoanManagement::addLoan() {
    int loanId;
    std::string borrowerName;
    double loanAmount, interestRate;
    int loanTerm;
    std::cout << "Enter Loan ID: ";
    std::cin >> loanId;
    std::cin.ignore();
    std::cout << "Enter Borrower Name: ";
    std::getline(std::cin, borrowerName);
    std::cout << "Enter Loan Amount: ";
    std::cin >> loanAmount;
    std::cout << "Enter Interest Rate: ";
    std::cin >> interestRate;
    std::cout << "Enter Loan Term (months): ";
    std::cin >> loanTerm;
    double outstandingBalance = loanAmount;

    time_t now = time(0);
    char* dt = ctime(&now);
    std::string lastInterestCalcDate(dt);

    Loan loan(loanId, borrowerName, loanAmount, interestRate, loanTerm, outstandingBalance, lastInterestCalcDate);
    std::vector<Loan> loans = loadLoans();
    loans.push_back(loan);
    saveLoans(loans);
    std::cout << "Loan added successfully." << std::endl;
}

void LoanManagement::updateLoan() {
    int loanId;
    std::cout << "Enter Loan ID to update: ";
    std::cin >> loanId;
    std::cin.ignore();
    std::vector<Loan> loans = loadLoans();
    for (auto& loan : loans) {
        if (loan.loanId == loanId) {
            std::cout << "Enter new Loan Amount: ";
            std::cin >> loan.loanAmount;
            std::cout << "Enter new Interest Rate: ";
            std::cin >> loan.interestRate;
            std::cout << "Enter new Loan Term (months): ";
            std::cin >> loan.loanTerm;
            loan.outstandingBalance = loan.loanAmount;
            time_t now = time(0);
            char* dt = ctime(&now);
            loan.lastInterestCalcDate = std::string(dt);
            saveLoans(loans);
            std::cout << "Loan updated successfully." << std::endl;
            return;
        }
    }
    std::cout << "Loan not found." << std::endl;
}

std::vector<Loan> LoanManagement::loadLoans() {
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

void LoanManagement::saveLoans(const std::vector<Loan>& loans) {
    std::ofstream file(filePath);
    for (const auto& loan : loans) {
        file << loan.loanId << " " << loan.borrowerName << " " << loan.loanAmount << " "
             << loan.interestRate << " " << loan.loanTerm << " " << loan.outstandingBalance << " "
             << loan.lastInterestCalcDate << std::endl;
    }
}
