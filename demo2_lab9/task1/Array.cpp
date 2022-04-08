#include "Array.h"
// 1-2
template <class T>
 Array<T>::Array(size_t size, const T& value) : n(size) {
	this->myArray = (T*) new char[n * sizeof(T)];
	for (uint16_t i = 0; i < n; i++) new (myArray + i) T(value);
}
template <class T>
Array<T>::Array(const Array& other) : n(other.size())
{
	this->myArray = (T*) new T[n];
	for (uint16_t i = 0; i < n; i++) {
		new (myArray + i) T(other.myArray[i]);
		//this->myArray[i] = other[i];
	}
}
template <class T>
Array<T>::~Array() {
	for (size_t i = 0; i < n; i++)
		myArray[i].~T();
	delete[] this->myArray;
}
template <class T>
Array<T>& Array<T>::operator = (const Array<T>& mas) {
	//this->~Array;
	/*
	for (size_t i = 0; i < n; i++)
		myArray[i].~T();
	delete[] this->myArray;

	this->n = mas.n;
	this->myArray = (T*) new char[n * sizeof(T)];
	for (size_t i = 0; i < this->n; i++) this->myArray[i] = mas.myArray[i];
	*/
	if (this != &mas) {
		for (size_t i = 0; i < n; ++i) {
			myArray[i].~T();
		}
		delete[](char*) myArray;

		this->n = mas.size();
		myArray = (T*) new char[mas.size() * sizeof(T)];

		for (size_t i = 0; i != n; ++i) {
			new (myArray + i) T(mas.myArray[i]);
		}
	}
	return *this;
}
template<class T>
T& Array<T>::operator[](size_t idx)
{
	if (idx >= n) cout << "error" << endl;
	return this->myArray[idx];
}
template<class T>
const T& Array<T>::operator[](size_t idx) const
{
	if (idx >= n) cout << "error" << endl;
	return this->myArray[idx];
}
template<class T>
size_t Array<T>::size() const
{
	return this->n;
}
template <class T>
void Array<T>::display() {
	for (size_t i = 0; i < this->n; i++)
		cout << this->myArray[i] << ' ';
	cout << endl;
};
template <typename T>
void flatten(const Array<T>& arr, ostream& out) {
	for (size_t i = 0; i < arr.size(); i++)
		out << arr[i] << ' ';
}
template <typename T>
void flatten(const Array< Array<T> >& arr, ostream& out) {
	for (size_t i = 0; i < arr.size(); i++)
		flatten(arr[i], out);
}


