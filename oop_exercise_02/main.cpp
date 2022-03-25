#include <iostream>
#include "money.h"

int main() {
        
        Money a1;
        Money a2;
        float arg;

        std::cout << "First summ:" << std::endl;
        a1.get(std::cin);
        std::cout << "Second summ:" << std::endl;
        a2.get(std::cin);
        std::cout << "Number to div and multiply" << std::endl;
        std::cin >> arg;
        if(arg == 0){
                std::cout << "Cannot be divided by zero" << std::endl;
                Money b;
                b = 100_rub;
                std::cout << "One hundred rub:" << std::endl;
                b.show(std::cout);
                return 0;
        }
        if(a1.roub_get(a1) < a2.roub_get(a2) || (a1.roub_get(a1) == a2.roub_get(a2) && a1.cop_get(a1) < a2.cop_get(a2))) {
		std::cout << "First summ less than second summ" << std::endl;
                Money b;
                b = 100_rub;
                std::cout << "One hundred rub:" << std::endl;
                b.show(std::cout);
		return 0;
	}
        std::cout << std::endl;

        std::cout << "First summ:" << std::endl;
        a1.show(std::cout);
        std::cout << "Second summ:" << std::endl;
        a2.show(std::cout);
        std::cout << "Addition:" << std::endl;
        a1.Plus(a2).show(std::cout);
        std::cout << "Subtraction:" << std::endl;
        a1.Minus(a2).show(std::cout);
        std::cout << "Division by second summ:" << std::endl;
        std::cout << a1.Div(a2) << std::endl;
        std::cout << "Division by number:" << std::endl;
        a1.DivN(arg).show(std::cout);
        std::cout << "Multiplication:" << std::endl;
        a1.Mult(arg).show(std::cout);

        if(a1 < a2) std::cout << "<:" << std::endl;
        else std::cout << "<: false" << std::endl;

        if(a1 > a2) std::cout << ">: true" << std::endl;
        else std::cout << ">: false" << std::endl;

        if(a1 <= a2) std::cout << "<=: true" << std::endl;
        else std::cout << "<=: false" << std::endl;

        if(a1 >= a2) std::cout << ">=: true" << std::endl;
        else std::cout << ">=: false" << std::endl;

        if(a1 == a2) std::cout << "==: true" << std::endl;
        else std::cout << "==: false" << std::endl;

        if(a1 != a2) std::cout << "!=: true" << std::endl;
        else std::cout << "!=: false" << std::endl;


        Money b;
        b = 100_rub;
        std::cout << "One hundred rub:" << std::endl;
        b.show(std::cout);


        return 0;
}