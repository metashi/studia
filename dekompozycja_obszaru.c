#include<stdio.h>
#include<pthread.h>
#include<math.h>

pthread_mutex_t muteks; 

double funkcja ( double x );

double calka_dekompozycja_obszaru(double a, double b, double dx, int l_w);

void* calka_podobszar_w(void* arg_wsk);

double calka_sekw(double a_local,double b_local,double dx);


  struct myData {
    double a_local;
    double b_local;
    double dx_local;
    int ID;
    double wynik_local;
  };

double calka_dekompozycja_obszaru(double a, double b, double dx, int l_w){


  printf("a %lf, b %lf, dx %lf\n", a, b, dx);

  double calka_suma_local = 0.0;

  // tworzenie struktur danych do obsługi wielowątkowości
  pthread_t watki[l_w];

  int i =0;
  int indeksy[l_w]; 
  for(i=0;i<l_w;i++) indeksy[i]=i;
  
  struct myData struct_data_table[l_w]; 

  pthread_mutex_init( &muteks, NULL);
  
  double len = (b-a)/l_w; 
  // tworzenie wątków
  for(i=0; i<l_w; i++ ) {
    struct_data_table[i].a_local = a+i*len;
    struct_data_table[i].b_local = a+i*len+len;
    struct_data_table[i].dx_local = dx;
    struct_data_table[i].ID = i;
    struct_data_table[i].wynik_local = 0.0;

    pthread_create( &watki[i], NULL, calka_podobszar_w, (void *) &struct_data_table[i] );
  }

  // oczekiwanie na zakończenie pracy wątków
  for(i=0; i<l_w; i++ ) {
    pthread_join( watki[i], NULL);
    calka_suma_local += struct_data_table[i].wynik_local;
  }

  return(calka_suma_local);
}



void* calka_podobszar_w(void* arg_wsk){

  double a_local, b_local, dx;
  // rozpakowanie danych przesłanych do wątku
  struct myData s_lok = *((struct myData*) arg_wsk );

 a_local = s_lok.a_local;
 b_local = s_lok.b_local;
 dx = s_lok.dx_local;


  int my_id; // skąd pobierany?
  printf("\nWątek %d: a_local %lf, b_local %lf, dx %lf\n", 
	 my_id, a_local, b_local, dx);
  // wywołanie zadania do wykonania: całkowanie w zadanym przedziale 
  double calka = calka_sekw(a_local, b_local, dx);
  // (trzeba także dodać prototyp na początku pliku)
  
// zadanie w funkcji calka_sekw jest równoważne obliczeniom:
//  int N_local = ceil((b_local-a_local)/dx);
//  double dx_adjust_local = (b_local-a_local)/N_local;
//  printf("a_local %lf, b_local %lf, dx_adjust_local %lf, n_local %d\n", 
//	 a_local, b_local, dx_adjust_local, N_local);
//  int i;
//  double calka = 0.0;
//  for(i=0; i<N_local; i++){
//    double x1 = a_local + i*dx_adjust_local;
//    calka += 0.5*dx_adjust_local*(funkcja(x1)+funkcja(x1+dx_adjust_local));
    //printf("i %d, x1 %lf, funkcja(x1) %lf, całka = %.15lf\n", 
    //	   i, x1, funkcja(x1), calka);
//  }
  
  ((struct myData*)arg_wsk) -> wynik_local = calka;
  printf("%lf %lf\n ", ((struct myData*)arg_wsk) -> wynik_local , calka);
}

