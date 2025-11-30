# UFCD 0809 — Exercícios em C

Este repositório reúne os exercícios desenvolvidos nas aulas práticas da UFCD 0809. Cada pasta `Aula-0X` contém os códigos-fonte em C e uma pasta `output` usada para guardar executáveis ou resultados de execução.

---

## 📘 Organização das aulas

**Aula-01** — Introdução à linguagem C: leitura de dados, cálculos simples e condicionais  
Arquivos: `CalcularArea.c`, `ParOuImpar.c`, `MediaAluno.c`

**Aula-02** — Ciclos e repetição  
Arquivos: `somaPar.c`, `contagemRegressiva.c`

**Aula-03** — Algoritmos matemáticos  
Arquivos: `ConverterTemperatura.c`, `Fatorial.c`, `Maximo.c`

**Aula-04** — Vetores  
Arquivo: `vetorInverso.c`

**Aula-05** — Validações, vetores e estatísticas básicas  
Arquivos: `FormarTriangulo.c`, `MaiorMenorMedia.c`, `PositivoNegativoNeutro.c`, `VetorEncurtado.c`

**Aula-06** — Modularização e cálculos geométricos  
Arquivo: `CalcularAreas.c`

---

## ⚙️ Como compilar e executar  
*(GCC, Linux, VS Code e Code::Blocks — tudo num único bloco)*

Cada exercício pode ser compilado individualmente com o GCC.

### ✔ Exemplo:

```bash
gcc Aula-01/ParOuImpar.c -o Aula-01/output/ParOuImpar
./Aula-01/output/ParOuImpar
```

---

## 🔥 IMPORTANTE — Programas que usam `<math.h>`

Funções como `sqrt()`, `pow()`, `sin()`, `cos()` e `M_PI` exigem a ligação da biblioteca matemática.

A regra é a mesma para:

- Linux (GCC)
- VS Code (extensão C/C++ Compile Run)
- Code::Blocks (MinGW no Windows)

### ✔ O linker `-lm` é obrigatório.

### Exemplo:

```bash
gcc CalcularAreas.c -o CalcularAreas -lm
```

Sem isso aparecerá:

```
undefined reference to `sqrt'
ld returned 1 exit status
```

---

## ✔ VS Code (extensão C/C++ Compile Run)

Abrir:

```
Settings → C-cpp-compile-run: C-linker-flags
```

E adicionar:

```
-lm
```

Opcionalmente, em **C Compiler Flags** colocar:

```
-Wall -Wextra -g3 -lm
```

Linha completa usada pela extensão:

```
gcc "$fileName" -Wall -Wextra -g3 -lm -o "$fileNameWithoutExt"
```

---

## ✔ Code::Blocks (Windows)

Adicionar a biblioteca matemática manualmente:

```
Project → Build options → Linker settings → Add → libm
```

---

## 🎯 Objetivo da UFCD 0809

Desenvolver competências práticas em:

- Programação estruturada em C  
- Condicionais, ciclos e modularização  
- Manipulação de vetores  
- Compilação e linkagem  
- Resolução de problemas algorítmicos  

---

## ✔ Estado do repositório

O repositório será atualizado regularmente com novos exercícios e melhorias aplicadas durante as aulas.
