#include<stdio.h>
#include<pthread.h>
#include<math.h>

pthread_mutex_t muteks; 

double funkcja ( double x );

double calka_zrownoleglenie_petli(double a, double b, double dx, int l_w);

static int l_w_global=0;

static double calka_global=0.0;
static double a_global;
static double b_global;
static double dx_global;
static int N_global;

void* calka_fragment_petli_w(void* arg_wsk);

double calka_zrownoleglenie_petli(double a, double b, double dx, int l_w){

  int N = ceil((b-a)/dx);
  double dx_adjust = (b-a)/N;

  printf("Obliczona liczba trapezów: N = %d, dx_adjust = %lf\n", N, dx_adjust);
  //printf("a %lf, b %lf, n %d, dx %.12lf (dx_adjust %.12lf)\n", a, b, N, dx, dx_adjust);
  a_global = a;
  b_global = b; 
  N_global = N;
  dx_global = dx_adjust;
  l_w_global = l_w;

  // tworzenie struktur danych do obsługi wielowątkowości
  pthread_t watki[l_w];
  
  int i =0;
  int indeksy[l_w]; 
  for(i=0;i<l_w;i++) indeksy[i]=i;
  

  pthread_mutex_init( &muteks, NULL);

  // tworzenie wątków
  for(i=0; i<l_w; i++ ) 
    pthread_create( &watki[i], NULL, calka_fragment_petli_w, (void *) &indeksy[i] );


  // oczekiwanie na zakończenie pracy wątków
  for(i=0; i<l_w; i++ ) pthread_join( watki[i], NULL );


  return(calka_global);
}

void* calka_fragment_petli_w(void* arg_wsk){

  int my_id;

  double a, b, dx; // skąd pobrać dane a, b, dx, N, l_w ? 
  int N, l_w;      // wariant 1 - globalne

  a = a_global; // itd. itp. - wartości globalne nadaje calka_zrownoleglenie_petli 
  b = b_global;
  dx = dx_global;
  N = N_global;
  l_w = l_w_global;

  // dekompozycja cykliczna
  int my_start = 0;
  int my_end = 0;
  int my_stride = 0;

  // dekompozycja blokowa
  //int my_start = 0;
  //int my_end = 0;
  //int my_stride = 0;

  // something else ? (dekompozycja blokowo-cykliczna)
  my_id = *((int*) arg_wsk);
  my_start = my_id;
  my_end = N;
  my_stride = l_w;


  printf("\nWątek %d: my_start %d, my_end %d, my_stride %d\n", 
	 my_id, my_start, my_end, my_stride);


  int i;
  double calka = 0.0;
  for(i=my_start; i<my_end; i+=my_stride){

    double x1 = a + i*dx;
    calka += 0.5*dx*(funkcja(x1)+funkcja(x1+dx));
    //printf("i %d, x1 %lf, funkcja(x1) %lf, całka = %.15lf\n", 
    //	   i, x1, funkcja(x1), calka);

  }

  pthread_mutex_lock( &muteks );
  calka_global += calka;
  pthread_mutex_unlock( &muteks );

  pthread_exit( NULL );
}
