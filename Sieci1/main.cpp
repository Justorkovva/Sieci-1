#include <iostream>
#include<fstream>
#include<string>
using namespace std;

/*string binary(int b)
{
    if(b==0) return "0";
    if(b==1) return "1";
    if(b%2 ==0)
        return binary(b/2) + "0";
    else
        return binary(b/2) + "1";
}
*/
int main()
{
    int i,j,int_char,length,bit_total_1=0, bit_mod2_1,algorytm=0,m,bit_mod;
    bool bit_p1;
    string byte;

    //wczytuje plik. Czy jest różnica między ifstream::binary, a ios::binary? czy to w ogóle potrzebne?
    ifstream infile( "1.txt", ios::binary );
// tworzę drugi plik
  ofstream outfile ("new.txt", ios::binary);

  // obliczam wielkość pliku
  infile.seekg (0,infile.end);
  long size = infile.tellg();
  infile.seekg (0);

  char* buffer = new char[size+1];

  // czytam z pierwszego pliku
  infile.read (buffer,size);

  cout<<" Ktory algorytm chcesz wybrac? \n 1 - bit parzystosci \n 2 - suma modulo \n 3 - Cykliczny kod nadmiarowy "<<endl;
cin>>algorytm;

  switch(algorytm) {

  case 1:
//Licze bit parzystości
for(i=0;i<size;i++)
{
    for(j=0;j<8;j++)
    {
    if((buffer[i] >> j) & 1)
        bit_total_1++;
    }
}
bit_mod2_1=bit_total_1 % 2;
cout<<"Bit parzystosci dla oryginalu wynosi : "<<bit_mod2_1<<endl;

//Dodaje sume kontrolna, przechowuje ja w int

buffer[size+1]=char(bit_mod2_1);

/* buffer[size+1] |=bit_mod2_1<<0; //nie jestem pewna tego zapisu
buffer[size+1] ^= (-bit_mod2_1 ^ buffer[size+1]) & (1 << 0);
cout<<((buffer[i] >> 0) & 1)<<endl;
*/
    break;

  case 2:
      //Licze sume modulo
      for(i=0;i<size;i++) {
    for(j=0;j<8;j++) {
    if((buffer[i] >> j) & 1)
        bit_total_1++;
    }}
    cout<<"Podaj modulo "<<endl;
    cin>>m;
bit_mod=bit_total_1 % m;
cout<<"Bit parzystosci dla oryginalu wynosi : "<<bit_mod<<endl;

//Dodaje sume kontrolna, przechowuje ja w int

buffer[size+1]=char(bit_mod);
cout<<int(buffer[size+1]); //zwraca 1 lub 0

    break;

  case 3:
    break;

  default:
      cout<<"Wybrales zla wartosc"<<endl;
    break;
  }






//dodaje zaklocenia


/*
    cout<<buffer[i]<<endl;
    buffer[i] ^= 1 << 0;
    cout<<buffer[i]<<endl;

    int_char=int(buffer[i]);
    byte=binary(int_char);
    length=byte.length();

    for(j=0;j<length;j++)
    {
        cout<<byte[j];
        if(byte[j]=='1')
        {
            bit_total_1++;
        }
    }
}
bit_total_1=bit_total_1 % 2;

*/
//cout<<endl<<bit_total_1;


  //obliczam dla pliku pierwszego

  //dodaje sume kontrolna na koniec pliku

  //dodaje zakłócenia do buffora

  //usuwam sumę kontrolną?

  //obliczam dla pliku drugiego

  //porównuję

  // Zapisuję drugi plik (będzie można zaobserwować czy to taki sam/prawie taki sam)
  outfile.write (buffer,size);

  //żeby nie tworzyć lagów na komputerze
  delete[] buffer;
  outfile.close();
  infile.close();
  return 0;


   // moge to zrobic na stringach i pojdzie dosc latwo, albo bawic sie w tablice bitow gdzie jest trudniej :/

    //zamienic na binarny   buffor bajtów?  tablica bajtów

    //jakos go przechowac najlepiej nie w stringu, aczkolwiek nie wiem czemu.
    //moze klasa biginteger w javie? to tez string :/

    //jak juz jest wczytany to 3 algorytmy na niego napisac i wyliczyc wartoœci

    //dodac bledy ktorych wartosc mozna zmienic np. 0,1% , 0,01 % . sufit z tej wartosci

    //wyliczyc jeszcze raz wartosci

    //porownac i zapisac recznie w excelu

    //size of , wskaŸniki , diff :(

    // zeby sprawdzic jaki bit to dodac np. 1010 and 0001 jak jest rozne od 0 to na ostanim bylo 1

    //wszystkie pliki sa binarne normalnie wiec nauczyc sie je czytac

    //w krypto 4 zad 2 nwm czy dziala mam zamiane bitow na stringi

    cout << "Hello world!" << endl;
    return 0;
}
