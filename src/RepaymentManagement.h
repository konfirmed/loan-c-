#ifndef REPAYMENTMANAGEMENT_H
#define REPAYMENTMANAGEMENT_H

#include <vector>
#include <string>
#include "Repayment.h"

class RepaymentManagement {
public:
    RepaymentManagement(const std::string& filePath);
    void recordRepayment();
    std::vector<Repayment> loadRepayments();
    void saveRepayments(const std::vector<Repayment>& repayments);

private:
    std::string filePath;
};

#endif
