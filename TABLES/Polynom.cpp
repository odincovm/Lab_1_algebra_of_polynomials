#include "Polynom.h"
#include <string>
using namespace std;

bool isDigit(const string str) {
	if (str >= "0" && str <= "9") return true;
	return false;
}

void Polynom::parseAndAddMonoms(const string input)
{
	size_t pos = 0;
	size_t nextSignPos = 0;
	do
	{
		nextSignPos = input.find_first_of("+-", pos + 1);
		if (nextSignPos == string::npos)
		{
			nextSignPos = input.size();
		}
		string term = input.substr(pos, nextSignPos - pos);
		pos = nextSignPos;

		size_t x_pos = term.find('x');
		size_t y_pos = term.find('y');
		size_t z_pos = term.find('z');
		// �������� �����������
		double coef = 0.0; bool flag = false;
		if (!isDigit(term.substr(0, x_pos))) {
			if (term.substr(0, x_pos) == "+" || term.substr(0, x_pos) == "") { coef = 1.0; flag = true; }
			if (term.substr(0, x_pos) == "-") {
				coef = -1.0; flag = true;
			}
		}
		if (flag == false) coef = stod(term.substr(0, x_pos));
		// �������� ������� ����������
		size_t degx = 0, degy = 0, degz = 0;
		if (x_pos != string::npos)
		{
			size_t y_deg_pos = term.find_first_of("0123456789", y_pos);
			size_t x_deg_pos = term.find_first_of("0123456789", x_pos);
			if (y_deg_pos == x_deg_pos) degx = 1;
			else {
				if (x_deg_pos != string::npos)
				{
					degx = stoi(term.substr(x_deg_pos));
				}
				else
				{
					degx = 1;
				}
			}
		}
		if (y_pos != string::npos)
		{
			size_t z_deg_pos = term.find_first_of("0123456789", z_pos);
			size_t y_deg_pos = term.find_first_of("0123456789", y_pos);
			if (y_deg_pos == z_deg_pos) degy = 1;
			else {
				if (y_deg_pos != string::npos)
				{
					degy = stoi(term.substr(y_deg_pos));
				}
				else
				{
					degy = 1;
				}
			}
		}
		if (z_pos != string::npos)
		{
			size_t z_deg_pos = term.find_first_of("0123456789", z_pos);
			if (z_deg_pos != string::npos)
			{
				degz = stoi(term.substr(z_deg_pos));
			}
			else
			{
				degz = 1;
			}
		}
		Monom monom = { coef, degx, degy, degz };
		poly.addNode(monom);
	} while (nextSignPos < input.size());
	castMonom();
}

void Polynom::printPolynom() {
	Node<Monom>* current = poly.FrontNode();
	bool isFirst = true;  // ���������� ��� ������������ ������� ������
	while (current != nullptr) {
		// ���� ����������� ������������� � ��� �� ������ �����, ������� ���� ����
		if (current->data.coef == 0) current = current->pNext;
		if (current->data.coef > 0 && !isFirst) {
			cout << "+";
		}

		// ������� �����������, ���� �� �� ����� 1 ��� -1
		if (current->data.coef != 1 && current->data.coef != -1) {
			cout << current->data.coef;
		}
		else if (current->data.coef == -1) {
			cout << "-";
		}

		// �������� ����� ������ � ����������� � ���������
		cout << "x" << current->data.degx << "y" << current->data.degy << "z" << current->data.degz;

		isFirst = false;
		current = current->pNext;
	}
	cout << endl;
}

void Polynom::castMonom() {
	Node<Monom>* current = poly.FrontNode();
	while (current != nullptr) {
		Node<Monom>* runner = current;
		while (runner->pNext != nullptr) {
			if (runner->pNext->data.degx == current->data.degx &&
				runner->pNext->data.degy == current->data.degy &&
				runner->pNext->data.degz == current->data.degz) {
				current->data.coef += runner->pNext->data.coef;  // ���������� ������������
				Node<Monom>* temp = runner->pNext;
				runner->pNext = temp->pNext;  // ������� ������������ �����
				delete temp;
			}
			else {
				runner = runner->pNext;
			}
		}
		current = current->pNext;
	}
}

void Polynom::addPolynom(Polynom& p) {
	Node<Monom>* pCurrent = p.getPolyFrontNode();
	while (pCurrent != nullptr) {
		poly.addNode(pCurrent->data);
		pCurrent = pCurrent->pNext;
	}
	castMonom();
	poly.removeZeroCoefficient();
}

Node<Monom>* Polynom::getPolyFrontNode() {
	return poly.FrontNode();
}

void Polynom::multiplyPolynom(Polynom& p) {
	myList<Monom> resultPoly;  // ��������� ���������
	Node<Monom>* current = poly.FrontNode();
	while (current != nullptr) {
		Node<Monom>* otherCurrent = p.getPolyFrontNode();
		while (otherCurrent != nullptr) {
			double coef = current->data.coef * otherCurrent->data.coef;  // �������� ������������
			size_t degx = current->data.degx + otherCurrent->data.degx;
			size_t degy = current->data.degy + otherCurrent->data.degy;
			size_t degz = current->data.degz + otherCurrent->data.degz;
			Monom newMonom = { coef, degx, degy, degz };
			resultPoly.addNode(newMonom);  // ��������� ���������� ����� � ���������
			otherCurrent = otherCurrent->pNext;
		}
		current = current->pNext;
	}
	// ������ ����������� ��������� ���������� poly
	poly = resultPoly;
}
double Polynom::calcPolynom(double x, double y, double z) {
	Node<Monom>* current = poly.FrontNode();
	double sum = 0.0;
	while (current != nullptr) {
		sum += (current->data.coef * pow(x, current->data.degx) * pow(y, current->data.degy) * pow(z, current->data.degz));
		current = current->pNext;
	}
	return sum;
}

