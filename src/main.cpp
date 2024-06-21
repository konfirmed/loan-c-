#include <iostream>
#include "UserAuthentication.h"
#include "LoanManagement.h"
#include "RepaymentManagement.h"
#include "ReportGeneration.h"
#include "InterestCalculation.h"
#include "Logging.h"

int main() {
    UserAuthentication userAuth("data/users.txt");
    LoanManagement loanManager("data/loans.txt");
    RepaymentManagement repaymentManager("data/repayments.txt");
    ReportGeneration reportGenerator("data/loans.txt", "data/repayments.txt");
    InterestCalculation interestCalculator("data/loans.txt");
    Logging logger("data/logfile.txt");

    if (userAuth.authenticate()) {
        int choice = 0;
        do {
            std::cout << "========================================\n";
            std::cout << "        Loan Management System         \n";
            std::cout << "========================================\n";
            std::cout << "1. Add Loan\n";
            std::cout << "2. Update Loan\n";
            std::cout << "3. Record Repayment\n";
            std::cout << "4. Generate Report\n";
            std::cout << "5. Calculate Interest\n";
            std::cout << "6. Exit\n";
            std::cout << "========================================\n";
            std::cout << "Please enter your choice (1-6): ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    loanManager.addLoan();
                    logger.log("Loan added.");
                    break;
                case 2:
                    loanManager.updateLoan();
                    logger.log("Loan updated.");
                    break;
                case 3:
                    repaymentManager.recordRepayment();
                    logger.log("Repayment recorded.");
                    break;
                case 4:
                    reportGenerator.generateReport();
                    logger.log("Report generated.");
                    break;
                case 5:
                    interestCalculator.calculateInterest();
                    logger.log("Interest calculated.");
                    break;
                case 6:
                    std::cout << "Exiting system...\n";
                    logger.log("System exited.");
                    break;
                default:
                    std::cout << "Invalid choice, please try again.\n";
                    break;
            }
        } while (choice != 6);
    } else {
        std::cout << "Authentication failed. Exiting system.\n";
    }

    return 0;
}
