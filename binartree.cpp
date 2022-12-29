#include <iostream>
#include <list>
using namespace std;

int tabs = 0;
int kol_vo = 0;
list <int> listed = {};


//ДОБАВИЛ МЕТОД ВОЗВРАЩАЮЩИЙ ВСЕ ЭЛЕМЕНТЫ ПОДДЕРЕВА В СПИСКЕ (subTree)
template<class T>
class Branch {
	public:
	T Data;
	T g;
	Branch* LeftBranch;
	Branch* RightBranch;
	Branch* Root;
	Branch( Branch*& aBranch ) {
		Root = aBranch;
	}
	Branch()
	{
	}

	void Add(T aData){
	if (!Root){
	Root = new Branch;
	Root->Data = aData;
	Root->LeftBranch = 0;
	Root->RightBranch = 0;
	return;
	}
	else
	if (Root->Data > aData){
	Add(aData, Root->LeftBranch);
	}
	else{
	Add(aData, Root->RightBranch);
	};
	}

	void Add(T aData, Branch*& aBranch){
	if (!aBranch){
	aBranch = new Branch;
	aBranch->Data = aData;
	aBranch->LeftBranch = 0;
	aBranch->RightBranch = 0;
	return;
	}
	else
	if (aBranch->Data > aData){
	Add(aData, aBranch->LeftBranch);
	}
	else{
	Add(aData, aBranch->RightBranch);
	};
	}

	void print()
	{
	if (!Root) return;
	tabs += 5;
	print(Root->LeftBranch);
	for (int i = 0; i < tabs; i++) cout << " ";
	cout << Root->Data << endl;
	print(Root->RightBranch);
	tabs-= 5;
	return;
	}
	void print(Branch* aBranch)
	{
	if (!aBranch) return;
	tabs += 5;
	print(aBranch->LeftBranch);
	for (int i = 0; i < tabs; i++) cout << " ";
	cout << aBranch->Data << endl;
	print(aBranch->RightBranch);
	tabs-= 5;
	return;
	}

	void add_elem(T aData)
	{
	if (!Root)
	{
	Root = new Branch;
	Root->Data = aData;
	Root->LeftBranch = 0;
	Root->RightBranch = 0;
	return;
	}
	else
	{
	if (aData < Root->Data) {
	add_elem(aData, Root->LeftBranch);
	}
	else if (aData > Root->Data) {
	add_elem(aData, Root->RightBranch);
	}
	}
	}

	void add_elem(T aData, Branch*& aBranch)
	{
	if (!aBranch)
	{
	aBranch = new Branch;
	aBranch->Data = aData;
	aBranch->LeftBranch = 0;
	aBranch->RightBranch = 0;
	return;
	}
	else
	{
	if (aData < aBranch->Data) {
	add_elem(aData, aBranch->LeftBranch);
	}
	else if (aData > aBranch->Data) {
	add_elem(aData, aBranch->RightBranch);
	}
	}
	}

Branch* del_elem(Branch*& aBranch, T aData) {
	if (aBranch == NULL)
	return aBranch;
	if (aData == aBranch->Data) {
	Branch* tmp;
	if (aBranch->RightBranch == NULL)
	tmp = aBranch->LeftBranch;
	else {
	Branch* ptr = aBranch->RightBranch;
	if (ptr->LeftBranch == NULL) {
	ptr->LeftBranch = aBranch->LeftBranch;
	tmp = ptr;
	}
	else {
	Branch* pmin = ptr->LeftBranch;
	while (pmin->LeftBranch != NULL) {
	ptr = pmin;
	pmin = ptr->LeftBranch;
	}
	ptr->LeftBranch = pmin->RightBranch;
	pmin->LeftBranch = aBranch->LeftBranch;
	pmin->RightBranch = aBranch->RightBranch;
	tmp = pmin;
	}
	}
	delete aBranch;
	return tmp;
	}
	else if (aData < aBranch->Data)
	aBranch->LeftBranch = del_elem(aBranch->LeftBranch, aData);
	else
	aBranch->RightBranch = del_elem(aBranch->RightBranch, aData);
	return aBranch;
	}

	Branch* del_elem(T aData) {
	if (Root == NULL)
	return Root;
	if (aData == Root->Data) {
	Branch* tmp;
	if (Root->RightBranch == NULL)
	tmp = Root->LeftBranch;
	else {
	Branch* ptr = Root->RightBranch;
	if (ptr->LeftBranch == NULL) {
	ptr->LeftBranch = Root->LeftBranch;
	tmp = ptr;
	}
	else {
	Branch* pmin = ptr->LeftBranch;
	while (pmin->LeftBranch != NULL) {
	ptr = pmin;
	pmin = ptr->LeftBranch;
	}
	ptr->LeftBranch = pmin->RightBranch;
	pmin->LeftBranch = Root->LeftBranch;
	pmin->RightBranch = Root->RightBranch;
	tmp = pmin;
	}
	}
	delete Root;
	return tmp;
	}
	else if (aData < Root->Data)
	Root->LeftBranch = del_elem(Root->LeftBranch, aData);
	else
	Root->RightBranch = del_elem(Root->RightBranch, aData);
	return Root;
	}

	void vivod(Branch* aBranch)
	{
	if (!aBranch) return;
	vivod(aBranch->LeftBranch);
	g = aBranch->Data;
	listed.push_back(g);
	vivod(aBranch->RightBranch);
	return;
	}


void change(T aData, T bData, Branch*& aBranch)
{
	if (NULL == aBranch)    return;   

	if (aBranch->Data == aData)
	{
		aBranch->Data = bData;
		return;
	}
	change(aData, bData, aBranch->LeftBranch);   
	change(aData, bData, aBranch->RightBranch); 
	return;
}
void change(T aData, T bData)
{
	if (NULL == Root)    return; 

	if (Root->Data == aData)
	{	
		Root->Data = bData;
		return;
	}
	change(aData, bData, Root->LeftBranch);  
	change(aData, bData, Root->RightBranch); 
	return;
}

};

int main()
{
setlocale(LC_ALL, "rus");
int number;
int value;
list<int> a;
Branch<int>* Root = 0;
Branch D(Root);
int vel;
int element;
int k;
cout << "Кол-во Элементов: ";
cin >> vel;
cout << endl;
for (int i = 0; i < vel; i++)
{
value = rand() % 100;
cout << "Добавление - " << value << endl;
D.Add(value);
}
cout << "Вывод дерева: " << endl;
D.print();
cout << "Элемент для Добавления:" << endl;
cin >> element;
D.add_elem(element);
cout << "Вывод дерева: " << endl;
D.print();
cout << "Элемент для поискаа:" << endl;
cin >> number;
cout << "Заменить на: " << endl;
cin >> value;
D.change(number, value);
cout << "Вывод дерева: " << endl;
D.print();
}