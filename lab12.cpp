#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Samochod {
public:
	double cena;
	string rodzaj_silnika;
	Samochod* nast;

	Samochod() : rodzaj_silnika("benzyna"), cena(10000), nast(NULL) {}
	Samochod(Samochod& nowy) : rodzaj_silnika(nowy.rodzaj_silnika), cena(nowy.cena), nast(NULL) {}
	Samochod(double cena_, string typ) : rodzaj_silnika(typ), cena(cena_), nast(NULL) {}
	~Samochod() {
		delete nast;
	}

	void wypisz() {
		cout << "Cena auta: " << cena << " zl, rodzaj silnika: " << rodzaj_silnika << endl;
	}

	void set_cena(double cena_) {
		cena = cena_;
	}

	double get_cena() {
		return cena;
	}

	void set_rodzaj_silnika(string rodzaj_silnika_) {
		rodzaj_silnika = rodzaj_silnika_;
	}

	string get_rodzaj_silnika() {
		return rodzaj_silnika;
	}
};

class Urzadzenie_optyczne {
public:
	double zoom, waga;
	Urzadzenie_optyczne* nast;

	Urzadzenie_optyczne() : zoom(2), waga(1), nast(NULL) {}
	Urzadzenie_optyczne(Urzadzenie_optyczne& nowy) : zoom(nowy.zoom), waga(nowy.waga), nast(NULL) {}
	Urzadzenie_optyczne(double zoom_, double waga_) : zoom(zoom_), waga(waga_), nast(NULL) {}
	~Urzadzenie_optyczne() {
		delete nast;
	}

	void wypisz() {
		cout << "Zoom urzadzenia: " << zoom << "x, waga urzadzenia: " << waga << " kg" << endl;
	}

	void set_zoom(double zoom_) {
		zoom = zoom_;
	}

	double get_zoom() {
		return zoom;
	}

	void set_waga(double waga_) {
		waga = waga_;
	}

	double get_waga() {
		return waga;
	}

};

class Osoba {
public:
	string imie, nazwisko, email;
	Osoba* nast;

	Osoba() : imie("Daniel"), nazwisko("Swiatek"), email("daniel.swiatek@zmyslony_hosting.pl"), nast(NULL) {}
	Osoba(Osoba& nowy) : imie(nowy.imie), nazwisko(nowy.nazwisko), email(nowy.email), nast(NULL) {}
	Osoba(string imie_, string nazwisko_, string email_) : imie(imie_), nazwisko(nazwisko_), email(email_), nast(NULL) {}
	~Osoba() {
		delete nast;
	}

	void operator+=(Osoba& nowa) {
		imie += nowa.imie;
		nazwisko += nowa.nazwisko;
	}

	void wypisz() {
		cout << "Imie i nazwisko: " << imie << " " << nazwisko << ", email: " << email << endl;
	}

	void set_imie(string imie_) {
		imie = imie_;
	}

	string get_imie() {
		return imie;
	}

	void set_nazwisko(string nazwisko_) {
		nazwisko = nazwisko_;
	}

	string get_nazwisko() {
		return nazwisko;
	}

	void set_email(string email_) {
		email = email_;
	}

	string get_email() {
		return email;
	}

};

class Student : public Osoba {
public:
	int nr_indeks, rok_rozpoczecia;
	Student* nast;

	Student() : Osoba(), nr_indeks(123633), rok_rozpoczecia(2023) {}
	Student(Student& nowy) : Osoba(nowy), nr_indeks(nowy.nr_indeks), rok_rozpoczecia(nowy.rok_rozpoczecia) {}
	Student(string imie_, string nazwisko_, string email_, int nr_indeks_, int rok_rozpoczecia_) : Osoba(imie_, nazwisko_, email_), nr_indeks(nr_indeks_), rok_rozpoczecia(rok_rozpoczecia_) {}

	Student& operator=(Student& nowa) {
		if (this == &nowa) {
			return *this;
		}
		nr_indeks = nowa.nr_indeks;
		rok_rozpoczecia = nowa.rok_rozpoczecia;
		return *this;
	}
	Student& operator+=(Student& nowy) {
		nr_indeks += nowy.nr_indeks;
		rok_rozpoczecia += nowy.rok_rozpoczecia;
		return *this;
	}

	void wypisz() {
		cout << "Nr indeksu studenta: " << nr_indeks << ", rok rozpoczecia studiow: " << rok_rozpoczecia << endl;
	}

	void set_nr(int nr_indeks_) {
		nr_indeks = nr_indeks_;
	}

	int get_nr() {
		return nr_indeks;
	}

	void set_rok(int rok_rozpoczecia_) {
		rok_rozpoczecia = rok_rozpoczecia_;
	}

	int get_rok() {
		return rok_rozpoczecia;
	}

};


class Pracownik : public Osoba {
public:
	int magistranci;
	char** prowadzone_przedmioty;
	Pracownik* nast;

	Pracownik() : Osoba(), magistranci(4), prowadzone_przedmioty() {
		prowadzone_przedmioty = new char* [6];
		for (int i = 0; i < 5; i++) {
			prowadzone_przedmioty[i] = new char[6];
		}
		char test[6] = "PO";
		set_prowadzone(test, 0);
		set_prowadzone(test, 1);
		set_prowadzone(test, 2);
		set_prowadzone(test, 3);
		set_prowadzone(test, 4);
	}

	Pracownik(Pracownik& nowy) : Osoba(nowy), magistranci(nowy.magistranci) {
		prowadzone_przedmioty = new char* [6];
		for (int i = 0; i < 5; i++) {
			prowadzone_przedmioty[i] = new char[6];
			strcpy(prowadzone_przedmioty[i], nowy.prowadzone_przedmioty[i]);
		}
	}
	Pracownik(string imie_, string nazwisko_, string email_, int magistranci_, char* prowadzone_przedmioty_[6]) : Osoba(imie_, nazwisko_, email_), magistranci(magistranci_) {
		prowadzone_przedmioty = new char*[6];
		for (int i = 0; i < 5; i++) {
			prowadzone_przedmioty[i] = new char[6];
			strcpy(prowadzone_przedmioty[i], prowadzone_przedmioty_[i]);
		}
	}
	 Pracownik& operator=(Pracownik& nowa) {
		if (this == &nowa) {
			return *this;
		}
		magistranci = nowa.magistranci;
		prowadzone_przedmioty = nowa.prowadzone_przedmioty;
		return *this;
	}

	Pracownik& operator+=(Pracownik& nowy) {
		magistranci += nowy.magistranci;
		return *this;
	}

	void wypisz() {
		cout << "Ilosc magistrantow pracownika: " << magistranci << ", lista prowadzonych przez niego przedmiotow: " << get_prowadzone(0) << ", " << get_prowadzone(1) << ", " << get_prowadzone(2) << ", " << get_prowadzone(3) << ", " << get_prowadzone(4) << endl;
	}

	void set_magistranci(int magistranci_) {
		magistranci = magistranci_;
	}

	int get_magistranci() {
		return magistranci;
	}

	void set_prowadzone(char* przedmioty, int adres) {
		strcpy(prowadzone_przedmioty[adres], przedmioty);
	}

	char* get_prowadzone(int indeks) {
		return prowadzone_przedmioty[indeks];
	}

};

void wypisz_liste(Student* glowa) {
	Student* p = glowa;
	while (p != NULL) {
		p->wypisz();
		p = p->nast;
	}
}

int main() {
	Student A1, A2, A3;
	Pracownik B1, B2, B3;
	A3 += A2;
	A1 = A2 = A3;
	B1 = B2 += B3;

	A1.wypisz();
	B1.wypisz();

	Student* nowy = new Student();
	Student* aktualny = nowy;

	for (int i = 0; i < 5; i++) {
		A1 += *aktualny;
		aktualny->nast = new Student();
		aktualny = aktualny->nast;
	}

	aktualny = nowy;

	cout << "Obiekt A1 po zsumowaniu listy: " << endl;
	A1.wypisz();


	return 0;
}