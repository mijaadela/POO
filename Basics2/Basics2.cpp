#include<iostream>
#include<fstream>
using namespace std;

class Cofetarie {
private:
	char* denumire;
	float cheltuieliUtilitati;
	float cheltuieliSalariale;
	float profitLuna;
public:

	Cofetarie();
	Cofetarie(char* den, float cU, float cS, float p);
	Cofetarie(Cofetarie& copie);
	~Cofetarie();

	//metode de acces
	char* getDenumire();
	float getCheltUtilitati();
	float getCheltSalariale();
	float getProfit();
	void setDenumire(char* den);
	void setCheltUtilitai(float cU);
	void setCheltSalariale(float cS);
	void setProfit(float p);

	void operator=(Cofetarie &c);

	//metode pt fisiere
	void citireFisierText(char* fisier);
	void scriereFisierText(char* fisier);
	void citireFisierCVS(char* fisier);
	void scriereFisierCVS(char* fisier);
	void serializareDate(char* fisier);
	void deserializareDate(char* fisier);
};

Cofetarie::Cofetarie(){
	this->denumire = new char[strlen("Necunoscuta") + 1];
	strcpy(this->denumire, "Necunoscuta");
	this->cheltuieliUtilitati = 1700;
	this->cheltuieliSalariale = 5430;
	this->profitLuna = 1500;
}

Cofetarie::Cofetarie(char* den, float cU, float cS, float p) {
	this->denumire = new char[strlen(den) + 1];
	strcpy(this->denumire, den);
	this->cheltuieliUtilitati = cU;
	this->cheltuieliSalariale = cS;
	this->profitLuna = p;
}

Cofetarie::Cofetarie(Cofetarie& copie) {
	if (copie.denumire != NULL)
	{
		delete[] this->denumire;
		this->denumire = new char[strlen(copie.denumire) + 1];
		strcpy(this->denumire, copie.denumire);
	}
	this->cheltuieliUtilitati = copie.cheltuieliUtilitati;
	this->cheltuieliSalariale = copie.cheltuieliSalariale;
	this->profitLuna = copie.profitLuna;
}

Cofetarie::~Cofetarie() {
	if (this->denumire != NULL)
		delete[] this->denumire;
}

char* Cofetarie::getDenumire() {
	return this->denumire;
}

float Cofetarie::getCheltUtilitati() {
	return this->cheltuieliUtilitati;
}

float Cofetarie::getCheltSalariale() {
	return this->cheltuieliSalariale;
}

float Cofetarie::getProfit() {
	return this->profitLuna;
}

void Cofetarie::setDenumire(char* den) {
	if (this->denumire != NULL)
	{
		this->denumire = new char[strlen(den) + 1];
		strcpy(this->denumire, den);
	}
}

void Cofetarie::setCheltUtilitai(float cU) {
	this->cheltuieliUtilitati = cU;
}

void Cofetarie::setCheltSalariale(float cS) {
	this->cheltuieliSalariale = cS;
}

void Cofetarie::setProfit(float p) {
	this->profitLuna = p;
}

void Cofetarie::operator=(Cofetarie &c) {
	if (c.getDenumire() != NULL)
	{
		this->denumire = new char[strlen(c.getDenumire()) + 1];
		strcpy(this->denumire, c.getDenumire());
	}
	this->cheltuieliUtilitati = c.cheltuieliUtilitati;
	this->cheltuieliSalariale = c.cheltuieliSalariale;
	this->profitLuna = c.profitLuna;
}

//lucrul cu fisiere
void Cofetarie::citireFisierText(char* fisier) {
	ifstream in;
	in.open(fisier, ios::in);
	if (in.is_open())
	{
		char buffer[300];
		in >> buffer;
		this->denumire = new char[strlen(buffer) + 1];
		strcpy(this->denumire, buffer);
		
		float cheltUtilitati;
		in >> cheltUtilitati;
		this->cheltuieliUtilitati = cheltUtilitati;

		float cheltSalariale;
		in >> cheltSalariale;
		this->cheltuieliSalariale = cheltSalariale;

		float profit;
		in >> profit;
		this->profitLuna = profit;
	}
	in.close();
	cout << "Datele au fost citite din " << fisier << endl;
}

void Cofetarie::scriereFisierText(char* fisier) {
	ofstream out;
	out.open(fisier, ios::out);
	if (out.is_open())
	{
		out << this->denumire;
		out << endl;
		out << this->cheltuieliUtilitati;
		out << endl;
		out << this->cheltuieliSalariale;
		out << endl;
		out << this->profitLuna;
		out << endl;
	}
	out.close();
	cout << "Fisierul " << fisier << " a fost generat" << endl;
}

void Cofetarie::citireFisierCVS(char* fisier) {
	ifstream in;
	in.open(fisier, ios::in);
	if (in.is_open())
	{
		char buffer[1000];
		in >> buffer;

		char* token = strtok(buffer, ",");
		this->denumire = new char[strlen(token) + 1];
		strcpy(this->denumire, token);
		token = strtok(NULL, ",");
		this->cheltuieliUtilitati = atof(token);
		token = strtok(NULL, ",");
		this->cheltuieliSalariale = atof(token);
		token = strtok(NULL, ",");
		this->profitLuna = atof(token);
	}
	in.close();
	cout << "Datele au fost citite din " << fisier << endl;
}

void Cofetarie::scriereFisierCVS(char* fisier) {
	ofstream out;
	out.open(fisier, ios::out);
	if (out.is_open())
	{
		out << this->denumire;
		out << endl;
		out << this->cheltuieliUtilitati;
		out << endl;
		out << this->cheltuieliSalariale;
		out << endl;
		out << this->profitLuna;
		out << endl;
	}
	out.close();
	cout << "Fisierul " << fisier << " a fost generat" << endl;
}

void Cofetarie::serializareDate(char* fisier) {
	ofstream out;
	out.open(fisier, ios::out | ios::binary);
	if (out.is_open())
	{
		int nrCaractere = strlen(this->denumire) + 1;
		out.write((char*)&nrCaractere, sizeof(int));
		out.write(this->denumire, sizeof(char) * nrCaractere);

		out.write((char*)&this->cheltuieliUtilitati, sizeof(float));
		out.write((char*)&this->cheltuieliSalariale, sizeof(float));
		out.write((char*)&this->profitLuna, sizeof(float));
	}
	out.close();
	cout << "Fisierul " << fisier << " a fost generat" << endl;
}

void Cofetarie::deserializareDate(char* fisier) {
	ifstream in;
	in.open(fisier, ios::in | ios::binary);
	if (in.is_open())
	{
		int nrCaractere;
		in.read((char*)&nrCaractere, sizeof(int));
		this->denumire = new char[nrCaractere];
		in.read(this->denumire, sizeof(char) * nrCaractere);

		in.read((char*)&this->cheltuieliUtilitati, sizeof(float));
		in.read((char*)&this->cheltuieliSalariale, sizeof(float));
		in.read((char*)&this->profitLuna, sizeof(float));
	}
}


void main() {
	Cofetarie c1;
	Cofetarie c2("Mar-Vio", 1500, 4750, 2000);
	c1.citireFisierText("Date.txt");
	cout << c2.getDenumire() << " are urmatoarele cheltuieli salariale: " << c1.getCheltSalariale() << endl;

	c2.scriereFisierText("Date2.txt");
	c1.scriereFisierCVS("Date.cvs");
	c1.citireFisierCVS("Date.cvs");

	Cofetarie c3;
	c3.serializareDate("Date.dat");
	c3.deserializareDate("Date.dat");
}