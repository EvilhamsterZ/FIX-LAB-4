#include <iostream>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);//русский ввод
    SetConsoleOutputCP(1251);//вывод
    int n;
    int y = 0;
    int smin = 10001;
    int sind = 0;
    int cmax = 0;
    int cmaxind = 0;
    int s[1000];
    int m[1000];
    int c[1000];
    std::cout << "Введите количество пассажиров/такси n=";
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Введите расстояние до пассажира номер (" << i << ")= ";
        std::cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Введите тариф для такси номер (" << i << ")= ";
        std::cin >> m[i];
        c[i] = m[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cmax < c[j])//реализация простая в сортировке находим индекс и максимальное для массива такси
            {
                cmax = c[j];
                cmaxind = j;
            }
            if (s[j] < smin)//минимальное и индекс минимального в массиве расстояний
            {
                smin = s[j];
                sind = j;
            }
        }//берем используя индекс максимального и минимального находим по индексу минимального расстояния элемент и вписываем значения индекса максимального от массива такси
        cmax = 0;//зануляем максимальное для подъема вверх по значениям
        c[cmaxind] = 0;// зануляем  максимальное чтобы не находить его в массиве
        s[sind] = 99999;// максимизируем минимальное чтобы не находить его в массиве
        m[sind] = cmaxind;
        smin = 10001;//это для сравнений чтобы спускаться к минимальному
        sind = 0;//обнуляем индексы
        cmaxind = 0;
    }
    std::cout << std::endl;
    for (int i = 1; i <= n; i++)
    {
        std::cout << m[i];//выводим новый массив
    }
}