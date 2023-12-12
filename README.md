# 20232-team-2
20232-team-2
# Documentação da Classe Carta em C++
## Resumo
#### A classe Carta representa uma carta de baralho para um jogo de Poker. Abaixo está um resumo dos seus conteúdos:

### Atributo Estático
naipes_possiveis: Este array estático contém os possíveis naipes que uma carta pode ter: "Ouros" , "Espadas", "Copas" e "Paus".

## Métodos
#### Carta(int valorCarta, std::string naipe): 
Este é o construtor da classe Carta. Ele recebe dois parâmetros: valorCarta, que é o valor da carta, e naipe, que é o naipe da carta. Inicializa as variáveis de instância valorCarta e naipe com os valores fornecidos.

#### ~Carta(): 
Este é o destrutor da classe Carta. Ele não realiza nenhuma ação.

#### get_Valor_Carta(): 
Este método retorna o valor da carta.

#### get_Naipe(): 
Este método retorna o naipe da carta.

#### Utilidade
Esta classe oferece uma maneira de criar e manipular cartas de baralho, elementos fundamentais em muitos jogos de cartas. Cada instância da classe representa uma carta com um valor (rank) e um naipe específico

# Documentação da Classe Mao(Mão) em C++
## Resumo
#### A classe Mao em C++ verifica se uma mão atende aos critérios de diferentes tipos de mãos de poker.

## Métodos
#### compare_Valor_Cartas(Carta &carta1, Carta &carta2)
Este método é utilizado para ordenar cartas com base em seus valores. Recebe dois objetos Carta como argumentos e retorna true se o valor da primeira carta for menor que o valor(int) da segunda carta. 

#### compare_Naipe(Carta &carta1, Carta &carta2)
Este método é utilizado para ordenar cartas com base em seus naipes. Se os naipes das duas cartas forem iguais, elas são ordenadas com base em seus valores. Caso contrário, são ordenadas com base em seus naipes. 

#### get_Cartas()
Este método retorna as cartas na mão como um std::vector de objetos Carta.

#### get_Valor_Mao()
Este método calcula e retorna o valor da mão com base nas regras do poker. Ele verifica se a mão atende aos critérios de vários tipos de mãos de poker, como Par, dois Pares, Trinca, Straight, Flush, Full House, Quadra, Straight Flush, Royal Flush, respectivamente ordenada com seus valores crescentes. Se a mão não atender aos critérios de nenhum desses tipos, o método ordena as cartas por valor e retorna o valor da carta mais alta. O valor da mão é utilizado para determinar o vencedor em um jogo de poker.

#### is_Par():
Verificar se há duas cartas do mesmo valor na mao. Retornará true caso existam e false caso contrário.

#### is_Dois_Pares():
Verifica se a mão contém Dois Pares.

#### is_Trinca():
Verifica se a mão contém uma Trinca (three-of-a-kind).

#### is_Straight()
Verifica se a mão contém um Straight (cinco cartas sequenciais).

#### is_Flush()
Verifica se a mão contém um Flush (cinco cartas do mesmo naipe).

#### is_Full_House()
Verifica se a mão contém um Full House (um par e uma trinca).

#### is_Quadra()
Verifica se a mão contém uma Quadra (four-of-a-kind).

#### is_Straight_Flush()
Verifica se a mão contém um Straight Flush (um straight e um flush).

#### is_Royal_Flush()
Verifica se a mão contém um Roayal Flush.

#### adicionar_Carta(Carta &novaCarta)
Este método é utilizado para adicionar um objeto Carta ao vetor cartas, que representa a mão do jogador em um jogo de cartas.

#### Cada método faz uma cópia ordenada das cartas, utilizado para não modificar a sequência real das cartas, e verifica se atendem aos critérios específicos do tipo de mão de poker.

