# 20232-team-2
20232-team-2
# Documentação da Classe Carta em C++
## Resumo
### A classe Carta representa uma carta de baralho para um jogo de Poker. Abaixo está um resumo dos seus conteúdos:

#### Atributo Estático
naipes_possiveis: Este array estático contém os possíveis naipes que uma carta pode ter: "Ouros" , "Espadas", "Copas" e "Paus".

#### Métodos
##### Carta(int valorCarta, std::string naipe): 
Este é o construtor da classe Carta. Ele recebe dois parâmetros: valorCarta, que é o valor da carta, e naipe, que é o naipe da carta. Inicializa as variáveis de instância valorCarta e naipe com os valores fornecidos.

##### ~Carta(): 
Este é o destrutor da classe Carta. Ele não realiza nenhuma ação.

##### get_Valor_Carta(): 
Este método retorna o valor da carta.

##### get_Naipe(): 
Este método retorna o naipe da carta.

#### Utilidade
Esta classe oferece uma maneira de criar e manipular cartas de baralho, elementos fundamentais em muitos jogos de cartas. Cada instância da classe representa uma carta com um valor (rank) e um naipe específico