#ifndef INTERESTCALCULATION_H
#define INTERESTCALCULATION_H

#include <vector>
#include <string>
#include "Loan.h"

class InterestCalculation {
public:
    InterestCalculation(const std::string& filePath);
    void calculateInterest();

private:
    std::string filePath;
    std::vector<Loan> loadLoans();
    void saveLoans(const std::vector<Loan>& loans);
};

#endif
