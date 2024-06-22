#include "ReportGeneration.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

ReportGeneration::ReportGeneration(const std::string& loanFilePath, const std::string& repaymentFilePath)
    : loanFilePath(loanFilePath), repaymentFilePath(repaymentFilePath) {}

void ReportGeneration::generateReport() {
    std::cout << "Select Report Type:\n1. All Loans\n2. Specific Borrower\n3. Overdue Loans" << std::endl;
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
        case 1:
            {
                auto loans = loadLoans();
                for (const auto& loan : loans) {
                    std::cout << "Loan ID: " << loan.loanId << ", Borrower Name: " << loan.borrowerName
                              << ", Outstanding Balance: " << loan.outstandingBalance << std::endl;
                }
                break;
            }
        case 2:
            {
                std::string borrowerName;
                std::cout << "Enter Borrower Name: ";
                std::getline(std::cin, borrowerName);
                auto loans = loadLoans();
                for (const auto& loan : loans) {
                    if (loan.borrowerName == borrowerName) {
                        std::cout << "Loan ID: " << loan.loanId << ", Outstanding Balance: " << loan.outstandingBalance << std::endl;
                    }
                }
                break;
            }
        case 3:
            {
                auto loans = loadLoans();
                std::string today = "2024-06-19"; // Replace with the current date.
                for (const auto& loan : loans) {
                    if (loan.lastInterestCalcDate < today) {
                        std::cout << "Loan ID: " << loan.loanId << ", Borrower Name: " << loan.borrowerName
                                  << ", Outstanding Balance: " << loan.outstandingBalance << std::endl;
                    }
                }
                break;
            }
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
            break;
    }
}

std::vector<Loan> ReportGeneration::loadLoans() {
    std::vector<Loan> loans;
    std::ifstream file(loanFilePath);
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
