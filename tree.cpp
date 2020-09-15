#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class tree {
private:
	ll i = 0, index = 1, len = 0, inf = 1e18;
	ll mas[1000], maxx[1000], minn[1000];

	void balance() {
		for (int j = index - 1; j > 0; j--) {
			mas[j] = mas[j * 2] + mas[j * 2 + 1];
			maxx[j] = maxxx(maxx[j * 2], maxx[j * 2 + 1]);
			minn[j] = minnn(minn[j * 2], minn[j * 2 + 1]);
		}
	}

	ll maxxx(ll first, ll second) {
		if (first > second) return first;
		else return second;
	}

	ll minnn(ll first, ll second) {
		if (first < second) return first;
		else return second;
	}

	void step(ll lenght) {
		while (index < lenght) index *= 2;
	}
public:
	void create(ll lenght) {
		len = lenght;
		step(lenght);
		for (int j = 0; j < index; j++) {
			mas[index + j] = 0;
			maxx[index + j] = -inf;
			minn[index + j] = inf;
		}
	}

	ll size() { return index; }

	ll lenght() { return len; }

	void push(ll element) {
		mas[index + i] = element;
		maxx[index + i] = element;
		minn[index + i] = element;
		i++;
		balance();
	}

	ll summary(ll l, ll r) {
		ll aa = 0;
		l += index - 1;
		r += index - 1;
		while (l <= r) {
			if (l % 2 == 1) aa += mas[l];
			if (r % 2 == 0) aa += mas[r];
			l = (l + 1) / 2;
			r = (r - 1) / 2;
		}
		return aa;
	}

	ll maximum(ll l, ll r) {
		ll aa = -inf;
		l += index - 1;
		r += index - 1;
		while (l <= r) {
			if (l % 2 == 1) aa = maxxx(aa, maxx[l]);
			if (r % 2 == 0) aa = maxxx(aa, maxx[r]);
			l = (l + 1) / 2;
			r = (r - 1) / 2;
		}
		return aa;
	}

	ll minimum(ll l, ll r) {
		ll aa = inf;
		l += index - 1;
		r += index - 1;
		while (l <= r) {
			if (l % 2 == 1) aa = minnn(aa, minn[l]);
			if (r % 2 == 0) aa = minnn(aa, minn[r]);
			l = (l + 1) / 2;
			r = (r - 1) / 2;
		}
		return aa;
	}
};


int main() {
	// Писать свой код, для пользования Деревом Отрезков (далее - ДО)
	// Ниже будет полный гайд по пользованию этой структурой данных
	// Данный код стоит стереть после прочтения и ознакомления

	tree derevo;
	// Создание самого значения ДО (переменная derevo)

	derevo.create(7);
	// Назначение размера ДО (от 1 до n включительно). В данном случае n = 7. Если не сделать данное действие, код будет неработастпособен
	// Время работы .create() составляет О(n)

	derevo.size();
	// заметим, что никакого агрумента передавать не нужно. Функция будет возвращать значение длины ДО. Можно сделать cout << derevo.size();
	// ВНИМАНИЕ!! Размер ДО будет равен ближайшему числу, который не меньше чем n. Размер ДО всегда равен степени двойки (ближайшая не меньшая степень 2 это 2^3 = 8)
	// При обращении к незаданному derevo.create(n) будет возвращена 1
	// Время работы .size() составляет О(1)

	derevo.lenght();
	// Тот же .size(), но возвращает уже реальную длину ДО. Если обратиться к незаданному ДО, вернется 0
	// Время работы .lenght() составляет О(1)

	derevo.push(3);
	// Запихивает элемент n (в данном случае 3) в ДО
	// Время работы .push() составляет О(1), дальше происходит изменение ДО за O(n)

	derevo.summary(2, 5);
	// Находит сумму от 2 элемента до 5 включительно. Аргументами функции является левая и правая границы
	// Время работы .summary() составляет О(logn)

	derevo.maximum(2, 5);
	// Находит сумму от 2 элемента до 5 включительно. Аргументами функции является левая и правая границы
	// Время работы .maximum() составляет О(logn)

	derevo.minimum(2, 5);
	// Находит сумму от 2 элемента до 5 включительно. Аргументами функции является левая и правая границы
	// Время работы .maximum() составляет О(logn)


	// Если нахождение суммы/максимум/минимума обычным перебором для n = 10^9 это 10^9 итераций, то в ДО это 32 итерации
	// Все эти 3 функции возврацают значение. Их можно вывести через cout или приравнять какой либо переменной long long



	// Привер реальной проги
	// Перед запуском удалить весь гайд


	long long n, number, l, r;
	tree mas;
	cin >> n; // Ввод длины ДО
	mas.create(n); // Создание ДО длины n
	for (int i = 1; i <= n; i++) {
		cin >> number; // Ввод каждого элемента
		mas.push(number); // Запихивание элемента в ДО
	}
	cin >> l >> r; // Левая и правая граница
	cout << "sum: " << mas.summary(l, r
	) << endl; // Вывод суммы от l до r
	cout << "max: " << mas.maximum(l, r) << endl; // Вывод максимума от l до r
	cout << "min: " << mas.minimum(l, r) << endl; // Вывод минимума от l до r


	/*
	 Тест:
	 5
	 3 2 5 10 2
	 1 4

	 Правильный ответ:
	 sum: 20
	 max : 10
	 min : 2
	*/
}