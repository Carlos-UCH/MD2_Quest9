# Questão 9 da Prova de MD2

## Autor

Carlos Henrique Brasil de Souza  

---

##  Fundamentos Matemáticos Utilizados

### Propriedades da Aritmética Modular

Sejam `a ≡ b (mod m)` e `c ≡ d (mod m)`, então:

- `a + c ≡ b + d (mod m)`
- `a * c ≡ b * d (mod m)`
- **Divisão:** Só é possível se existir o **inverso modular** de `c mod m`. Ou seja, se `c` e `m` são coprimos (`mdc(c, m) = 1`), então:  
  `a / c ≡ a * c⁻¹ (mod m)`
---
- `a ≡ b (mod m)` => `a^n ≡ b^n (mod m)`
- `a ≡ b (mod m)` => `b ≡ a (mod m)`
- `a ≡ b (mod m)` e `b ≡ b' (mod m)` => `a ≡ b' (mod m)` 


### Pequeno Teorema de Fermat

Se `p` é primo e `a` é um inteiro tal que `a` não é divisível por `p` (ou seja, `mdc(a, p) = 1`), então:  
`a^(p−1) ≡ 1 (mod p)`


### Teorema de Euler

Generalização do Teorema de Fermat. Se `a` e `n` são coprimos:  
`a^φ(n) ≡ 1 (mod n)`

Onde `φ(n)`  => número de interios positivos menores ou iguais a n que são relativamente primos de n.

### Identidade de Bézout

Para quaisquer inteiros `a` e `b`, existem inteiros `x` e `y` tais que:  
`a * x + b * y = mdc(a, b)`


---

---

## Compilação

```bash
gcc quest9.c -o quest
```

---

##  Execução

```bash
./quest
```

---


