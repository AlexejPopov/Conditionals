﻿#include <iostream>
#include <locale.h>
#include <math.h>       // math library
#include <stdlib.h>

using namespace std;

/* Switch - конструкция множественного выбора, позводяющая выбрать один из подходящих вариантов.
Мы задаем определенное значение (выражение), а конструкция switch по этому значению ищет соответствие среди тех вариантов, которые в нем указаны. Мы указываем ключевой
вариант/значение, поиск которого будет осуществлен среди тех вариантов, коорые мы укажем в теле switch. Если в лесенке if else мы можем задать любое условие, например
summa > 5000, то в switch мы можем указать только значение и проверять найдется ли соответствие этому значению.
Эти значения могут быть целочисленными или символьными, но обязательно константами! (их нельзя менять, нельзя задавать переменными!)
Например, безномерной ключ и шкафчики в раздевалке. Я буду проходить и перебирать шкафчики пока не попаду в нужный шкафчик. В лесенке if else я должен это делать под-
ряд, не подошел к первому шкафчику, пошел ко второму, потом к третьему, а в switch кейсе мы можем выбирать произвольно. В switch проверяется строгое соответствие, но
сами кейсы указываются в произвольном порядке!

          Нюансы у switch и if else:
          У if else условия могут быть любые, не только равно, но и больше, меньше, и комбинированные условия
          У switch строгое соответствие какому-то значению
          У switch кейсы пишутся в произвольном порядке, но рекомендуется писать самые вероятные кейсы первыми

Принцып действия:
В конструкции switch мы указываем значения, те данные, которые необходимо проверить на соответствие. Это м/б переменная или выражение, результатом которых будет только
тип данных char или целое число! И этот символ или целое число мы будем искать среди тех вариантов, которые будут записаны нами в кейсах, искать строгое соответствие.
Кейсы в свою очередь м/б целочисленными или символьными постоянными значениями, указанные с помощью констатн или литералов в самом коде. И после того как мы непосредст-
венно пройдем по всему списку кейсов и найдем нужное значение, будет выполнено соответствующее действие, указанное в этом кейсе. Если произошло совпадение, то выполнят-
ся все действия кейса, с которым совпало значение.

(!) Множественный вывод, это когда мы в одну команду cout отправляем сначала текст, потом переменную или даже ее с вычислением, а потом может еще и снова текст, а потом
    еще и endl. А множественный ввод, это когда мы с помощью одного потока cin считываем несколько переменных. */

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "------------------------------------------------------------Мой лучший калькулятор!--------------------------------------------------------------" << endl;
    float A = 0.0F, B = 0.0F, Result = 0.0F;
    char Key = '+';

    // 1-й вариант меню
    cout << "Введите число А: "; cin >> A;
    cout << R"(
Выберите действие:
'+' - Сложение
'-' - Вычитание
'*' - Умножение
'/' - Деление
'^' - Число А в степени В
'V' - Корень А-ой степени из В
)";
    cin >> Key;
    cout << "Введите число B: "; cin >> B;


    switch (Key)                                                                // тут мы пишем что будем искать (символ, введенный пользователем)
    {
    case '+':                                                                   // данное действие выполнится если Key == '+' (если мы ввели '+')
        Result = A + B;                                                         // сначала подсчитается отдельно переменная Result, а потом
        cout << "Результат равен: " << Result << endl;                          // выведется Result на экран
        break;                                                                  // break прерывает конструкцию и выводит из switch. Каждый кейс должен завершаться им и
    case '-':                                                                   // каждый следующий кейс должен отличаться от уже существующего кейса
        Result = A - B;
        cout << "Результат равен: " << Result << endl;
        break;
    case '*':
        Result = A * B;
        cout << "Результат равен: " << Result << endl;
        break;
    default:
        cout << "Некорректное действие!" << endl;
    case '/':
        Result = A / B;
        cout << "Результат равен: " << Result << endl;
        break;

        /* Для возведения в степень используется мат.функция pow. Их 3 на выбор: pow возводит чисто double в степень типа double, powf работает с float, powl - long double,
        а с целыми числами можно использовать любую, т.к. любое вещественное число может хранить в себе целое число (вещественный тип данных старше чем целочисленный). */

    case '^':
        Result = powf(A, B);                                                    // число А в степени В
        cout << "Результат равен: " << Result << endl;
        break;
    case 'V':                                                                   // кв.корень из А равен А в степени 1/2
        Result = powf(B, 1 / A);                                                // корень А-ой степени из В
        cout << "Результат равен: " << Result << endl;
        break;
        system("pause");
    }

    /* Особенности конструкции:
    Если ошибиться и ввести символ, которого нет в switch, то ничего не произойдет! Т.к. если внутри switch нет ни одного соответствующего значения, то ни одного подхо-
    дящего кейса не будет найдено, switch будет просто не выполнен и компилятор выйдет прямо в system pause. В этом случае нам нужна какая-то реакция на это. Для этого
    используется default. Если ни одного подходящего кейса не найдено и присутствует default, то будет выполнено действие, находящееся в default. default не является
    обязательным содержимым switch. И default м/б добавлен в любое место в switch.

    Как это работает?
    Сначала компилятор, зайдя в switch, берет содержание в круглых скобках (здесь это переменная Key, но также м/б выражение, вычисление или какое-то действие), ищет
    его среди кейсов по порядку с первого по последний. Если где-то нашел, выполняет содержимое кейса и по break выходит из switch в system pause. Если же, пройдя по
    всем кейсам, подходящего значения не найденно, компелятор проверяет есть ли default. Если default есть, то компилятор выполняет его содержимое. Если default от-
    сутствует, то ничего не будет выполнено.

    Почему каждый кейс должен заканчиваться break?
    Кейсы это не команды, а метки, они не выполняются сами по себе, а след, попав в нужный кейс, мы начнем выполнять все действия до тех пор пока не встретим break. А
    это м/б также и несколько кейсов подряд где пропущен break. Все выполнится, т.к. компилятор ищет break чтобы остановить выполнение условия и выполнит все кейсы по
    порядку пока не встретит break. break нельзя пропускать!
    (!) Последний break можно не ставить, но лучше поставить чтобы потом не забыть о нем, добавив еще кейс.

    Но есть случаи когда можно не писать break.
    Особый случай, когда например нужно учесть ошибку ввода пользователя, скажем, ввод строчной буквы вместо заглавной, как ниже:

    case 'v':
    case 'V':
        Result = powf(B, 1 / A);
        cout << "Результат равен: " << Result << endl;
        break;

    Пользователь ошибется и введет маленькую 'v'. У нас активируется кейс с 'v', а потом станет все выполняться до тех пор пока компилятор не наткнется на break. В та-
    кой конструкции при вводе большой или маленькой 'v' программа выполнит одно и тоже действие! Этот прием можно использовать когда нам нужно для нескольких кейсов вы-
    полнить одно и тоже действие.
    (!) Плюсом к этому, мы можем в кейс с 'v' добавить собственное действие, которое будет индивидуально лишь для этого кейса!

    case 'v':
        cout << "Вы ввели 'v' вместо 'V'. Будьте внимательны!" << endl;
    case 'V':
        Result = powf(B, 1 / A);
        cout << "Результат равен: " << Result << endl;
        break;

    В этом случае если пользователь введет 'v' или 'V', программа все равно выполнит для него нужное действие, т.к. после 'v' нет break. Но в кейс 'v' добавим предуп-
    реждение, чтобы в следующий раз пользователь вводил корректно.


    2-й вариант меню
    Калькулятор в строчку.
    Для меню идеальна сырая строка */

    cout << R"(
Используйте действие по образцу:
Сложение:                   А+В
Вычитание:                  А-В
Умножение:                  А*В
Деление:                    А/В
Число А в степени В         А^B
Корень А-ой степени из В    AVB
)";

    cin >> A >> Key >> B;                                                               // конструкция множественного ввода данных                                  

    /*  Когда мы введем 15 + 3, 15 попадет в А, плюс попадет в Key, а 3 попадет в В.

        При множественном вводе содержимое ввода распределяется автоматически в переменные в зависимости от следующих моментов:

        1. Разграничение типами данных (число и символ; число и переменная; у нас число, символ, число): float, char, float.

        2. Разделение через пробелы или enter.
           Этот тип мы обязаны использовать если у нас один и тот же тип данных, например, int, int, int.
           В этом случае главное не вводить некорректный тип данных, скажем, вместо числа символ или наоборот, т.к. это сломает всю конструкцию. Конструкция неразрывна!
           Использовать этот множественный ввод можно в простых конструкциях и желательно с переменными разных типов данных, хотя бы чередующихся, но не подряд! */

    switch (Key)
    {
    case '+':
        Result = A + B;
        cout << "Результат равен: " << Result << endl;
        break;
    case '-':
        Result = A - B;
        cout << "Результат равен: " << Result << endl;
        break;
    case '*':
        Result = A * B;
        cout << "Результат равен: " << Result << endl;
        break;
    default:
        cout << "Некорректное действие!" << endl;
    case '/':
        Result = A / B;
        cout << "Результат равен: " << Result << endl;
        break;
    case '^':
        Result = powf(A, B);
        cout << "Результат равен: " << Result << endl;
        break;
    case 'V':
        Result = powf(B, 1 / A);
        cout << "Результат равен: " << Result << endl;
        break;
        system("pause");
    }
}