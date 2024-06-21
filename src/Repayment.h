#ifndef REPAYMENT_H
#define REPAYMENT_H

#include <string>

class Repayment {
public:
    int repaymentId;
    int loanId;
    double amountPaid;
    std::string paymentDate;

    Repayment(int rId, int lId, double amount, std::string date)
        : repaymentId(rId), loanId(lId), amountPaid(amount), paymentDate(date) {}
};

#endif
