//TEMA 6
#include <iostream>
#include <string>
#include <vector>
#include <exception>
//using namespace std;
#include "clase.h"
int main()

{
    try {
        Abonament a1, a2("Standard", 10.2, 2);
        Abonament_Premium s1, s2("Standard", 10.2, 2, 30);
        Persoana p1, p2(38, "Nohai", "1234567890123");
        Abonat v1, v2("0781531230", "Standard", 10, 5, 46, "Alex", "0987654321123"), v3("0712312306", "Standard", 10, 5, p2), v4("0712345886", s2, p2), v5("0734567854", s1, p1),v6("0712345678",a2,p1);
        v3.afisare();
        Clienti c1;
     //   c1.adaugaAbonat(v2);
        try {
            v1.citire();
        }
        catch (Exceptie& e) {
            std::cout << e.what() << "\n";
        }

        try {
            p1.citire();
        }
        catch (Exceptie& e) {
            std::cout << e.what() << "\n";
        }
      //  c1.adaugaAbonat(v1);
        c1.adaugaAbonat(v4);
      //  c1.adaugaAbonat(v5);
        c1.adaugaAbonat(v6);
       

       std::cout << "\n"<<"Numar abonamente premium : " << c1.numar_abonati_premium() << "\n\n";
       std::cout << "\n" << "Suma totala incasata : " << c1.suma_totala() << "\n\n";
      //  c1.afisare();
       std::cout << "GATA";
    }
    catch (Exceptie& e) {
		std::cout << e.what() << "\n";
	}
    catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
    catch (...) {
		std::cout << "Eroare necunoscuta\n";
	}

    std::cout << "Hello World!\n";
}
