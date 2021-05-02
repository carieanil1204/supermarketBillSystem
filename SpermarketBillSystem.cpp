#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;
//*************
class supermarket
{
private:
	string product_name;
	double product_price;
	int product_id;
public:

	supermarket();
	void set_name(string);
	void set_price(double);
	void set_id(int);
	string get_name();
	double get_price();
	int get_id();
	void show();
};
//*********
void supermarket::set_name(string _name)
{
	product_name = _name;
}
//************
void supermarket::set_price(double _price)
{
	product_price = _price;
}
//*************
supermarket::supermarket()
{
	product_name = "\0";
	product_price = 0;
}
//************
string supermarket::get_name()
{
	return product_name;
}
//************
double supermarket::get_price()
{
	return product_price;
}
//*************
void supermarket::set_id(int _id)
{
	product_id = _id;
}
//***************
int supermarket::get_id()
{
	return product_id;
}
//*****************
void supermarket::show()
{
	if (product_id != -1)
		cout << product_id << "\t\t\t" << product_name << "\t\t\t\t" << product_price << endl;
}
//**************
void adminstrater(supermarket[], int&);
void admin_add(supermarket[], int&);
bool check(string, supermarket[], int );
void display(supermarket[] ,int );
void admin_edit(supermarket[], int);
void admin_remove(supermarket[], int);
void costumer(supermarket[], int);
//******************
int main()
{
	const int size = 30;
	supermarket sp[size];
	int number = 0;

	while (true)
	{
		cout << "\t\t\t****************************\n\t\t\t" <<
		"Welcome to the supermarket"
		<< "\n\t\t\t****************************\n";

		cout << "\t\t\t1)Enter as a adminstarter\n\t\t\t2)enter as a costumer\n\t\t\t3)exit\n";
		cout << "\t\t\tplease enter your option:\t";

		int option;
		cin >> option;

		if (option == 1)
			adminstrater(sp, number);
		if (option == 2)
			costumer(sp, number);
		if (option == 3)
			exit(0);
	}
}
//****************
void adminstrater(supermarket sp[], int&number)
{
	system("cls");

	cout << "1)Add a product\n2)Edit a product\n3)Remove a product\n4)display products\n5)Back to main menu\n";
	cout << "Choose a option:\t";

	int option;
	cin >> option;

	if (option == 1)
		admin_add(sp, number);

	if (option == 2)
		admin_edit(sp, number);

	if (option == 3)
		admin_remove(sp, number);

	if (option == 4)
	{
		system("cls");
		display(sp, number);
		cout << "Press 'Enter' to back to the main menu\n";
		_getch();
		system("cls");
	}

	if (option == 5)
		system("cls");
}
//***************
void admin_add(supermarket sp[], int& number)
{
	system("cls");

	cin.clear();
	cin.ignore();

	string _name;
	while (true)
	{
		cout << "Enter product name:\n";

		getline(cin,_name);

		if (check(_name, sp, number))
			break;

		cout << "Already Exist try another\n";
	}
	cout << "Enter product price:\n";

	double _price;
	cin >> _price;

	sp[number].set_name(_name);
	sp[number].set_price(_price);
	sp[number].set_id(number);
	number++;

	cout << "Press 'Enter' to back to the main menu\n";
	_getch();

	system("cls");
}
//*******************
bool check(string name, supermarket sp[], int number)
{
	if (number == 0)
		return true;

	for (int i = 0; i < number; i++)
	{
		if (name == sp[i].get_name())
			return false;
	}
	return true;
}
//*******************
void display(supermarket sp[], int number)
{
	cout << "-------------------------------------------------------------\n";
	cout << "Product id\t\tProduct name \t\t Product price\n";
	cout << "-------------------------------------------------------------\n";

	for (int i = 0; i < number; i++)
		sp[i].show();
}
//*************
void admin_edit(supermarket sp[], int number)
{
	cin.clear();
	cin.ignore();

	system("cls");

	cout << "Enter the product name:\n";

	string name;
	int n_product;
	bool flag =true ;

	while (flag)
	{
		getline(cin, name);

		for (n_product=0; n_product < number; n_product++)
		{
			if (name == sp[n_product].get_name())
			{
				flag = false;
				break;
			}
		}

		if(flag)
			cout <<"not found,try another\n";
	}

	cout << "The product information:\n";
	cout << "Product name\tproduct price\n";

	cout << sp[n_product].get_name() << "\t\t\t" << sp[n_product].get_price() << endl;

	cout << "1)Edit name\n2)Edit price\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		cout << "Enter the new name:\n";

		cin.clear();
		cin.ignore();

		string name;

		while (true)
		{
			getline(cin,name);

			if (check(name, sp, number))
				break;

			cout << "Already Exist try another\n";
		}
		sp[n_product].set_name(name);

		cout << "Editted Succesfully\n";
	}
	if (option == 2)
	{
		cout << "Enter the new price:\n";

		double price;
		cin >> price;

		sp[n_product].set_price(price);

		cout << "Editted Succesfully\n";
	}
	cout << "Press 'Enter' to back to the main menu\n";
	_getch();

	system("cls");
}
//*******************
void admin_remove(supermarket sp[], int number)
{
	cin.clear();
	cin.ignore();

	system("cls");

	cout << "Enter the product name:\n";

	string name;
	int n_product = 0;
	bool flag = true;

	while (flag)
	{
		getline(cin, name);

		for (; n_product < number; n_product++)
		{
			if (name == sp[n_product].get_name())
			{
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "not found,try another\n";
	}
	sp[n_product].set_id(-1);

	cout << "Remove Successfully\n";
	cout << "Press 'Enter' to back to the main menu\n";

	_getch();

	system("cls");
}
//**************
void costumer(supermarket sp[], int number)
{
	system("cls");

	display(sp, number);

	double pay_list = 0;

	while (true)
	{
		cout << "Enter the item id you want to buy:\t";
		int _id;
		cin >> _id;

		cout << "Enter the quantity of item:\t";
		int quantity;
		cin >> quantity;

		pay_list += sp[_id].get_price() * quantity;

		cout << "Your pay list is " << pay_list << ",wanna buy more(y/n)?\t";

		char ch;
		cin >> ch;

		if (ch == 'n')
			break;
	}
	cout << "Press 'Enter' to back to the main menu\n";
	_getch();

	system("cls");
}