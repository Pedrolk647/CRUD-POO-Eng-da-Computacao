# 🕶️ Sistema CRUD – Agência de Matador de Aluguel (Ficção)

Projeto da disciplina **Linguagem de Programação I** (Programação Orientada a Objetos) – Semestre 2026.2
**Professor:** Derzu Omaia
**Tema:** Outros (opção 53) – Matador de Aluguel
**Equipe:** Pedro Luís de Oliveira Lima, Antonio Lucas de Oliveira Silva Belchior Dias Cruz
**Data de entrega:** 02/11/2026

> ⚠️ **Aviso:** este é um projeto **totalmente fictício e humorístico**, criado apenas para fins didáticos. Todos os nomes, contratos e "alvos" são personagens imaginários. O sistema não possui nenhuma funcionalidade real além do cadastro de dados em memória e em arquivo.

---

## 1. Sobre o projeto

O sistema simula a **gestão de contratos de uma agência fictícia de mercenários**, como as que aparecem em jogos e filmes. Cada contrato registra o cliente, o alvo (um vilão fictício), o local, a recompensa e o status, permitindo cadastrar, consultar, alterar, remover e gerar relatórios, com persistência em arquivo.

Linguagem: **C++** (padrão C++11 ou superior).

---

## 2. Funcionalidades (menu)

| Opção | Descrição |
|:-----:|-----------|
| 1 | **Inserir** um novo contrato (escolhendo o tipo: furtivo, espetacular ou diplomático) |
| 2 | **Listar todos** os contratos |
| 3 | **Exibir um** contrato (pesquisa por nome do cliente) |
| 4 | **Alterar** um contrato (pesquisa por nome do cliente) |
| 5 | **Remover** um contrato (pesquisa por nome do cliente) |
| 6 | **Exibir relatório** (resumo geral da agência) |
| 7 | **Sair** |
| 8 | **Viajar para a lua** 🚀 (missão especial) |
| H | **Sair** (letra `H` maiúscula encerra o programa e salva os dados) |

O programa roda em laço contínuo até o usuário digitar **`H`**.

### Pesquisa por nome
Um único método reutilizado pelas opções 3, 4 e 5:

```cpp
int Pesquisar(std::string nome);
```

- Aceita o nome completo **ou apenas o início** do nome, inclusive com espaços.
- Se mais de um contrato corresponder, todos são exibidos com seus índices e o usuário escolhe pelo índice.

### Relatório
- quantidade total de contratos cadastrados;
- quantidade por tipo de contrato;
- valor total e média das recompensas;
- quantidade de **Girafas** e **Vacas Loucas** armazenadas.

---

## 3. Persistência em arquivo

- Dados **carregados automaticamente** ao abrir o programa e **salvos ao finalizar**.
- Todas as operações ocorrem na **fila em memória**, nunca direto no arquivo.
- Um **único arquivo** (`dados.txt`) guarda objetos de todas as classes.
- Cada linha começa com **`Vaca`** e termina com **`Girafa`**.

Exemplo (campos separados por `;`):

```
Vaca;FURTIVO;Barao Imaginario;Vilao Mascarado;5000.00;90000;Cobertura Ficticia;Gotham City;3;12;1;Girafa
Vaca;ESPETACULAR;Dona Fantasia;Doutor Maligno;8000.00;75000;Fabrica Abandonada;Cidade Neon;5;9;1;Girafa
Vaca;DIPLOMATICO;Sr. Ficticio;Chefe da Mafia de Mentira;3000.00;100000;Restaurante Italiano;Vila Pixel;Mediador Joao;1;Girafa
```

---

## 5. Estrutura de arquivos

```
AgenciaMercenarios/
**Ainda a declarar**
```

---

## 6. Como compilar e executar

```bash
g++ -std=c++11 main.cpp -o agencia
./agencia            # Linux/macOS
agencia.exe          # Windows
```

---

## 7. Uso de Inteligência Artificial

> Conforme exigido na especificação, indicar onde a IA foi utilizada.



---

## 8. Autores

|Pedro Luís de Oliveira Lima|
|Antônio Lucas de Oliveira Silva|
|Belchior Dias Cruz|

