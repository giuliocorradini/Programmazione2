/* 
   Scrivere un programma che definisca una variabile a di tipo int ed
   una variabile p di tipo puntatore ad int.  Successivamente si
   assegni un valore ad a e si assegni a p l'indirizzo di a. Infine si
   stampino, rispettivamente, l'indirizzo di a, il valore di a, il
   valore di p ed il valore della variabile a cui punta p.
*/

#include <iostream>

using namespace std ;

int main()
{
  int a;        /* a e' un intero */
  int *aPtr;    /* aPtr e' un puntatore ad intero */
  a = 7;
  aPtr = &a;    /* aPtr punta all'indirizzo di a */
  cout<<"L'indirizzo di a e': "<<&a
      <<"\nIl valore di aPtr e' "<<aPtr ;
  cout<<"\n\nIl valore di a e' "<<a   
      <<"\nIl valore di *aPtr e' "<<*aPtr<<endl ;

  int n=75;
    int & rif=n;
    cout<<"n="<<n<<",rif="<<rif<<". ";
    rif = 30;
    cout<<"n="<<n<<",rif="<<rif<<". ";


  return 0; 
} 
