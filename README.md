# 20232-team-2
20232-team-2
## Colaboradores
### Anderson Gabriel Souza Rosario
### Hygor de Oliveira Souza
# Resumo das Regras do Poker

### O poker é um jogo de cartas amplamente praticado em diversas variações. A seguir, apresentamos um resumo das regras básicas do poker, que podem ser adaptadas conforme a variante específica do jogo:

## Objetivo do Jogo:

O objetivo principal do poker é ganhar fichas ou dinheiro, que são apostados pelos jogadores ao longo das rodadas.

### Ranking de Mãos:

As mãos de poker são classificadas de acordo com a combinação de cartas que um jogador possui. Sendo elas:
1)Royal Flush = 100 pontos.
2)Straight Flush = 90 pontos.
3)Quadra = 80 pontos.
4)Full House = 70 pontos.
5)Flush = 60 pontos.
6)Straight = 50 pontos.
7)Trinca = 40 Pontos.
8)Dois Pares = 30 pontos.
9)Um Par = 20 Pontos.
10)Nenhum dos anteriores = {A pontuação será dada de acordo com a maior carta na mão do jogador, com seus valores dados entre 2 e 14, 2 equivale a própria carta 2, 14 equivalente ao Ás}


## Rodadas de Apostas:

O jogo consiste em rodadas de apostas, onde os jogadores têm a oportunidade de apostar, aumentar, igualar ou desistir.

## Apostas e Fichas:

Cada jogador receberá 1000 unidades em fichas no início de cada jogo e as apostará durante as rodadas.
As apostas podem ser forçadas (small e big blind) ou voluntárias (apostas normais).
Blinds e Antes:

Alguns jogos de poker começam com apostas forçadas chamadas "blinds" e/ou "antes" para iniciar o pote.

## Cartas Comunitárias:

Composta por cinco cartas. A partir da da segundada rodada elas começam a serem mostradas respectivamente na ordem três, uma e uma totalizando as cinco cartas.
Desempate:

## Mãos Iniciais e Combinações:

Conhecimento das mãos iniciais fortes e estratégias de combinação de cartas é crucial para o sucesso no poker.
Desistência (Fold):

### Os jogadores podem desistir de uma mão a qualquer momento, abrindo mão das fichas apostadas até o momento.
Showdown:

Após a última rodada de apostas, se mais de um jogador permanecer, ocorre o showdown, revelando as cartas e determinando o vencedor.

# Informaçções sobre o código

# Documentação da Classe Carta em C++
## Resumo
#### A classe Carta representa uma carta de baralho para um jogo de Poker. Abaixo está um resumo dos seus conteúdos:
#### Utilidade
Esta classe oferece uma maneira de criar e manipular cartas de baralho, elementos fundamentais em muitos jogos de cartas. Cada instância da classe representa uma carta com um valor (rank) e um naipe específico

### Atributo Estático
naipes_possiveis: Este array estático contém os possíveis naipes que uma carta pode ter: "Ouros" , "Espadas", "Copas" e "Paus".

## Métodos
#### Carta(int valorCarta, std::string naipe): 
Este é o construtor da classe Carta. Ele recebe dois parâmetros: valorCarta, que é o valor da carta, e naipe, que é o naipe da carta. Inicializa as variáveis de instância valorCarta e naipe com os valores fornecidos.

#### ~Carta(): 
Este é o destrutor da classe Carta. Ele não realiza nenhuma ação.

### Métodos de acesso
#### get_Valor_Carta(): 
Este método retorna o valor da carta.

#### get_Naipe(): 
Este método retorna o naipe da carta.


# Documentação da Classe Mao(Mão) em C++
## Resumo
#### A classe Mao em C++ verifica se uma mão atende aos critérios de diferentes tipos de mãos de poker.

## Métodos de acesso
#### get_Cartas()
Este método retorna as cartas na mão como um std::vector de objetos Carta.

#### get_Valor_Mao()
Este método calcula e retorna o valor da mão com base nas regras do poker. Ele verifica se a mão atende aos critérios de vários tipos de mãos de poker, como Par, dois Pares, Trinca, Straight, Flush, Full House, Quadra, Straight Flush, Royal Flush, respectivamente ordenada com seus valores crescentes. Se a mão não atender aos critérios de nenhum desses tipos, o método ordena as cartas por valor e retorna o valor da carta mais alta. O valor da mão é utilizado para determinar o vencedor em um jogo de poker.

### Métodos de Verificação
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

## Métodos
#### compare_Valor_Cartas(Carta &carta1, Carta &carta2)
Este método é utilizado para ordenar cartas com base em seus valores. Recebe dois objetos Carta como argumentos e retorna true se o valor da primeira carta for menor que o valor(int) da segunda carta. 

#### compare_Naipe(Carta &carta1, Carta &carta2)
Este método é utilizado para ordenar cartas com base em seus naipes. Se os naipes das duas cartas forem iguais, elas são ordenadas com base em seus valores. Caso contrário, são ordenadas com base em seus naipes. 

#### adicionar_Carta(Carta &novaCarta)
Este método é utilizado para adicionar um objeto Carta ao vetor cartas, que representa a mão do jogador em um jogo de cartas.

#### Cada método faz uma cópia ordenada das cartas, utilizado para não modificar a sequência real das cartas, e verifica se atendem aos critérios específicos do tipo de mão de poker.

# Documentação da Classe Jogador em C++
## Resumo
#### A classe Jogador tem o propósito de representar um jogador em um jogo de poker. O código fornece métodos para gerenciar a mão do jogador, receber cartas, desistir e realizar apostas, além de atributos essenciais para o jogo, como o saldo.

### Métodos de Acesso (Getter)
#### get_Nick()
Este método retorna o apelido do jogador. É um método getter, utilizado para acessar o nome que o usuário escolheu utilizar no jogo, não podemos ter dois usuários com nomes iguais.

#### get_Mao()
Descrição: Retorna a mão do jogador (mao).
Tipo de Retorno: Objeto Mao (Mão).

#### get_Valor_Mao()
Descrição: Retorna o valor da mão do jogador.
Tipo de Retorno: Inteiro.

#### get_Apostado()
Descrição: Retorna a quantia que o jogador apostou (apostado).
Tipo de Retorno: Inteiro.
#### get_Saldo()
Descrição: Retorna o saldo do jogador (saldo).
Tipo de Retorno: Inteiro.
### Métodos de Verificação 
#### is_Ativo()
Retorna verdadeiro se o jogador estiver ativo, falso caso contrário.

#### is_Small_Blind()
Retorna verdadeiro se o jogador for o small blind, falso caso contrário.

#### is_Big_Blind()
Retorna verdadeiro se o jogador for o big blind, falso caso contrário.

#### is_All_In()
Retorna verdadeiro se o jogador estiver em estado all-in, falso caso contrário.

#### is_Vez()
Retorna verdadeiro se for a vez do jogador agir, falso caso contrário.

#### is_Check()
Retorna verdadeiro se o jogador deu check, falso caso contrário.

#### is_Primera_Rodada()
Retorna verdadeiro se for a primeira rodada de apostas, falso caso contrário.

#### is_Partida_Finalizada()
Retorna verdadeiro se a partida estiver finalizada, falso caso contrário.

### Métodos de Modificação (Setter)
#### set_Ativo(bool _ativo)
Descrição: Define o status ativo do jogador.
Parâmetro: _ativo - Booleano.

#### set_Apostado(int valor)
Descrição: Define a quantia apostada pelo jogador.
Parâmetro: valor - Inteiro.

#### Métodos para Definir Status 
#### set_Small_Blind(bool small)
Define o status do jogador como small blind. Parâmetro: Booleano.

#### set_Big_Blind(bool big) 
Define o status do jogador como big blind. Parâmetro: Booleano.

#### set_Vez(bool _vez)
Define se é a vez do jogador agir. Parâmetro: Booleano.

#### set_All_In(bool _all_in)
Define se o jogador está em estado all-in. Parâmetro: Booleano..

## Métodos
#### Jogador(std::string nick)
Este é o construtor da classe Jogador. Recebe um parâmetro nick do tipo string, que representa o apelido do jogador. O construtor inicializa o apelido do jogador com o valor fornecido, define o status do jogador como ativo (ativo = true), e inicializa várias outras variáveis booleanas como falsas. Além disso, configura as fichas do jogador com denominações e quantidades específicas, define o saldo do jogador (saldo) como 1000, e inicializa a quantidade apostada pelo jogador (apostado) como 0. (Para fazer uso do polimorfismo(modo competitivo(todos os jogadores iniciam com a mesma quantidade de fichas) ou cast game(utiliza dinheiro para comprar fichas)) esse método t)

#### ~Jogador()
Este é o destrutor da classe Jogador. Não realiza nenhuma ação porque a classe não possui nenhum espaço de memória alocado dinamicamente que precisa ser liberado.

#### reset_Mao()
Este método reinicia a mão do jogador. Ele cria um novo objeto Mao e atribui à variável mao.

#### receber_Carta(Carta carta)
Permite que o jogador receba uma carta, adicionando-a à mão do jogador usando o método adicionar_Carta do objeto mao.

#### desistir()
Permite que o jogador desista. Solicita confirmação e, se o jogador digitar "SIM", define a bandeira ativo como false, indicando que o jogador não está mais ativo.

#### apostar(int &valorMesa)
Método de aposta que interage com o usuário para lidar com diferentes cenários. Inclui verificações para apostar o saldo total como "all-in" e apostas específicas com fichas. Retorna true se a aposta for bem-sucedida; caso contrário, retorna false. 

#### exibir_Info(int ValorMesa)
Este método é utilizado para exibir as informações do jogador. Imprime o apelido do jogador, a quantidade de fichas de cada tipo que o jogador possui, o saldo total e se o jogador cobriu a aposta mais alta na mesa. Também indica se o jogador é o small blind ou big blind na rodada atual.
Parâmetro: ValorMesa - Inteiro representando a aposta mais alta na mesa.

#### aumenta_Saldo(int _saldo)
Descrição: Este método é utilizado para aumentar o saldo do jogador (saldo). Adiciona o valor fornecido (_saldo) ao saldo do jogador e, em seguida, chama o método converte_Sobressalente com _saldo como argumento.
Parâmetro: _saldo - Inteiro representando o valor a ser adicionado ao saldo.

#### converte()
Este método é utilizado para converter as fichas do jogador de um tipo para outro. O jogador escolhe o tipo de ficha que deseja converter, o tipo de ficha para o qual deseja converter, bem como a quantidade de fichas a serem convertidas. O método verifica se o jogador possui fichas suficientes do tipo escolhido e se a quantidade de fichas a ser convertida é suficiente para obter pelo menos uma ficha do tipo desejado. Se essas condições forem atendidas, o método realiza a conversão.

#### converte_Sobressalente(int aposta_em_fichas)
Este método converte uma quantidade especificada de dinheiro (aposta_em_fichas) em fichas de várias denominações. Começa com a denominação mais alta e percorre até a mais baixa, convertendo o máximo possível de dinheiro em fichas em cada etapa.
Estes métodos da classe Jogador fornecem funcionalidades para exibir informações, aumentar o saldo e realizar conversões de fichas, sendo essenciais para a interação e o funcionamento do jogador em um jogo de poker.

# Documentação da Classe Dealer em C++
## Resumo
#### A classe Dealer em C++ gerencia um jogo de poker, com métodos para designar papéis, iniciar partidas, criar salas, baralhos e controlar fases do jogo.
## Métodos de Acesso (Getter)
#### get_baralho()
Retorna o baralho, que é um vetor de objetos Carta (Card). Representa o baralho atual de cartas que o dealer possui.
Tipo de Retorno: Vetor de Carta.

#### get_mesa()
Retorna a mesa, que também é um vetor de objetos Carta. Provavelmente representa as cartas que estão atualmente na mesa.
Tipo de Retorno: Vetor de Carta.
#### get_jogadores()
Retorna os jogadores, que é um vetor de objetos Jogador (Player). Representa os jogadores no jogo.
Tipo de Retorno: Vetor de Jogador.

#### get_Valor_Mesa()
Retorna o valorMesa. Pode representar a aposta ou valor atual no pote na mesa.
Tipo de Retorno: Inteiro.

#### get_Primeiro_Jogador()
Retorna o primeiro_Jogador. Pode representar o jogador que inicia a rodada.
Tipo de Retorno: Inteiro.

#### Métodos de Modificação (Setter)
#### set_Valor_Mesa(int valorMesa)
Define o valorMesa para o valor inteiro fornecido.
Parâmetro: valorMesa - Inteiro.

#### set_Valor_Acumulado_Mesa(int valorAtualMesa)
Adiciona o valor inteiro fornecido ao valor_Acumulado_mesa. Pode representar o valor total das apostas feitas na mesa ao longo de várias rodadas.
Parâmetro: valorAtualMesa - Inteiro.

#### set_Primeiro_Jogador(int id_Primeiro_Jogador)
Define o primeiro_Jogador para o valor inteiro fornecido, provavelmente representando o ID do primeiro jogador.
Parâmetro: id_Primeiro_Jogador - Inteiro.

#### set_Primeira_Aposta(int primeira_Aposta)
Define a primeira_Aposta para o valor inteiro fornecido. Pode representar a primeira aposta feita em uma rodada.
Parâmetro: primeira_Aposta - Inteiro.

## Métodos
#### Dealer()
Este é o construtor da classe Dealer. Inicializa várias variáveis de membro com seus valores padrão. rodada é definido como 1, indicando o início do jogo. check é definido como 0, e é usada para rastrear quantos jogadores verificaram suas mãos. primeiro_Jogador é definido como -1, valor inexistente no jogo, mas utilizado para indicar que nenhum jogador foi definido como o primeiro. valor_Acumulado_mesa é definido como 0, indicando que nenhuma aposta foi feita ainda. primeira_Aposta é definido como 10, valor inicial mínimo da aposta(aumentará em 10 a cada partida). small_blind_apostou é definido como 0, indicando que o jogador do small blind ainda não fez uma aposta. valorMesa é definido como o valor de primeira_Aposta, indicando que a aposta ou valor atual no pote na mesa é igual à aposta inicial. partidaFinalizada é definido como falso, indicando que o jogo ainda não está finalizado.

#### designar_Small_Blind()
Atribui o papel de Small Blind ao próximo jogador na lista, ciclando se necessário.

#### designar_Big_Blind()
Atribui o papel de Big Blind de maneira semelhante ao designar_Small_Blind().

#### designar_Primeiro_Jogador()
Designa o primeiro jogador a jogar na rodada, considerando o Small Blind inicial e lidando com jogadores inativos.

#### iniciar_Partida()
Inicia o jogo, criando a sala, atribuindo papéis, distribuindo cartas e iniciando quatro rodadas de apostas. Finaliza a rodada se houver apenas um jogador com dinheiro restante.

#### criar_Sala()
Cria a sala do jogo, solicitando o número e apelidos dos jogadores, definindo aleatoriamente o Big Blind e atribuindo o Small Blind ao próximo jogador.

#### criar_Baralho()
Cria e embaralha um baralho padrão de 52 cartas.

#### criar_Mesa()
Cria as cartas comunitárias (a "mesa") simulando as fases "flop", "turn" e "river".

#### embaralhar_Cartas()
Embaralha o baralho usando a função std::random_shuffle da Biblioteca Padrão do C++.

#### dar_Cartas()
Distribui duas cartas para cada jogador, define estados iniciais e exibe as cartas.

#### passar_Vez()
Passa a vez para o próximo jogador ativo.

#### verificar_Check()
Verifica se todos os jogadores ativos deram check.

#### verificar_Rodadas()
Verifica se a rodada atual acabou, reinicia apostas e incrementa o contador de rodadas. Define partidaFinalizada como true se atingir a quarta rodada.

#### mostrar_Cartas()
Exibe um número especificado de cartas de uma lista fornecida, lidando com cartas de face separadamente das numeradas.

#### finalizar_Partida()
Não implementado no código fornecido, provavelmente lidaria com o fim do jogo.
