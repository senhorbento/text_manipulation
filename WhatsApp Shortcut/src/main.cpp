#include <iostream>

using namespace std;

#define _MAX_QTD_ 100

int main() {
	string prefix = "https://api.whatsapp.com/send/?phone=";
	string resultado[_MAX_QTD_], leitura;

	for(int i=0; i<_MAX_QTD_; i++){
		cin >> leitura;
		resultado[i] = prefix + leitura;
	}
	
	for(int i=0; i<_MAX_QTD_; i++)
		cout << resultado[i] << endl;

	return 0;
}
