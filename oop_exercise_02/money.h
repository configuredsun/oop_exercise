#ifndef D_MONEY_H_
#define D_MONEY_H_

#include <iostream>

class Money {
        private:
                unsigned long long roub; // количество рублей
                unsigned char cop; // количество копеек
        public:
                Money() {
                        roub = 0;
                        cop = 0;
                }
                Money(unsigned long long x) {//конструктор класса
                this->roub = x;
                this->cop = 0;
                }
                unsigned long long roub_get(const Money& a);
                unsigned char cop_get(const Money& a);
                void get(std::istream& is); // Получить сумму std::istream&
                void show(std::ostream& os) const; // Вывести сумму
                Money Plus(const Money& a2); // сложение сумм
                Money Minus(const Money& a2); // вычитание сумм
                double Div(const Money& a2); // Деление 2х сумм
                Money DivN(double arg); // Деление суммы на число
                Money Mult(double arg); // Умножение суммы на число
                bool operator<(const Money& a2); // <
                bool operator>(const Money& a2); // >
                bool operator<=(const Money& a2); // <=
                bool operator>=(const Money& a2); // >=
                bool operator==(const Money& a2); // ==
                bool operator!=(const Money& a2); // !=
};
Money operator ""_rub(unsigned long long rub);
#endif