using namespace std;
#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Выберите задание: \n 6.Корни уравнения \n 7.Площадь треугольника \n 8.Калькулятор \n 9.Угадай число \n 10.Возведение в степень \n 11.Факториал \n 12.Простое число \n 13.Степень двойки \n 14.Фиксированная сумма \n";
	int answ;
	cin >> answ;
	if (answ == 6)
	{
		int a, b, c, d; //6 задача
		double x, y;
		cout << "axx + bx + c" << "\n Введите a, b, c:" << endl;
		cin >> a >> b >> c;
		if (b == 0)
		{
			if (c == 0)
				cout << "x=0";
			else
			{
				if (a == 0)
					cout << "Нет решений";
				if (-c / a > 0)
					cout << "x1,2=+-" << (sqrt(-c / a));
				else
					cout << "Нельзя вывести корень из отрицательного числа";
			}
		}
		else
		{
			if (c == 0)
			{
				if (a == 0)
					cout << "x=0";
				else
					cout << "x1=0 \n x2=" << (-b / a);
			}
			else
			{
				if (a == 0)
					cout << "x=" << (-c / b);
				else
				{
					if ((b * b - 4 * a * c) < 0)
					{
						cout << "\n Дискриминант меньше 0(";
						return 0;
					}
					d = b * b - 4 * a * c;
					d = sqrt(d);
					x = (-b + d) / (2 * a);
					y = (-b - d) / (2 * a);
					cout << endl << "x1= " << x << "\n x2= " << y;
				}
			}
		}
	}
	if (answ == 7)
	{
		int n = 1;
		while (n != 2) //7 задача
		{
			int answer;
			cout << "Выберите способ нахождения площади: \n" << "1.По координатам; \n 2.По длинам. \n";
			cin >> answer;
			if (answer == 1)
			{
				int xa, xb, xc, ya, yb, yc;
				double p, s, l1, l2, l3;
				cout << "Введите координаты: \n" << "А(x, y) \n B(x, y) \n C(x, y) \n";
				cin >> xa >> ya >> xb >> yb >> xc >> yc;
				l1 = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
				l2 = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
				l3 = sqrt((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb));
				p = (l1 + l2 + l3) / 2;
				if (l1 + l2 - l3 > 0 && l1 + l3 - l2 > 0 && l2 + l3 - l1 > 0)
				{
					s = sqrt(p * (p - l1) * (p - l2) * (p - l3));
					cout << "Площадь: " << s;
				}
				else
					cout << "Треугольник не существует.";
			}
			if (answer == 2)
			{
				double l1, l2, l3, s, p;
				cout << "Введите длины сторон: \n";
				cin >> l1 >> l2 >> l3;
				p = (l1 + l2 + l3) / 2;
				if (l1 + l2 - l3 > 0 && l1 + l3 - l2 > 0 && l2 + l3 - l1 > 0)
				{
					s = sqrt(p * (p - l1) * (p - l2) * (p - l3));
					cout << "Площадь: " << s;
				}
				else
					cout << "Треугольник не существует.";
			}
			if (answer != 1 && answer != 2)
			{
				cout << "Введено неправильное число";
			}
			cout << "\n Xотите ли Вы начать заново ? \n" << "1 - Да; \n 2 - Нет. \n";
			cin >> n;
		}
	}
	if (answ == 8)
	{
		cout << "Введите пример: \n"; //8задание
		double a, b, result;
		char S;
		cin >> a >> S >> b;
		if (S != '+' && S != '-' && S != '*' && S != '/')
			cout << "Используйте один из знаков: + - * /" << endl;
		else
		{
			switch (S)
			{
			case '+':
				result = a + b;
				break;
			case '-':
				result = a - b;
				break;
			case '*':
				result = a * b;
				break;
			case '/':
				if (b == 0)
				{
					cout << "На ноль делить нельзя.";
					return 0;
				}
				else
					result = a / b;
				break;
			}
			cout << result << endl;
		}
	}
	if (answ == 9)
	{
		cout << "Я хочу сыграть с тобой в игру! \n Попробуй угадать число от 0 до 100 включительно \n"; //9 задание
		int a, ua, c;
		srand(time(0));
		a = rand() % 100;
		c = 0;
		while (c < 5)
		{
			cin >> ua;
			if (ua == a)
			{
				cout << "Поздравляю! Вы угадали";
				c = 6;
			}
			else
			{
				if (ua > a)
					cout << "Загаданное число меньше \n";
				else
					cout << "Загаданное число больше \n";
				c++;
			}
		}
		if (c == 5)
			cout << "\n Вы проиграли. Было загадано: " << a << endl;
	}
	if (answ == 10)
	{
		cout << "Введите число и степень \n"; //10 задание
		double b, c, d = 1, i;
		cin >> c;
		cin >> b;
		if (c == 0)
		{
			if (b == 0)
				cout << "Ошибка" << endl;
			else
				cout << 0 << endl;
		}
		else
		{
			if (b == 0)
				cout << 1 << endl;
			else
			{
				i = c;
				if (b < 0)
				{
					b = -b;
					while (d != b)
					{
						c = c * i;
						d++;
					}
					c = 1 / c;
					cout << c << endl;
				}
				else
				{
					while (d != b)
					{
						c = c * i;
						d++;
					}
					cout << c << endl;
				}
			}
		}
	}
	if (answ == 11)
	{
		cout << "Введите число, которое хотите возвести в факториал \n"; //11 задание
		int a, b = 1, c = 1;
		cin >> a;
		while (b <= a)
		{
			c = b * c;
			b++;
		}
		cout << c;
	}
	if (answ == 12)
	{
		cout << "Введите число, которое хотите проверить. \n"; //12задача
		int a, b, c;
		cin >> a;
		b = 1;
		c = 0;
		while (a != b)
		{
			if (a % b == 0)
				c++;
			b++;
		}
		if (c > 1)
			cout << "Составное";
		else
			cout << "Простое";
	}
	if (answ == 13)
	{
		int n, a = 1, b = 0; //13 задание
		cin >> n;
		if (n != 0) {
			while (a <= n) {
				b++;
				a *= 2;
			}
		}
		cout << b << endl;
	}
	if (answ == 14)
	{
		int s, l1, r1, l2, r2;
		bool flag = false;
		cin >> s >> l1 >> r1 >> l2 >> r2;
		int l2_2 = l2;
		for (; l1 <= r1; l1++) {
			for (l2 = l2_2; l2 <= r2; l2++) {
				if (l1 + l2 == s) {
					flag = true;
					break;
				}
			}
			if (flag)break;
		}
		if (flag)cout << l1 << ' ' << l2 << endl;
		else cout << -1 << endl;
	}
system("pause");
}