#include "RepaymentManagement.h"
#include "LoanManagement.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

RepaymentManagement::RepaymentManagement(const std::string& filePath) : filePath(filePath) {}

void RepaymentManagement::recordRepayment() {
    int repaymentId, loanId;
    double amountPaid;
    std::string paymentDate;
    std::cout << "Enter Repayment ID: ";
    std::cin >> repaymentId;
    std::cout << "Enter Loan ID: ";
    std::cin >> loanId;
    std::cout << "Enter Amount Paid: ";
    std::cin >> amountPaid;
    std::cout << "Enter Payment Date (YYYY-MM-DD): ";
    std::cin >> paymentDate;

    Repayment repayment(repaymentId, loanId, amountPaid, paymentDate);
    std::vector<Repayment> repayments = loadRepayments();
    repayments.push_back(repayment);
    saveRepayments(repayments);

    LoanManagement loanManager("data/loans.txt");
    std::vector<Loan> loans = loanManager.loadLoans();
    for (auto& loan : loans) {
        if (loan.loanId == loanId) {
            loan.outstandingBalance -= amountPaid;
            loanManager.saveLoans(loans);
            std::cout << "Repayment recorded successfully." << std::endl;
            return;
        }
    }
    std::cout << "Loan not found." << std::endl;
}

std::vector<Repayment> RepaymentManagement::loadRepayments() {
    std::vector<Repayment> repayments;
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int repaymentId, loanId;
        double amountPaid;
        std::string paymentDate;
        ss >> repaymentId >> loanId >> amountPaid >> paymentDate;
        repayments.push_back(Repayment(repaymentId, loanId, amountPaid, paymentDate));
    }
    return repayments;
}

void RepaymentManagement::saveRepayments(const std::vector<Repayment>& repayments) {
    std::ofstream file(filePath);
    for (const auto& repayment : repayments) {
        file << repayment.repaymentId << " " << repayment.loanId << " " << repayment.amountPaid << " "
             << repayment.paymentDate << std::endl;
    }
}
