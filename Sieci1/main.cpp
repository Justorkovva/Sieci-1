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
    int i,j,int_char,length,bit_total_1=0, bit_mod2_1,algorytm=1,m,bit_mod,n;
    bool bit_p1;
    string crc, crc2;


    //wczytuje plik. Czy jest różnica między ifstream::binary, a ios::binary? czy to w ogóle potrzebne?
    ifstream infile( "1.txt", ios::binary );
// tworzę drugi plik
  ofstream outfile ("new.txt", ios::binary);

  // obliczam wielkość pliku
  infile.seekg (0,infile.end);
  long size = infile.tellg();
  infile.seekg (0);

   // czytam z pierwszego pliku
  char* buffer = new char[size+1];
   infile.read (buffer,size);

  while(algorytm>0) {

  buffer[size+1]=0; //zeruje sume kontrolna

  cout<<" Ktory algorytm chcesz wybrac? \n 1 - bit parzystosci \n 2 - suma modulo \n 3 - Cykliczny kod nadmiarowy  \n 0 - Wyjscie"<<endl;
cin>>algorytm;

  switch(algorytm) {

  case 1:
//Licze bit parzystości
for(i=0;i<size;i++)
{    for(j=0;j<8;j++) {
        if((buffer[i] >> j) & 1)
            bit_total_1++;
    }
}
bit_mod2_1=bit_total_1 % 2;
cout<<"Bit parzystosci dla oryginalu wynosi : "<<bit_mod2_1<<endl;

//Dodaje sume kontrolna, przechowuje ja w int

buffer[size+1]=char(bit_mod2_1);

/* buffer[size+1] |=bit_mod2_1<<0; //nie jestem pewna tego zapisu, i tak zajmie 1 bajt w charze, to tak będzie łatwiej
buffer[size+1] ^= (-bit_mod2_1 ^ buffer[size+1]) & (1 << 0);
cout<<((buffer[size+1] >> 0) & 1)<<endl;
*/

//Dodaj zakłocenia - sufit żeby zawsze jakieś było.

//Policz jeszcze raz
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
cout<<"Suma modulo dla oryginału wynosi : "<<bit_mod<<endl;

//Dodaje sume kontrolna,
buffer[size+1]=char(bit_mod);
//cout<<int(buffer[size+1]); //zwraca 1 lub 0

//Dodaj zakłocenia - sufit żeby zawsze jakieś było.

//Policz jeszcze raz
    break;

  case 3:
     {/*
      cout<<"Ilo bitowy kod CRC chcesz otrzymac?"<<endl;
      cin>>n;
      cout<<"Podaj CRC (o jeden wiecej bit niz podales przed chwila)"<<endl;
      cin>>crc;
      */}

      n=3;
     crc="1010";

     for(i=0;i<(size);i++)
     {  for(j=0;j<8;j++)
         { //wsadzam bity do stringa
             if((buffer[i] >> j) & 1)
             crc2[j]='1';
             else
            crc2[j]='0';
             cout<<crc2[j]<<endl;
         }
        // buffer[i]; na bity
         //dzielenie xor
     }




    break;
  case 0:
    cout<<"Do widzenia"<<endl;
    break;

  default:
      cout<<"Wybrales zla wartosc"<<endl;
    break;
  }
  }
    // Zapisuję drugi plik (będzie można zaobserwować czy to taki sam/prawie taki sam)
  outfile.write (buffer,size);

//żeby nie tworzyć lagów na komputerze
  delete[] buffer;
  outfile.close();
  infile.close();
  return 0;
}


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

    //porownac i zapisac recznie w excelu
    //size of , wskazniki , diff :(
    // zeby sprawdzic jaki bit to dodac np. 1010 and 0001 jak jest rozne od 0 to na ostanim bylo 1
    //w krypto 4 zad 2 nwm czy dziala mam zamiane bitow na stringi


