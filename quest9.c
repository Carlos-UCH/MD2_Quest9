#include<stdio.h>

//Carlos Henrique Brasil de Souza
//232014404

long long algoritmo_euclides(long long g, long long n){

    
    printf("Utilizando o algoritmo de Euclides para mdc(%lld, %lld)", g, n);

    printf("\n");
    long long r;
    while(g%n != 0){
        r = g%n;
        g = n;
        n = r;
        printf("mdc(%lld, %lld) = %lld ", g, n, r);
        printf("\n");
    }

    printf("\n");

    if(r == 1) return 1;
    else return 0;

}

long long sucessiva(long long g, long long n) {

    printf("%lld^-1 em %lld\n\n", g, n);
    long long a = g, mod = n;
    long long y = 1, s = 0;

    printf("%lld^-1 em Z(%lld)\n", g, n);
    printf("%lldx + %lldy = 1\n", n, g);

    while (n != 0) {
        long long div = g / n;
        long long resto = g % n;
        long long temp = n;
        printf("%lld = %lld * %lld + %lld\n", g, div, n, resto);
        
        n = resto;  
        g = temp;

        temp = s;
        s = y - div * s;
        y = temp;
    }

    if (y < 0) {
        y += mod;  
    }

    printf("O inverso de %lld em Z(%lld) é %lld\n", a, mod, y % mod);
    printf("\n");
    return y % mod;
}



long long primo(long long n){
  
	if (n <= 1) return 0;  
    if (n == 2) return 1;   
    if (n % 2 == 0) return 0;  
    
    for (long long j = 3; j*j <= n; j += 2) { 
        if (n % j == 0) {
            return 0; 
        }
    }
    return 1;
    
}

long long fermat(long long n, long long a){
    long long x1 = n - 1;

    printf("Temos que saber se p(n1) divide a\n");
    printf("%lld mod %lld = %lld\n", a, n, a%n);

    if(a % n == 0) {
        printf("O número %lld é divisível por %lld. Portanto temos que a é congruente a modulo p\n", a, n);
        return 0;
    }
    printf("P não divide a\n");
    printf("Vamos aplicar o Pequeno Teorema de Fermat\n");
    printf("a^(p-1) mod p = 1\n");
    printf("%lld^(%lld-1) é congruente a 1 mod %lld\n", a, n, n);
    
    return x1;

}

int potencia(long long x, unsigned int y, int p) 
{ 
    int res = 1;     

    x = x % p;
               
    if (x == 0) return 0; 

    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 


int main(){

    printf("Dados de Entrada:\n\n");
    long long h, g, n;

    printf("Digite H: ");
    scanf("%lld", &h);

    printf("Digite G: ");
    scanf("%lld", &g);

    printf("Digite n: ");
    scanf("%lld", &n);

    printf("\n");

    printf("=================ETAPA 1=================\n");
    printf("\n");

    if(algoritmo_euclides(g, n)) printf("Os números são primos entre si");
    else {
        printf("Os números não são primos entre si");
        return 0;
    }
        
        printf("\n");

    printf("=================ETAPA 2=================\n");
    printf("\n");

    long long inverso = sucessiva(g, n);

    printf("==================ETAPA 3=================\n\n");

    long long a = (h * inverso) % n;

    printf("Temos que a = %lld\n", a);


    printf("=================ETAPA 4=================\n\n");
    long long x, n1; 

    printf("Digite x: ");
    scanf("%lld", &x);

    printf("Digite n1: ");
    scanf("%lld", &n1);

    long long coprimo = algoritmo_euclides(a, n1);

    if(coprimo) printf("Os números %lld e %lld são coprimos", a, n1);
    else { 
        printf("Os números %lld e %lld não são coprimos\n", a, n1);
        return 0;
    }

    printf("\n");


    printf("=================ETAPA 5=================\n\n");
    long long primon1 = primo(n1); 
    
    if(primon1) printf("O número %lld é primo. Então vamos aplicar o Pequeno Teorema de Fermat.\n\n", n1);
    else printf("O número %lld não é primo. Então vamos aplicar o Teorema de Euler\n\n", n1);
    
    long long x1 = 0;

    if(primon1) {
        printf("=================ETAPA 6=================\n\n");
        printf("Utilizando o Pequeno Teorema de Fermat\n\n");

        x1 = fermat(n1, a);
        printf("Temos entao x1 = %lld\n", x1);
        
    }else {

        
        printf("Utilizando o algoritmo de Euclides\n\n");
        printf("=================ETAPA 7=================\n\n");


        x1 = 0;
        long long aux = n1;
        printf("\nOs coprimos de n1 sao:\n");
        while (aux){
            long long a = n1;
            long long b = aux;
            long long r;
        
            while (a % b != 0){
                r = a % b;
                a = b;
                b = r;
               
            }
            if (b == 1){
            x1++;
            printf("%lld é coprimo\n", aux);
            }
            aux--;
           
        }

        printf("phi(%lld) = %lld\n", n1, x1);

    }

    printf("\n");

    printf("=================ETAPA 8=================\n\n");
    printf("Teorema da divisão: \n");

    long long q = x/x1, r = x%x1;

    printf("%lld = %lld * %lld + %lld\n", x, q, x1, r);
    printf("O quociente é %lld e o resto é %lld\n", q, r);

    printf("\n");

    printf("==================ETAPA 9=================\n\n");

    printf("%lld^%lld mod %lld\n", a, x, n1);
    printf("%lld^(%lld * %lld + %lld) mod %lld\n", a, x1, q, r, n1);
    printf("((%lld^%lld)^%lld * %lld^%lld) mod %lld\n", a, x1, q, a, r, n1);
    printf("(((%lld^%lld)^%lld mod %lld) * (%lld^%lld mod %lld)) mod %lld\n", a, x1, q, n1, a, r, n1, n1);

    printf("\n");


    printf("==================ETAPA 10=================\n\n");
    printf("Valores intermediarios:\n");
    printf("\n");

    printf("a^x1 mod n1 = x2\n"); 
    printf("%lld^%lld mod %lld = x2\n", a, x1, n1);
    long long x2 = potencia(a, x1, n1);
    printf("x2 = %lld\n", x2);

    printf("\n");
    printf("x2^q mod n1\n");
    long long x2q = potencia(x2, q, n1);
    printf("%lld^%lld mod %lld = %lld\n", x2, q, n1, x2q);
    printf("\n");
    printf("a^r mod n1\n"); 
    long long ar = potencia(a, r, n1);
    printf("%lld^%lld mod %lld = %lld\n", a, r, n1, ar);
    printf("\n");

    printf("==================ETAPA 11=================\n\n");
    printf("x2^q * a^r mod n1\n");
    long long resultado = (x2q * ar) % n1;
    printf("%lld * %lld mod %lld = %lld\n", x2q, ar, n1, resultado);


return 0; 
}
