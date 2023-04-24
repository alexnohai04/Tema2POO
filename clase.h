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
	Abonament(const Abonament& a) {
		nume_abonament = a.nume_abonament;
		pret = a.pret;
		perioada = a.perioada;
		cout << "Constructor de copiere Abonament\n";
	}
	friend ostream& operator <<(ostream& os, const Abonament& a)
	{
		return os << a.nume_abonament<<'\n'<<a.pret<<'\n'<<a.perioada<<'\n';

	}
	friend istream& operator >>(istream& is, Abonament& a) {
		cout << "Nume Abonament:\n";
		is >> a.nume_abonament;
		cout << "Pret:\n";
		is >> a.pret;
		cout << "Perioada:\n";
		is >> a.perioada;
		return is;
	}
	//supraincarcarea operatorului =
	Abonament& operator=(const Abonament& a) {
		nume_abonament = a.nume_abonament;
		pret = a.pret;
		perioada = a.perioada;
		return *this;
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
	//constructor cu parametrii
	Abonament_Premium(string _nume_abonament, float _pret, int _perioada, int _reducere) :Abonament(_nume_abonament, _pret, _perioada) {
		cout << "Constructor cu parametru Abonament_Premium\n";
		reducere = _reducere;
	}
	//constructor de copiere
	Abonament_Premium(const Abonament_Premium& a) {
		reducere = a.reducere;
		cout << "Constructor de copiere Abonament_Premium\n";
	}
	//supraincarcarea operatorului <<
	friend ostream& operator << (ostream& os, const Abonament_Premium& a) {
		return os << a.reducere <<'\n';
	}
	//supraincarcarea operatorului >>
	friend istream& operator >>(istream& is, Abonament_Premium& a) {
		cout << "Reducere:\n";
		is >> a.reducere;
		return is;
	}
	//supraincarcarea operatorului =
	Abonament_Premium& operator=(const Abonament_Premium& a) {
		reducere = a.reducere;
		return *this;
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
	Persoana(const Persoana& p) {
		id = p.id;
		nume = p.nume;
		cnp = p.cnp;
		cout << "Constructor de copiere Persoana\n";
	}
	friend ostream& operator <<(ostream& os, const Persoana& p){
		return os << p.id << p.nume << p.cnp;
	}
	//supraincarcarea operatorului >>
	friend istream& operator >>(istream& is, Persoana& p) {
		cout << "Id:\n";
		is >> p.id;
		cout << "Nume:\n";
		is >> p.nume;
		cout << "CNP:\n";
		is >> p.cnp;
		return is;
	}
	//supraincarcarea operatorului =
	Persoana& operator=(const Persoana& p) {
		id = p.id;
		nume = p.nume;
		cnp = p.cnp;
		return *this;
	}
private:
	int id;
	string nume,cnp;
};

class Abonat : public Persoana {
public:
	Abonat() { cout << "Constructor Default Abonat\n"; }
	~Abonat() { cout << "Destructor Default Abonat\n"; }
	//constructor cu parametrii
	Abonat(string _nr_telefon, string _nume_abonament, float _pret, int _perioada) {
		cout << "Constructor cu parametru Abonat\n";
		nr_telefon = _nr_telefon;
		x = Abonament(_nume_abonament, _pret, _perioada);
	}

	//Abonat(const Abonat& a) {
		//nr_telefon = a.nr_telefon;
		//x = a.x;
		//cout << "Constructor de copiere Abonat\n";
	//}
	// 
	//constructor de copiere
	Abonat(const Abonat& a) :Persoana(a), x(a.x) {
		nr_telefon = a.nr_telefon;
		cout << "Constructor de copiere Abonat\n";
	}
	//supraincarcarea operatorului <<
	friend ostream& operator <<(ostream& os, const Abonat& a)
	{
		return os << a.nr_telefon<<'\n'<<a.x<<'\n';
	}
	//supraincarcarea operatorului >>
	friend istream& operator >>(istream& is, Abonat& a) {
		cout << "Numar Telefon:\n";
		is >> a.nr_telefon;
		cout << "Abonament:\n";
		is >> a.x;
		return is;
	}
	//getter	
	string getNrTelefon() {
		return nr_telefon;
	}
	//setter
	void setNrTelefon(string _nr_telefon) {
		nr_telefon = _nr_telefon;
	}

private:
	string nr_telefon;
	Abonament x;
};

class Clienti {
public:
	Clienti() { cout << "Constructor Default Clienti"; }
	~Clienti() { cout << "Destructor Default Clienti"; }


	void adaugaAbonat(Abonat _Abonat){
		client.push_back(_Abonat);
	}

	friend ostream& operator <<(ostream& os, const Clienti& c) {
		for (int i=0; i < c.client.size(); i++)
		{	
			os << c.client[i] << '\n';
		}
		return os;
	}
	//supraincarcarea operatorului >> pentru citirea unui client
	friend istream& operator >>(istream& is, Clienti& c) {
		int n;
		cout << "Numarul de abonati:\n";
		is >> n;
		for (int i = 0; i < n; i++)
		{
			Abonat a;
			is >> a;
			c.adaugaAbonat(a);
		}
		return is;
	}
	//supraincarcarea operatorului << pentru afisarea unui client
	friend ostream& operator <<(ostream& os, const Clienti& c) {
		for (int i = 0; i < c.client.size(); i++)
		{
			os << c.client[i] << '\n';
		}
		return os;
	}
private:
	vector <Abonat>client;
};