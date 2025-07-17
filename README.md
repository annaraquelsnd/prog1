# Listas de Exercícios — Programação I (UFES)

Este repositório contém minhas listas de exercícios da disciplina **Programação I**, cursada no curso de **Engenharia de Computação** da **Universidade Federal do Espírito Santo (UFES)**.

## 📁 Estrutura do Repositório

- Cada **lista de exercícios** possui seu próprio diretório (ex: `Lista1`, `Lista2`, ...).
- Dentro de cada lista, há uma pasta separada para **cada questão** (ex: `L1_01`, `L1_02`, ...).

### Estrutura de um exercício

Cada exercício segue a seguinte organização:
```
ListaX/
└── LX_Y/
    ├── LX_Y.pdf        # Enunciado original da questão
    ├── input/               # Arquivos de entrada de teste
    ├── output/              # Arquivos de saída esperada
    └── main.c               # Minha solução em linguagem C
```
### Script de Testes: `fazdiff.sh`

No repositório principal há um script chamado `fazdiff.sh`, usado para **testar meus códigos automaticamente** comparando as saídas das minhas soluções com os arquivos de teste fornecidos.

Ele executa arquivos nomeados `prog` com as entradas presentes no diretório `input/` e envia as saídas para um diretório chamado `outprog/` da seguinte forma:
```
./prog <input/test_1 >outprog/test_1
./prog <input/test_2 >outprog/test_2
./prog <input/test_3 >outprog/test_3
...
```
Por fim, ele realiza o diff entre as saídas geradas e as saídas esperadas (armazenadas no `output/`):
```
diff output/ outprog/
```

---
## 🛠️ Tecnologias

- Linguagem C
- Compilador: `gcc`
- Sistema: macOS / Linux

---

## Como executar um exercício

1. Acesse a pasta do exercício.
2. Compile o código: `gcc -o prog main.c`
3. Execute com: `./prog`

Lembre-se de inserir a entrada nos parâmetros definidos pelo enunciado do exercício!
