#include<iostream>
#include<string>
using namespace std;

void resolveError(int errorCode)
{
	if (errorCode == 0)
	{
		return;
	}
	if (errorCode == 1)
	{
		if (rand() % 2 == 1)
		{
			cout << "К сожалению, оганиченность функционала программы не позволяет ей считать Вашу запись. Пожалуйста, повторите попытку ввода. Запись числа не должна содержать пробелы." << endl;
		}
		else
		{
			cout << "Попробуйте не использовать пробелы в записи." << endl;
		}
	}
	if (errorCode == 2)
	{
		if (rand() % 2 == 1)
		{
			cout << "Пожалуйста, попробуйте ввести число заново. Запись числа не может содержать буквенные символы" << endl;
		}
		else
		{
			cout << "Нам очень жаль, но программе не удается считать Вашу запись. Постарайтесь не использовать буквы" << endl;
		}
	}
	if (errorCode == 3)
	{
		if (rand() % 2 == 1)
		{
			cout << "Приносим свои извинения за доставленные неудобства. Пожалуйста, повторите попытку. Число не должно содержать символы, отличные от цифр" << endl;
		}
		else
		{
			cout << "К сожалению, программа не может считать Ваше число. Попробуйте исключить из записи числа знаки препинания и другие символы, отличные от цифр" << endl;
		}
	}
}

bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool isLetter(char symbol)
{
	return (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z') || (symbol >= 'А' && symbol <= 'Щ') || (symbol >= 'Ы' && symbol <= 'Я') || (symbol == 'Ё') || (symbol >= 'а' && symbol <= 'п') || (symbol >= 'р' && symbol <= 'я') || (symbol == 'ё');
}

int readInt(long long& intNum)
{
	char c = ' ';
	while (true)
	{
		cin.get(c);
		if (isDigit(c))
		{
			intNum = intNum * 10 + c - '0';
		}
		if (c == ' ')
		{
			cin.ignore(32767, '\n');
			intNum = 0;
			return 1;
		}
		if (isLetter(c))
		{
			cin.ignore(32767, '\n');
			intNum = 0;
			return 2; 
		}
		if ((c == '\n' || c == '\t' || c == '\0' || c == '\r') && (intNum != 0))
		{
			return 0;
		}
		if (!isDigit(c))
		{
			cin.ignore(32767, '\n');
			intNum = 0;
			return 3;
		}
	}
}

double readDouble(double& doubleNum)
{
	bool flag = false;
	double k = 0.1;
	char c = ' ';
	while (true)
	{
		cin.get(c);
		if (isDigit(c))
		{
			if (flag)
			{
				doubleNum += (c - '0')*k;
				k/10;
			}
			else
			{
				doubleNum = doubleNum * 10 + c - '0';
			}                                         // doubleNum = doubleNum * 10 + c - '0';
		}
		if (c == '.' && doubleNum != 0)
		{
			flag = true;
		}
		if (c == ' ')
		{
			cin.ignore(32767, '\n');
			doubleNum = 0;
			flag = false;
			k = 0.1;
			return 1;
		}
		if (isLetter(c))
		{
			cin.ignore(32767, '\n');
			doubleNum = 0;
			flag = false;
			k = 0.1;
			return 2;
		}
		if ((c == '\n' || c == '\t' || c == '\0' || c == '\r') && (doubleNum != 0))
		{
			return 0;
		}
		if (!isDigit(c) && c != '.')
		{
			cin.ignore(32767, '\n');
			doubleNum = 0;
			flag = false;
			k = 0.1;
			return 3;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	long long intNum = 0;
	int resultCode = -1;
	cout << "Введите целое число" << endl;
	while (resultCode != 0)
	{
		resultCode = readInt(intNum);
		resolveError(resultCode);
	}
	double doubleNum = 0;
	resultCode = -1;
	cout << "Введите вещественное число" << endl;
	while (resultCode != 0)
	{
		resultCode = readDouble(doubleNum);
		resolveError(resultCode);
	}
	double x = intNum * 1.0;
	double result = x + doubleNum;
	cout << "intNum + doubleNum = " << result << endl;
}






/*Вы попали в неловкую ситуацию : ваша дражайшая родственница посмотреть 
"чему вас там учат в этом вашем университете".В качестве демонстрации своего 
недюжинного интеллекта вы решили написать программу, которая складывает два числа(long long + double) 
и выводит результат.Родственница достаточно упрямая и не очень дружит с "этими вашими компьютерами" 
и не очень любит выполнять "всякие там указки ваши, сама разберусь что делать".А еще родственница очень обидчивая,
но очень упорная.Программу вашу она запустит один раз и будет добиваться от нее ответа до упора.В случае некорректного ввода 
программа должна извиниться за ограниченность собственного функционала напомнить родственнице правила ввода чисел и аккуратно намекнуть
родственнице на конкретную проблему в предыдущем вводе.Родственница достаточно коварна и в случае с вводом целого числа правильной 
должна считаться строка вида "523456", а в случае с дробным числом "53216.125" (родственница еще и ленива - она не вводит более трех 
знаков после запятой).В связи с этим предполагается наличие следующих функций :

void resolveError(int errorCode); -программа принимает на вход число "errorCode" и выводит на экран текст ошибки.
Разъяснение каждого кода ошибки должно иметь как минимум две различных формулировки и каждая из них должна выводиться случайным образом.
Желательно догадаться сделать тут массив string.
int readInt(long long& number); -программа каким - то образом делает так, что в number окажется введенное целое число, либо записывает 
в него 0 и возвращает код ошибки.
double readDouble(double& double); -программа считывает double.Как и предыдущая функция она может вернуть код ошибки.

кроме этих функций у вас еще может быть много других замечательных и прелестных функций.*/