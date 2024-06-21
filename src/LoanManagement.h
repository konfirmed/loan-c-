#ifndef LOANMANAGEMENT_H
#define LOANMANAGEMENT_H

#include <vector>
#include <string>
#include "Loan.h"

class LoanManagement {
public:
    LoanManagement(const std::string& filePath);
    void addLoan();
    void updateLoan();
    std::vector<Loan> loadLoans();
    void saveLoans(const std::vector<Loan>& loans);

private:
    std::string filePath;
};

#endif
