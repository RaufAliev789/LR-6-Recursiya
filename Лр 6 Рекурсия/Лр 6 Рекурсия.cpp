#include <iostream>

int Summa_cifr(int n, int glubina) {
    if ((abs(n) < 10) || (n == 0)) {
        std::cout << "Глубина рекурсии: " << glubina << std::endl;
        std::cout << "Вызов с аргументом " << abs(n) << ", возвращено значение " << n << std::endl;
        return abs(n);
    }
    else if (abs(n) >= 10) {
        int last_cifra = abs(n) % 10;
        int begin_cifri = abs(n) / 10;
        int recursiveSum = Summa_cifr(begin_cifri, glubina + 1);
        int result = last_cifra + recursiveSum;
        std::cout << "Глубина рекурсии: " << glubina << std::endl;
        std::cout << "Вызов с аргументом " << abs(n) << ", возвращено значение " << result << std::endl;
        return result;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    int result;
    std::cout << "Введите число: " << std::endl;
    std::cin >> n;
    
  
    if ((n != static_cast<int>(n) || (n == static_cast<double>(n)))         ) {
        try {
            throw std::exception("Введено не целое число или 0");
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
            exit(0);
        }
    }

    result = Summa_cifr(n, 1);
    std::cout << "Положительная cумма цифр числа " << n << " равна " << result << std::endl;
    return 0;
}
