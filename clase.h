class Abonament {
public:
	Abonament() { cout << "Constructor Default Abonament\n"; }
	~Abonament() { cout << "Destructor Default Abonament\n"; }
	Abonament(string _nume_abonament, float _pret, int _perioada) {
		cout << "Constructor cu parametru Abonament\n";
		nume_abonament = _nume_abonament;
		pret = _pret;
		perioada = _perioada;
	}
private:
	string nume_abonament;
	float pret;
	int perioada;
};

class Abonament_Premium : public Abonament {
public:
	Abonament_Premium() { cout << "Constructor Default Abonament_Premium\n"; }
	~Abonament_Premium() { cout << "Destructor Default Abonament_Premium\n"; }
	Abonament_Premium(int _reducere) {
		cout << "Constructor cu parametru Abonat_Premium\n";
		reducere = _reducere;
	}
private:
	int reducere;
};

class Persoana {
public:
	Persoana() { cout << "Constructor Default Persoana\n"; }
	~Persoana() { cout << "Destructor Default Persoana\n"; }
	Persoana(int _id, string _nume, string _cnp) {
		cout << "Constructor cu parametru Persoana\n";
		id = _id;
		nume = _nume;
		cnp = _cnp;
	}


private:
	int id;
	string nume,cnp;
};

class Abonat : public Persoana {
public:
	Abonat() { cout << "Constructor Default Abonat\n"; }
	~Abonat() { cout << "Destructor Default Abonat\n"; }
	Abonat(string _nr_telefon, Abonament _x) {
		cout << "Constructor cu parametru Abonat\n";
		nr_telefon = _nr_telefon;
		x = _x;
	}


private:
	string nr_telefon;
	Abonament x;
};

