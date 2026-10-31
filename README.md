# APBC – Agência Paraibana de Contratos

Sistema de gerenciamento (CRUD) de uma agência **fictícia** de mercenários, desenvolvido em C++ para o projeto da disciplina **Linguagem de Programação I** (Semestre 2026.2 – Prof. Derzu Omaia).

> Projeto totalmente fictício, feito para fins acadêmicos. Qualquer semelhança com a realidade é coincidência.

## Sobre o projeto

A APBC cadastra e administra contratos de execução. Cada contrato tem cliente, alvo, local, recompensa, prazo e, se já foi cumprido, data de conclusão. A agência cobra uma **taxa adicional** (percentual sobre a recompensa) que varia conforme o tipo do contrato.

## Funcionalidades

Menu principal em loop até o usuário escolher sair:

| Opção | Descrição |
|-------|-----------|
| 1 | Inserir contrato |
| 2 | Listar todos os contratos |
| 3 | Exibir um contrato (pesquisa por nome do alvo) |
| 4 | Alterar contrato (pesquisa por nome do alvo) |
| 5 | Remover contrato (pesquisa por nome do alvo) |
| 6 | Exibir relatório da agência |
| 7 | Sair |

O relatório mostra o total de contratos, o valor total das recompensas somadas às taxas e os detalhes de cada contrato.

## Tipos de contrato e taxas

| Tipo | Atributos próprios | Regra da taxa |
|------|--------------------|---------------|
| **Diplomático** | cargo do alvo, organização envolvida | 50% fixa |
| **Espetacular** | público estimado, divulgação na mídia | 10% base; +20% se público > 10.000; +10% se houver divulgação na mídia |
| **Furtivo** | tempo limite (min), nível de segurança (1–10) | 5% base; +10% se tempo < 60; +15% se nível > 5 |

## Modelagem (POO)

- **Herança:** `Contrato` (classe abstrata) é a superclasse de `ContratoDiplomatico`, `ContratoEspetacular` e `ContratoFurtivo`.
- **Composição:** `Contrato` possui dois objetos `Data` (`dataLimite` e `dataConclusao`).
- **Polimorfismo:** a agência guarda `vector<Contrato*>` e chama `exibirContrato()` (método virtual puro) sem saber o tipo concreto.
- **Encapsulamento:** atributos privados/protegidos com getters e setters.
- **Gerenciamento:** a classe `AgenciaMercenarios` concentra as operações CRUD, deixando a `main` só com o menu.
- **Memória:** os contratos são alocados dinamicamente e liberados no destrutor da agência.

```
Data
  ▲ (composição)
Contrato  «abstract»
  ├── ContratoDiplomatico
  ├── ContratoEspetacular
  └── ContratoFurtivo

AgenciaMercenarios ◇── 0..* Contrato
```

## Estrutura de pastas

```
.
├── include/
│   ├── AgenciaMercenarios.h
│   ├── Contrato.h
│   ├── ContratoDiplomatico.h
│   ├── ContratoEspetacular.h
│   ├── ContratoFurtivo.h
│   └── Data.h
├── src/
│   └── main.cpp
└── README.md
```

## Como compilar e executar

Requer um compilador com suporte a C++11 ou superior (g++, clang++ ou MSVC).

```bash
g++ -std=c++17 -Iinclude src/main.cpp -o apbc
./apbc          # Linux/macOS
apbc.exe        # Windows
```

## Exemplo de uso

```
Bem-vindo ao sistema de gerenciamento da APBC (Agência Paraibana de Contratos).
Digite a opcao desejada:
 1 - Inserir contrato
 ...
1
Digite o tipo de contrato (Diplomatico, Espetacular, Furtivo): Furtivo
Digite o nome do cliente: Maria Silva
Digite o nome do alvo: Joao
Digite a recompensa: 1000
...
```

Observações de entrada:
- O tipo deve ser digitado exatamente como `Diplomatico`, `Espetacular` ou `Furtivo`.
- Datas no formato `dd/mm/aaaa`.
- Campos de sim/não usam `1` (sim) e `0` (não).

## Limitações conhecidas

- A pesquisa (opções 3, 4 e 5) exige o **nome exato** do alvo e, como usa `cin >>`, não aceita nomes com espaço.
- Não há persistência: os dados são perdidos ao sair do programa.
- Entradas inválidas (ex.: letras em campos numéricos) não são tratadas de forma robusta.


## Autores

- Belchior Dias Cruz
- Pedro Luís de Oliveira Lima
- Antônio Lucas de Oliveira Silva

**Disciplina:** Linguagem de Programação I – 2026.2 · **Professor:** Derzu Omaia