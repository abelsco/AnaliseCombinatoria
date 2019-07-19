#  Análise Combinatória

(Caso I) Ordem: Sim; Repetição: Sim

Permutação simples

---

(Caso II) Ordem: Sim; Repetição: Não

Permutação sem repeticão     

---

(Caso III) Ordem: Não; Repetição: Sim

Combinação simples

---

(Caso IV) Ordem: Não; Repetição: Não

Combinação sem repetição

---

Para execução
```
gcc main.c -o main -lm
./main
```

Entradas válidas
```
Ordem Repetição n r
```

Onde
```
Ordem ::= S | N
Repetição ::= S | N
n ::= 1 ≤ n ≤ 10
r ::= 1 ≤ r ≤ n, para os casos I, II e IV | r ≥ 1, para o caso III
```
#### Exemplo de entrada válida
```
Digite os dados:
s s 4 3
O resultado é > 64 <
(1): 1 1 1 
(2): 1 1 2 
(3): 1 1 3 
(4): 1 1 4 
. . .
(61): 4 4 1 
(62): 4 4 2 
(63): 4 4 3 
(64): 4 4 4 
```
O arquivo `APS_MatematicaDiscreta.txt` contem a saida a descrição da entrada e tamanho do conjunto formado.
`OBS.: Permutações funcionais, Combinações com bugs`
