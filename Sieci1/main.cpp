#include <iostream>
#include<fstream>
#include<string>
#include <math.h>
using namespace std;

int main()
{
    int i,j,int_char,length,bit_total_1=0, bit_mod2_1,algorytm=1,m,bit_mod,n,liczba,reszta,ten,a=0;
    string crc;
    char crc2[80]="0";
    ifstream infile( "1.txt", ios::binary );
    ofstream outfile ("new.txt", ios::binary);

  infile.seekg (0,infile.end);  // obliczam wielkość pliku
  long size = infile.tellg();
  infile.seekg (0);

  char* buffer = new char[size+1];
    infile.read (buffer,size);

  while(algorytm>0) {
    buffer[size+1]='0'; //zeruje sume kontrolna

cout<<" Ktory algorytm chcesz wybrac? \n 1 - bit parzystosci \n 2 - suma modulo \n 3 - Cykliczny kod nadmiarowy  \n 0 - Wyjscie"<<endl;
cin>>algorytm;

  switch(algorytm) {
  case 1:  //Licze bit parzystości
{
for(i=0;i<size;i++)
{    for(j=0;j<8;j++) {
        if((buffer[i] >> j) & 1)
            bit_total_1++;
    }}
bit_mod2_1=bit_total_1 % 2;
cout<<"Bit parzystosci dla oryginalu wynosi : "<<bit_mod2_1<<endl<<endl;

buffer[size+1]=char(bit_mod2_1); //Dodaje sume kontrolna, przechowuje ja w int zmienionym na char

//Dodaj zakłocenia - sufit żeby zawsze jakieś było.
//Policz jeszcze raz dla nowego pliku
  }
    break;

  case 2:   //Licze sume modulo
{

      for(i=0;i<size;i++) {
    for(j=0;j<8;j++) {
    if((buffer[i] >> j) & 1)
        bit_total_1++;
    }}
    cout<<"Podaj modulo "<<endl;
    cin>>m;
bit_mod=bit_total_1 % m;
cout<<"Suma modulo dla oryginalu wynosi : "<<bit_mod<<endl;
buffer[size+1]=char(bit_mod); //suma kontrolna

//Dodaj zakłocenia - sufit żeby zawsze jakieś było.
//Policz jeszcze raz
}
    break;

  case 3: //CRC
     {/*
      cout<<"Ilo bitowy kod CRC chcesz otrzymac?"<<endl;
      cin>>n;
      cout<<"Podaj CRC (o jeden wiecej bit niz podales przed chwila)"<<endl;
      cin>>crc;
      */}

      n=3;
     crc="1011";
     ten=10;
     liczba=floor(size/ten);  // ile bedzie przejsc petli i resztka
     reszta= size % ten;

     // Taki ciąg mogę podzielić 80-n razy
     // Potem n+1 ostatnich bitów na początkowe miejsca w ciągu, a resztę uzupełnić z pozostałych
     //size podłoga 10 = ile razy przejdzie petla. Modulo - ile "resztek" sie doda + wyzerowac nieuzywane

    // pierwszy raz uzupelniam ciag
     if(liczba>0)
     {  for(i=0;i<ten;i++) {
            for(j=0;j<8;j++)
                { (((buffer[i] >> j) & 1) ? crc2[(i*8)+j]='1' : crc2[(i*8)+j]='0');
     }}}
     for(i=0;i<80;i++) {cout<<crc2[i];}

cout<<"Teraz dzielenie"<<endl;

while(a<liczba)
{ a++;
    for(j=0;j<((8*ten)-n);j++) // dziele przez crc po kazdym bicie
    { if(crc2[j]=='1')
        {for(m=0;m<=n;m++) // XOR
            { if(crc[m]=='1')
                { crc2[j+m]= '0' ;}
                else
                { crc2[j+m] = '1';}
}}}}

         //zostaje n bitów
         // n bity idą na początkowe wartosci
         //liczę ile bajtów trzeba odpuścić teraz i z którego dalej zacząć dodawać

     //cout<<endl<<crc2;
    // cout<<endl<<"eee";
     for(i=0;i<80;i++){
        cout<<crc2[i];
     }
    break;

  case 5:
    //test
    buffer[5]='d';
  case 0: cout<<"Do widzenia"<<endl;
    break;
  default: cout<<"Wybrales zla wartosc"<<endl;
    break;
  }}
  // Zapisuję drugi plik (będzie można zaobserwować czy to taki sam/prawie taki sam)
  outfile.write (buffer,size);


  delete[] buffer; //żeby nie tworzyć lagów na komputerze
  outfile.close();
  infile.close();
  return 0;
}




//cout<<int(buffer[size+1]); //zwraca 1 lub 0

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

 //   buffer w bicie
/* buffer[size+1] |=bit_mod2_1<<0; //nie jestem pewna tego zapisu, i tak zajmie 1 bajt w charze, to tak będzie łatwiej
buffer[size+1] ^= (-bit_mod2_1 ^ buffer[size+1]) & (1 << 0);
cout<<((buffer[size+1] >> 0) & 1)<<endl;
*/


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
