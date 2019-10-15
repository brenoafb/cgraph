# Projeto 2 - Teoria e Aplicação de Grafos 2019/2

- Breno Fatureto - 17/0007014
- Igor Bispo - 17/0050432
- Prof. Díbio Leandro Borges

## Sumário

O projeto consiste na implementação de um dígrafo acíclico (no qual estão representadas as disciplinas obrigatórias do curso de Ciência da Computação) e algoritmos relacionados a ordenação topológica e determinação de caminhos críticos.

## Diretórios

```
src/ (contendo o código fonte)
bin/ (contendo os arquivos de entrada)
grafos_imagens/ (contendo representações visuais do grafo gerado)
```

## Como compilar

```bash
$ cd src/
$ make
```

Será gerado um arquivo com nome *main.out* na pasta bin/ .

## Como usar

```bash
$ cd bin/
$ ./main.out graph_file.txt labels_file.txt
```

Ambos arquivos de entrada foram gerados pela equipe e devem estar contidos na pasta bin/

Após a execução, será imprimida na tela a ordenação topológica na ordem respectiva e os caminhos críticos considerando número de créditos total e número de matéria, vale ressaltar que estes dois caminhos foram idênticos
considerando o grafo de entrada gerado.
