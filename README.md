# Barbeiro Dorminhoco

Trabalho final da disciplina de Sistemas Operacionais.

## Descrição do Problema

O problema do Barbeiro Dorminhoco é um clássico da programação concorrente. Ele descreve um cenário em que um barbeiro dorme enquanto não há clientes na barbearia. Quando um cliente chega, ele acorda o barbeiro para ser atendido. Se o barbeiro estiver ocupado e houver cadeiras disponíveis, o cliente espera. Se todas as cadeiras estiverem ocupadas, o cliente vai embora. O problema modela um sistema de multitarefas, onde precisamos garantir que o acesso à barbearia e às cadeiras seja controlado corretamente, evitando condições de corrida e garantindo a sincronização entre clientes e barbeiro. 

Nesta implementação, utilizou semáforos em C++ com Programação Orientada a Objetos (POO) para resolver o problema e gerenciar a sincronização.

## Instruções de Uso

### Configuração

Para ajustar a quantidade máxima de cadeiras e clientes:
- Localize o arquivo `BarberShop.h`.
- Abaixo do cabeçalho, altere os valores das constantes `NCHAIRS` (número de cadeiras) e `NCLIENTS` (número de clientes) conforme desejado.

### Execução no Linux

Este programa foi desenvolvido para Linux. Para executar o código no CodeBlocks com suporte à biblioteca pthread, siga os seguintes passos:

1. Abra a IDE **CodeBlocks**.
2. Acesse o menu **Settings**.
3. Selecione a opção **Compiler**.
4. Na janela **Compiler**, vá para a aba **Linker settings**.
5. No campo **Link libraries**, adicione a biblioteca `pthread` para suporte à execução de threads.

### Passos Finais

- Abra o projeto no **CodeBlocks**.
- Compile e execute o programa.

---

Com essas configurações, o programa será capaz de simular corretamente o problema do Barbeiro Dorminhoco utilizando semáforos para controlar o fluxo de clientes e o barbeiro.
