#include "../include/Jogador_Bot.hpp"

Jogador_Bot::Jogador_Bot(std::string _nick) : Jogador(_nick)
{
}

Jogador_Bot::~Jogador_Bot()
{
}

void Jogador_Bot::funcao_teste()
{

}
bool Jogador_Bot::apostar(int &valorMesa) 
{
   int aposta = valorMesa - this->get_Apostado();

   //Se o bot já estiver apostado o valor da mesa, então ele dará check()
   if(aposta == 0) return true;

   //Em caso contrário verificaremos se ele ainda pode apostar nessa rodada
   else if(this->get_Saldo() + this->get_Apostado() > valorMesa)
   {
      int aposta_em_fichas = 0, ficha, quantidadeFicha;
        
      for (int i = 0; i < this->get_Fichas().size(); i++)
      {
         if(this->get_Fichas()[i].second > 0)
         {
            ficha = this->get_Fichas()[i].first;
            quantidadeFicha = this->get_Fichas()[i].second;
         }
            
         aposta_em_fichas += ficha * quantidadeFicha;
         this->get_Fichas()[i].second -= quantidadeFicha;
         // se a quantidade apostada em fichas ate então suprir o valor da aposta proposta, ele finaliza com um goto endloop
         if(aposta_em_fichas >= aposta)
         {
            aposta_em_fichas -= aposta;
            this->aumenta_Saldo( -aposta);
            set_Apostado(this->get_Apostado() + aposta);
            converte_Sobressalente(aposta_em_fichas);
            return true;
         }
      }
   }                 
    
   //Se a aposta for igual ao saldo do jogador, isso quer dizer que o jogador entrará em modo all in
   else if(!(this->is_True_All_In()))
   {
      this->set_All_In(true);
      this->aumenta_Saldo(0);
      this->set_Apostado(get_Apostado() + aposta);
      return true;
   }
      return false;
}

/*int main()
{
   int valorMesa = 100;
   Jogador_Bot bot1("bot1");
   Jogador_Bot bot2("bot2");

   bot1.exibir_Info(valorMesa); // Add missing argument here
   bot1.apostar(valorMesa);
   bot1.exibir_Info(valorMesa);
   std::cout << valorMesa << std::endl;
}*/

