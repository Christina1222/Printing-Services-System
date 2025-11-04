#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Numerical Constants
const double COST_A4_COLOUR = 0.50;
const double COST_A4_BW = 0.20;
const double COST_A3_COLOUR = 1.00;
const double COST_A3_BW = 0.80;
const double BINDING_COST_COIL = 3.50;
const double BINDING_COST_COMB = 3.00;
const double BINDING_COST_RING = 5.00;
const double LAMINATION_COST = 1.00;
const double DISCOUNT_MEMBER = 0.10;


double calculateCost1(bool isMember, int quantity, string paperSize, string colorType, string bindingType, bool lamination, bool stapling) {
    double cost = 0;
    double discount = isMember ? DISCOUNT_MEMBER : 0.00;

    if (paperSize == "A4") {
        cost += (colorType == "Colour") ? COST_A4_COLOUR : COST_A4_BW;
    }
    else if (paperSize == "A3") {
        cost += (colorType == "Colour") ? COST_A3_COLOUR : COST_A3_BW;
    }

    cost *= quantity;

    if (bindingType == "Coil") cost += BINDING_COST_COIL;
    else if (bindingType == "Comb") cost += BINDING_COST_COMB;
    else if (bindingType == "3-ring") cost += BINDING_COST_RING;

    if (lamination) cost += LAMINATION_COST;
    // Stapling cost is zero, but included for completeness
    if (stapling) cost += 0.00;

    cost -= cost * discount;
    return cost;
}