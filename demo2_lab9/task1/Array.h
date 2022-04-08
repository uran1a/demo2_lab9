#include <iostream>
#include <locale>
#include <iomanip>
#include <fstream>
using namespace std;

template <class T>
class Array {
private:
	T* myArray;
	size_t n;
public:
	//explicit Array(size_t size = 0, const T& value = T());
	explicit Array(size_t size = 0, const T& value = T());
	Array(const Array&);
	~Array();
	Array& operator = (const Array&);
	T& operator [] (size_t idx);
	const T& operator [](size_t idx) const;
	size_t size() const;
	void display();

};
class Student
{
private:
	string name;
	string number;
	string gruppa;
public:
	Student() {}
	Student(string name, string gruppa, string number) : name(name), gruppa(gruppa), number(number) {}
	operator string() const { return name; }
	
	//std::ostream& operator << (std::ostream& stream, const Student& matrix){};
	void getStudent() {
		cout << name << endl;
		cout << gruppa << endl;
		cout << number << endl;
	}
};
struct Icloneable {
	virtual Icloneable* clone() const = 0;
	virtual ~Icloneable() {}
};
template <typename T>
struct ValueHolder : public Icloneable {
	T data_;
	ValueHolder(const T& data_) : data_(data_)
	{
		cout << "Конструктор: " << this << endl;
	}
	ValueHolder* clone() const {
		cout << "Копирование: " << this << endl;
		return new ValueHolder(data_);
	}
	~ValueHolder(){ cout << "Деструктор: " << this << endl; }
};
//4
template <class T, class U>
void copy_n(T* Dest, U* Src, int Count)
{
	for (int i = 0; i < Count; ++i)
		Dest[i] = Src[i];
}
//5
struct Greater {
	bool operator()(int a, int b) {
		return b < a;
	}
};
template <typename T>
bool less(T a, T b) {
	return a < b;
}
template <typename T, typename C>
T minimum(Array<T> arr, C comp) {
	T temp = arr[0];
	for (int i = 0; i < sizeof(arr) / sizeof(T); i++)
	{
		if (comp(arr[i], temp))
			temp = arr[i];
	}
	return temp;
}
//6
template <typename T>
void flatten(const Array<T>& arr, ostream& out);
template <typename T>
void flatten(const Array< Array<T> >& arr, ostream& out);
//7
class Any {
private:
	Icloneable* arr;
public:
	Any() : arr(0)
	{}
	template <typename T>
	Any(const T& value) : arr(new ValueHolder<T>(value))
	{}
	~Any() { delete arr; }
	Any(const Any& other) : arr(other.arr->clone())
	{}
	template<class T>
	Any& operator = (const T& other)
	{
		delete this->arr;
		this->arr = new ValueHolder<T>(other);

		return *this;
	}
	Any& operator = (const Any& other)
	{
		delete this->arr;
		this->arr = other.arr->clone();

		return *this;
	}
	template<class T>
	const T* cast(void) const
	{
		ValueHolder<T>* temp = dynamic_cast<ValueHolder<T>*>(arr);
		if (temp) return &temp->data_;
		else return 0;
	}
};
//8
template<class T1, class T2>
struct Type { 
	static const bool value; 
};

template<class T1, class T2> 
const bool Type<T1, T2>::value = false;

template<class T>
struct Type<T, T> { 
	static const bool value; 
};

template<class T> 
const bool Type<T, T>::value = true;
//9
template<typename T, size_t N>
size_t array_size(T(&arr)[N]) {
	return N;
}
