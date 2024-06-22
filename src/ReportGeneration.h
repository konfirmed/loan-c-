#ifndef REPORTGENERATION_H
#define REPORTGENERATION_H

#include <vector>
#include <string>
#include "Loan.h"

class ReportGeneration {
public:
    ReportGeneration(const std::string& loanFilePath, const std::string& repaymentFilePath);
    void generateReport();

private:
    std::string loanFilePath;
    std::string repaymentFilePath;
    std::vector<Loan> loadLoans();
};

#endif
