#include "task1/Array.cpp"

void task1_2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();

int main() {
	setlocale(LC_ALL, "rus");
	
	task9();

	return 0;
}

void task1_2() {
	Array<string> arr(10, "hi"); Array<string>arr2(10, "bye");
	arr = arr2;

	arr.display();
	arr2.display();
	cout << arr2[3] << ' ' << arr2.size() << endl;
	/*
	Student st1("Nikita", "bist-214", "1314");
	Array <Student> as(10, st1);
	as.display();
	*/
}
void task3() {
	ValueHolder <int> a(10);
	a.clone();
}
void task4() {
	int ints[] = { 1, 2, 3, 4 };
	double doubles[4] = {};
	copy_n(doubles, ints, 4);
	for (int i = 0; i < 4; i++)
		cout << setprecision(1) << fixed << doubles[i] << ' ';
	cout << endl;
}
void task5() {
	Array<int> ints(3);
	ints[0] = 10;
	ints[1] = 2;
	ints[2] = 15;
	cout << minimum(ints, Greater()) << endl;
}
void task6() {
	Array<int> int2s(2, 0);
	int2s[0] = 10;
	int2s[1] = 20;
	int2s.display();

	Array< Array<int> > arrInts(2, int2s);
	flatten(arrInts, cout);
}
void task7() {
	Any i(10);
	i = 100;
	const int* Cast = i.cast<int>();
	cout << *Cast << endl;
}
void task8() {
	struct Dummy { };
	typedef int type;
	cout << "Значение: " << Type<int, int>::value << endl;
	cout << "Значение: " << Type<int, type>::value << endl;
	cout << "Значение: " << Type<int, int&>::value << endl;
	cout << "Значение: " << Type<Dummy, Dummy>::value << endl;
	cout << "Значение: " << Type<int, const int>::value << endl;
}
void task9() {
	int ints[] = { 1, 2, 3, 4 };
	int* iptr = ints;
	double doubles[] = { 3.14 };
	cout << array_size(ints) << endl;
	cout << array_size(doubles) << endl;
}
