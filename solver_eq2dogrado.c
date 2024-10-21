ñ /*
ECUACION DE SEGUNDO GRADO

DESCRIPCIÓN GENERAL
   Se requiere un programa que resuelva una ecuación de segundo grado
   expresada en la forma general: ax^2 + bx + c = 0
   El programa solicitará los coeficientes de la ecuación al usuario.
   Si el coeficiente a es diferente de cero, el programa hará el cálculo
   de las raíces y las desplegará en pantalla.
   Si las raíces son imaginarias, el programa no las calcula y despliega
   un mensaje notificándolo.
   Si el coeficiente a es igual a cero, el programa volverá a solicitar
   los coeficientes de una ecuación de segundo grado. Esta conducta se
   repetirá mientras el usuario no introduzca los coeficientes de una
   ecuación de segundo grado.

COMPORTAMIENTO DETALLADO
   1. Solicitar los coeficientes a, b y c al usuario.
   2. Mientras el coeficiente a sea igual a cero,
      2.1 Desplegar un mensaje de error.
      2.2 Solicitar los coeficiente a, b, y c al usuario.
   3. Si el discriminante (b*b - 4*a*c) es mayor o igual a cero, entonces
      3.1 Calcular las raíces x1 y x2.
      3.2 Desplegar las raíces x1 y x2 en la pantalla.
   4. Si el discriminante (b*b - 4*a*c) es negativo, entonces
      4.1 Indicar que las raíces son imaginarias.

SALIDAS
   Este programa entrega las raíces x1 y x2 si a es diferente de 0.

ENTRADAS
   Este programa recibe los coeficientes a b y c de una ecuación de
   segundo grado expresada en la forma general.

PROCESOS (Funciones)
   1. Pedir coeficientes. (Además despliega un mensaje de bienvenida)
   2. Calcular Raíces.
   3. Desplegar Raíces

ALCANCES
   Este programa sólo es capaz de resolver ecuaciones de segundo grado,
   siempre expresadas en la forma general, cuyas raíces estén en el
   dominio de los números reales. Si las raíces son imaginarias, el programa
   lo notifica al usuario, pero no las calcula.
   Si la ecuación no es de segundo grado, el programa vuelve a solicitar
   los coeficientes de una ecuación de segundo grado.

LIMITACIONES
   Este programa valida si la ecuación es de segundo grado, pero no ofrece
   otro tipo de validación. Se asume que es responsabilidad del usuario
   usarlo adecuadamente.
   Si el usuario introduce los coeficientes de una ecuación cuyas raíces
   sean imaginarias, el programa no las calcula, pero lo notifica.
   Si el usuario introduce alguna letra en lugar de sólo números, el
   programa entrega resultados incorrectos.

DISEÑO DE PANTALLA (Prototipo no funcional)

Escenario 1: La ecuación dada sí es de segundo grado (a != 0)
             y las raíces son reales
   $ ./eq2
   Bienvenido.
   Este programa resuelve una eq. de 2o grado, expresada
   en la forma general ax^2 + b x + c = 0
   Dame el coeficiente a: 1
   Dame el coeficiente b: 2
   Dame el coeficiente c: 1
   Las raíces de tu ecuación som:
   x1 = -1.000000
   x2 = -1.000000
   $

Escenario 2: La ecuación dada sí es de segundo grado (a != 0)
             y las raíces imaginarias
   $ ./eq2
   Bienvenido.
   Este programa resuelve una eq. de 2o grado, expresada
   en la forma general ax^2 + b x + c = 0
   Dame el coeficiente a: 1
   Dame el coeficiente b: 1
   Dame el coeficiente c: 5
   Las raíces de tu ecuación son imaginarias.
   $
   
Escenario 3: La ecuación dada no es de segundo grado (a == 0)                    
   $ ./eq2
   Bienvenido.
   Este programa resuelve una eq. de 2o grado, expresada
   en la forma general ax^2 + b x + c = 0
   Dame el coeficiente a: 0
   Dame el coeficiente b: 2
   Dame el coeficiente c: 1
   La ecuación no es de segundo grado. Intenta otra vez.
   Dame el coeficiente a: 0
   Dame el coeficiente b: 3
   Dame el coeficiente c: 2
   La ecuación no es de segundo grado. Intenta otra vez.
   Dame el coeficiente a: 1
   Dame el coeficiente b: 2
   Dame el coeficiente c: 1
   Las raíces de tu ecuación som:
   x1 = -1.000000
   x2 = -1.000000
   $
   
FUNCION PRINCIPAL()
INICIO
      a, b, c -> ENTERO;
      x1, x2 -> REAL;

      Bienvenida( | );
      Pedir_Coeficientes( | &a, &b, &c);
      IF (b*b - 4*a*c >= 0) THEN
      INICIO
            Calcular_Raíces(a, b, c | &x1, &x2);
            Desplegar_Raíces(x1, x2 | );
      FIN
      ELSE
      INICIO
            Write("La raíces son imaginarias." | );
      FIN
FIN

FUNCION Bienvenida( | )
INICIO
      Write("Bienvenido." | );
      Write("Este programa resuelve una eq. de 2o grado, expresada " | );
      Write("en la forma general ax^2 + b x + c = 0" | );
FIN

FUNCION Pedir_Coeficientes( | *a, *b, *c -> ENTERO)
INICIO
      Write(“Dame los coeficientes de tu eq.“ | );
      Write(“Dame a: “ | );
      Read (| a);
      Write(“Dame b: “ | );
      Read (| b);
      Write(“Dame c: “ | );
      Read (| c);
      WHILE (*a == 0)
      INICIO
            Write("La ecuacion no es de segundo grado. Intenta otra vez." | );
	    Write(“Dame a: “ | );
            Read (| a);
            Write(“Dame b: “ | );
            Read (| b);
            Write(“Dame c: “ | );
            Read (| c);
      FIN
FIN

FUNCION Calcular_Raíces(a, b, c -> ENTERO | *x1, *x2 -> REAL)
INICIO
      Discriminante -> REAL;

      Discriminante = b*b – 4*a*c;
      *x1 = (-b + sqrt(Discriminante)) / (2*a);
      *x2 = (-b - sqrt(Discriminante)) / (2*a);
FIN

FUNCION Desplegar_Raíces(Paco, Luis -> REAL | )
INICIO
      Write(“Las raíces resultantes son: “ | );
      Write(“x1 = “, Paco | );
      Write(”x2 = “, Luis | );
FIN   

AQUI HAY UNA FUNCION Pedir_Coeficientes ALTERNATIVA:

FUNCION Pedir_Coeficientes( | *a, *b, *c -> ENTERO)
INICIO
      *a = 0;
      Write(“Dame los coeficientes de tu eq.“ | );
      WHILE (*a == 0)
      INICIO            
	    Write(“Dame a: “ | );
            Read (| a);
            Write(“Dame b: “ | );
            Read (| b);
            Write(“Dame c: “ | );
            Read (| c);
	    IF (*a == 0) THEN
	    INICIO
                  Write("La ecuacion no es de segundo grado. Intenta otra vez." | );
	    FIN
      FIN
FIN

AQUI HAY OTRA FUNCION Pedir_Coeficientes ALTERNATIVA:

FUNCION Pedir_Coeficientes( | *a, *b, *c -> ENTERO)
INICIO
      Write(“Dame los coeficientes de tu eq.“ | );
      DO
      INICIO            
	    Write(“Dame a: “ | );
            Read (| a);
            Write(“Dame b: “ | );
            Read (| b);
            Write(“Dame c: “ | );
            Read (| c);
	    IF (*a == 0) THEN
	    INICIO
                  Write("La ecuacion no es de segundo grado. Intenta otra vez." | );
	    FIN
      FIN
      WHILE (*a == 0);
FIN


*/

#include <stdio.h>
#include <math.h>

void Bienvenida(  );
void Pedir_Coeficientes(int *a, int *b, int *c);
void Calcular_Raices(int a, int b, int c, float *x1, float *x2);
void Desplegar_Raices(float Paco, float Luis);

void main(void)  //Alternativas: main(), int main (); void main(), int main(void)
{
  int a, b, c;
  float x1, x2;

  Bienvenida(  );
  Pedir_Coeficientes(&a, &b, &c);
  if (b*b - 4*a*c >= 0) 
    {
      Calcular_Raices(a, b, c, &x1, &x2);
      Desplegar_Raices(x1, x2 );
    }
  else
    {
      printf("La raíces son imaginarias.\n");
    }
}


void Bienvenida(  )
{
  printf("Bienvenido.\n"  );
  printf("Este programa resuelve una eq. de 2o grado, expresada\n"  );
  printf("en la forma general ax^2 + b x + c = 0\n"  );
}

void Pedir_Coeficientes(int *a, int *b, int *c)
{
  printf("Dame los coeficientes de tu eq.\n");
  printf("Dame a: ");
  scanf ("%d", a);
  printf("Dame b: ");
  scanf ("%d", b);
  printf("Dame c: ");
  scanf ("%d", c);
  while (*a == 0)
    {
      printf("La ecuacion no es de segundo grado. \nIntenta otra vez.\n"  );
      printf("Dame a: "  );
      scanf ("%d", a);
      printf("Dame b: "  );
      scanf ("%d", b);
      printf("Dame c: "  );
      scanf ("%d", c);
    }
}

void Calcular_Raices(int a, int b, int c, float *x1, float *x2)
{
  float Discriminante;
  
  Discriminante = b*b - 4*a*c;
  *x1 = (-b + sqrt(Discriminante)) / (2*a);
  *x2 = (-b - sqrt(Discriminante)) / (2*a);
}

void Desplegar_Raices(float Paco, float Luis)
{
  printf("Las raíces resultantes son\n");
  printf("x1 = %f\n", Paco);
  printf("x2 = %f\n", Luis);
}