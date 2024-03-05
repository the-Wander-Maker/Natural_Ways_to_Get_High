#include "Equation.h"
#include "Exponentiation.h"
#include "FourBasicOperation.h"
#include "FunctionExcersises.h"
#include "HeronFormula.h"
#include "CapitalReplace.h"
#include "ContainersSort.h"
#include "Crosswords.h"
#include "GodrokErettsegi.h"
#include "FutarErettsegi.h"
#include "PrimeNum.h"


int main() {

    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
    std::cout << "--------------------------------Natural_Ways_to_Get_High-1.0-----------------------------" << std::endl;

    // Equation task
    Equation equation; // Using the default constructor
    equation.equation(0.0, 0.0, 0.0); // You can pass actual values here if needed

    // Four Basic Operation
    FourBasicOperation fourbasicoperation; // Using the default constructor
    fourbasicoperation.get_user_input(); // No need to pass 0, 0 here, as it gets user input


    /* You can try all the functions in FunctionExcersises, I don't want to waste space here for them...*/
    

    // Exponentiation task
    Exponentiation exponentiation;
    int num_1 = 0;
    int num_2 = 0;
    exponentiation.run_exponentiation_procedure(num_1, num_2);

    // Heron formula task
    HeronFormula heronformula;
    heronformula.heron_formula_process();

    // Capital replace task
    CapitalReplace capitalreplace;
    capitalreplace.capital_replace_process();

    // Sorting containers task
    ContainersSort containersSort;
    containersSort.sortingProcedure();

    // Crosswords task
    Crosswords crosswords;
    crosswords.crosswordsExec();
 
    // Godrok Erettsegi task
    GodrokErettsegi godrok;
    godrok.godrokErettsegiExec();

    // Futar Erettsegi task
    Futar futar;
    futar.futarExec();

    // Primenumber task
    PrimeNum primeNum;
    primeNum.primeExec();



}
